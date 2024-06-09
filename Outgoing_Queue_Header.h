#pragma once
#pragma warning(disable : 4996)
class Node {
public:
	Node* next;
	msg m;

	Node()
	{
		next = NULL;
	}
};

class Outgoing_Queue {
public:
	Node* front;
	Node* rear;
	int numItems;
	int time;
	Outgoing_Queue()
	{
		front = NULL;
		rear = NULL;
		time = 60;
	}


	void Enqueue(msg& data)
	{
		Node* temp = new Node();
		temp->m.Msg_Priority = data.Msg_Priority;
		temp->m.Msg_id = data.Msg_id;
		temp->m.Msg_Payload = data.Msg_Payload;
		temp->m.Msg_Sourceaddress = data.Msg_Sourceaddress;
		temp->m.Msg_Destaddress = data.Msg_Destaddress;
		strcat(data.Msg_Trace, data.Msg_Sourceaddress);
		temp->m.Msg_Trace = data.Msg_Trace;

		time--; // time dec tab hoga jab mein data incoming ko bheijungi
		if (front == NULL)
		{
			front = temp;
			rear = temp;
		}

		else
		{
			rear->next = temp;
			rear = temp;
		}

	}

	msg Dequeue()
	{
		Node* temp = new Node();
		msg ret;
		if (IsEmpty())
			cout << "The queue is empty" << endl;

		else {
			ret = front->m;
			temp = front->next;
			delete front;
			front = temp;
			numItems--;
			if (!numItems)
				rear = NULL;
		}
		return ret;
	}

	bool IsEmpty()
	{
		if (numItems)
			return true;
		else
			return false;

	}

	void display()
	{
		Node* temp = new Node;
		temp = front;
		while (temp != NULL)
		{
			cout << "The message id is = " << temp->m.Msg_id << endl;
			cout << "The priority is = " << temp->m.Msg_Priority << endl;
			cout << "The source address is = " << temp->m.Msg_Sourceaddress << endl;
			cout << "The destination address is = " << temp->m.Msg_Destaddress << endl;
			cout << "The message's payload is = " << temp->m.Msg_Payload << endl;
			cout << "The message's trace is = " << temp->m.Msg_Trace << endl;

			cout << endl << endl;
			temp = temp->next;
		}


	}

	void Timer_Interrupt()
	{
		// specific element
		//insert(incoming);
		//dequeue();

		//while (perform routing untill target reached)
			//int input;
			//cout << "What do you want to perform?" << endl;
			// call function giving user choices
	}

	
};