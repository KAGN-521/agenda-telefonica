#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

#define FILE_NAME "FILE.txt" 
#define TEMP_NAME "TEMP.txt" 

using namespace std;

namespace Model {
	class Contact
	{
	public:
		Contact(string, int);
		string toString();
		
		void save();
		void update();
		void del();
		static Contact* create(string, int);

		static Contact* find(string);

		int id;
		string name;
		int phone;

	private:
		int getCount();
	};
}


