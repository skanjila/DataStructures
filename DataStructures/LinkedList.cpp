//
//  LinkedList.cpp
//  DataStructures
//
//  Created by Saikat Kanjilal on 1/21/14.
//  Copyright (c) 2014 Saikat Kanjilal. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>
template<class T>
LinkedList<T>::LinkedList(){head = NULL;}

/* Reverse a singly linked list by manipulation
 * of pointers, given a previous pointer
 * current pointer and next pointer
 * iterate through the list
 * and swap the contents of the pointers
 * @param[in] none;
 * @return the new head of the reversed list
 */
template<class T>
Node<T> LinkedList<T>::reverseList() {
    Node<T> * prev;
    prev->next=head;
    Node<T> * curr=head;
    Node<T> * next=head->next;
    while (next!=NULL) {
        curr->next=prev;
        prev=curr;
        curr=curr->next;
        next=next->next;
    }
    return head;
}


/* A method to add a node into the list
 * We return a pointer to this node after insertion
 * @param[in] the string which the node encapsulates
 * @return a pointer to the node which was inserted
*/
template<class T>
void LinkedList<T>::insertNode(T nodeToInsert) {
    Node<T> * curNodeToInsert;
    curNodeToInsert->data=nodeToInsert;
    curNodeToInsert->next=head;
    head=curNodeToInsert;
    sizeOfList++;
}


/* Find the node we are looking for and return
 * a reference to this node
 * @param[in] nodeToFind
 * @return true or false depending on whether or not we found the node
 */
template<class T>
bool LinkedList<T>::findNode(T nodeToFind) {
    Node<T> * tmpPtr=head;
    while (tmpPtr->next!=NULL) {
        std::string contents=tmpPtr->data;
        if (contents.compare(nodeToFind->data)==0) {
            return true;
        }
    }
    return false;
}

/* Delete the node by setting the previous pointer's next
 * element to the next pointer after the current one
 * @param[in] nodeToDelete the node that we are trying to delete
 * @return true or false depending on whether we could delete the node
 */
template<class T>
void LinkedList<T>::deleteNode(T nodeToDelete) {
    Node<T> * tmpPtr=head;
    if (tmpPtr->data.compare(nodeToDelete->data)==0) {
        head=head->next;
    }
    while (tmpPtr!=NULL) {
        if ((tmpPtr->next->data.compare(nodeToDelete->data))) {
            tmpPtr->next=nodeToDelete->next;
        }
    }
}

/* Return the current size of the list
 * @param[in] none
 * @return the current size of the list
 */
template<class T>
int LinkedList<T>::size() {
    return sizeOfList;
}

/* Return whether or not the current list is empty
 * this function should simply call sizeOfList
 */
template<class T>
bool LinkedList<T>::isListEmpty() {
    return true;
}
