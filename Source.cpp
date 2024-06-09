#include"Router_Header.h"
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//#include"Header2.h"
using namespace std;

int main()
{
	msg* m;
	string M1, M2, M3, M4, M5, M6, M7, M8, M9, M10;
	string R1, R2, R3, R4, R5;
	Router r, r2, r3, r4, r5;
	string fname = "b.csv";//file name
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

	for (int i = 0; i < content.size(); i++)
	{
		m = new msg;
		m->Msg_id = m->Msg_id + 1;
		m->Msg_Priority = atoi(content[i][0].data());
		char c[3];
		strcpy_s(c, content[i][1].c_str());
		m->Msg_Sourceaddress = c;
		for (int i = 0; i < 50; i++)
			m->Msg_Trace[i] = {};
		char d[3];
		strcpy_s(d, content[i][2].c_str());
		m->Msg_Destaddress = d;
		char a[50];
		strcpy_s(a, content[i][3].c_str());
		m->Msg_Payload = a;

		//m->Display_Message();
		r.In.insert_values(m);
		//r.In.print_array();
	//insert to q overhere
	}


	r.Compare();
	/*if (!r.o1.IsEmpty())
		r2.In.insert_values(r.o1.Dequeue());
	if (!r.o2.IsEmpty())
		r3.In.insert_values(r.o2.Dequeue());

	r2.Compare();
	r3.Compare();

	if (!r2.o1.IsEmpty())
		r4.In.insert_values(r2.o1.Dequeue());
	if (!r2.o2.IsEmpty())
		r5.In.insert_values(r2.o2.Dequeue());*/


		// SHORTEST PATH 



	graph<string> g;
	g.addEdge("R1", "M2", 3);
	g.addEdge("R1", "M5", 2);
	g.addEdge("R1", "M4", 1);
	g.addEdge("R2", "M2", 3);
	g.addEdge("R3", "M2", 6);
	g.addEdge("M1", "M2", 3);
	g.addEdge("M10", "M3", 4);
	//g.addEdge(M9, M4, 1);
	//g.addEdge(M3, M2, 9);
	//g.addEdge(M2, M2, 2);
	g.printAdja();
	g.dijsktra("R1");

}
