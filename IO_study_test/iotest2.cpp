#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;


int test()
{
	ifstream ifs("iotest1.cpp");
	if(!ifs.good())
	{
		cout<<"file open failed!"<<endl;
		return -1;
	}

	string s;

	while(ifs>>s)
	{
		sleep(2);
		cout<<"read s : "<<s<<endl;
	}

	/*while(getline(ifs,s))
	{
		sleep(2);
		cout<<s<<endl;
	}*/

	

	return 1;
}

int main()
{
	test();

	/*ifstream ifs("iotest1.cpp");
	if(!ifs.good())
	{
		cout<<"file open failed!"<<endl;
		return -1;
	}

	ofstream ofs("IOtestcopy.txt");
	if(!ofs.good())
	{
		cout<<"open ofs failed!"<<endl;
		return -1;
	}

	string line;

	while(getline(ifs,line))
	{
		ofs<<line<<endl;
	}*/

	return 0;
}
