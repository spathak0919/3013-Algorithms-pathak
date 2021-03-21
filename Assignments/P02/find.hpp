#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


typedef std::vector<std::string> vs;


struct wordNode
{
    wordNode* Next;
    std::string word;

    wordNode()
    {
        Next = NULL;
        word = "";
    }

};

/**********************************************************************
***********************************************************************
*                                                                     *
* LINKEDLIST                                                          *
*                                                                     *
* Description:  Node structure for a linked list                      *
*                                                                     *
*                                                                     *
* Private Methods:  None                                              *
*                                                                     *
*                                                                     *
* Public Methods:                                                     *
*        LINKEDLIST                                                   *
*        getSize                                                      *
*        insert                                                       *
*        print                                                        *
*                                                                     *
***********************************************************************
**********************************************************************/


class LINKEDLIST
{
    protected:
        wordNode* head;       
        wordNode* tail;
        int size;           //get size


    public:

    /**********************************************************************
    *                                                                     *
    * LINKEDLIST                                                          *
    *                                                                     *
    * Description:                                                        *
    *        Default Constructor                                          *
    *        Node structure for a linked list, created using our struct   *
    *                                                                     *
    * Method Variables:                                                   *
    *        head                                                         *
    *        tail                                                         *
    *        size                                                         *
    *                                                                     *
    * Use:                                                                *
    *   Create a linked list within our class                             *
    *                                                                     *
    **********************************************************************/

        LINKEDLIST()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        /*******************************************************************
        *                                                                  *
        * print                                                            *
        *                                                                  *
        * Description:                                                     *
        *        Prints the linked list                                    *
        *                                                                  *
        * Method Variables:                                                *
        *        None                                                      *
        *                                                                  *
        * Return:                                                          *
        *   NULL                                                           *
        *                                                                  *
        *******************************************************************/

        void print()
        {
        
            wordNode* current = head;
        
            while (current)
            {
                std::cout << current->word;   
                std::cout << std::endl;
                current = current->Next;      
            }
        
        }
         /*******************************************************************
        *                                                                  *
        * insert                                                           *
        *                                                                  *
        * Description:                                                     *
        *        Adds a word to the linked list                            *
        *                                                                  *
        * Method Variables:                                                *
        *        None                                                      *
        *                                                                  *
        * Return:                                                          *
        *   NULL                                                           *
        *                                                                  *
        *******************************************************************/

        void insert(wordNode* word)
        {
            if (!head)
            {
                head = tail = word;
            }else
            {
                tail->Next = word;
                tail = word;
            }

            size++;
        }

        /*******************************************************************
        *                                                                  *
        * getSize                                                          *
        *                                                                  *
        * Description:                                                     *
        *        Gets the size of the linked list                          *
        *                                                                  *
        * Method Variables:  None used                                     *
        *                                                                  *
        *                                                                  *
        * Return: size                                                     *
        *                                                                  *
        *                                                                  *
        *******************************************************************/

        int getSize()
        {
            return size;
        }

        /*******************************************************************
        *                                                                  *
        * search                                                           *
        *                                                                  *
        * Description:                                                     *
        *        searches through the liked list to find a matching word   *
        *                                                                  *
        * Method Variables:                                                *
        *        vector <string> (vs) results                              *
        *                                                                  *
        * Return:                                                          *
        *   vector <string> (vs) results                                   *
        *                                                                  *
        *******************************************************************/

        vs search(std::string userInput)
        {
            std::cout << "Searching" << std::endl;

           vs results;
           wordNode* current = head;
        
            while (current)
                {
                    std::string found = "";

                   found = current->word;

                    int length = userInput.length();

                    if (found.substr(0, length) == userInput)
                    {
                        results.push_back(found);
                    }
                    current = current->Next;
                }
            return results;
        }
};
