#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
void signup();
void login();
void make();
void open();
void hdesign();
void design();
char fpath[40],path[40],txt[10]={".ltp"},usrname[20],pass[20],pin[10]; //sign up
char enpass[20],ckpin[10]; //login
char data[400],tname[20],pname[20],spp[10]={".spp"}; //make
char fname[20],nspp[10]={"pps"},ext[10],temp;
int i,j,k,l=0,m,n,chkp,p=0,r=0,algo1,algo2,algo3,algo4,falgo,falgo2,nfalgo,a,b=0;
int main()
{
	hdesign();
	cout<<"\n Enter your option in: "<<endl;
	cout<<"\n 1. Sign Up into your Account \n\n 2. Login into your Account \n\n Enter Here: ";
	cin>>i;
	clrscr();
	if(i==1)
		signup();
	else if(i==2)
		login();
	else
	{
		design();
		cout<<"\n Enter a valid option or press Alt+F4 to quit";
	}
	return 0;
}
void signup()
{
		design();
		cout<<" ---------------------------------- ";
		cout<<"\n Home >> Sign up into your Account"<<endl;
		cout<<" ---------------------------------- ";
		cout<<"\n Enter the path: (for eg: E:/My_Software/): ";
		gets(path);
		cout<<"\n Enter your username: (It must contain numbers for eg: John99) ";
		cout<<"\n Enter here: ";
		gets(usrname);
		for(i=0;path[i]!='\0';i++)
		fpath[i]=path[i]; // path
		for(j=0;usrname[j]!='\0';j++)
		fpath[i+j]=usrname[j]; // username
		for(k=0;txt[k]!='\0';k++)
		fpath[i+j+k]=txt[k]; // final path and username
		ofstream outfile(fpath);
		// cout<<" "<<fpath;  // for testing
		cout<<"\n Set a Secret Pin Code of 4 digit: (Note: Don't share  your Secret Pin Code with your friends)";
		cout<<"\n Enter here: ";
		gets(pin);
		for(i=0;pin[i]!='\0';i++)
		chkp=i+1;
		if(chkp==4)
		{
			while(pin[p]!='\0')
			{
				pin[p]=pin[p]-30;
				p++;
			}
			outfile<<pin<<endl;

		}
		else
			cout<<"\n Error: The Pin Code should be of 4 numbers. ";
		cout<<"\n Enter the password: ";
		gets(pass);
		while(pass[l]!='\0')
		{
			pass[l]=pass[l]-30;
			l++;
		}
		outfile<<pass;
		cout<<"\n Congratulations! You have Sign up Successfully ";
		outfile.close();

}
void login()
{
		design();
		cout<<" ---------------------------------- ";
		cout<<"\n Home >> Login into your Account"<<endl;
		cout<<" ---------------------------------- ";
		cout<<"\n Enter the same path: (the Sign up path for eg: E:/My_Software/): ";
		gets(path);
		cout<<"\n Enter your username: ";
		gets(usrname);
		for(i=0;path[i]!='\0';i++)
		fpath[i]=path[i]; // path
		for(j=0;usrname[j]!='\0';j++)
		fpath[i+j]=usrname[j]; // username
		for(k=0;txt[k]!='\0';k++)
		fpath[i+j+k]=txt[k]; // final path and username
		// cout<<" "<<fpath<<endl; // for testing
		ifstream infile(fpath);
		if(infile)
		{
			cout<<"\n Enter your Secret 4 digit Pin Code: ";
			gets(ckpin);
			infile>>pin;
			while(pin[p]!='\0')
			{
				pin[p]=pin[p]+30;
				p++;
			}
			algo1=pin[0]; // logic starts........................................
			algo2=pin[1];
			algo3=pin[2];
			algo4=pin[3];
			falgo=((char)algo1)+((char)algo3);
			falgo2=((char)algo2)+((char)algo4);
			// cout<<falgo<<endl;  // for testing
			nfalgo=(falgo+falgo2)-70;
			// cout<<nfalgo;  // logic ends....................................
			// cout<<" "<<pin; //for testing
			if(strcmp(pin,ckpin)==0)
			{
					cout<<"\n Enter your password: ";
					gets(enpass);
					infile>>pass;
					while(pass[l]!='\0')
					{
						pass[l]=pass[l]+30;
						l++;
					}
					// cout<<" "<<pass; //for testing
					if(strcmp(pass,enpass)==0)
					{
						cout<<"\n Congratulations! You have Login Successfully "<<endl;
						cout<<"\n Press any key to continue ";
						getch();
						clrscr();
						design();
						cout<<"\n Enter your option in: "<<endl;
						cout<<"\n 1. Make a file \n\n 2. Open a file \n\n Enter Here: ";
						cin>>i;
						clrscr();
						if(i==1)
							make();
						else if(i==2)
							open();
						else
						{
							design();
							cout<<"\n Enter a valid option or press Alt+F4 to quit";
						}
					}
					else
					{
						cout<<"\n Your password is incorrect. Please enter a valid one.";
					}

			}
			else
			{
				cout<<"\n Your 4 digit Secret Pin is incorrect ";
			}
		}
		else
		{
		 cout<<"\n You must Sign up first ";
		}
		infile.close();
}
void make()
{
	design();
	cout<<" ---------------------------------------------- ";
	cout<<"\n Home >> Login into your Account >> Make a file"<<endl;
	cout<<" ---------------------------------------------- ";
	cout<<"\n Enter the path and name of the file you want to make. For eg: E:/test\n\n Enter Here: "; //covertion Starts
	gets(tname);
	for(i=0;tname[i]!='\0';i++)
	pname[i]=tname[i];
	for(j=0;spp[j]!='\0';j++)
	pname[i+j]=spp[j];
	pname[i+j]='\0';
   cout<<"\n Enter your data here: ";
	gets(data);
	ofstream outfile(pname);
	while(data[r]!='\0')
	{
		data[r]=data[r]-nfalgo;
		r++;
	}
	outfile<<data;
	outfile.close();
	cout<<"\n Your data is saved in "<<pname<<". Thanks for using ";
}
void open()
{
	design();
	cout<<" ---------------------------------------------- ";
	cout<<"\n Home >> Login into your Account >> Open a file"<<endl;
	cout<<" ---------------------------------------------- ";
	cout<<"\n Enter the path of the file you want to open. For eg: E:/test.spp\n\n Enter Here: "; //covertion Starts
	gets(fname);
	a=0; // reverse mechanism of fname starts
	b=strlen(fname)-1;
	while(a<b)
	{
		temp=fname[a];
		fname[a]=fname[b];
		fname[b]=temp;
		a++;
		b--;
	} // reverse mechanism of fname ends
	for(i=0;fname[i]!='.';i++) // cutting of pps starts
	ext[i]=fname[i];
	ext[i]='\0'; // cutting of pps ends
	// cout<<ext<<endl; //for testing
	a=0; // reverse mechanism of fname starts
	b=strlen(fname)-1;
	while(a<b)
	{
		temp=fname[a];
		fname[a]=fname[b];
		fname[b]=temp;
		a++;
		b--;
	} // reverse mechanism of fname ends
	// cout<<fname; //for testing
	if(strcmp(nspp,ext)==0) // condition checking for only .spp file
	{
		ifstream infile(fname);
		if(infile)
			{
				cout<<"\n Your data is here: "<<endl<<endl;
				infile>>data;
				while(data[r]!='\0')
				{
					data[r]=data[r]+nfalgo;
					r++;
				}
				cout<<" "<<data;
				infile.close();
			}
		else
			cout<<"\n The path of the file is incorrect. Enter a valid one."; //Convertion Ends
	}
	else
	{
		cout<<"\n This extension cannot be opened. You can open only .spp format.";
	}
}
void hdesign()
{
	cout<<"��������������������������������������������������������������������������������\n";
	cout<<"\t\t* * * * The Bob Software Production Presents * * * *"<<endl;
	cout<<"\t\t\t    * * * * Security++ v.1 * * * *\n"<<endl;
	cout<<"��������������������������������������������������������������������������������";
	cout<<"\n This is a new software that is used to make and open files in .spp format. For  that you have to Sign in first then Login into your account. This is an         end-to-end encryption system.";
	cout<<"\n\n\n\t\t\t   Press any key to continue";
	getch();
	clrscr();
	cout<<"��������������������������������������������������������������������������������\n";
	cout<<"\t\t* * * * The Bob Software Production Presents * * * *"<<endl;
	cout<<"\t\t\t    * * * * Security++ v.1 * * * *\n"<<endl;
	cout<<"��������������������������������������������������������������������������������";
}
void design()
{
	cout<<"��������������������������������������������������������������������������������\n";
	cout<<"\t\t* * * * The Bob Software Production Presents * * * *"<<endl; // first menu
	cout<<"\t\t\t    * * * * Security++ v.1 * * * *\n"<<endl;
	cout<<"��������������������������������������������������������������������������������";
}