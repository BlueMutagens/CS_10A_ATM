//
//  atm.cpp
//  Homework7
//
//  Created by Sean Belingheri on 10/13/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string const pin = "1065";
    string pinenter;
    int option;
    float balance = 100, moneymove;
    int i = 0, a = 0;
    
    cout<<"Enter PIN number: "; //first attempt is unique, so sits outside the loop
    cin>>pinenter;
    cin.ignore();
    
    while(i<3)
    {
       if(pin != pinenter && i == 2) // activates when wrong pin is entered a 3rd time, iterating i above the condition, ending the loop
       {
           cout<<"Wrong PIN. Ending session.";
           i++;
       }
        
       else if(pin != pinenter) // activates when wrong pin is entered, but only twice before above happens
       {
           cout<<"Wrong PIN. Try again: ";
           cin>>pinenter;
           cin.ignore();
           i++;
       }
        
       else
       {
           cout<<"Welcome!\n1. Withdraw\n2. Deposit\n3. Check Balance\n4. Exit\n";
           cout<<"Please select your option: ";
           cin>>option;
           cin.ignore();
           
           switch(option)
           {
               case 1:
               {
                   while(a<1) //while loop allows for amounts exceeding the balance to be entered indefinitely. the loop only breaks when a value <= the balance is entered
                   {
                       cout<<"Amount to withdraw ($): ";
                       cin>>moneymove;
                       cin.ignore();
                       if(moneymove <= balance)
                       {
                           balance -= moneymove;
                           cout<<"Your balance is now $"<<balance<<endl;
                           cout<<"Press enter to continue";
                           cin.get();
                           a++;
                       }
                       else
                       {
                           cout<<"Withdrawal amount exceeds balance! Available balance is $"<<balance<<endl;
                       }
                   }
                   break;
               }
               case 2:
               {
                   cout<<"Amount to deposit ($): ";
                   cin>>moneymove;
                   cin.ignore();
                   balance += moneymove;
                   cout<<"Your balance is now $"<<balance<<endl;
                   cout<<"Press Enter to continue";
                   cin.get();
                   break;
               }
               case 3:
               {
                   cout<<"Your current balance is $"<<balance<<endl;
                   cout<<"Press Enter to continue";
                   cin.get();
                   break;
               }
               case 4:
               {
                   i = 3; //breaks the parent while loop. All other cases lack this line, allowing the program to run until the user selects option 4
                   cout<<"Have a nice day!";
                   break;
               }
           }
       }
    }
    
    cout<<endl;
    return 0;
}

