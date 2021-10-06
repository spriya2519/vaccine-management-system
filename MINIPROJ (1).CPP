#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
int n=0,index=0;
class student
{
     public:char name[10],aaddarno[20],gender[20],mobilenumber[10];
     int age;
     void insert(fstream &f1,fstream &f2)
     {
	 cout<<"enter NAME:";
	 cin>>name;
	 cout<<"enter AADDARNO:";
	 cin>>aaddarno;
	 cout<<"enter GENDER:";
	 cin>>gender;
	 cout<<"enter MOBILENUMBER:";
	 cin>>mobilenumber;
	 cout<<"enter AGE:";
	 cin>>age;
	 write(f1,f2);
      }
      void write(fstream &f1,fstream &f2)
      {
	 f1<<++index<<"\t"<<aaddarno<<"\n";
	 f2<<name<<"\t"<<aaddarno<<"\t"<<gender<<"\t"<<mobilenumber<<"\t"<<age<<"\n";
      }
      void display(fstream &f2)
      {
	 f2>>name>>aaddarno>>gender>>mobilenumber>>age;
	 cout<<"NAME\tAADDARNO\tGENDER\tMOBILENUMBER\tAGE\n";
	 cout<<name<<"\t"<<aaddarno<<"\t"<<gender<<"\t"<<mobilenumber<<"\t"<<age<<"\n";
      }
      int search(fstream &f1,char key[20])
      {
	       int i,x;
	       for(i=1;i<=n;i++)
	       {
		    f1>>x>>aaddarno;
		    if(strcmp(aaddarno,key)==0)
		    return i;
	       }
	       cout<<"record not found\n";
	       return 0;
	       }
	       int remove(fstream &f1,char key[20])
	       {
		     int i;
		     i=search(f1,key);
		     return i;
	       }

      };
      void main()
      {
	fstream f1,f2;
	student s[20],p;
	int ch,k=0,i;
	clrscr();
	f1.open("index.txt",ios::trunc);
	f2.open("data.txt",ios::trunc);
	f1.close();
	f2.close();
	for(;;)
	{    cout<<"\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 VACCINE MANAGEMENT SYSTEM \xB3\xB2=\xB2=\xB2-\xB3\n\n";
	     cout<<"1.Insert 2.Display 3.Search 4.Delete 5.Exit\n";
	     cout<<"Enter your choice:";
	     cin>>ch;
	     switch(ch)
	     {
		case 1 : f1.open("index.txt",ios::app);
			 f2.open("data.txt",ios::app);
			 cout<<"Enter no. of people to be vaccinated:";
			 cin>>k;
			 n=n+k;
			 for(int i =1;i<=k;i++)
			 s[i].insert(f1,f2);
			 f1.close();
			 f2.close();
			 break;
		case 2 :f2.open("data.txt",ios::in);
			for(i=1;i<=n;i++)
			   s[i].display(f2);
			   f2.close();
			break;
		case 3 :char aaddarno[20];
			cout<<"Enter AADDARNO to search:";
			cin>>aaddarno;
			f1.open("index.txt",ios::in);
			f2.open("data.txt",ios::in);
			int j=p.search(f1,aaddarno);
			if(j!=0)
			{
				cout<<"Record found & Details are\n";
				cout<<"Name="<<s[j].name<<"\t"<<"AADDARNO="<<s[j].aaddarno<<"\n";
				cout<<"Gender="<<s[j].gender<<"\t"<<"MobileNumber="<<s[j].mobilenumber<<"\t"<<"Age="<<s[j].age<<"\n";
			}
			f1.close();
			f2.close();
			break;
		 case 4 :f1.open("index.txt",ios::in);
			 f2.open("data.txt",ios::in);
			 cout<<"Enter AADDARNO to delete:";
			 cin>>aaddarno;
			 j = p.remove(f1,aaddarno);
			 if(j!=0)
			 {
			   for(i=j;i<n;i++)
			   s[i]=s[i+1];
			   cout<<"Deletion successful\n";
			 }
			 n--;
			 index--;
			 f1.close();
			 f2.close();
			 f1.open("index.txt",ios::trunc|ios::app);
			 f2.open("data.txt",ios::trunc|ios::app);
			 index = 0;
			 for(i= 1;i<=n;i++)
			    s[i].write(f1,f2);
			    f1.close();
			    f2.close();

		 break;
		 default:exit(0);

	     }
	}
      }