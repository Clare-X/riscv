#include <bits/stdc++.h>
#include "users.h"
#include "order.h"
using namespace std;


int main()
{
	fstream Command;
	char x[220];
	Command.open("command.txt",ios::in);
	if (!Command) return 0;
	users U("UMain.txt","URoad.txt");
	while (!Command.eof())
	{try{
			//cout<<"xstat\n";
			Command.getline(x,200);
			if (strcmp(x,"exit")==0) return 0;
			Processline(x,strlen(x),U);
			//cout<<"xend\n";
		}
	catch(...){
			cout<<"Invalid"<<endl;
		}
	}

	return 0;
}