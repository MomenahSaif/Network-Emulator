#pragma once
#include"Message_Header.h"
#include"Outgoing_Queue_Header.h"
using namespace std;
class IncomingQueue {
public:
	int curr_size;
	msg* M;



	IncomingQueue()
	{
		curr_size = 1;
		M = new msg[10];

	}
		//cout << "IN Constructor called*****************************" << endl;
		/*M[1].Msg_id = 1;
		M[2].Msg_id = 2;
		M[3].Msg_id = 3;
		M[4].Msg_id = 4;
		M[5].Msg_id = 5;


		M[1].Msg_Priority = 4;
		M[2].Msg_Priority = 2;
		M[3].Msg_Priority = 1;
		M[4].Msg_Priority = 3;
		M[5].Msg_Priority = 5;

		curr_size = 6;*/
	

	IncomingQueue(IncomingQueue &I1)
	{
		curr_size = 1;
		M->Msg_id = I1.M->Msg_id;
		M->Msg_Priority = I1.M->Msg_Priority;
		M->Msg_Sourceaddress = I1.M->Msg_Sourceaddress;
		M->Msg_Destaddress = I1.M->Msg_Destaddress;
		M->Msg_Payload = I1.M->Msg_Payload;
		M->Msg_Trace = I1.M->Msg_Trace;


	}
	void insert_values(msg *a)
	{
		
		M[curr_size].Msg_id = a->Msg_id;
		M[curr_size].Msg_Priority = a->Msg_Priority;
		//M[curr_size].Msg_Sourceaddress = a->Msg_Sourceaddress;
		strcpy(M[curr_size].Msg_Sourceaddress, a->Msg_Sourceaddress);
		//M[curr_size].Msg_Destaddress = a->Msg_Destaddress;
		strcpy(M[curr_size].Msg_Destaddress , a->Msg_Destaddress);
		strcpy(M[curr_size].Msg_Payload ,a->Msg_Payload);
		//M[curr_size].Msg_Payload= a->Msg_Payload;
		strcpy(M[curr_size].Msg_Trace , a->Msg_Trace);
		M[curr_size].Msg_Trace= a->Msg_Trace;
		curr_size++;


	}



	msg insert()
	{
        for (int i = 1; i < curr_size; i++)
			make_valid(M, curr_size);

		cout << "============== Valid =================\n";
		print_array();

		msg m1;
		m1 = delete_heap();
		return m1;


	}


	void print_array()
	{
		for (int i = 1; i < curr_size; i++)
		{
			cout << endl << "The values regarding message are:" << endl;
			cout << "ID: " << M[i].Msg_id << endl;
			cout << "Priority: " << M[i].Msg_Priority << endl;
			cout << "Source Address: " << M[i].Msg_Sourceaddress << endl;
			cout << "Destination_address: " << M[i].Msg_Destaddress << endl;
			cout << "Pay Load: " << M[i].Msg_Payload << endl;
			cout << "Trace: " << M[i].Msg_Trace << endl;
		}




	}


	void swap(int x, int y)           // swap two values of an array
	{
		msg temp;
		//cout << "X=" << M[x].Msg_Priority << "\tY=" << M[y].Msg_Priority << endl;
		temp = M[x];
		M[x] = M[y];
		M[y] = temp;


	}


	void make_valid(msg a[], int num)
	{
		for (int i = 1; i < num; ++i)
		{
			if ((i / 2) > 0)                                  //checking parent is present
			{
				if (a[i].Msg_Priority > a[i / 2].Msg_Priority)                             // checking is child is smaller than parent
				{
					swap(i, (i / 2));
					if (a[i / 2].Msg_Priority < a[(i / 2) / 2].Msg_Priority)                //  after swap if the child is still smaller than parent
						make_valid(a, num);


				}
			}

			else if (a[2 * i].Msg_Priority)                       //checking left child is present
			{
				if ((a[2 * i].Msg_Priority > a[i].Msg_Priority))                 // checking is left child is greater than parent
				{
					swap(i, 2 * i);
					if ((a[(2 * i) * 2].Msg_Priority > a[i * 2].Msg_Priority))        // after swap if the left child is still greater than parent
						make_valid(a, num);


				}
			}

			else if (a[2 * i + 1].Msg_Priority)                   //checking right child is present
			{

				if (a[2 * i + 1].Msg_Priority > a[i].Msg_Priority)                     // checking is right child is greater than parent
				{
					swap(i, 2 * i + 1);
					if (a[(2 * i + 1) * 2 + 1].Msg_Priority < a[2 * i + 1].Msg_Priority)      // after swap if the right child is still greater than parent
						make_valid(a, num);


				}

			}


		}



	}

	msg delete_heap()
	{
		cout<<endl<<endl << "Deleting: " << M[1].Msg_Priority << endl << endl;
		msg N = M[1];
		//cout << "N" << N.Msg_Priority << endl;
		int var = M[curr_size - 1].Msg_Priority;
		M[1] = M[curr_size - 1];               //swapping
		M[curr_size - 1].Msg_id = 0;
		M[curr_size - 1].Msg_Priority = 0;
		M[curr_size - 1].Msg_Sourceaddress= NULL;
		M[curr_size - 1].Msg_Destaddress = NULL;
		M[curr_size - 1].Msg_Payload = NULL;
		M[curr_size - 1].Msg_Trace = NULL;
		curr_size--;
		for (int i = 1; i < curr_size; i++)
		{
			make_valid(M, curr_size);
			/*if ((M[i].Msg_Priority == var) && ((2 * i + 1) < (curr_size)) || ((2 * i) < (curr_size)))
			{
				if ((M[2 * i].Msg_Priority > M[2 * i + 1].Msg_Priority) || (!M[2 * i + 1].Msg_Priority))          //checking if left child is smaller
					swap(i, (2 * i));                                   //or right child is not present
				else if ((M[2 * i].Msg_Priority < M[2 * i + 1].Msg_Priority) || (!M[2 * i].Msg_Priority))
					swap(i, (2 * i + 1));
			}*/
		}
		cout << "============== Delete =================\n";
		print_array();
		return N;
		
	}

	
	
	


};