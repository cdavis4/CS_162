//
//  LetterFrequency.hpp
//  
//
//  Created by Carrie Davis on 7/7/18.
//

#ifndef LetterFrequency_hpp
#define LetterFrequency_hpp
class LetterFrequency{
    
private:  //only accessable to the LetterFrequency class
    static const int NUM_ALPHA = 27;  //constant array size
    char alphabetArray[NUM_ALPHA] = {'a','b','c','d','e','f','g','h','i','j','k','l','o','m','n','o','p','q','r',
        's','t','u','v','w','x','y','z'}; // letters in alphabet
    
     void output_letters(ofstream &, int *);
   
public: //function prototypes

    //initalize class
    LetterFrequency();
    void count_letters(ifstream &, int *);
};

#endif /* LetterFrequency_hpp */
