#include<iostream>
#include<array>
#include<vector>
#include<list>

//using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//#define STL_ARRAY
//#define STL_VECTOR
//#define EXEPTIONS_IN_VECTOR
#define STL_LIST

template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:     " << vec.size() << endl;				//	������.
	cout << "Capasity: " << vec.capacity() << endl;		//	��������������� - ������� ��������� ����� �������� � ���� ������, ��� ��������������� ������.
	cout << "MaxSize:  " << vec.max_size() << endl;		//	������������ ������
}

template<typename T> void vector_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template <typename T> void vector_reverse_print(const std::vector<T>& vec)
{
	//	�������� ������� vector_reverse_print(...),
	//	������� ����� �������� ������� � �������� �������.
	for (typename std::vector<T>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template<typename T> void vector_insert(std::vector<T>& vec, int index, T data)
{
	//	�������� �������� � ������ �� �������.
	//	������ � �������� �������� � ����������.

	////	C++98
	//if (index > vec.size())
	//{
	//	vec.push_back(data);
	//}
	//else
	//{
	//	vec.insert(vec.begin() + index, data);
	//}

	//	����� ����������� �����!
	//	>= C++11
	if (index > vec.size())
	{
		vec.emplace_back(data);
	}
	else if (index < 0)
	{
		return;
	}
	else
	{
		vec.emplace(vec.begin() + index, data);
	}
}

template<typename T> void vector_erase(std::vector<T>& vec, int index)
{
	//	������� �������� �� ������� �� ���������� �������, ���������� � ����������.
	if (index > vec.size() || index < 0)
	{
		return;
	}
	else
	{
		vec.erase(vec.begin() + index);
	}
}

template<typename T> void list_print(std::list<T>& list)
{
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

}

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef STL_ARRAY
	//	array - ��� ���������, ������� ������ ������ � ���� ������������ �������.
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
		//cout << arr.at(i) << tab;

	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	// Vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };

	vector_properties(vec);

	vec.push_back(55);
	cout << "vec.push_back(55)" << endl;

	vector_properties(vec);

#ifdef EXEPTIONS_IN_VECTOR
	// exeption - ��� ������ �� ����� ����������.
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//	[] - ������ �������h (subscript operator)
			//	try...catch...
			//cout << vec[i] << tab;	//	�������� '[]' - �� ������� '����������' ��� ������ �� ������� �������.

			cout << vec.at(i) << tab;	//	����� 'at()' - ������� '����������' (out of range exeption) ��� ������ �� ������� �������.
		}

		throw 123;
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (int e)
	{
		std::cerr << "Error: " << e << endl;
	}
#endif // EXEPTIONS_IN_VECTOR

	vector_print(vec);
	cout << "Revers:\n";
	vector_reverse_print(vec);

	vector_properties(vec);
	int data; int index;
	cout << "������ �������: "; cin >> index;
	cout << "�������� ��� �������: "; cin >> data;
	vector_insert(vec, index, data);

	/*std::vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, data);*/

	vector_print(vec);
	vector_properties(vec);
	cout << "������ ��� ��������: "; cin >> index;
	//vec.erase(vec.begin() + index);
	vector_erase(vec, index);
	vector_print(vec);
	vector_properties(vec);

	vector_properties(vec);
	vec.assign({ 1024,2048,3072 });
	vector_print(vec);
	vector_properties(vec);
	vec.shrink_to_fit();
	vector_properties(vec);

#endif // STL_VECTOR

#ifdef STL_LIST
	//	List - ��� ���������, ������� ������ ������� � ���� ����������� ������
	std::list<int> list = { 3,5,8,13,21 };

	/*for (int i = 0; i < list.size(); i++)
	{
		//	�������� [] - �� ��������, ������ ��� �� ������ ������� ������������������!!!
		cout << list[i] << tab;
	}
	cout << endl;*/

	list_print(list);

	/*std::vector<int> vec = {3,5,8,13,21};
	cout << "Vsize: " << vec.size() << endl;
	cout << "Vmax_size: " << vec.max_size() << endl;*/

	cout << "Lsize: " << list.size() << endl;
	cout << "Lmax_size: " << list.max_size() << endl;

	int data; int index;
	cout << "������ �������: "; cin >> index;
	cout << "�������� ��� �������: "; cin >> data;
	std::list<int>::iterator it;

	it = list.begin();
	for (int i = 0; i < index; i++)
	{
		it++;
	}

	list.insert(it, data);
	list_print(list);

#endif // STL_LIST

}