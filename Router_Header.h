#pragma once
#include"Incoming_queue_Header.h"
#include"Outgoing_Queue_Header.h"
#include"Routing _TableHeader.h"
class Router {
public:
	IncomingQueue In;
	RoutingTable rt;
	//Outgoing_Queue Out;
	Outgoing_Queue o1, o2, o3;
	msg send;
	
	Router()
	{
		

	}
	
	
	void Compare()
	{
		send = In.insert();
		cout << "Incoming  " << send.Msg_Priority << endl;
		
		/*if (send.Msg_Destaddress == "M1")
			o0.Enqueue(send);
			

		else if (send.Msg_Destaddress == "M2")
			o1.Enqueue(send);
			
		
		else if (send.Msg_Destaddress == "M3")
            o2.Enqueue(send);
			
		else if (send.Msg_Destaddress == "M4")
		     o1.Enqueue(send);
		else
		   o0.Enqueue(send);*/
		
		rt.RoutingTable_insert_filehandling();
		rt.showarray();
		int num=0;
		for (int i = 0; i < In.curr_size; i++)
		{
			if (rt.array[i][0] == send.Msg_Destaddress)
				num = i;
		}
		send.Display_Message();

		if (rt.array[num][1].compare("R1") == 0)
			o1.Enqueue(send);
		else if (rt.array[num][1].compare("R2") == 0)
			o2.Enqueue(send);
		else if (rt.array[num][1].compare("R3") == 0)
			o3.Enqueue(send);
		else
			cout << "The outgoing queue is not available , the message has been lost";


		
		cout<<endl << "The first outgoing queue is" << endl;
			o1.display();
		cout << "The second outgoing queue is" << endl;
		   o2.display();
	    cout << "The third outgoing queue is" << endl;
		   o3.display();

	}
	
	/*/void show_path(msg N)
	{
		int num = N.Msg_Trace.size();
		for(int i=0;i<num;i=i+2)
	}*/


};
