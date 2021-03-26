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
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=\t\t" << this << endl;
		return *this;
	}

	//			Increment/Decrement
	Point& operator++()	//Prefix increment
	{
		this->x++;
		this->y++;
		cout << "Prefix increment:\t\t" << this << endl;
		return *this;
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this;	//CopyConstructor
		this->x++;
		this->y++;
		cout << "Postfix increment:\t" << this << endl;
		return old;
	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator+" << endl;
		return result;
	}*/
	/*Point operator-(const Point& other)const
	{
		Point result(this->x - other.x, this->y - other.y);
		cout << "operator-" << endl;
		return result;
	}*/
	/*Point operator*(const Point& other)
	{
		return Point(this->x*other.x, this->y*other.y);
	}
	Point operator/(const Point& other)
	{
		return Point(this->x/other.x, this->y/other.y);
	}*/


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

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}
Point operator/(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}

std::ostream& operator<<(std::ostream& os/*output stream*/, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}

//#define INTRO
//#define CONSTRUCTORS
//#define ASSIGNMENT_CHECK
//#define DISTANCE
//#define OPERATOR_EXAMPLES
#define OPERATOR_OVERLOADS
//#define ARITHMETICAL_OPERATORS
#define COMPOUND_ASSIGNMENTS

void main()
{
	3;
	-3;//Unary minus
	5 - 3;//Binary minus
	5 * 3;//Binary multiplication
	//*3;//Have no sense
	int i = 3;
	i++;//Unary suffix increment
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

#ifdef OPERATOR_OVERLOADS
	int a = 2;
	int b = 3;
	int c = a + b;
	a += b;
	//++a++;

#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	Point D = A - B;//������� ����� ���������
	D.print();
	(A * B).print();
	//Point E = A.operator/(B);//����� ����� ���������. �� ��� ���� ��������, ��� ������� �����
	Point E = operator/(A, B);//����� ����� ����������� ���������.
	E.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef COMPOUND_ASSIGNMENTS
	Point A(2, 3);
	Point B(4, 5);
	A += B;
	A.print();
	/*++A;
	A.print();
	(A++).print();
	A.print();*/

	cout << A++ << endl;
	cout << A << endl;
	cout << ++A << endl;
	cout << A << endl;
	++A++;
#endif

#endif // OPERATOR_OVERLOADS


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