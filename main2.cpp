#include"iostream"
#include"stdlib.h"
#include"string"
using namespace std;
class booking
{
public:
	void f1()
	{
	string name="gabbar";
	int total,rate=100,t,num;
	cout<<"enter number of tickets :"<<endl;
	cin>>num;
	total=num*rate;
	/*cout<<"select time:"<<endl;
	cout<<"1> 9"<<endl;
	cout<<"2> 4"<<endl

	switch()*/
	cout<<"Movie : "<<name<<endl;
	cout<<"number of tickets : "<<num<<endl;
	cout<<"total amounts : "<<total;
	}
	void f2()
	{
	string name="baghi";
	int total,rate=150,t,num;
	cout<<"enter number of tickets :"<<endl;
	cin>>num;
	total=num*rate;
	/*cout<<"select time:"<<endl;
	cout<<"1> 9"<<endl;
	cout<<"2> 4"<<endl

	switch()*/
	cout<<"Movie : "<<name<<endl;
	cout<<"number of tickets : "<<num<<endl;
	cout<<"total amounts : "<<total;
	}
	void f3()
	{
	string name="bahubali";
	int total,rate=200,t,num;
	cout<<"enter number of tickets :"<<endl;
	cin>>num;
	total=num*rate;
	/*cout<<"select time:"<<endl;
	cout<<"1> 9"<<endl;
	cout<<"2> 4"<<endl

	switch()*/
	cout<<"Movie : "<<name<<endl;
	cout<<"number of tickets : "<<num<<endl;
	cout<<"total amounts : "<<total;

	}
};

class Time
{
    public:
  int select;
  char str;
  void f4()
  {
  cout<<"\n***********************************************************************************"<<endl;
  cout<<"1.    8:20AM "<<endl;
  cout<<"2.    10:20AM "<<endl;
  cout<<"3.    12:20PM "<<endl;
  cout<<"4.    2:20PM "<<endl;
  cout<<"5.    4:20PM "<<endl;
  cout<<"6.    6:20PM "<<endl;
  cout<<"7.    8:20PM "<<endl;
  cout<<"8.    10:20PM "<<endl;
  cout<<"9.    12:20PM" <<endl;
  s:cout<<"enter the time slot you want to select"<<endl;
  cin>> select;
switch(select)
{
  case 1:   cout<< "8:20AM "<<endl;
		break;
  case 2 :  cout<< "10:20AM "<<endl;
	break;
  case 3  :  cout<<"12:20PM "<<endl;
	break;
  case 4:    cout<<"2:20PM "<<endl;
	break;
  case 5 :   cout<<"4:20PM "<<endl;
	break;

  case 6:     cout<<"6:20PM "<<endl;
	break;
  case 7:    cout<<"8:20PM "<<endl;
	break;
  case 8:   cout<<"10:20PM "<<endl;
	break;
  case 9:    cout<<"12:20PM" <<endl;
	break;
  default:cout<<"you have entered wrong value:"<<endl;
break;
}




cout<<"you have selected "<<select<<"time slot"<<endl;
  cout<<"are you sure?(y/n)";
  cin>>str;
  if (str=='n')
  {
goto s;
  }
  }
};
class place
{
int  cho;
char sure;
public:
void f5()
{
cout<<"\n******************************"<<endl;
cout<<"1.   Cinepolis   "    <<endl;
cout<<"2.   Carnival cinemas"<<endl;
cout<<"3.   wide angle      "<<endl;
cout<<"4.   PVR Acropolis   "<<endl;
cout<<"5.   Rajhans cinema  "<<endl;
p:cout<<"6.enter your choice:"<<endl;
cin>>cho;
switch(cho)
{
case 1:cout<<"   Cinepolis   "    <<endl;
break;
case 2:cout<<"   Carnival cinemas"<<endl;

break;
case 3:cout<<"   wide angle      "<<endl;
break;
case 4:cout<<"   PVR Acropolis   "<<endl;
break;
case 5:cout<<"   Rajhans cinema  "<<endl;
break;
default:cout<<"you have entered wrong value:"<<endl;
break;
}
cout<<"you have entered"<<cho<<endl;
cout<<"Are u sure with these cinema :?(y/n)";
cin>>sure;
if(sure=='n')
{
goto p;
}
}

};



int main()
{
system("clear");
	booking obj;
	Time t;
	place p;	
	int n;
	cout<<"********SELECT MOVIE********"<<endl;
	cout<<"# MOVIE		Rate"<<endl;
	cout<<"1. gabbar 	100"<<endl;
	cout<<"2. baghiw	150"<<endl;
	cout<<"3. bahubali	200"<<endl;
	cout<<"enter your choice:"<<endl;
	cin>>n;
		switch(n)
		{
			case 1: obj.f1();system("clear");
		    	t.f4();	system("clear");
			p.f5();
			break;
			case 2: obj.f2();system("clear");
			t.f4();system("clear");
			p.f5();
			break;
			case 3: obj.f3();system("clear");
			t.f4();system("clear");
			p.f5();
			break;
			default:"\n you have entered wrong data:";
			break;
		}
return 0;
}
	
