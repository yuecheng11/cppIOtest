#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>


using namespace std;

typedef struct
{
	string word;
	int num;
}Elem;

class WordStatic
{
public:
	void read_file(string filename);
	void write_file(string filename);
	void print_vec_value();
private:
	bool isnum(string s);
	bool is_str_in_vec(string s);
	vector<Elem> vecword;

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

	Elem countElem;
	countElem.num = 1;
	
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
		countElem.word = sTmp;
		
		vecword.push_back(countElem);
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
		{
			return true;
		}
	return false;
}

bool WordStatic::is_str_in_vec(string s)
{
	vector<Elem>::iterator it;
	for(it = vecword.begin();it!=vecword.end();++it)
	{
		if(it->word == s)
		{
			it->num++;
			return true;
		}
	}

	return false;
}

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

	
	string s;

	for(vector<Elem>::iterator it = vecword.begin();it != vecword.end();++it)
	{
		
		ofs<<it->word<<"  :  "<<it->num << "times"<<endl;
	}

	
}
int main()
{
	

	WordStatic ws;
	ws.read_file("The_Holy_Bible.txt");

	cout<<"test print value "<<endl;
	
	string write_filename("count.txt");
	ws.write_file(write_filename);
	
	return 0;
}
