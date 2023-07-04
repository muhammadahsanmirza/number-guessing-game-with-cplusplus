#include<fstream>
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

string gamename="\n\n\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t::::                     NUMBER                    ::::\n"
	"\t\t::::                     DUMBER                    ::::\n"
	"\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
string plname;
	int totmoney,playerbalance;
	int betamount;
	int plnumb;
	int dice;
	char opt;
    
void filling()
{
	ofstream f (" Player.txt",ios::app);
	f<<plname<<"\t";
	f<<playerbalance<<" \t\t";
	f<<betamount<<"\t\t "<<totmoney<<"\t\t  "<<plnumb<<"\t\t  "<<dice<<endl;
}
void intro()
{
	string intro="\n\n\n\n\n\n\n\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t\t\t::::                     NUMBER                    ::::\n"
	"\t\t\t\t::::                     DUMBER                    ::::\n"
	"\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"
	"\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	
	for(int i=0; i<intro.size();i++)
    {
    	Sleep(5);
    	cout<<intro[i];
    	
	}
}

void instructions()
{
	system("cls");
	SetConsoleTextAttribute(h,11);//red
	cout<<gamename;
	
	cout<<"\n";
	SetConsoleTextAttribute(h,1);//red
	cout<<"\n\n*****************************************************************\n";
	cout<<" \t RULES OF THE GAME\t\t\t\t \n";
	cout<<"*****************************************************************\n\n";
	SetConsoleTextAttribute(h,3);
	cout<<"  \t1. ENTER ANY NUMBER BETWEEN 1-10.\n\n";
	cout<<"  \t2. IF YOU WON YOU WILL GET DOUBLE OF YOUR BETING AMOUNT.\n\n";
	cout<<"  \t3. IF YOU LOSE YOU WILL LOST YOUR BETTING AMOUNT.\n\n";
	SetConsoleTextAttribute(h,1);
	cout<<"*****************************************************************\n";
	SetConsoleTextAttribute(h,14);//white
	cout<<"\n\n  PRESS ANY KEY TO START ";
	getche();
	
}
                                       //*******************
									   //    color
									   //*******************
int userdefinecolor()
{
		int color;
	
	system("cls");		
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,1);
	cout<<"1. NUMBER DUMBER";
	cout<<"\t\t";
		SetConsoleTextAttribute(h,2);
	cout<<"2. NUMBER DUMBER";
	cout<<"\n\n";
		SetConsoleTextAttribute(h,3);
	cout<<"3. NUMBER DUMBER";
	cout<<"\t\t";
		SetConsoleTextAttribute(h,4);
	cout<<"4. NUMBER DUMBER";
	cout<<"\n\n";
		SetConsoleTextAttribute(h,5);
	cout<<"5. NUMBER DUMBER";
	cout<<"\t\t";
		SetConsoleTextAttribute(h,6);
	cout<<"6. NUMBER DUMBER";
	cout<<"\n\n";
do
{
     SetConsoleTextAttribute(h,15);
	 cout<<"\n PRESS NUMBER BETWEEN 1-6 TO CHANGE THE COLOUR OF GAME : ";
     cin>>color;
   if(color<0 || color>6)
   {
   	SetConsoleTextAttribute(h,4);		
	cout<<"\n\n";
	cout<<"\t\tINVALID CHOICE !!";
   }

}while(color<0 || color>6);

SetConsoleTextAttribute(h,color);
return color;
}
                                        //************************
                                        // USER DEFINE COLOR GAME
                                        //************************
void play1()
{
	
	//variables 
	int udc=userdefinecolor();
	system("cls");
	// name 
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,udc);
	cin.ignore();
	cout<<" ENTER YOUR NAME : ";
	getline(cin , plname);
	cout<<endl;
	cout<<" ENTER YOUR BALANCE : ";
	cin>>totmoney;
	playerbalance=totmoney;
	do
	{
		system("cls");
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,udc);
	cout<<"\n\n CURRENT BALANCE IS "<<totmoney<<" PKR\n\n";
	do
	{
		cout<<plname<<" , PLEASE ENTER AMOUNT TO BET : ";
		cin>>betamount;
		if(betamount > totmoney)
		{
		
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n BETTING AMOUNT IS GREATER THAN YOUR BALANCE \n\n";
		SetConsoleTextAttribute(h,udc);
		}
	}
	while( betamount> totmoney);
	
	do
	{
		system("cls");
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,udc);
		cout<<" \n\nENTER GUESS NUMBER TO BET : ";
		cin>>plnumb;
		if (plnumb < 1 || plnumb>11)
		{
		
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n NUMBER SHOULD BE BETWEEN 1 TO 10 \n  RE-ENTER THE NUMBER ";
		SetConsoleTextAttribute(h,udc);
		}
	}
	while ( plnumb <1 || plnumb >11);
	dice = rand( ) % 10+1;
	if(dice != plnumb )
	{
		
		totmoney-= betamount;
		SetConsoleTextAttribute(h,3);
		cout<<"\n\n YOU LOST ";
		SetConsoleTextAttribute(h,udc);
		cout<<" \n YOUR REMAINING BALANCE IS : "<<totmoney<<" PKR ";
		
	}
	else
	{
	   totmoney+=betamount;
	   SetConsoleTextAttribute(h,11);
	   cout<<"\n\n CONGRATULATION!! YOU WON ";
	   SetConsoleTextAttribute(h,udc);
	   cout<<"\n\n YOUR BALNCE IS : "<<totmoney<< " PKR";	
	}
	SetConsoleTextAttribute(h,udc);
	cout<<"\n\n THE WINNING NUMBER : "<<dice<<endl;
	cout<<"\n"<<plname<<", YOU HAVE "<<totmoney<<" PKR \n";
	if(totmoney==0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n YOU HAVE NO MONEY\n ";
		break;
	}
	filling();
	SetConsoleTextAttribute(h,10);
	cout<<"\n\n\nDO YOU WANT TO PLAY AGAIN (y/n)"<<endl;
	opt=getche();
	}while(opt=='Y' || opt=='y');
	system("cls");
	SetConsoleTextAttribute(h,11);
	cout<<"\n\n\n\n\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\t\t\t::              THANKS                                            ::\n";
	cout<<"\t\t\t::                       FOR                                      ::\n";
	cout<<"\t\t\t::                             PLAYING                            ::\n";
	cout<<"\t\t\t::                                       GAME                     ::\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	SetConsoleTextAttribute(h,udc);
	cout<<"   \n\nYOUR CURRENT AMOUNT IS : "<<totmoney<<" PKR\n";
	getch();
	
}
                                           //******************
                                          // without color
                                         //********************
void play()
{
	//variables 
	
	system("cls");
	instructions();
	system("cls");
	
	

	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,14);
	cout<<" ENTER YOUR NAME : ";
	getline(cin , plname);
	cout<<endl;
	cout<<" ENTER YOUR BALANCE : ";
	cin>>totmoney;
	playerbalance=totmoney;
	do
	{
		system("cls");
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
    
	SetConsoleTextAttribute(h,14);
	cout<<"\n\n CURRENT BALANCE IS "<<totmoney<<" PKR\n\n";
	do
	{
		cout<<plname<<" , HOW MANY AMOUNT YOU WANT TO BE  : ";
		cin>>betamount;
		if(betamount > totmoney)
		{
		
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n BETTING AMOUNT IS GREATER THAN YOUR BALANCE \n\n";
		SetConsoleTextAttribute(h,15);
		}
	}
	while( betamount> totmoney);
	
	do
	{
		system("cls");
	cout<<"\n";SetConsoleTextAttribute(h,11);
	cout<<gamename;
    cout<<"\n";
	
	SetConsoleTextAttribute(h,14);
		cout<<" \n\nENTER GUESS NUMBER TO BET : ";
		cin>>plnumb;
		if (plnumb < 1 || plnumb>11)
		{
		
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n NUMBER SHOULD BE BETWEEN 1 TO 10 \n  RE-ENTER THE NUMBER ";
		SetConsoleTextAttribute(h,15);
		}
	}
	while ( plnumb <1 || plnumb >11);
	dice = rand( ) % 10+1;
	if(dice != plnumb )
	{
		
		totmoney-= betamount;
		SetConsoleTextAttribute(h,4);
		cout<<"\n\n YOU LOST ";
		cout<<" \n YOUR REMAINING BALANCE IS : "<<totmoney<<" PKR ";
		
	}
	else
	{
	   totmoney += betamount;
	   SetConsoleTextAttribute(h,11);
	   cout<<"\n\n CONGRATULATION!! YOU WON ";
	   SetConsoleTextAttribute(h,15);
	   cout<<"\n\n YOUR BALNCE IS : "<<totmoney<< " PKR";	
	}
	SetConsoleTextAttribute(h,14);
	cout<<"\n\n THE WINNING NUMBER : "<<dice<<endl;
	cout<<"\n"<<plname<<", YOU HAVE "<<totmoney<<" PKR \n";
	if(totmoney==0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"\n YOU HAVE NO MONEY\n ";
		break;
	}
	filling();
	SetConsoleTextAttribute(h,10);
	cout<<"\n\n\nDO YOU WANT TO PLAY AGAIN (y/n) .";
	opt=getche();
	}while(opt=='Y' || opt=='y');
	system("cls");
	SetConsoleTextAttribute(h,11);
	cout<<"\n\n\n\n\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\t\t\t::              THANKS                                            ::\n";
	cout<<"\t\t\t::                       FOR                                      ::\n";
	cout<<"\t\t\t::                             PLAYING                            ::\n";
	cout<<"\t\t\t::                                       GAME                     ::\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	SetConsoleTextAttribute(h,14);
	cout<<"   \n\n\t\tYOUR CURRENT AMOUNT IS : "<<totmoney<<" PKR\n";
	getch();
}

int main()
{
	SetConsoleTextAttribute(h,11);
	intro();
	do
	{
		system("cls");
	{
		cout<<"\n";
	cout<<gamename;
    cout<<"\n";
	}
	SetConsoleTextAttribute(h,14);//yellow
	cout<<"1. Start Game\n\n";
	cout<<"2. Change Game Color\n\n";
	cout<<"3. RULES \n\n";
	cout<<"4. QUIT\n\n";
	cout<<"\n** SELECT OPTION :- ";
	char op=getche();
	if(op=='1') play();
	else
	if(op=='2') play1();
	else
	if(op=='3')instructions();
	if(op=='4')exit(0);
	}
	while(1 || 2);
	return 0;
}
