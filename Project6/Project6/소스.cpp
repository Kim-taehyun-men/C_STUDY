#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Student {
	string name;
	double marks;
public:
	Student(string na, double ma) { name = na; marks = ma; }
	void print() {
		cout << " �̸�: " << name << "����: " << marks << endl;

	}
	void setter_name(string na) { name = na; }
	void setter_marks(double ma) { marks = ma; }
	string getter_name() { return name;}
	double getter_marks() { return marks;}
};

int main()
{
	vector<Student> people;
	string name;
	double marks;
	for (int i = 0 ;i < 3; i++)
	{
		cout << "�̸� �� ����";
		cin >> name >> marks;
		people.push_back(Student(name, marks));
	}
	
	return 0;
}