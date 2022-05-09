#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	string name = "";

	int count = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] != name2[i])
			count++;
	}

	cout << count;
	return 0;
}