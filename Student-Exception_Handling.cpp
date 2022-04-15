#include<iostream>
#include<string>
using namespace std;

class student
{
    string student_name;
    int student_rollno,student_subject;

    protected:
        int markarr[5],total_mark=0;
        double average_mark;
        char grade;

    public:
        void set_details (string s_name,int rollno,int no_of_sub) 
        {
            student_name = s_name;
            student_rollno = rollno;
            student_subject = no_of_sub;
        }

        void student_progress()
        {
            for(int j=0;j<student_subject;j++)
            {
                cout<<"Enter the Mark of the subject"<<j+1<<" : "<<endl;
                cin>>markarr[j];

                if(markarr[j]>100)
                    throw string {"Subject Mark shouldn't exceeds 100"};
                else if(markarr[j]<0)
                    throw -1;
                else
                {
                    total_mark+=markarr[j];
                }
            }
            average_mark=total_mark/student_subject;
            if(average_mark>90 && average_mark<=100)
                grade='A';
            else if(average_mark>75 && average_mark<=90)
                grade='B';
            else if(average_mark>60 && average_mark<=75)
                grade='C';
            else if(average_mark>45 && average_mark<=60)
                grade='D';
            else if(average_mark>30 && average_mark<=45)
                grade='E';
            else   
                grade='F';
        }   

        void print_report()
        {
            cout<<". . . ___ ___ ___ Student Progress Report Card ___ ___ ___ . . ."<<endl;
            cout<<"Name of the Student : "<<student_name<<endl;
            cout<<"Roll Number of the Student : "<<student_rollno<<endl;
            cout<<"Total Number of Subjects, Student have in this Academic year : "<<student_subject<<endl;
            for(int j=0;j<student_subject;j++)
            {
                cout<<"Mark in Subject"<<j+1<<" : "<<markarr[j]<<endl;
            }
            cout<<"Total Marks scored by the Student in "<<student_subject<<" Subjects : "<<total_mark<<endl;
            cout<<"Average Mark of the Student : "<<average_mark<<endl;
            cout<<"Student Grade : "<<grade<<endl;
            cout<<"A-Excellent\tB-Very Good\t<<C-Good\tD-Satisfied\tE-Need Improvement\tF-Fail"<<endl;
        }     
};

int main()
{
    student s[25];
    string s_name;
    size_t size=0;
    int rollno,subarr[5],no_of_sub;

    try
    {
        cout<<"Enter the Number of Students in the Class : "<<endl;
        cin>>size;
        if(size>25)
            throw string{"SizeExceedsException\nEach Class can permit only 25 students"};
        if(size<0)
            throw -1;
            
        for(int i=0; i<size;i++)
        {
            cout<<"Enter the Student Name : "<<endl;
            cin>>s_name;
            cout<<"Enter the Student Roll Number : "<<endl;
            cin>>rollno;
            cout<<"How many subjects did the Student have : "<<endl;
            cin>>no_of_sub;
            if (no_of_sub>5)
                throw string {"ArrayIndexOutOfBoundException\nEach Student have Maximum of 5 Subjects"};
            else if (no_of_sub<0)
                throw -1;
            else if (no_of_sub==0)
                throw string {"Number of Subjects can't be Zero"};
            else
            {
                s[i].set_details(s_name,rollno,no_of_sub);
                s[i].student_progress();
                s[i].print_report();
            }
        }
    }

    catch (string &exception)
    {
        cerr<<exception<<endl;
    }
    
    catch (int &ex)
    {
        cerr<<"NegativeValueException"<<endl;
    }
    return 0;
}