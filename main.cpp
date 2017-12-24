// Name of Author: Vijay Ramakrishna
// ASU ID: 1202948495
// Homework Number: 6
// Description: This program prompts the user to enter two strings of DNA letters or Binary numbers and uses these strings to
//              construct a LCSFunctions class object. The object then validates the strings. If they are found to be invalid, or if the
//              strings are not of the same type, an error  message will be displayed, and the invalid string(s) will be printed with
//              their invalid characters bracketed. If found to be valid, the program then runs the LCS function. It finds the LCS, prints it
//              along with its length, and prints the 2D arrays used to find the LCS and its length.
//              This file is the driver file for the program.

#include <iostream>
#include "functions.h"

using namespace std;

// Main
// Description: Driver to initialize LCS Functions class and run the functions for the class.
// Program will end after running through the Main function once.
int main()
{
    string input1;
    string input2;
    string endMarker = "\r";

    cout << "Enter Two Strings (Both Must Be Sequences of DNA Letters-{A,T,C,G} or Binary Numbers-{0,1} of the Same Type)" << endl; // Get Strings
    cout << "String #1: "; // Get first string
    getline(cin, input1);
    int saveLastPosition1 = input1.size()-1;
    if (saveLastPosition1 >= 0)
    {
        string analyzeCommand1 = input1.substr(saveLastPosition1, 1); //Used to ensure compatibility with both Windows and UNIX machines
        if (analyzeCommand1.compare(endMarker) == 0)
        {
            input1.erase(input1.size()-1);
        }
    }
    cout << "String #2: ";
    getline(cin, input2); // Get second string
    int saveLastPosition2 = input2.size()-1;
    if (saveLastPosition2 >= 0)
    {
        string analyzeCommand2 = input2.substr(saveLastPosition2, 1); //Used to ensure compatibility with both Windows and UNIX machines
        if (analyzeCommand2.compare(endMarker) == 0)
        {
            input2.erase(input2.size()-1);
        }
    }
    LCSFunctions * f = new LCSFunctions(input1, input2); // Create new LCS Functions class object and set its x and y equal to inputs
    bool validStrings = f->validate(); // Validate inputs
    if (validStrings == true)
    {
        f->lcs(); // Call lcs function if both string are valid
    }
    return 0; // exit program
}
