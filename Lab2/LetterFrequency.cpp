/********************************************************************
 ** Author: carrie davis
 ** Date:July 7, 2018
 ** Description: Lab 2 ; Letter frequency program
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
#include "LetterFrequency.hpp"

//Default Constructor
LetterFrequency::LetterFrequency()
{

}

/******************************************************
 * LetterFrequency::count_letters
 * counts all the letters in a file
 ********************************************************/
void LetterFrequency::count_letters(ifstream & inStream , int * inArray)
{
    string paragraph;
    string fileName;
    
   getline(inStream, paragraph);
    
    while(inStream)  //checking the # of different letters in the paragraph and adding to array
    {
        cout << paragraph << endl;
        
        for( int i = 1; i < paragraph.length(); i++)
            {
                char letter = paragraph[i];
                letter = tolower(letter);
                
                for( int index = 0; index < NUM_ALPHA; index ++)
                {
                    if (alphabetArray[index] == letter)
                        {
                        inArray[index] += 1;
                        }
                }
           
            }
        //Get output file name from user
        cout << "Please enter your output filename for paragraph." << endl;
        cin >> fileName;
        
        ofstream outputFile(fileName);
        
        // error checking
        int count;
        while((outputFile.fail()) && count!=6)
        {
            count++;
            cout << "Could not open file. Please try again." <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Could not create data stream.";
            cout << "Enter File Name: ";
            cin >> fileName;
            ofstream outputFile(fileName);
        }
        
        //write output from paragraph
        output_letters(outputFile, inArray);
        
        //get next paragraph
        getline(inStream,paragraph);
    }
   
}

/******************************************************
 * LetterFrequency::output_letters
 * outputs results in new file
 ********************************************************/
void LetterFrequency::output_letters(ofstream & outStream , int * inArray)
{
    //puts data into text file for each letter and # of times used
    for( int index = 0; index < NUM_ALPHA; index++ )
            {
                outStream << alphabetArray[index] << ": " << inArray[index] << endl;
            }
     outStream.close();
    
    //resets array values to 0
    for (int i=0; i < NUM_ALPHA; i++)
        {
         inArray[i] = 0;
        }
}


