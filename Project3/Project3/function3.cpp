#include<iostream>
using namespace std;
int sum(int a = 0, int b = 0, int c = 0, int d = 0)
{
	return a + b + c + d;
}

int main()
{
	cout << "sum(10, 15)= " << sum(10, 15) << endl;
	cout << "sum(10, 15)= " << sum(10, 15, 25) << endl;
	cout << "sum(10, 15)= " << sum(10, 15, 25, 30) << endl;
	return 0;
}

