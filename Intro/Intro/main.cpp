#include <iostream>
using namespace std;

// �������� ���������.
class Point
{
	// ��������� Point ��������� ����� �� ���������.
	double x; // ���������� x.
	double y; // ���������� y.
public:
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	void set_x(double x)
	{
		this -> x = x;
	}
	void set_y(double y)
	{
		this -> y = y;
	}
	// constructors:
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this -> = x;
		this -> = 0;
		cout << "Constructor:\t\t" << this << endl;

		Point B = 5;
		B.print();
	}
	~Point()
	{
		cout << "Destructor\t" << this << endl;
	}
	void print()
		{
		cout << "X =" << x << "\tY =" << y << endl;
		}
};

//�������� ��������� ��� �����, �� ������� ����� ��� ������,
// � �������� �������� ����� ������ ��� ��������� �� ������� ���������� ����� ����.

// ����� - ��� ��� ������.
//��������� - ��� ��� ������.
// ������ - ��� ����� ������������ ����������.

void main()
{
	setlocale(LC_ALL, "Rus");
	int a; // ���������� ���������� ���� int.
	Point A; //���������� ������� � ��������� Point.
             // ���������� ���������� � ���� Point.
	A.set_x (2);
	A.set_y (3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A; // ������� ��������� �� ������.
	cout << pA-> get_x () << "\t" << pA-> get_y () << endl;

	Point B; // Default constructor.
	cout << B.get_x() << "\t" << B.get_y() << endl;
}