//
//  binary_all.cpp
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
    int start;
    cout<<"Enter a number: ";
    cin>>start;
    cout<<"Binary value is 0b";
    
    for(int i = 0; i <= start ; i++) // finds the first power of 2 thats bigger than the starting number
    {
       if((2<<i)>start) // when that power of two is found, the calculations can begin
        {
            while(i>0) // if i = 0, the program freaks out
            {
                i--; // immediately subtract 1. This is because the value of i that gets us into the if statement is one larger than the last power of 2 that is smaller than the starting number (which is the power of 2 we actually want to start with)
                cout<<start / (2<<(i)); // formula for calculating the binary bit
                start %= (2<<(i)); // finds and saves the remainder of the above division; used in next iteration of while loop.
            }
            cout<<(start/1); // final division step. Tried to account for this in above while loop, but solution wouldn't work for a starting number of 0.
            i = start + 1; // ends for loop, as i is now 1 bigger than the value of start
        }
    }

    cout<<endl;
    return 0;
    
}
