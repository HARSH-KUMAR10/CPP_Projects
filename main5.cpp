#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<stdlib.h>
using namespace std;
//global variable declaration
int k=7,r=0,flag=0;
struct date
{
    int mm,dd,yy;
};

ofstream fout;
ifstream fin;

class item
{
    protected:
    int itemno;
    char name[25];
    date d;
public:
    void add()
    {
        cout<<"\n\n\tItem No: ";
        cin>>itemno;
        cout<<"\n\n\tName of the item: ";
        cin>>name;
//gets(name);
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }
    void show()
    {
        cout<<"\n\tItem No: ";
        cout<<itemno;
        cout<<"\n\n\tName of the item: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    /*void report()
    {
       // gotoxy(3,k);
        cout<<itemno;
       // gotoxy(13,k);
        cout<<"\t";puts(name);
    }*/
    int retno()
    {
        return(itemno);

    }

};

class amount: public item
{
    float price,qty,tax,gross,dis,netamt;
public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt()
    {
        return(netamt);
    }
} amt;

void amount::add()
{
    item::add();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    cout<<"\n\n\tTax percent: ";
    cin>>tax;
    cout<<"\n\n\tDiscount percent: ";
    cin>>dis;
    calculate();
    fout.write((char *)&amt,sizeof(amt));
    fout<<".\n";
    fout.close();
}
void amount::calculate()
{
    gross=price+(price*(tax/100));
    netamt=qty*(gross-(gross*(dis/100)));
}
void amount::show()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    item::show();
    cout<<"\n\n\tNet amount: ";
    cout<<netamt;
    fin.close();
}

void amount::report()
{
    //cout<<"\t"; item::report();cout<<"\t";
    //gotoxy(23,k);
    cout<<"\t";cout<<itemno;
       // gotoxy(13,k);
    cout<<"\t";cout<<name;
    cout<<"\t";cout<<price;cout<<"\t";
   // gotoxy(33,k);
    cout<<qty;cout<<"\t\t";
   // gotoxy(44,k);
    cout<<tax;cout<<"\t";
   // gotoxy(52,k);
    cout<<dis;cout<<"\t";
    //gotoxy(64,k);
    cout<<"     "<<netamt;cout<<"\n";
    k=k+1;
    if(k==50)
    {
       // gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
       // getch();
        k=7;
       // system("clear");
       // gotoxy(30,3);
        cout<<" ITEM DETAILS ";
       // gotoxy(3,5);
        cout<<"NUMBER";
       // gotoxy(13,5);
        cout<<"NAME";
        //gotoxy(23,5);
        cout<<"PRICE";
       // gotoxy(33,5);
        cout<<"QUANTITY";
       // gotoxy(44,5);
        cout<<"TAX";
       // gotoxy(52,5);
        cout<<"DEDUCTION";
      //  gotoxy(64,5);
        cout<<"NET AMOUNT";
    }
}

void amount::pay()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                     :"<<price;
    cout<<"\n\n\t\tQUANTITY                  :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
    cout<<"\n\n\n\t\tNET AMOUNT              :Rs."<<netamt;
    cout<<"\n\t\t*********************************************\n\n";
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
menu:
   // system("clear");
    //gotoxy(25,2);
    cout<<"\n===========================Super Market Billing ";
   // gotoxy(25,3);
    cout<<"===========================\n\n";
    cout<<"\n\t\t1.Bill Report\n\n";
    cout<<"\t\t2.Add/Remove/Edit Item\n\n";
    cout<<"\t\t3.Show Item Details\n\n";
    cout<<"\t\t4.Exit\n\n";
    cout<<"\t\tPlease Enter Required Option: ";
    int ch,ff;
    float gtotal;
    cin>>ch;
    switch(ch)
    {
    case 1:
ss:
       //system("clear");
       // gotoxy(25,2);
        cout<<"\n\n\t\t ================Bill Details";
      //  gotoxy(25,3);
        cout<<"================\n";
        cout<<"\n\t\t1.All Items\n\n";
        cout<<"\t\t2.Back to Main menu\n\n";
        cout<<"\t\tPlease Enter Required Option: ";
        int cho;
        cin>>cho;
        if(cho==1)
        {
           // system("clear");
           // gotoxy(30,3);
            cout<<"\n\n\n\t    ***************BILL DETAILS*************\n ";
            //gotoxy(3,5);
            cout<<"\n\tITEM NO";
            //gotoxy(13,5);
            cout<<"\tNAME";
            //gotoxy(23,5);
            cout<<"\tPRICE";
            //gotoxy(33,5);
            cout<<"\tQUANTITY";
            //gotoxy(44,5);
            cout<<"\tTAX %";
            //gotoxy(52,5);
            cout<<"\tDISCOUNT %";
            //gotoxy(64,5);
            cout<<"  NET AMOUNT\n";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            gtotal=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report();
                    gtotal+=amt.retnetamt();
                    ff=0;
                }
                if(ff!=0) gtotal=0;
            }
            //gotoxy(17,k);
            cout<<"\n\n\t\t\tGrand Total="<<gtotal;
            //getch();
            fin.close();
        }
        if(cho==2)
        {
            goto menu;
        }
        goto ss;
    case 2:
db:
        //system ("clear");
        //gotoxy(25,2);
        cout<<"\n\t\t =================Bill Editor";
        //gotoxy(25,3);
        cout<<"=================\n\n";
        cout<<"\n\t\t1.Add Item Details\n\n";
        cout<<"\t\t2.Edit Item Details\n\n";
        cout<<"\t\t3.Delete Item Details\n\n";
        cout<<"\t\t4.Back to Main Menu ";
        int apc;
        cout<<"\n\n\t\tPlease Enter Required Option: ";
        cin>>apc;
        if(apc==1){
            fout.open("itemstore.dat",ios::binary|ios::app);
            amt.add();
            cout<<"\n\t\tItem Added Successfully!";
           // getch();
            goto db;
}
	else if(apc==2){
	    int check;
	    check=0;
	    char c;
            flag=0;
            cout<<"\n\n\tEnter Item Number to be Edited :";
            char ino;cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            fout.open("itemstore.dat",ios::binary|ios::app);
	    ofstream f("temp_itemstore.dat");
	    int x=amt.item::retno();
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
	    while(fin>>ch){
	    if(ch==ino){check=10;}
	    if(check==10){
	    if(ch=='.'){check=0;}
	    }
	    if(check!=10){
	    f<<ch;
	    }
	    }
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    if(x==ino)
                    {
                        flag=1;
                        fout.seekp(r*sizeof(amt));
                        //system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        amt.show();
                        cout<<"\n\n\t\tEnter New Details\n";
                        amt.add();
                        cout<<"\n\t\tItem Details edited";
                        break;
                    }
                r++;
		}
            }
            if(flag==0)
            {
                cout<<"\n\t\tItem No does not exist...Please Retry!";
               // getch();
                goto db;
            }
            fin.close();
           // getch();
            goto db;
}
	else if(apc==3){
            flag=0;
            cout<<"\n\n\tEnter Item Number to be deleted :";
            int ino;cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
//fstream tmp("temp.dat",ios::binary|ios::out);
            fin.seekg(0);
            while(fin.read((char*)&amt, sizeof(amt)))
            {
                int x=amt.item::retno();
                if(x!=ino)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    flag=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("itemstore.dat",ios::trunc|ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat",ios::binary|ios::in);
            if(!tmp)
            {
                cout<<"Error in File";
                goto db;
            }
            while(tmp.read((char*)&amt,sizeof(amt)))
                fout.write((char*)&amt,sizeof(amt));
            tmp.close();
            fout.close();
            if(flag==1)
                cout<<"\n\t\tItem Succesfully Deleted";
            else if (flag==0)
                cout<<"\n\t\tItem does not Exist! Please Retry";
           // getch();
            goto db;
}
	else if(apc==4){
            goto menu;
}
	else{
            cout<<"\n\n\t\tWrong Choice!!! Retry";
           // getch();
            goto db;
        }
    case 3:
        system("clear");
        flag=0;
        int ino;
        cout<<"\n\n\t\tEnter Item Number :";
        cin>>ino;
        fin.open("itemstore.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.item::retno();
            if(x==ino)
            {
                amt.pay();
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tItem does not exist....Please Retry!";
       // getch();
        fin.close();
        goto menu;
    case 4:
        system("clear");
        //gotoxy(20,20);
        cout<<"\n\tARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
          //  gotoxy(12,20);
            system("clear");
            cout<<"\n************************** THANKS **************************************";
            //getch();
            exit(0);
        }
        else if((yn=='N')||(yn=='n'))
            goto menu;
        else
        {
            goto menu;
        }
    default:
        cout<<"\n\n\t\tWrong Choice....Please Retry!";
       // getch();
        goto menu;
    }
    return 0;
}
