#include<iostream>
#include<string>
#include<cstdlib>
#include "Bank_Account.h"
using namespace std;

class bank
{
    protected:
        string bank_name,branch_name,IFSC_code;

    public:
        void set_bankdetails(string b_name,string branch,string f_code)
        {
            bank_name=b_name;
            branch_name=branch;
            IFSC_code=f_code;
        }
    
};

class customer : public bank
{
    string customer_name;
    int age_limit;
    double account_number,amount,balance;

    public:
        void set_customerdetails(string c_name,double acc_no,int age,double remaining_balane)
        {
            customer_name=c_name;
            account_number=acc_no;
            age_limit=age;
            balance=remaining_balane;
        }

        double deposit_amount()
        {
            cout<<"Enter the amount to Deposit : "<<endl;
            cin>>amount;
            if(amount<0)
                throw NegativeValueException{};
            if(amount==0)
                throw 0;
            return (balance+=amount);
        }

        double withdraw_amount()
        {
            cout<<"Enter the amount to Withdraw : "<<endl;
            cin>>amount;
            if(amount<0)
                throw NegativeValueException{};
            return (balance-=amount);
        }    

};

int main()
{
    string b_name,c_name,f_code,branch;
    int age,choice;
    double acc_no,remaining_balane{500.00};

    try
    {
        cout<<"Enter your Bank Name : "<<endl;
        cin>>b_name;
        cout<<"Enter the Bank Branch Name : "<<endl;
        cin>>branch;
        if(b_name.length() >25 || branch.length() >15)
            throw NameSizeOutOfBoundException{};
        cout<<"Enter the IFSC Code : "<<endl;
        cin>>f_code;
        if(f_code.length() >10)
            throw CodeSizeOutOfBoundException{};

        cout<<"Enter your Name : "<<endl;
        cin>>c_name;
        if(c_name.length() >20)
            throw NameSizeOutOfBoundException{};
        cout<<"Enter your Account Number : "<<endl;
        cin>>acc_no;
        cout<<"Enter your Age : "<<endl;
        cin>>age;
        if(age<18)
            throw IllegalAgeLimitException {};
        cout<<"1.To Deposit the Money.\n2.To Withdraw the Money.\n3.To Check the Balance in the Account."<<endl;

        cout<<"Choose the option to continue further process : "<<endl;
        cin>>choice;

        customer c1;
        c1.set_bankdetails(b_name,branch,f_code);
        c1.set_customerdetails(c_name,acc_no,age,remaining_balane);

        switch(choice)
        {
            case 1:
                remaining_balane = c1.deposit_amount();
                cout<<"Your amount has been deposited into Account "<<acc_no<<" : "<<endl;
                cout<<"Account Balance : "<<remaining_balane<<endl;
                break;
            case 2:
                remaining_balane = c1.withdraw_amount();
                cout<<"The amount has been withdrawn from your Account "<<acc_no<<" : "<<endl;
                cout<<"Account Balance : "<<remaining_balane<<endl;
                break;
            case 3:
                cout<<"Your Account Balance : "<<remaining_balane<<endl;
        }
    }

    catch(int &e)
    {
        cerr<<"Depositing / Withdrawing on zero amount is un senseable operation."<<endl;
    }

    catch(const NameSizeOutOfBoundException &e)
    {
        cerr<<"Invalid !\nLength of the Name shouldn't be exceeds more than 25."<<endl;
    }

    catch(const CodeSizeOutOfBoundException &e)
    {
        cerr<<"Invalid IFSC Code !\nIFSC Code can't be more than 10 digits."<<endl;
    }

    catch(const IllegalAgeLimitException &e)
    {
        cerr<<"Invalid !\nAge of the Customer should be more than or equals to 18."<<endl;
    }

    catch(const NegativeValueException &e)
    {
        cout<<"Invalid Input ! \nAmount value can't be negative."<<endl;
    }
    return 0;
}