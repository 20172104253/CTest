// CTest.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
using namespace std;
class CTest {
private:
	int *p;
	int x;
	static int flag;
public:
	CTest()
	{
		p = new int;
		x = 0;
		flag = 1;
	}
	CTest(CTest &t)
	{
		p = new int;
		*p = *t.p;
		x = t.x;
	}
	void setx(int a, int b)
	{
		*p = a;
		x = b;
	}
	void display()
	{
		cout << "*p=" << *p << endl;
		cout << "x=" << x << endl;
	}
	~CTest()
	{
		if (flag != 0)
		{
			delete p;
			flag = 0;
		}
	}
};
int CTest::flag = 0;
int main()
{
	CTest ot1;
	ot1.display();
	ot1.setx(100, 1000);
	ot1.display();
	CTest ot2(ot1);
	ot1.setx(200, 2000);
	ot1.display();
	ot2.display();
	return 0;
}

