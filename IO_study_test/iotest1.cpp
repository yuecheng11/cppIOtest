#include <iostream>
#include <string>
#include <limits>

using namespace std;

void printCin()
{
	cout<<"bad = "<<cin.bad()<<endl;
	cout<<"fail = "<<cin.fail()<<endl;
	cout<<"eof = "<<cin.eof()<<endl;
	cout<<"good = "<<cin.good()<<endl;
}

int main()
{
	printCin();

	int ival;

	while(cin>>ival,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"IO stream corrupted!"<<endl;
			return -1;
		}
		else if(cin.fail())
		{
			cout<<"data illegal,please try again!"<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		cout<<"ival = "<<ival<<endl;
	}
	
	return 0;
}
