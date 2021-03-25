#include<iostream>
using namespace std;

#define tab "\t"

using std::cin;
using std::cout;
using std::endl;

//�������� ���������:
class Point
{
	//��������� Point ��������� ����� �� ���������.
	double x;//���������� �� X
	double y;//���������� �� Y
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	/*Point()
	{
		//����������� �� ��������� ������� ����� � ������ ���������
		x = y = int();	//����� �������� ���������� �� ��������� ��� 'int', � �� ���������� �������� �� ���������
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		//����������� � ����� ���������� ������� ����� �� ������.
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		//����������� � ����������� ������� ����� �� ���������
		//���� ���������� � ����������� ����� ���� ������ 
		//-��� ����������;
		//-� ����� ����������;
		//-� ����� �����������;
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//other - ��� ������ ������, ����� �������� �� �������
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//				Methods:
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);//sqrt - Square Root (���������� ������)
		return distance;
	}
};
//�������� ��������� ��� �����, �� ������� ����� ��� ������, 
//� �������� ������� ����� ������ ��� ��������� �� ������� ���������� ������ ����.
//			����� - ��� ��� ������
//		��������� - ��� ��� ������
//		������ - ��� ����� ������� ����������.

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define INTRO
//#define CONSTRUCTORS
#define ASSIGNMENT_CHECK
//#define DISTANCE
//#define OPERATOR_EXAMPLES

void main()
{

	setlocale(LC_ALL, "Rus");
#ifdef INTRO
	int a;	//���������� ���������� 'a', ���� 'int'
	Point A;//���������� ������� 'A' ��������� 'Point'
			//���������� ���������� 'A' ���� 'Point'
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;	//������� ��������� �� ������
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO

#ifdef CONSTRUCTORS
	Point A;//Default constructor
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(8);	//Single-Argument constructor
	C.print();

	Point D{ 12 };//Single-Argument constructor
	D.print();

	int a(2);
	int b{ 3 };
	cout << a << tab << b << endl;

	Point E(5, 3);//Parametrized constructor
	E.print();

	Point F = E;//CopyConstructor. ����� �� ������� ������, � �������������� ��� ������ ��������
	Point G;	//DefaultConstructor
	G = D;	//CopyAssignment - operator=
	G.print();
#endif // CONSTRUCTORS

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point();
#endif // ASSIGNMENT_CHECK

#ifdef DISTANCE
	Point A(2, 3);
	Point B(4, 5);
#ifdef OPERATOR_EXAMPLES
	cout << A + B << endl;	//������� ����� ��������� '+'
	cout << A.operator+(B) << endl;//����� ����� ��������� '+', �������������� � ������
	cout << operator+(A, B) << endl;//����� ����� ��������� '+', �������������� �� �������  
#endif // OPERATOR_EXAMPLES


	A.print();
	B.print();
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
	int();
	A.print();
	B.print();
#endif // DISTANCE

}

/*
-------------------------------------
.  - �������� ������� ������� (Point operator) ������������ ��� ������� � ����� ������� �� ����� �������
-> - �������� ���������� ������� (Arrow operator) ������������ ��� ������� � ����� ������� �� ������ �������
this - ��� ��������� �� ������, ��� �������� ���������� �����.
-------------------------------------
*/

/*
-------------------------------------
1. Encapsulation - ��� �������� ������������ ����� ������ �� �������� ����;
	������������ �������:
		private: �������� ���� (�����) ������, ��������� ������ ������� ������
				 � ���������� �� ��� ���������.����� ����������� ������ ���������� ���������� ����� ������!!!
		public:	 �������� ����, ��������� �� ������ ����� ���������, ��� �������� ������.
				 � public-������ ������ ��������� ������.
		protected: ����������� ������ ��� ������������.
	get/set-������
	get - �����
	set - ������ + ������������� ������������ ��������.
2. Inheritance;
3. Polymorphism;
-------------------------------------
*/

/*
-------------------------------------
Constructor - ��� �����, ������� ������� ������.
			  �������� ������ ��� ������ � �������������� ��� ���� ��� ��������.
Destructor  - ��� �����, ������� ���������� ������ �� ��������� ��� ������� �����.
~
class Class
{
	Class()
	{
		//Constructor
	}
	~Class()
	{
		//Destructor
	}
};
for(Point A = 0; A < 10; A++)
{
}
if(�������)
{
	Point A;
	...
	./...
}����� ����� A ��� ���, �� ����� ����� �������.
-------------------------------------
*/

/*
------------------------------------------
			OPERATOR OVERLOADS
1) ����������� ����� ������ ������������ ���������:
	+  - �������������;
	++ - �������������;
	*  - ��������������
	** - �� �������������;
2) �� ��� ������������ ��������� ����� �����������.
   �� �������������:
	:: - scope operator (�������� ���������� ���������);
	?: - ��������� ��������;
	.  - �������� ������� �������;
	.* -
	#  - preprocessor directive
	## - preprocessor concatenation
3) ������������� ��������� ��������� ���������;
4) ������ �������������� ��������� ���������� �� ����������� ������;
------------------------------------------
*/