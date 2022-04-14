#include<iostream>
#include<string>
using namespace std;

double labour_salary(int total_days,int leave_days)
{
    int working_days;
    if (total_days>31 || leave_days>31)
        throw string {"Total or Leave days can't be exceed more than 31 days"};
    else if (total_days<0 || leave_days<0)
        throw -1;
    else if (total_days==0)
        throw string {"Total days in a month can't be zero"};
    else
    {
        working_days=total_days-leave_days;
        return (working_days*450.50);
    }
}

int main()
{
    string name;
    int id,total_days,leave_days;
    double salary;

    cout<<"\nEnter the labour Name : "<<endl;
    cin>>name;
    cout<<"Enter the labour ID : "<<endl;
    cin>>id;
    cout<<"Total Days in this month : "<<endl;
    cin>>total_days;
    cout<<"Leave Days of the labour "<<name<<" in this month : "<<endl;
    cin>>leave_days;
    try
    {
        salary=labour_salary(total_days,leave_days);
        cout<<"The salary for the labour "<<name<<" of this month : "<<salary<<endl;
    }
    
    catch(string &errormessage)
    {
        cerr<<errormessage<<endl;
    }
    catch(int &n)
    {
        cerr<<"NegativeValueException"<<endl;
    }
    return 0;
}