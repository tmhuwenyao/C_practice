//有两个矩阵a 和 b ，均为2行3列，求两个矩阵之和。 重载运算符“+” ，使之能用于矩阵相加，如 c =a +b；
#include <iostream>
#include <iomanip>
using namespace std;
//定义一个矩阵
class Matrix
{
	public:
	Matrix(double *n)
	{
		m = n;
	}
	//输出显示矩阵
	void display()
	{
		for(int i =0;i <6;i += 3)
		{
			cout << "|" << left << setw(10) << m[i] << " ";
			cout << left << setw(10) << *(m+i+1) << " ";
			cout << left << *(m+i+2) << "|" << endl;
		}
	}
	Matrix operator+(Matrix &m2);
	
	private:
		double *m;
};
//运算重载符
//return 不能反回一个数组，只能返回一个字符串或者数字
#if 0
Matrix Matrix::operator+(Matrix &m2)
{
	double c[6] = {0,0,0,0,0,0};
	Matrix m3(c);
	for(int i =0;i <6;i++)
	{
		m3.m[i] = m[i] + m2.m[i];
		
	}
	return m3;
}
#endif

Matrix Matrix::operator+(Matrix &m2)
{
	double c[6] = {0,0,0,0,0,0};
	Matrix m3(c);
	for(int i =0;i <6;i++)
	{
		m3.m[i] = m[i] + m2.m[i];
	}
	m3.display();
}

//测试程序
void test01()
{
	double a[6] = {0,1,2,3,4,5};
	double b[6] = {1,2,3,4,5,6};
	double c[6] = {0,0,0,0,0,0};
	Matrix m1(a),m2(b),m3(c);
	m3 = m1 + m2;
	cout << "---------------" << endl;
	m1.display();
	cout << "+" <<endl;
	cout << "---------------" << endl;
	m2.display();
	cout << "=" << endl;
	cout << "---------------" << endl;
	m3.display();
	
	
}

int main()
{
	test01();
	return 0;
}