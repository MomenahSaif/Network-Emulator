#pragma once
#include"Router_Header.h"
//#include<iostream>
//#include<vector>
//#include<string>
#include<cstring>
//#include<fstream>
//#include"header.h"
#include <limits.h>
#include <stdio.h>
//#include"Header1.h"


// Number of vertices in the graph
#define V 9
using namespace std;

class Machine {
public:
	string data;
	char* name;
	int weight;
	Machine* next = NULL;
};
class adjList
{
public:
	Machine* head = NULL;

};

class graph
{
	adjList* ptr;
	string vertice[21];
	bool* isvisited;
public:


	graph(string vertice[])
	{

		ptr = new adjList[21];
		for (int i = 0; i < 21; i++)
		{
			this->vertice[i] = vertice[i];
			ptr[i].head = new Machine;
			ptr[i].head->data = vertice[i];
		}


	}


	void insertEdge(string source[], string destination[], string graphing[][21])
	{
		for (int i = 0; i < 21; i++)
		{
			if (ptr[i].head->data == source[i])
			{

				Machine* t = ptr[i].head;
				Machine* temp = new Machine();
				temp->data = destination[i];
				if (ptr[i].head == NULL)
				{
					if (ptr[i].head->data != "?")
					{
						for (int j = 0; j < 21; j++)
						{
							ptr[j].head->weight = stoi(destination[j]);
							ptr[j].head->data = graphing[0][j];
						}




					}
				}
				else
				{
					while (t->next)
					{
						t = t->next;
					}
					t->next = temp;
				}
			}

			if (ptr[i].head->data == destination[i])
			{
				Machine* t1 = ptr[i].head;
				Machine* temp = new Machine();
				temp->data = source[i];
				if (ptr[i].head == NULL)
				{
					if (ptr[i].head->data != "?")
					{
						for (int j = 0; j < 21; j++)
						{
							ptr[j].head->weight = stoi(source[j]);
							ptr[j].head->data = graphing[0][j];
						}

					}
				}
				else
				{
					while (t1->next)
					{
						t1 = t1->next;
					}
					t1->next = temp;
				}
			}
		}

	}
	void showgraphStructure()
	{
		Machine* node = new Machine;

		for (int i = 0; i < 21; i++)
		{
			//cout << i << " -> ";
			if (ptr[i].head)
			{
				node = ptr[i].head;
				while (node)
				{
					cout << node->data << " | " << node->weight << "  ";
					node = node->next;
				}
			}
			cout << endl;
		}
	}
};
int main()
{

	//string source[21];
	//string destination[21];
	string vertice[21] = { "M1","M2","M3","M4","M5","M6","M7","M8","M9","M10","M11","M12","M13","M14","M15","R1","R2","R3","R4","R5" };
	string graphing[21][21];
	string source[21] = { "M1","M2","M3","M4","M5","M6","M7","M8","M9","M10","M11","M12","M13","M14","M15","R1","R2","R3","R4","R5" };
	string destination[21] = { "M1","M2","M3","M4","M5","M6","M7","M8","M9","M10","M11","M12","M13","M14","M15","R1","R2","R3","R4","R5" };

	graph G(vertice);
	ifstream mi;
	int weight[100];
	mi.open("NETWORK.csv", ios::out | ios::app);

	if (mi.fail())
	{
		cout << "Enable to open \n";
	}
	vector<string> row;
	string line, word, temp;

	while (mi.good())
	{

		int i = 1;
		int j = 1;
		getline(mi, graphing[i][j], ',');
		cout << graphing[i][j];

		G.insertEdge(source, destination, graphing);



		//stringstream s(line);
		//while (getline(s, graphing[i][j]))
		/** {
			row.push_back(graphing[i][j]);
			cout << word << " ";
		}*/

		i++;
	}
	G.showgraphStructure();

	mi.close();

	cout << "\n=================== GRAPH STRUCTURE ======================\n";
	G.showgraphStructure();









}