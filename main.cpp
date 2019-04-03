// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 * howMany()'s goal is to find the US population in one year from now. We are provided with a few bits of data.
a. There is a birth every 8 seconds
b. There is a death every 12 seconds
c. There is a new immigrant every 33 seconds

My function sets all these values to ints, as well as defines how many seconds are in a year. Using this data,
it calculates how many babies are born, people are killed, and immigrants have migrated into the US in a year.
Then it simply adds the births, immigrants, and current population, then subtracts the deaths, to find the
new population in a year.
 *
 */
int howMany(int cPop) {

    int birthR = 8;
    int deathR = 12;
    int immR = 33;
    int yearSecs = 31536000;

    int birthYr =
        yearSecs / birthR;

    int deathYr =
        yearSecs / deathR;

    int immYr =
        yearSecs / immR;

    int newPop =
        (birthYr+immYr+cPop)-deathYr;

    return newPop;
}

/**
 * givenSec equals the amount of seconds, between 0-1000000, given.
 An if statement makes sure that numbers outside of this range won't work.
 The point of this function is to covert seconds into a day/hour/min/
 sec format. It does so with the following steps:
 -finds days, sets it to variable.
 -finds remainder of days, then converts to hours, sets it to variable.
 -finds remainder of hours, then converts to mins, sets it to variable.
 -finds remainder of mins, then converts to secs, sets it to variable.
 -outputs the variables along with a string of text to make it understandable.
 We have to find remainders because ints truncate.
 *
 */
void howLong(int givenSec) {

    int daySec=0;
    int hourSec=0;
    int minSec=0;
    int secSec=0;

    if(givenSec<=1000000 && givenSec>=0){

    daySec =
        givenSec / 86400;

    hourSec =
        (givenSec % 86400) / 3600;

    minSec =
        ((givenSec % 86400) % 3600) / 60;

    secSec =
        (((givenSec % 86400) % 3600) % 60);
    }

    cout<<"Time is "<<daySec<<" days, "<<hourSec<<" hours, "<<minSec<<" minutes, and "
    <<secSec<<" seconds."<< endl;
    return;

}

/**
 * This function is actually pretty simple.
 We were given an equation that converted Fahrenheit to Celsius,
 so I algebraically reversed it, then plugged it into the program.
 We're given Celsius (collected as int), and then it is put it into
 the equation, which the answer is set to a new int, the Fahrenheit
 variable. Then that variable is returned.
 */
int howHot(int cTemp) {
    int fTemp =
        ((cTemp*9.0)/5) + 32;
    return fTemp;
}


int main() {
    // Problem 1 test
    // Change value of 'pop' to change value you want to test
    int pop = 1000000;
    cout << "Given the initial population of " << pop;
    cout << " your estimation finds a population of ";
    cout << howMany(pop) << endl << endl;

    // Problem 2 test
    // Change value 'sec' to change value you want to test
    int sec = 70000;
    cout << "Given the seconds value of " << sec;
    cout << " your output is: " << endl;
    howLong(sec);
    cout << endl;

    // Problem 3 test
    // Change value 'temp' to change value you want to test
    int temp = 20;
    cout << "Given temperature " << temp;
    cout << " degrees Celsius you calculate ";
    cout << howHot(temp) << " degrees Fahrenheit" << endl;
    return 0;
}
