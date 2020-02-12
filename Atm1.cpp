#include<bits\stdc++.h>

using namespace std;

//Global Variables
double initialAmount = 10000;
int notes_2000 = 1000;
int notes_500 = 1000;
int notes_100 = 1000;

//Functions
bool stringEqual( char str1[],char str2[]);
void logIn();
void menu();
void withdraw();
void deposit();
void balanceInquiry();
void remainingCash();

//Function body
bool stringEqual( char str1[], char str2[])
{
	int i;
	for( i = 0; str1[i] !='\0' || str2[i] != '\0'; i++)
	{
		if( str1[i] != str2[i])
			return false;
	}
	return true;
}
void logIn()
{
	char correctUsername[30] = "12345678";
	char correctPassword[30] = "1893";
	char username[30];
	char password[30];
	cout << "Enter Card_Number:";
	cin >> username;
	if (stringEqual(correctUsername, username) )
    {
		cout << "Enter password: ";
		cin >> password;
		if (stringEqual(correctPassword, password))
		{
			menu();
		}
		else
			cout << "Invalid password";
	}
	else
		cout << "Invalid Card Number !!";
}
void menu()
{
	int choice;
	cout<<"***********Menu************"<<endl;
	cout << "1.Withdrawal" << endl;
	cout << "2.Deposit" << endl;
	cout << "3.Balance Inquiry" << endl;
	cout << "4.Remaining Cash" << endl;
	cout << "5.Exit" << endl << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
		    withdraw();
            break;
		case 2:
		    deposit();
            break;
		case 3:
		    balanceInquiry();
            break;
        case 4:
            remainingCash();
            break;
        case 5:
		    cout << "Thank you. Have a nice day!";
            break;
        default:
            cout<<"Invalid Choice !!";
            break;
	}
}
void remainingCash()
{
    cout<<"Number of 2000 notes : "<<notes_2000<<endl;
    cout<<"Number of 500 notes : "<<notes_500<<endl;
    cout<<"Number of 100 notes : "<<notes_100<<endl;
    menu();
}
void withdraw()
{
	double withdrawAmount;
	cout << "Enter Amount : ";
	cin >> withdrawAmount;
	if(int(withdrawAmount) % 100 == 0 && withdrawAmount <= 20000)
    {
        if(withdrawAmount > initialAmount)
        {
            cout<<"Invalid Amount"<<endl;
        }
        else
        {
            int number_2000,number_500,number_100,remainingAmount = withdrawAmount;


            number_2000 = remainingAmount/2000;
            if(notes_2000 != 0 && number_2000 <= notes_2000)
            {
                remainingAmount -= number_2000 * 2000;
                notes_2000 = notes_2000 - number_2000;
            }
            else if(notes_2000 != 0 && number_2000 > notes_2000)
            {
                remainingAmount -= notes_2000 * 2000;
                number_2000 = notes_2000;
                notes_2000 = 0;
            }
            else
            {
                number_2000 = 0;
            }

            number_500 = remainingAmount/500;
            if(notes_500 != 0 && number_500 <= notes_500)
            {
                remainingAmount -= number_500 * 500;
                notes_500 = notes_500 - number_500;
            }
            else if(notes_500 != 0 && number_500 > notes_500)
            {
                remainingAmount -= notes_500 * 500;
                number_500 = notes_500;
                notes_500 = 0;
            }
            else
            {
                number_500 = 0;
            }

            number_100 = remainingAmount/100;
            if(notes_100 != 0 && number_100 <= notes_100)
            {
                remainingAmount -= number_100 * 100;
                notes_100 = notes_100 - number_100;
            }
            else if(notes_100 != 0 && number_100 > notes_100)
            {
                remainingAmount -= notes_100 * 100;
                number_100 = notes_100;
                notes_100 = 0;
            }
            else
            {
                number_100 = 0;
            }
            if(remainingAmount == 0)
            {
                initialAmount = initialAmount - withdrawAmount;
                cout<<"Current Balance is : "<<initialAmount<<endl;
            }
            else
            {
                cout<<"Cash Not Available."<<endl;
            }
        }
    }
    else
    {
        cout<<"Invalid Amount !!"<<endl;
    }
	menu();
}
void deposit()
{
	double depositAmount;
	int note_2000,note_500,note_100,total=0;
	cout << "Enter deposit amount: ";
	cin >> depositAmount;


	cout<<"Enter Number of notes of 2000.:"<<endl;
	cin>>note_2000;
	total += note_2000*2000;

	cout<<"Enter Number of notes of 500.:"<<endl;
	cin>>note_500;
	total += note_500*500;

	cout<<"Enter Number of notes of 100.:"<<endl;
	cin>>note_100;
	total += note_100 * 100;

	if(total == depositAmount)
    {
        initialAmount = initialAmount + depositAmount;
        notes_2000+=note_2000;
        notes_500+=note_500;
        notes_100+=note_100;
        cout << "Your current balance is $"<< initialAmount << endl << endl;
    }
    else
    {
        cout<<"Invalid Amount";
    }
	menu();
}
void balanceInquiry()
{
	cout << "Your current balance is "<< initialAmount << endl << endl;
	cout << "What do you want to do next?" << endl << endl;
	menu();
}
//Main Program start from here
int main()
{
	cout << "*****Welcome to ATM Simulator*****" << endl << endl;
	logIn();
	return 0;
}
