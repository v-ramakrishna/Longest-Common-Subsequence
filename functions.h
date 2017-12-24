// Name of Author: Vijay Ramakrishna
// ASU ID: 1202948495
// Homework Number: 6
// Description: This program prompts the user to enter two strings of DNA letters or Binary numbers and uses these strings to
//              construct a LCSFunctions class object. The object then validates the strings. If they are found to be invalid, or if the
//              strings are not of the same type, an error  message will be displayed, and the invalid string(s) will be printed with
//              their invalid characters bracketed. If found to be valid, the program then runs the LCS function. It finds the LCS, prints it
//              along with its length, and prints the 2D arrays used to find the LCS and its length.
//              This file is the header file for the LCS Functions class.

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>

using namespace std;

//class LCS Functions will store two strings and can call functions to validate, find, and print the Longest Common Substring of these strings
class LCSFunctions
{
private:
    string x;
    string y;

public:
    LCSFunctions(string mX, string mY);
    bool validate();
    bool validateDNA();
    bool validateBinary();
    void lcs(); // Call all Print Functions in here
    void lcsPrint(char ** b, int i, int j);
    void bPrint(char ** b, int xLength, int yLength);
    void cPrint(int ** c, int xLength, int yLength);

};


#endif // FUNCTIONS_H_INCLUDED
