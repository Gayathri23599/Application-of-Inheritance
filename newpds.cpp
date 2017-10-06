#include<iostream>
#include<string.h>
using namespace std;
class attendees
{
	public:
		char *name,*college,*dept;
		long roll;
		int year;
		static int count;
		attendees()
		{
			name = new char;
			college = new char;
			dept = new char;
			count++;
		}
		attendees(char *n,char *c,char *d,long r,int y)
		{
			name = new char[strlen(n)+1];
			strcpy(name,n);
			college = new char[strlen(c)+1];
			strcpy(college,c);
			dept = new char[strlen(d)+1];
			strcpy(dept,d);
			roll=r;
			year=y;
			count++;
		}
		virtual void display()=0;
};
int attendees::count=0;
class workshop:public attendees
{
	char *w_name;
	bool fee_payment,attendance;
	public:
		static int w_count;
		workshop():attendees()
		{
			w_name = new char;
			fee_payment=false;
			attendance=false;
			w_count++;
		}
		workshop(char *n,char *c,char *d,long r,int y,char *w):attendees(n,c,d,r,y)
		{
			w_name = new char[strlen(w)+1];
			strcpy(w_name,w);
			fee_payment=false;
			attendance=false;
			w_count++;
		}
		friend istream& operator>>(istream&,workshop&);
		friend ostream& operator<<(ostream&,workshop&);
		void payfees();
		void display();
		void attend();
};
int workshop::w_count=0;
istream& operator>>(istream& din,workshop& a)
{
	cout<<"Enter your name,college,department,roll number,year of study and workshop attending"<<endl;
	cin>>a.name>>a.college>>a.dept>>a.roll>>a.year>>a.w_name;
	return din;
}
ostream& operator<<(ostream& dout,workshop& a)
{
	a.display();
	return dout;
}
void workshop::display()
{
	cout<<"Name:"<<name<<endl<<"College:"<<college<<endl<<"Department:"<<dept<<endl<<"Roll number:"<<roll<<endl<<"Year of study:"<<year<<endl<<"Workshop attending:"<<w_name<<endl<<"Fees paid:";
	if(fee_payment)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;	
	cout<<"Whether attended the workshop:";
	if(attendance)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
void workshop::payfees()
{
	cout<<"Paying fees.."<<endl;
	fee_payment=true;
	cout<<"Fee paid:)"<<endl;
}
void workshop::attend()
{
	if(fee_payment)
	{
		cout<<"Attending the workshop"<<endl;
		attendance=true;
	}
	else
	{
		cout<<"Fee not paid.Cannot attend the workshop"<<endl;
		attendance=false;
	}
}
class event:public attendees
{
	bool prizes;
	int no_prizes;
	public:
		static int e_count;
		event():attendees()
		{
			prizes=false;
			no_prizes=0;
			e_count++;
		}
		event(char *n,char *c,char *d,long r,int y):attendees(n,c,d,r,y)
		{
			prizes=false;
			no_prizes=0;
			e_count++;
		}
		friend istream& operator>>(istream&,event&);
		friend ostream& operator<<(ostream&,event&);
		void display();
		void win();
};
int event::e_count=0;
istream& operator>>(istream& din,event& a)
{
	cout<<"Enter your name,college,department,roll number and year of study"<<endl;
	cin>>a.name>>a.college>>a.dept>>a.roll>>a.year;
	return din;
}
ostream& operator<<(ostream& dout,event& a)
{
	a.display();
	return dout;
}
void event::display()
{
	cout<<"Name:"<<name<<endl<<"College:"<<college<<endl<<"Department:"<<dept<<endl<<"Roll number:"<<roll<<endl<<"Year of study:"<<year<<endl<<"No. of prizes won:"<<no_prizes<<endl;
}
void event::win()
{
	prizes=true;
	no_prizes++;
}
class event_template
{
	public:
		static char *first_prize,*second_prize,*third_prize;
		event_template()
		{
			first_prize = new char;
			second_prize = new char;
			third_prize = new char;
		}
};
char* event_template::first_prize;
char* event_template::second_prize;
char* event_template::third_prize;
class hackathon:public event,public event_template
{
	public:
		static int h_count;
		hackathon():event(),event_template()
		{
			h_count++;
		}
		hackathon(char *n,char *c,char *d,long r,int y):event(n,c,d,r,y),event_template()
		{
			h_count++;
		}
		friend istream& operator>>(istream&,hackathon&);
		friend ostream& operator<<(ostream&,hackathon&);
		void setdata(char *f,char *s,char *t);
		void display();
};
int hackathon::h_count=0;
istream& operator>>(istream& din,hackathon& a)
{
	cout<<"Enter your name,college,department,roll number and year of study"<<endl;
	cin>>a.name>>a.college>>a.dept>>a.roll>>a.year;
	return din;
}
ostream& operator<<(ostream& dout,hackathon& a)
{
	a.display();
	return dout;
}
void hackathon::setdata(char *f,char *s,char *t)
{
	strcpy(first_prize,f);
	strcpy(second_prize,s);
	strcpy(third_prize,t);
}
void hackathon::display()
{
	cout<<"First Prize:"<<first_prize<<endl<<"Second Prize:"<<second_prize<<endl<<"Third Prize:"<<third_prize<<endl;
}		
int main()
{
	workshop w;
	cin>>w;
	w.payfees();
	w.attend();
	cout<<w;
	event e;
	cin>>e;
	cout<<e<<endl;
	cout<<"Workshop and Event count"<<endl;
	cout<<"Workshop :"<<w.w_count<<"\t"<<"Event :"<<e.e_count<<endl;
	hackathon h;
	cin>>h;
	cout<<"Enter the First three prizes for Hackathon"<<endl;
	char a[20],b[20],c[20];
	cin>>a>>b>>c;
	h.setdata(a,b,c);
	cout<<h<<endl;
	cout<<"Total count"<<endl;
	cout<<"Total:"<<h.count<<"\t"<<"Event :"<<h.e_count<<"\t"<<"Hackathon :"<<h.h_count<<endl;
	return 0;
}
	
