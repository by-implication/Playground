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

void set(string key, string value)
{
	data[key] = value;
	keys.push_back(key);
	cout << "<" << key << "," << value <<">" " was added.\n";
}

string get(string key)
{
	if( data.count(key) > 0 )
	{
		return data[key];
	}
	else
		return "Key not found.";
}

void del(string key)
{
	if( data.count(key) > 0 )
	{
		data.erase(key);
		cout << "<" << key << "," << data[key] <<">" " was deleted.\n";
	}
	else
		cout << "Key does not exist.\n";
}

int main()
{
	init();
	
	save();
	return 0;
}