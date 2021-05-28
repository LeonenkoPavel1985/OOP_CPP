#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//��������� �� ��������� �������
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class Iterator;
	friend class ForwardList;
};

int Element::count = 0;	//������������� ����������� ����������

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr)
	{
		this->Temp = Temp;
		cout << "IConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
	}

	//			Operators:
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	Element*& operator->()
	{
		return Temp;
	}
	Element* get_current_address()
	{
		return Temp;
	}
};

class ForwardList
{
	Element* Head;
	int size;
public:
	ForwardList()
	{
		//DefaultConstructor ������� ������ ������.
		Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other)
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyConstructor:" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//			Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyAssignment:" << this << endl;
		return *this;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/

		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		//���� ����� �� ����� �������� � ������ �������
		if (Head == nullptr)	//���� ������ ����
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		Temp->pNext = new Element(Data);
		size++;
	}

	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr)break;
		//Temp = Temp->pNext;
		/*New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//					Erasing elements:
	void pop_front()
	{
		//1) ������ ��� ��������� ������� �� ������, ����� ��������� ��� �����, ��� ����, ����� ����� ���� ������� ��� �� ������.
		Element* Temp = Head;
		//2) ��������� ������� �� ������:
		Head = Head->pNext;
		//3) ������� ������� �� ������:
		delete Temp;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;	//������� �� ��������� �������
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		//1)������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//2)���������� ����� ���������� ��������:
		Element* to_del = Temp->pNext;
		//3)��������� ��������� ������� �� ������:
		Temp->pNext = Temp->pNext->pNext;
		//4)������� ������� �� ������:
		delete to_del;
		size--;
	}

	//			Methods:
	void print()
	{
		//Element* Temp = Head;	//Temp - ��� ��������.
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}
		//for(Initialisation; Condition; Expression)...
		//for (Element* Temp = Head; Temp; /*Temp=Temp->pNext*/Temp++)
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << Temp.get_current_address() << tab << Temp->Data << tab << Temp->pNext << endl;;
		cout << "���������� ��������� � ������: " << size << endl;
		cout << "����� ���������� ���������:    " << Element::count << endl;
	}
};

#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
#ifdef BASE_CHECK
	/*cout << delimiter << endl;
list.pop_front();
list.pop_back();
list.print();*/
	int value;
	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	list.insert(value, index);
	list.print();
	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();

	/*cout << "��� ���� ������:\n";
	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.print();*/
#endif // BASE_CHECK

	//ForwardList list2 = list;//CopyConstructor
	//list2.print();

	//ForwardList list3;
	//list3 = list2;		//CopyAssignment
	//list3.print();
}