// Name of Author: Vijay Ramakrishna
// ASU ID: 1202948495
// Homework Number: 6
// Description: This program prompts the user to enter two strings of DNA letters or Binary numbers and uses these strings to
//              construct a LCSFunctions class object. The object then validates the strings. If they are found to be invalid, or if the
//              strings are not of the same type, an error  message will be displayed, and the invalid string(s) will be printed with
//              their invalid characters bracketed. If found to be valid, the program then runs the LCS function. It finds the LCS, prints it
//              along with its length, and prints the 2D arrays used to find the LCS and its length.
//              This file is the implementation file for the LCS Functions class.

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include "functions.h"

using namespace std;

// LCS Functions Constructor
// Description: Constructor to initialize an LCS Functions class object
LCSFunctions::LCSFunctions(string mX, string mY)
{
    x = mX;
    y = mY;

}

// Validate
// Description: Checks if the first input is a DNA sequence or Binary sequence by first checking its first character
// then checking its last character, and then checking its middle character, in this order. After determining what type of
// sequence the user has entered, the function calls the appropriate validator, either for DNA sequences or Binary sequences,
// and returns the result of the validator called. If none of the characters checked are valid, will return false. The function
// was structured this way to ensure that the program recognized the user's entering two different types of sequences as inputs as
// invalid.
bool LCSFunctions::validate()
{
    bool validated;
    // Check first character of first input, call appropriate validator if the character is valid
    if (x.substr(0, 1) == "0" || x.substr(0,1) == "1")
    {
        validated = validateBinary();
    }
    else if (x.substr(0,1) == "A" || x.substr(0,1) == "T" || x.substr(0,1) == "G" || x.substr(0,1) == "C" )
    {
        validated = validateDNA();
    }
    else
    {
        // Check last character of first input, call appropriate validator if the character is valid.
        if (x.substr(x.length()-1, 1) == "0" || x.substr(x.length()-1,1) == "1")
        {
            validated = validateBinary();
        }
        else if (x.substr(x.length()-1,1) == "A" || x.substr(x.length()-1,1) == "T" || x.substr(x.length()-1,1) == "G" || x.substr(x.length()-1,1) == "C" )
        {
            validated = validateDNA();
        }
        else
        {
            // Check middle character of first input, call appropriate validator is the character is valid. If not, return false.
            if (x.substr(x.length()/2, 1) == "0" || x.substr(x.length()/2,1) == "1")
            {
                validated = validateBinary();
            }
            else if (x.substr(x.length()/2,1) == "A" || x.substr(x.length()/2,1) == "T" || x.substr(x.length()/2,1) == "G" || x.substr(x.length()/2,1) == "C" )
            {
                validated = validateDNA();
            }
            else
            {
                cout << "Input Type Not Recognized" << endl;
                return false;
            }
        }
    }
    return validated;
}

// Validate Binary
// Description: Checks each character of the two input strings for validity. A valid character will be either a 0 or a 1.
// Stores valid characters in an array, in the index corresponding with their position in the input. If a character is found to be invalid,
// [ and ] will be appended to the left and right side of the character respectively, and the result will be added to the array, in the index
// corresponding with the position of the character in the input. Additionally, the input is flagged as being invalid. If both inputs are valid
// will return true. Otherwise, will print an error message, along with the invalid strings, with invalid characters bracketed, and return false.
bool LCSFunctions::validateBinary()
{
    bool valid1 = true;
    bool valid2 = true;
    string xValidator[x.length()];
    string yValidator[y.length()];

    // Check x's validity
    for (int i = 0; i < x.length(); i++)
    {
        string currentChar = x.substr(i,1);
        if (currentChar != "0" && currentChar != "1") // If character is invalid, highlight and store character and flag x as invalid
        {
            string newLetter = "[" + currentChar + "]";
            xValidator[i] = newLetter;
            valid1 = false;
        }
        else // If character is valid, just store character
        {
            xValidator[i] = currentChar;
        }
    }
    //Check y's validity
    for (int j = 0; j < y.length(); j++)
    {
        string currentChar = y.substr(j,1);
        if (currentChar != "0" && currentChar != "1") // If character is invalid, highlight and store character and flag y as invalid
        {
            string newLetter = "[" + currentChar + "]";
            yValidator[j] = newLetter;
            valid2 = false;
        }
        else // If character is valid, just store character
        {
            yValidator[j] = currentChar;
        }
    }
    if (valid1 == false || valid2 == false) // If either x or y is flagged as being invalid print error message
    {
        cout << "" << endl << "Input Contains Error" << endl << endl;
        cout << "Error in Input 1: ";
        for (int k = 0; k < x.length(); k++)
        {
            cout << xValidator[k];
        }
        cout <<""<<endl;
        cout << "Error in Input 2: ";
        for (int z = 0; z < y.length(); z++)
        {
            cout << yValidator[z];
        }
        cout <<""<<endl;
        return false; // return false if either input is invalid
    }
    return true; // If both inputs are valid, return true
}

// Validate DNA
// Description: Checks each character of the two input strings for validity. A valid character will be an A, T, C,or G.
// Stores valid characters in an array, in the index corresponding with their position in the input. If a character is found to be invalid,
// [ and ] will be appended to the left and right side of the character respectively, and the result will be added to the array, in the index
// corresponding with the position of the character in the input. Additionally, the input is flagged as being invalid. If both inputs are valid
// will return true. Otherwise, will print an error message, along with the invalid strings, with invalid characters bracketed, and return false.
bool LCSFunctions::validateDNA()
{
    bool valid1 = true;
    bool valid2 = true;
    string xValidator[x.length()];
    string yValidator[y.length()];

    // Check x's validity
    for (int i = 0; i < x.length(); i++)
    {
        string currentChar = x.substr(i,1);
        if (currentChar != "A" && currentChar != "T" && currentChar != "C" && currentChar != "G") // If character is invalid, highlight and store character and flag x as invalid
        {
            string newLetter = "[" + currentChar + "]";
            xValidator[i] = newLetter;
            valid1 = false;
        }
        else // If character is valid, just store character
        {
            xValidator[i] = currentChar;
        }
    }
    //Check y's validity
    for (int j = 0; j < y.length(); j++)
    {
        string currentChar = y.substr(j,1);
        if (currentChar != "A" && currentChar != "T" && currentChar != "C" && currentChar != "G") // If character is invalid, highlight and store character and flag y as invalid
        {
            string newLetter = "[" + currentChar + "]";
            yValidator[j] = newLetter;
            valid2 = false;
        }
        else // If character is valid, just store character
        {
            yValidator[j] = currentChar;
        }
    }
    if (valid1 == false || valid2 == false) // If either x or y is flagged as being invalid print error message
    {
        cout << "" << endl << "Input Contains Error" << endl << endl;
        cout << "Error in Input 1: ";
        for (int k = 0; k < x.length(); k++)
        {
            cout << xValidator[k];
        }
        cout <<""<<endl;
        cout << "Error in Input 2: ";
        for (int z = 0; z < y.length(); z++)
        {
            cout << yValidator[z];
        }
        cout <<""<<endl;
        return false; // return false if either input is invalid
    }
    return true; // If both inputs are valid, return true
}

// Longest Common Subsequence
// Description: Gets the length of the two inputs and creates two 2D arrays, b and c, with dimensions dependent on the lengths
// of the two inputs. Populates the first row and first column of c with 0's and then computes and populates the rest of the table
// in row-major order, along with 2D array b, used to trace the optimal solution. Then, calls the Longest Common Subsequence Print
// function to print the LCS, using 2D array b and uses 2D array c to print the length of the LCS. Then, calls C Print and B Print
// functions to print b and c, in that order.
void LCSFunctions::lcs()
{
    //Get String Lengths
    int m = x.length();
    int n = y.length();

    // Create 2D Arrays
    char **b;
    b = new char *[m];
    for (int i=0; i<= m-1; i++)
    {
        b[i] = new char[n];
    }

    int **c;
    c = new int *[m+1];
    for (int j = 0; j<=m; j++)
    {
        c[j] = new int[n+1];
    }

    // Initially Populate 2D Array c
    for (int i = 1; i<=m; i++)
    {
        c[i][0] = 0; // Make all of c's first column equal to 0
    }
    for (int j = 0; j<=n; j++)
    {
        c[0][j] = 0; // Make all of c's first row equal to 0
    }
    // Populate 2D Arrays b and c
    for (int i = 1; i<=m; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            // If the character at position i in x and position j in y are identical
            if(x.substr(i-1,1).compare(y.substr(j-1,1)) == 0)
            {
                c[i][j] = c[i-1][j-1]+1; // c[i][j] = The value of the index directly above it and then directly left + 1
                b[i-1][j-1] = 'D'; //b[i-1][j-1] = Diagonal
            }
            // If the index directly above c[i][j] is greater than or equal to the one directly to its left
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j]; // c[i][j] = The value of the index directly above it
                b[i-1][j-1] = 'U'; //b[i-1][j-1] = Up
            }
            // Otherwise
            else
            {
                c[i][j] = c[i][j-1]; //c[i][j] = The value of the index directly left of it
                b[i-1][j-1] = 'L'; //b[i-1][j-1] = Left
            }
        }
    }
    cout << "" << endl << "The LCS is: ";
    lcsPrint(b, m-1, n-1); // Call Longest Common Subsequence Print function
    cout << "" << endl << "Length = " << c[m][n] << endl; // Print value in bottom right corner of c for length of the LCS
    cPrint(c,m,n); // Call C Print function
    bPrint(b,m,n); // Call B Print function
}

// Longest Common Subsequence Print
// Description: Recursively moves along the b table in order to identify and
// prints the Longest Common Subsequence. Starts in the lower right corner of the table
// and moves according to which way the arrows are pointing. D = Diagonal,
// U = Up, and L = Left.
void LCSFunctions::lcsPrint(char ** b, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return;
    }
    if (b[i][j] == 'D') // Diagonal
    {
        lcsPrint(b,i-1,j-1); // Recursively move to the index directly above the current one and then directly to the left
        cout << x.substr(i,1); // Print character at position i in x
    }
    else if (b[i][j] == 'U') // Up
    {
        lcsPrint(b,i-1,j); // Recursively move to index directly above the current one
    }
    else // Left
    {
        lcsPrint(b,i,j-1); // Recursively move to index directly left of the current one
    }
}

// B Print
// Description: Prints the contents of the b table using a nested loop to iterate through the whole table.
void LCSFunctions::bPrint(char ** b, int xLength, int yLength)
{
    cout << "" << endl << "b Table" << endl;
    for (int i = 0; i <= xLength-1; i++) // For each row
    {
        for (int j = 0; j <= yLength-1; j++) // For each column
        {
            if (j == yLength-1)
            {
                cout << b[i][j] << endl; // If last entry in row, print value in array at current index and a newline
            }
            else
            {
                cout << b[i][j] << " "; // Otherwise print value in array at current index and a space
            }
        }
    }
}

// C Print
// Description: Prints the contents of the c table using a nested loop to iterate through the whole table.
// Adjusts the spacing of the printed table depending on how many digits the Longest Common Subsequence has.
void LCSFunctions::cPrint(int ** c, int xLength, int yLength)
{
    cout << "" << endl << "c Table" << endl;
    for (int i = 0; i <= xLength; i++) // for each row
    {
        for (int j = 0; j <= yLength; j++) // for each column
        {
            if (j == yLength)
            {
                cout << c[i][j] << endl; // If last entry in row, print value in array at current index and a newline
            }
            else
            {
                if (c[xLength][yLength] < 10) // If the LCS is less than 10
                {
                    cout << c[i][j] << " "; // Print value in array at current index and a space
                }
                else if (c[xLength][yLength] >= 10 && c[xLength][yLength] < 100) // If LCS is from 10-99
                {
                    if (c[i][j] < 10) // If value at current index is less than 10
                    {
                        cout << c[i][j] << "  "; // Print value in array at current index and two spaces
                    }
                    else // If value at current index is from 10-99
                    {
                        cout << c[i][j] << " "; // Print value in array at current index and a space
                    }
                }
                else // If the LCS is 100 or more
                {
                    if (c[i][j] < 10)// If value at current index is less than 10
                    {
                        cout << c[i][j] << "   "; // Print value in array at current index and three spaces
                    }
                    else if (c[i][j] >= 10 && c[i][j] < 100) // If value at current index is from 10-99
                    {
                        cout << c[i][j] << "  "; // Print value in array at current index and two spaces
                    }
                    else // If the value at current index is 100 or more
                    {
                        cout << c[i][j] << " "; // Print value in array at current index and a space
                    }
                }
            }
        }
    }
}
