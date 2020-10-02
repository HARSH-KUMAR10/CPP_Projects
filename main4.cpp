//Hospital Management System
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
//NOTE: RUN THE PROGRAM IN FULL SCREEN ONLY
{
ofstream f;
f.open("hos.txt");										//putting content into hos.txt
f<<"|GU*HOSPITAL|(Ganpat*University*Hospital)|";
f<<"Address*:*Ganesh*Maridain,*Ahmedabad|";
f<<"with*state-of-the-art*facilities*&*treatments*at*an*affordable*cost,*encompassing*wide*spectrum*of*accurate*diagnostics*and*elegant*therapeutics *created*on*the*philosophical*edifice*of*patient*and*ethical*centricity*ensuring*humanistic*dispensation.|";
f.close();
char fname[20];
int i;
//int login();
//login();
//giving option to the user for their choice
b:system("clear");
cout<<"  HOSPITAL MANAGEMENT SYSTEM \n\n";
cout<<" Please,  Choose from the following Options: \n";					//option for different functions
cout<<" 1  >> Add New Patient Record\n";
cout<<" 2  >> Add Diagnosis Information\n";
cout<<" 3  >> Modify Patient Record\n";
cout<<" 4  >> Full History of the Patient\n";
cout<<" 5  >> Information About the Hospital\n";
cout<<" 6  >> Exit the Program \n";
a:
cout<<"Enter your choice: ";
cin>>i;
if(i>6||i<1)											//checks if wrong option entered
{
cout<<"\n Invalid Choice\n";
cout<<"Try again...........\n";
goto a;
} //if inputed choice is other than given choice


//displaying the information about the hospital........option 5
if(i==5)											//if you want to see the hospital information
{
	ifstream file;
	file.open("hos.txt");									//opening the file hos.txt
		if(!file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"Information about the Hospital.\n\n";
		    char ch;
			while(file>>ch)
			{
			if(ch=='*'){
			cout<<" ";
			}
			else if(ch=='|'){
			cout<<"\n";
			}
			else{
			cout<<ch;								//taking all the file content and printing on the 													screen
			}
			}
			cout<<"\n";
cout<<"press any key to continue.";
char any;cin>>any;
			goto b;
		}
}

//Adding the record of the new patient..................option 1
if(i==1)								
{
  ofstream pat_file;
  char fname[20];
system("clear");
cout<<"\n GU Hospital \n";
  cout<<"\n\n\n\nEnter the patient's file name : ";
  cin.ignore();
  fgets(fname,sizeof(fname),stdin);
  pat_file.open(fname);										//creating file of fname entered by user
  		if(!fname)									//if file not found or created
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
                        struct patient_info
                        {
                            char name[20];
                            char address[100];
                            char contact[12];
                            char age[5];
                            char sex[8];
                            char blood_gp[5];
                            char disease_past[50];
                            char id[15];
                        };
//taking all the input from the user
            patient_info ak;
            cout<<"\nName : ";pat_file<<"Name : ";fgets(ak.name,sizeof(ak.name),stdin);pat_file<<ak.name<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";fgets(ak.address,sizeof(ak.address),stdin);pat_file<<ak.address<<"\n";
            contactg:cout<<"\nContact Number : ";pat_file<<"Contact Number : ";fgets(ak.contact,sizeof(ak.contact),stdin);pat_file<<ak.contact<<"\n";
		int len=strlen(ak.contact);
		try{									//checking if the length of the phone number is less than 10 												digits
		if(len<11 ||len>11){
		throw 0.0f;
		}
		}
		catch(float a){
		cout<<"\nWrong input, enter phone number of 10 digits.";
		goto contactg;
		}
            cout<<"\nAge : ";pat_file<<"Age : ";fgets(ak.age,sizeof(ak.age),stdin);pat_file<<ak.age<<"\n";
            sexg:cout<<"\nSex (male/female) : ";pat_file<<"Sex : ";fgets(ak.sex,sizeof(ak.sex),stdin);pat_file<<ak.sex<<"\n";
            cout<<"\nBlood Group : ";pat_file<<"Blood Group : ";fgets(ak.blood_gp,sizeof(ak.blood_gp),stdin);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";fgets(ak.disease_past,sizeof(ak.disease_past),stdin);pat_file<<ak.disease_past<<"\n";
            cout<<"\nPatient ID : ";pat_file<<"Patient ID : ";fgets(ak.id,sizeof(ak.id),stdin);pat_file<<ak.id<<"\n";
            cout<<"\nInformation Saved Successfully\n";
            }
cout<<"Enter any key to continue.";
char any;cin>>any;
  goto b;

}

if(i==3)									//to modify person record
{
  ofstream pat_file;
  char fname[20];
system("clear");
cout<<"\n GU Hospital \n";
  cout<<"\n\n\n\nEnter the patient's file name : ";
  cin.ignore();
  fgets(fname,sizeof(fname),stdin);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n";
cout<<"Press any key to continue.";
char any;cin>>any;
goto b;
		}
		else
		{
                        struct patient_info
                        {
                            char name[20];
                            char address[100];
                            char contact[12];
                            char age[5];
                            char sex[8];
                            char blood_gp[5];
                            char disease_past[50];
                            char id[15];
                        };
//taking correct inputs from the user
            patient_info ak;
            cout<<"\nCorrect Name : ";pat_file<<"Name : ";fgets(ak.name,sizeof(ak.name),stdin);pat_file<<ak.name<<"\n";
            cout<<"\nCorrect Address : ";pat_file<<"Address : ";fgets(ak.address,sizeof(ak.address),stdin);pat_file<<ak.address<<"\n";
            contactg1:cout<<"\nCorrect Contact Number : ";pat_file<<"Contact Number : ";fgets(ak.contact,sizeof(ak.contact),stdin);pat_file<<ak.contact<<"\n";
		int len=strlen(ak.contact);
		try{
		if(len<11 ||len>11){
		throw 0.0f;
		}
		}
		catch(float a){
		cout<<"\nWrong input, enter phone number of 10 digits.";
		goto contactg1;
		}
            cout<<"\nCorrect Age : ";pat_file<<"Age : ";fgets(ak.age,sizeof(ak.age),stdin);pat_file<<ak.age<<"\n";
            cout<<"\nCorrect Sex (male/female) : ";pat_file<<"Sex : ";fgets(ak.sex,sizeof(ak.sex),stdin);pat_file<<ak.sex<<"\n";
            cout<<"\nCorrect Blood Group : ";pat_file<<"Blood Group : ";fgets(ak.blood_gp,sizeof(ak.blood_gp),stdin);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";fgets(ak.disease_past,sizeof(ak.disease_past),stdin);pat_file<<ak.disease_past<<"\n";
            cout<<"\nCorrect Patient ID : ";pat_file<<"Patient ID : ";fgets(ak.id,sizeof(ak.id),stdin);pat_file<<ak.id<<"\n";
            cout<<"\nInformation Modified Successfully\n";
            }
cout<<"Enter any key to continue.";
char any;cin>>any;
  goto b;

}



//Appending diagnosis information of patient datewise.................option 2
if(i==2)
{
    fstream pat_file;
system("clear");
cout<<"\n GU HOSPITAL\n";
    cout<<"\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    fgets(fname,sizeof(fname),stdin);
	pat_file.open(fname, ios::in);								//opening fname file taken from the user
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\nInformation about "<<fname<<" \n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
			pat_file.close();
			pat_file.open(fname, ios::out | ios::app);
            		cout<<"\n";
                            struct app
                            {
                                char symptom[500];
                                char diagnosis[500];
                                char medicine[500];
                                char addmission[30];
                                char ward[15];
                            };
//taking the diagonosis information from the user
            app add;
            cout<<"\nSymptoms : "; pat_file<<"Symptoms : ";fgets(add.symptom,sizeof(add.symptom),stdin); pat_file<<add.symptom<<"\n";
            cout<<"\nDiagnosis : "; pat_file<<"Diagnosis : ";fgets(add.diagnosis,sizeof(add.diagnosis),stdin); pat_file<<add.diagnosis<<"\n";
            cout<<"\nMedicines : "; pat_file<<"Medicines : ";fgets(add.medicine,sizeof(add.medicine),stdin); pat_file<<add.medicine<<"\n";
            cout<<"\nAddmission Required?(yes/no) : "; pat_file<<"Addmission Required? : ";fgets(add.addmission,sizeof(add.addmission),stdin); pat_file<<add.addmission<<"\n";
		if(add.addmission=="yes"){
            cout<<"\nType of ward : "; pat_file<<"Type of ward : ";fgets(add.ward,sizeof(add.ward),stdin); pat_file<<add.ward<<"\n";pat_file<<"\n";
            cout<<"\n\n"<<add.ward<<" ward is alloted Successfully\n";
		}
			pat_file.close();
			cout<<"\n\n";
		cout<<"Enter any key to continue.";
		char any;cin>>any;
			  goto b;
	}
}
//For displaying the full medical history of patient in that hospital............option 4
if(i==4)
{
    fstream pat_file;
    cout<<"\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    fgets(fname,sizeof(fname),stdin);
	cout<<fname;
	fflush(stdin);
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";		
		cout<<"Press any key to continue:";
		char any;cin>>any;
		goto b;
		}
		else
		{

		    cout<<"\n\n\n\n\t\t\t\t........................................ Full Medical History of "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        std::cin.get();
        fflush(stdin);
        goto b;
}//Exiting Through the system with a Thank You note........................option 6
if(i==6)
{
system("clear");
cout<<"\t THANK YOU FOR USING \n";
cout<<"\t HOSPITAL MANAGEMENT SYSTEM \n";
}
cout<<"\n";
}
