#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class msg{
public:
	int Msg_id;
	int Msg_Priority;
	char* Msg_Sourceaddress;
	char* Msg_Destaddress;
	char* Msg_Payload;
	char* Msg_Trace;
		

	msg()
	{
		Msg_id = 0;
		Msg_Priority = 0;
		Msg_Sourceaddress = new char[3];
		Msg_Destaddress = new char[3];
		Msg_Payload = new char[50];
		Msg_Trace = new char[50];


	}
	
	void Display_Message()
	{
		cout << endl << "The values regarding message are:" << endl;
		cout << "ID: " << Msg_id << endl;
		cout << "Priority: " << Msg_Priority << endl;
		cout << "Source Address: " << Msg_Sourceaddress << endl;
		cout << "Destination_address: " << Msg_Destaddress << endl;
		cout << "Pay Load: " << Msg_Payload << endl;
		cout << "Trace: " << Msg_Trace << endl;


	}


	void InsertMsg_commandline()
	{
		int num = 5;
		for (int i = 0; i < num; i++)
		{

			cout << "Enter the values regarding message:" << endl;
			cout << "ID: ";
			cin >> Msg_id;
			cout << "Priority: ";
			cin >> Msg_Priority;
			cout << "Source Address: ";
			cin >> Msg_Sourceaddress;
			cout << "Destination_address: ";
			cin >> Msg_Destaddress;
			cout << "Pay Load: ";
			cin >> Msg_Payload;
			cout << "Trace: ";
			cin >> Msg_Trace;

			Display_Message();

		}

	}


	/*void InsertMsg_fileHandling()
	{
		string fname = "D:/Semester 3/Data Structures/Project/b.csv";//file name
		vector<vector<string>> content;
		vector<string> row;
		string line, word;

		fstream file(fname, ios::in);// File handling
		if (file.is_open())
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				content.push_back(row);
			}
		}
		else
			cout << "Could not open the file\n";
		int n = 0;
		for (int i = 0; i < content.size(); i++)
		{
			n=n+1;
			Msg_id = Msg_id + 1;
			Msg_Priority = atoi(content[i][0].data());
			char c[3];
			strcpy_s(c, content[i][1].c_str());
			Msg_Sourceaddress = c;
			char d[3];
			strcpy_s(d, content[i][2].c_str());
			Msg_Destaddress = d;
			char a[50];
			strcpy_s(a, content[i][3].c_str());
			Msg_Payload = a;
			char b[50];
			strcpy_s(b, content[i][4].c_str());
			Msg_Trace = b;

			
		}
	

	}*/

};
