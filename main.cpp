#include <cstdlib>
#include <iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
class student
{
        int rollno;
        char name[20];
        int p_marks,c_marks,m_marks,e_marks,cs_marks,paid,sem;
        float per;
        char grade;
        void calculate();
public:
        void getdata();
        void showdata();
        void show_tabular();
        int retrollno();
        void payment();
        void payshow();
};
void student::calculate()
{    per=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5;
     if(per>=95)
     grade='A+';
     else
      if(per>=85)
     grade='A';
     else
     if(per>=75)
     grade='B+';
     else
     if(per>=65)
     grade='B';
     else
     if(per>=50)
     grade='C';
     else
     if(per>=33)
     grade='C';
     else
     grade='F';
}
void student::getdata()
{	cout<<"\nEnter the Roll number of student:";
	cin>>rollno;
	cout<<"\n\n Enter the name of student";
	cin>>name;
	cout<<"\n Enter the marks in physics out of 100:";
	cin>>p_marks;
	cout<<"\n Enter the marks in chemistry out of 100:";
	cin>>c_marks;
	cout<<"\n Enter the marks in maths out of 100:";
	cin>>m_marks;
	cout<<"\n Enter the marks in English out of 100:";
	cin>>e_marks;
    cout<<"\n Enter the marks in computer science out of 100:";
    cin>>cs_marks;
	calculate();
	cout<<"Enter the semester paid: ";
	cin>>sem;
	cout<<"Enter the amount paid: ";
	cin>>paid;
	
	
	
}
void student::showdata()
{	cout<<"\nroll number of student "<<rollno ;
	cout<<"\n name of student :"<<name ;
	cout<<"\n marks in physics:"<<p_marks;
	cout<<"\n marks in chemistry :"<< c_marks ;
	cout<<"\n marks in mahs :"<< m_marks ;
	cout<<"\n marks in English :"<< e_marks ;
	cout<<"\n marks in computer science:"<< cs_marks ;
	cout<<"\n percentage of student :"<< per ;
	cout<<"\n Grade of student:"<< grade ;
	cout<<"\n Fees was paid in semster: "<<sem;
	cout<<"\n Amount paid is : rs"<<paid;
}
	

void student:: show_tabular()
{ cout<<rollno<<setw(6)<<" "<<name<<setw(10)<<p_marks<<setw(4)<<c_marks<<setw(4)<<m_marks<<setw(4)
	<<e_marks<<setw(4)<<cs_marks<<setw(6)<<per<<setw(6)<<" "<<grade<<endl;
}

int student:: retrollno()
{return rollno;}
void student::payment(){
	cout<<"Enter the semester paid: ";
	cin>>sem;
	cout<<"Enter the amount paid: ";
	cin>>paid;
	
}
void student:: payshow()
{
	cout<<"\nFees was paid in semster: "<<sem;
	cout<<"\nAmount paid is : rs"<<paid;
}
//-------------------------------------
void write_student()
{
	student st;
ofstream outfile;
outfile.open("student.dat",ios::binary|ios::app);
st.getdata();
outfile.write((char*)&st,sizeof(student));
outfile.close();
cout<<"\n\n student record has been created";
cin.ignore();

}
//----------------------------------------
void display_all()
{student st;
ifstream infile;
infile.open("student.dat",ios::binary);
if(!infile)
{cout<<"file could not be open!!press any key....";

return;
}
cout<<"\n\n\n\t\t display all record!!!\n\n";
while(infile.read((char*)&st,sizeof(student)))
{st.showdata();
cout<<"\n\n==================================\n";
}infile.close();

}
//----------------------------------------
void display_sp(int n)
{
    int ag=0;
student st;
ifstream infile;
infile.open("student.dat",ios::binary);
if(!infile)
{
cout<<"file could not be open !!press any key..";

return;
}

while(infile.read((char*)&st,sizeof(student)))
{
if(st.retrollno()==n)
{
st.showdata();
ag=1;
}

}
infile.close();
if(ag==0);
cout<<"\n\nrecord not exist";

}
//-----------------------------------------
void modify_student(int n)
{
int found=0;
student st;
fstream file;
file.open("student.dat",ios::binary|ios::in|ios::out);
if(!file)
{
cout<<"file could not be open!!press any key...";

return;
}
while(file.read((char*)&st,sizeof(student))&& found==0)
{
if(st.retrollno()==n)
{	st.showdata();
	cout<<"\n\nplease enter the new details of student";
st.getdata();
int pos=(-1)*sizeof(st);
file.seekp(pos,ios::cur);
file.write((char*)&st,sizeof(student));
cout<<"\n\n\trecord updated";
found=1;
}
}
file.close();
if(found==0)
cout<<"\n\nrecord not found";

}
void payfunc(int n)
{
	int found=0;
student st;
fstream file;
file.open("student.dat",ios::binary|ios::in|ios::out);
if(!file)
{
cout<<"file could not be open!!press any key...";

return;
}
while(file.read((char*)&st,sizeof(student))&& found==0)
{
if(st.retrollno()==n)
{	st.payment();
	cout<<"\n\nplease enter the new Fees of student";
st.payshow();
int pos=(-1)*sizeof(st);
file.seekp(pos,ios::cur);
file.write((char*)&st,sizeof(student));
cout<<"\n\n\trecord updated";
found=1;
}
}
file.close();
if(found==0)
cout<<"\n\nrecord not found";
}

void delete_student(int n)
{
student st;
ifstream infile;
infile.open("student.dat",ios::binary);
if(!infile)
{
	cout<<"file could not be open !!press any key...";

	return;
}
ofstream outfile;
outfile.open("temp.dat",ios::out);
infile.seekg(0,ios::beg);
while(infile.read((char*)&st,sizeof(student)));
{
if(st.retrollno()!=n)
{
outfile.write((char*)&st,sizeof(student));
}
}
outfile.close();
infile.close();
remove("student.dat");
rename("temp.dat","student.dat");
cout<<"\n\n\trecord deleted..";

}
/*void class_result()
{
	student st;
	ifstream infile;
	if(!infile)
{
cout<<"file could not be open!!press any key..";

return;
}
cout<<"\n\n\t\tALL STUDENTS RESULT\n\n";
cout<<"==================================\n";
cout<<"R.NO    Name PC ME CS %age grade"<<endl;
cout<<"==========================================\n";
while(infile.read((char*)&st,sizeof(student)));
{
st.show_tabular();
}

infile.close();
}*/
void result()
{char ch;
int rno;
cout<<"\n\n\n\tresult menu";
//cout<<"\n\n\t1.class result  ";
cout<<"\n\n\t1.student report card  ";
cout<<"\n\n\t2.backto main menu ";
cout<<"\n\n\n\tenter choice(1/2/3)?  ";
cin>>ch;
system("cls");
switch(ch)
{
//	case'1': class_result();break;
	case'1': cout<<"\n\n enter roll number of student:";
              cin>>rno;display_sp(rno);break;
	case'2': break;
default:cout<<"\a";
}
}
void payment()
{
	
}
void intro()
{
cout<<"\n\n\n\t students arsheef ";
cout<<"\n\n\n\t project:of student ";
cout<<"\n\n\n\t mede by: ABDUSSAMAD ";
cout<<"\n\n\t\t files processing:0.0001";
}
void entry_menu()
{
char ch;
int num;
system("cls");
cout<<"\n\n\\n\t entry menu ";
cout<<"\n\n\\n\t 1_create student";
cout<<"\n\n\\n\t 2_display all students record";
cout<<"\n\n\\n\t 3_search students record";
cout<<"\n\n\\n\t 4-modify student record";
cout<<"\n\n\\n\t 5-Delete record";
cout<<"\n\n\n\t  6-Modify fees";
cout<<"\n\n\n \t 7-Back to main menu ";
cout<<"\n\n\\n\t please enter your choice(1-6)";
cin>>ch;
switch(ch)
{
case '1':write_student();break;
case '2':display_all() ;break;
case '3':cout<<"\n\n\t please enter the roll number";cin>>num ;
                             display_sp(num);break;
case '4':cout<<"\n\n\t please enter the roll number";cin>>num ;
                             modify_student(num);break; ;
case '5':cout<<"\n\n\t please enter the roll number";cin>>num ;
                              delete_student(num);break;
case '6':cout<<"\n\n\t  please enter the roll number";cin>>num;
								payfunc(num); break;
case '7':break;
defult:cout<<"\a"; entry_menu();
}
}
int main(int argc, char *argv[])
{char ch;
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision(2);
//system("cls");
intro();
do
{//system("cls");
cout<<"\n\n\n\t main menu";
cout<<"\n\n\t01.result menu";
cout<<"\n\n\t02.entry /edit menu";
cout<<"\n\n\t03.exit";
cout<<"\n\n\t please select your op on (1-3)";
cin>>ch;
system("cls");
switch(ch)
{case'1':result();break;
case'2':entry_menu();break;
case'3':break;
default:cout<<"\a";
}
}while(ch!='3');

    system("PAUSE");
    return EXIT_SUCCESS;
}
