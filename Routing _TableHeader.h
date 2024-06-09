#pragma once
class RoutingTable {
public:
	string** array;
	int row;
	int col;
	int sizeof_string;


	RoutingTable()
	{
		/*row = 3, col = 2, sizeof_string = 3;
		//array = new char** [row];

		for (int i = 0; i < row; i++) {
			array[i] = new char* [col];

			for (int j = 0; j < col; j++) {
				array[i][j] = new char[sizeof_string];
			}
		}*/
		row = 10;
	    col = 2;
		array = new string* [row];
		for (int i = 0; i < row; ++i)
			array[i] = new string[col];
	}

	void RoutingTable_insert_commandline()
	{
		cout << "Enter the number of values you want or have enter in file in routing table" << endl;
		cin >> row;
		cout << "Enter the values of routing table" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{

				cin >> array[i][j];
			}
		}


	}

	void RoutingTable_insert_filehandling()
	{
		//fstream fout;
		//fout.open("RoutingTable.csv", ios::out | ios::app);
		string fname= "RoutingTable.csv";

		vector<vector<string>> content;
		vector<string> row;
		string line, word;

		fstream file(fname, ios::in);
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
			for (int j = 0; j < content[i].size(); j++)
			{
				//cout << content[i][j] << " ";
				array[i][j] = content[i][j].c_str();
				
			}
			cout << "\n";
		}

	
	}


	void showarray()
	{
		cout << "The routing table values are" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				cout << array[i][j] << "  ";
			cout << endl;
		}
		cout << endl;
	}



};



