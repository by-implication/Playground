#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

map<string, string> data;
vector<string> keys;
int counter = 0;

void init()
{
	ifstream reader;
	reader.open("data");
	if(reader.is_open())
	{
		while( !reader.eof() )
		{
			string key;
			string value;
			if(	reader >> key )
				keys.push_back(key);
			if( reader >> value )
				data[key] = value;
		}
		
		counter = keys.size(); 
		reader.close();
	}
	else
	{
		ofstream maker;
		maker.open("data");
		maker.close();
	}
}

void save()
{
	fstream writer;
	writer.open("data", ios::app | ios::out);
	for( int i = counter; i <  keys.size(); i++)
	{
		writer << keys[i] << " " << data[keys[i]] << endl;
	}
	writer.close();
}

int main()
{
	init();
	
	save();
	return 0;
}