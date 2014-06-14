//
//  main.cpp
//  DataStructures
//
//  Created by Saikat Kanjilal on 1/21/14.
//  Copyright (c) 2014 Saikat Kanjilal. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;
#include "LinkedList.h"
#include "BinaryTree.h"
char * reverseNullTerminatedString(char *);
bool containsUniqueChars(char *);
#define useCase 2
int main(int argc, const char * argv[])
{

    if (useCase==1) {
    // insert code here...
        std::cout << "Hello, World!\n";
        char fool[]={'s','a','i','k','a','t',0};
        reverseNullTerminatedString(fool);
    
        std::cerr<<"The result is "<<fool<<std::endl;
        if (containsUniqueChars(fool)) {
            std::cerr<<"The string contains unique characters";
        } else {
            std::cerr<<"The string does not contain unique characters";
        }
    } else if (useCase==2) {
    
        //create the list
        LinkedList<string> myList;
    
        //test the insert
        string nodeToInsert="testMe";
        myList.insertNode(nodeToInsert);
        string nodeToInsertAgain="testMeAgain";
        myList.insertNode(nodeToInsertAgain);
        string nodeToInsertAgainAndAgain="testMeAgainAndAgain";
        myList.insertNode(nodeToInsertAgainAndAgain);
    
        //test node retrieval
        std::cerr<<"The size of the list is "<<myList.size()<<std::endl;
        if (myList.findNode(nodeToInsert)) {
            std::cerr<<nodeToInsert<<" was found in the list"<<std::endl;
        } else {
            std::cerr<<nodeToInsert<<" was not found in the list"<<std::endl;
        }
        std::string falseNodeToInsert="notfound";
        if (myList.findNode(falseNodeToInsert)) {
            std::cerr<<falseNodeToInsert<<" was found in the list"<<std::endl;
        } else {
            std::cerr<<falseNodeToInsert<<" was not found in the list"<<std::endl;
        }
    
        std::cerr<<"Printing initial list"<<endl;
        myList.printList();
        
        std::cerr<<"About to reverse the list"<<endl;
        myList.reverseList();
        myList.printList();
    
        std:cerr<<"About to delete the node called testMe"<<endl;
        myList.deleteNode(nodeToInsert);
    
        //print the list
        std::cerr<<"After deleting the size of the list is "<<myList.size()<<std::endl;
        myList.printList();
    } else if (useCase==3) {
    
        BinaryTree<string> binaryTree("foo");
    }
    return 0;
}

/**
 * Simple function to reverse a null terminated string
 * @param[in] stringToReverse the input string
 * @return the null terminated string
*/
char * reverseNullTerminatedString(char * stringToReverse) {
    if (stringToReverse==NULL) {
        return NULL;
    } else if (strlen(stringToReverse)==1) {
        return stringToReverse;
    }
    int i=0;
    char tmp;
    unsigned long lengthOfStr=strlen(stringToReverse)-1;
    while (i<=lengthOfStr) {
        tmp=stringToReverse[i];
        stringToReverse[i]=stringToReverse[lengthOfStr];
        stringToReverse[lengthOfStr]=tmp;
        i++;
        lengthOfStr--;
    }
    return stringToReverse;
}

/** Simple function to determine whether or not
 * a string contains unique characters, uses an additional
 * data structure which could be simplified out
 * @param[in] the string to check for uniqueness
 * @return true or false depending on whether or not a string contains unique characters
*/
bool containsUniqueChars(char * string) {
    if (string==NULL) {
        return NULL;
    }
    std::set<char> mySet;
    for (int i=0;i<strlen(string);i++) {
        mySet.insert(string[i]);
    }
    //std::cerr<<"The size of the set="<<mySet.size()<<std::endl;
    //std::cerr<<"The size of the string="<<strlen(string)<<std::endl;
    if (mySet.size()==strlen(string)) {
        return true;
    }
    return false;
    
}

