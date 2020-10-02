//Mess management System
/*Author:Harsh Kumar(19162121009)
Geetangali Purohit(19162121008)
Meet Gajjar(19162121007)*/

#include<iostream>										//input-output streaming
#include<stdlib.h>										//for system("clear"),etc.
#include<fstream>										//for file streamin
#include<string>										//for string functions
#include<cstring>
char entry10[20];
using namespace std;

class mess{											//class for mess
protected:
string filename,name;										//filename to take input of enrollment no and use it 													//as filenames
long int id;
short int f1;
int date;
public:


void entry(){											//entry() function to create a new entry
int total=0;
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
cout<<"\n--New Entry--\n";
enroll:cout<<"Enter Enrollment no:";
cin>>filename;						
int len = filename.length();
try{	
if(len<11 || len>11){										//length of enrollment number should be exact 11
throw 0.0f;
}
}								
catch(float a){											//catches a floating type value
cout<<"\nInvalid Enrollment Entered please enter again\n";
goto enroll;											//go back to enroll
}
const char *c = filename.c_str();	
ofstream f;											//object of type ofstream for file input
f.open(c,ios::binary|ios::app);		
ofstream f10;			
f10.open("enteries.txt",ios::binary|ios::app);							//opens file "enteries.txt" to append 
f10<<filename<<"|"<<"\n";			
f10.close();											//file "enteries.txt" is closed
dateg:cout<<"\nEnter Today's date (format:DDMM):";
cin>>date;											//reading date
if(date>3112 || date<0000){								
cout<<"Wrong date entered, Please enter again.";
goto dateg;											//go back to date input
}
f<<"|-------------------------Order-----------------------|";
f<<"|Date(DDMM)-";

if(date<999){											//checks if date is in between 1 to 9 
f<<"0";	
}
f<<date<<"";											//gives file date as input
ft:cout<<"\nFood Type:\n1.Western\n2.Indian\n:";
cin>>f1;											//takes input for choice in f1
if(f1==1){		
cout<<"\n---Western cusine---";
int ind_type;
int wes_price;
ind_typo1:cout<<"\nChoose Theme:\n1.Pizza-100\n2.Noodles-80\n3.Burger-100\n4.Pasta-110\n5.French Fries-50\n6.Cold Drink-60\n:";
cin>>ind_type;											//takes input for food
if(ind_type==1){
cout<<"Added";
wes_price=100;	
f<<"|Pizza-"<<wes_price<<"\n";		
total=total+wes_price;										//price of pizza is added to the total
}
else if(ind_type==2){										//checks if input is 2 for noodles
cout<<"Added";
wes_price=80;											//noodles price
f<<"|Noodles-"<<wes_price<<"\n";								//item name and price is given into the file
total=total+wes_price;										//price of noodles is added to the total
}
else if(ind_type==3){										//checks if input is 3 for burger
cout<<"Added";
wes_price=100;											//burger price
f<<"|Burger-"<<wes_price<<"\n";									//item name and price is given into the file
total=total+wes_price;										//price of burger is added to the total
}
else if(ind_type==4){										//checks if input is 4 for pasta
cout<<"Added";
wes_price=110;											//pasta price
f<<"|Pasta-"<<wes_price<<"\n";									//item name and price is given into the file
total=total+wes_price;										//price of pasta is added to the total
}
else if(ind_type==5){										//checks if input is 5 for french fries
cout<<"Added";
wes_price=50;											//french fries price
f<<"|FrenchFries-"<<wes_price<<"\n";								//item name and price is given into the file
total=total+wes_price;										//price of french fries is added to the total
}
else if(ind_type==6){										//checks if input is 6 for cold drink
cout<<"Added";
wes_price=60;											//cold drink price
f<<"|ColdDrink-"<<wes_price<<"\n";								//item name and price is given into the file
total=total+wes_price;										//price of cold drink is added to the total
}
else{												//checks if input is wrong
cout<<"Wrong Input";
goto ind_typo1;											//go back to item section
}
}
else if(f1==2){											//checks if f1 is 2 if true then indian cusine is 													selected
cout<<"\n---Indian cusine---";
int ind_type;
int ind_price;
ind_typo:cout<<"\nChoose:\n1.gujarati-100\n2.rajasthani-100\n3.punjabi-120\n4.southern-110\n:";
cin>>ind_type;
if(ind_type==1){										//checks if input is 1 for gujarati thali
cout<<"Added";
ind_price=100;											//gujarati thali price
f<<"|Gujarati*Thali-"<<ind_price<<"\n";								//item name and price is given into the file
total=total+ind_price;										//price of gujarati thali is added to the total
}
else if(ind_type==2){										//checks if input is 2 for rajasthani thali
cout<<"Added";
ind_price=100;											//rajasthani thali price
f<<"|Rajasthani*Thali-"<<ind_price<<"\n";								//item name and price is given into the file
total=total+ind_price;										//price of Rajasthani Thali is added to the total
}
else if(ind_type==3){										//checks if input is 3 for Punjabi Thali
cout<<"Added";
ind_price=120;											//Punjabi Thali price
f<<"|Punjabi*Thali-"<<ind_price<<"\n";								//item name and price is given into the file
total=total+ind_price;										//price of Punjabi Thali is added to the total
}
else if(ind_type==4){										//checks if input is 4 for Southern Thali
cout<<"Added";
ind_price=110;											//Southern Thali price
f<<"|Southern*Thali-"<<ind_price<<"\n";								//item name and price is given into the file
total=total+ind_price;										//price of Southern Thali is added to the total
}
else{												//if input of indian food is wrong
cout<<"Wrong Input";goto ind_typo;								//go back to indian food choices
}
}
else{												//if input of choosing between cusine is wrong
cout<<"Wrong Input";goto ft; 									//go back to cusine choices
}
anyg:cout<<"\nWant to add anything ?(y/n): ";							//if you want to add something to your order
char any;cin>>any;
if(any=='y'){											//if yes
goto ft;											//go back to cusine choices
}
else if(any=='n'){										//if no
f<<"|Total-"<<total;										//Total is given as input to the file
cout<<"\nTotal:"<<total;
cout<<"\norder recorded\n";
}
else{												//if input of any is noy y|n
cout<<"\nentered wrong choice,please enter again.\n";
goto anyg;											//go back to choice for more ordering
}
f<<"|-------------------------Order-----------------------|";
f.close();
cout<<"Enter any key:";
char anyt;cin>>anyt;
}
};
class new_class:public mess{
public:
new_class(){
string username,password;
creg:system("clear");
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
cout<<"\nEnter Credentials to enter.\n";
cout<<"Enter User Name:";
cin>>username;
cout<<"Enter Password:";
cin>>password;
if(username=="ganpatuniversity"){
if(password=="gnu123"){
strcpy(entry10,"allowed");
}
else{cout<<"Wrong password entered please enter again.";goto creg;}
}
else{cout<<"Wrong username entered please enter again.";goto creg;}
}
~new_class(){
cout<<"\nThanks for coming!\n";
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
cout<<"\n Created By:\tHARSH-KUMAR(19162121009)\n\t\tGEETANJALI-PUROHIT(19162121008)\n\t\tMEET-GAJJAR(19162121007)\n\n";
}
void Index(){											//index() for having order records by enrollment 													number
system("clear");
char a;
int count=0;
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
cout<<"\n--Search Bill--\n";
cout<<"Enter Enrollment no:";
cin>>filename;											//enrollment number is taken as string 
const char *c = filename.c_str();								//string filename is converted to const char *c
ifstream f;											//object of ifstream to read from the file
f.open(c,ios::binary);										//file opened to read name "c"
if(!f){												//check if file is not found or unable to open
cout<<"\nEnable to open the file please check the enrollment number.";
}
while(f>>a){											//file pointer gives the character of file to 													character a
if(a=='*'){											//checks if a is *
cout<<" ";											//if true prints a blank sapce
}
else if(a=='|'){										//checks if a is |
cout<<"\n";											//if true prints a new line
}
else{												//if a is neither * or |
cout<<a;											//if true print a i.e. character from the file
}
}
f.close();
press:cout<<"\npress 1)paid\n2)not paid : ";							//check if the bill is paid or not
int any;
cin>>any;
if(any == 1){											//if bill is paid
ofstream f;											//object of ofstream for writing inside of the file
f.open(c);											//opening the last file
f<<"";												//overwriting the file with nothing
f.close();
}
else if(any==2){}										//if bill is not paid the bill remains as it is
else{												//if wrong input is given
cout<<"Entered wrong input please enter again.";
goto press;											//we go back to press
}
}
void Entries(){											//entries() for having an index of all the 													enrollment number who makes order
char a;
int count=0;
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
ifstream f20;											//object of ifstream to read from a file
f20.open("enteries.txt",ios::binary);								//file opened named "entries.txt" to read
if(!f20){											//if file is not available or unable to open
cout<<"\nEnable to open the file.";
}
cout<<"\nAll the entries:\n";
while(f20>>a){											//file pointer gives character to a
if(a=='*'){
cout<<" ";
}
else if(a=='|'){
cout<<"\n";
}
else{
cout<<a;											//a is printed
}
}
cout<<"\nenter any key:";
char number;
cin>>number;
f20.close();
}
};
int main(){
int n;
strcpy(entry10,"not-allowed");
new_class ob1;
cout<<entry10;
if(strcmp(entry10,"allowed")==0){
main:system("clear");
cout<<"\n**********************MESS MANAGEMENT SYSTEM**************************\n";
cout<<"MM\tMM  EEEEEEEE  SSSSSSSS  SSSSSSSS";
cout<<"\nMMMMMMMMMM  EE        SS        SS";
cout<<"\nMM  MM \tMM  EEEEEEEE  SSSSSSSS  SSSSSSSS";
cout<<"\nMM\tMM  EE              SS        SS";
cout<<"\nMM\tMM  EEEEEEEE  SSSSSSSS  SSSSSSSS";
cout<<"\n";
cout<<"\n";
cout<<"MM\tMM      AAAAA      NN     NN       AAAAA      GGGGGGGG    EEEEEEEE  MM      MM  EEEEEEEE  NN     NN  TTTTTTTT";
cout<<"\nMMMMMMMMMM     AA   AA     NNNN   NN      AA   AA     G           EE        MMMMMMMMMM  EE        NNNN   NN     TT";
cout<<"\nMM  MM \tMM    AAAAAAAAA    NN NN  NN     AAAAAAAAA    G    GGGGG  EEEEEEEE  MM  MM  MM  EEEEEEEE  NN NN  NN     TT";
cout<<"\nMM   \tMM   AA       AA   NN  NN NN    AA       AA   G      G    EE        MM      MM  EE        NN  NN NN     TT";
cout<<"\nMM      MM  AA         AA  NN   NNNN   AA         AA  GGGGGGGG    EEEEEEEE  MM      MM  EEEEEEEE  NN   NNNN     TT";
cout<<"\n";
cout<<"\n";
cout<<"SSSSSSSS  YY      YY  SSSSSSSS  TTTTTTTT  EEEEEEEE  MM      MM";
cout<<"\nSS         YY    YY   SS           TT     EE        MMMMMMMMMM";
cout<<"\nSSSSSSSS    YYYYYY    SSSSSSSS     TT     EEEEEEEE  MM  MM  MM  ";
cout<<"\n      SS      YY            SS     TT     EE        MM      MM";
cout<<"\nSSSSSSSS      YY      SSSSSSSS     TT     EEEEEEEE  MM      MM";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n1.New Entry\n2.Billing Record\n3.All the entries\n4.Exit\nEnter your choice:";
cin>>n;												//choice input
if(n==1){											//checks if choice is 1
system("clear");
ob1.entry();											//calls entry() from the class
goto main;											//go back to choices section
}
else if(n==2){											//checks if choice is 2
system("clear");
ob1.Index();											//calls Index() from the class
goto main;											//go back to choices section
}
else if(n==3){											//checks if choice is 3
system("clear");
ob1.Entries();											//calls entries() from the class
goto main;											//go back to choices section
}
else if(n==4){											//checks if choice is 4
system("clear");
}
else{
cout<<"\nWrong Choice\n";
goto main;											//go back to choices section
}
}
}
