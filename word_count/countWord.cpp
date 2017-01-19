#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>


using namespace std;


class WordStatic
{
public:
	void read_file(string filename);
	void write_file(string filename);
	void print_vec_value();
private:
	bool isnum(string s);
	bool is_str_in_vec(string s);
	vector<std::string> vecword;

};

void WordStatic::read_file(string filename)
{
	const char* file_name = filename.c_str();
	cout<<"read file name: "<<file_name;
	
	ifstream ifs("The_Holy_Bible.txt");
	if(!ifs.good())
	{
		cout<<"file open failed!"<<endl;
		return ;
	}

	string sTmp;
	while(ifs>>sTmp)
	{
		if(isnum(sTmp) == true)
		{
			continue;
		}
		if(is_str_in_vec(sTmp) == true)
		{
			continue;
		}
		vecword.push_back(sTmp);
	}
}

bool WordStatic::isnum(string s)
{

	stringstream sin(s);
	int t;
	//char p;
	if(!(sin>>t))
	{
		return false;
	}
	else
		return true;
	
	return false;
}

bool WordStatic::is_str_in_vec(string s)
{
	vector<std::string>::iterator it;
	it = std::find(vecword.begin(),vecword.end(),s);
	if(it == vecword.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*void WordStatic::print_vec_value()
{
	int i = 0;
	for(vector<string>::iterator it = vecword.begin();it != vecword.end();++it)
	{
		cout<<*it;
		
		if(i == 10)
		{
			cout<<endl;
		}
		i++;
	}
}*/

void WordStatic::write_file(string filename)
{
	const char* str = filename.c_str();
	ofstream ofs(str);
	if(!ofs.good())
	{
		cout<<"open ofs failed!"<<endl;
		return ;
	}
	
	int i = 0;
	

	ifstream ifs("The_Holy_Bible.txt");
	if(!ifs.good())
	{
		cout<<"file open failed!"<<endl;
		return ;
	}
	
	string s;

	for(vector<std::string>::iterator it = vecword.begin();it != vecword.end();++it)
	{
		
		while(ifs>>s)
		{

			if(*it== s)
			{
				cout<<"========";
				i++;
			}
		}

		cout<<*it<<"  :  "<<i<<endl;
		i = 0;
	}

	
}
int main()
{
	

	WordStatic ws;
	ws.read_file("The_Holy_Bible.txt");

	cout<<"test print value "<<endl;
	//ws.print_vec_value();

	string write_filename("count.txt");
	ws.write_file(write_filename);
	
	return 0;
}
