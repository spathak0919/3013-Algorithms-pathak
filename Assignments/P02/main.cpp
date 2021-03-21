/*************************************************************
*                                                            *
*   Author  : Sandesh pathak                                 *
*   E-mail  : spathak0919@my.msutexas.edu                    *
*   Program : P02                                            *
*   Course  : Advanced Algorithms 3013                       *
*                                                            *
**************************************************************/

#include "getch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include "find.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


typedef std::vector<std::string> vs;


int main()
 {
    char k;                // initialize character as l
    string word = "";      // var for letters
    vs wordList;           // Location  
    vs matches;            // Matches found 
    LINKEDLIST dictionary;

      // file open
    ifstream fin;           
    ofstream fout;       

    fin.open("dictionary.txt");

    Timer timer;   // create an object timer
    timer.Start(); 

    while(!fin.eof())
    {
        
        std::string tempWord;
        fin >> tempWord;

        wordList.push_back(tempWord);

    }

    timer.End(); // end the current timer

    
    std::cout << "It took " << timer.Seconds() << " seconds to read in the data" << std::endl;
    std::cout << "It took " << timer.MilliSeconds() << " milliseconds to read in the data" << std::endl<<endl;

    std::cout << "Type any keys or Type capital 'Z' to quit." << std::endl<<endl;

    // start timer

    timer.Start();      

    
    for (int i = 0; i < wordList.size(); i++)
    {
        wordNode* temp = new wordNode;
        temp->word = wordList[i];
        dictionary.insert(temp);
    }

    timer.End(); // end the current timer

    // print out how long it took to load the linked list dictionary
    std::cout << "It took " << timer.Seconds() << " seconds to read in the data" << std::endl;
    std::cout << "It took " << timer.MilliSeconds() << " milliseconds to read in the data" << std::endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z')
    {
        
        // Tests for a backspace and if pressed deletes
        
        if ((int)k == 127 || k == 8)
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }else
        {
            // For only a letter

            if (!isalpha(k))
            {
                std::cout << "Letters only!" << std::endl;
                continue;
            }

            // For lowercase.
            // Any letter with ascii value < 97 is capital so we
            
            if ((int)k < 97)
            {
                k += 32;
            }
            word += k; // append char to word
        }

        //  Any animals in the array that half match
       
        timer.Start(); // start it
        matches = dictionary.search(word);
        timer.End(); // end the current timer

        std::cout << timer.Seconds() << " seconds to read in and print" << std::endl;
        std::cout << timer.MilliSeconds() << " milli to read in and print" << std::endl;

        if (word == "")
        {
          // If "word" is empty, do not print the dictionary
          // value k
        }else if ((int)k != 32) 
        { 
           

            std::cout << "Keypressed: " << termcolor::on_yellow << termcolor::blue << k << " = " << (int)k << termcolor::reset << std::endl;
            std::cout << "Current Substr: " << termcolor::red << word << termcolor::reset << std::endl;
            std::cout << "Word found: ";
            std::cout << termcolor::green;
            
            // print all 

            for (int i = 0; i < matches.size(); i++) {
                std::cout << matches[i] << " ";
            }
            std::cout << termcolor::reset << std::endl
                 << std::endl;
        }

    }

    return 0;
}
