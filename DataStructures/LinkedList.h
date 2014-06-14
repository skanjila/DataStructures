// A simple implementation of a singly linked list, typical operations
// include reverseList, findNode, deleteNode
//  LinkedList.h
//  DataStructures
//
//  Created by Saikat Kanjilal on 1/21/14.
//  Copyright (c) 2014 Saikat Kanjilal. All rights reserved.
//
#ifndef __DataStructures__LinkedList__
#define __DataStructures__LinkedList__
template <class T>
class LinkedList {
private:
    class Node{
    public:
        T data;
        Node * next;
    };
    typedef Node * nodePtr;
    nodePtr head;
    int sizeOfList;
public:
    
    /* Constructor that initializes the head pointer
     * to be null
     * @param[in] none
     * @return none
    */
    LinkedList();
    
    /* Destructor that calls a helper method to get
     * rid of all the elements in the list
     * @param[in] none
     * @return none
    */
    ~LinkedList();
    
    
    /* A method to add a node into the list
     * We return a pointer to this node after insertion
     * @param[in] the value for the node to be inserted
     * @return none
    */
    void insertNode(T nodeToInsert);
    
    
    /* Reverse a singly linked list by manipulation
     * of pointers, given a previous pointer
     * current pointer and next pointer
     * iterate through the list
     * and swap the contents of the pointers
     * @param[in] none;
     * @return none
     */
    void reverseList();
    
    
    /* Find the node we are looking for and return
     * a reference to this node
     * @param[in] nodeToFind
     * @return true or false depending on whether or not we found the node
    */
    bool findNode(T nodeToFind);
    
    
    /* Delete the node by setting the previous pointer's next
     * element to the next pointer after the current one
     * @param[in] nodeToDelete the node that we are trying to delete
     * @return true or false depending on whether we could delete the node
    */
    void deleteNode(T nodeToDelete);
    
    
    /* Return the current size of the list
     * @param[in] none
     * @return the current size of the list
    */
    int size();
    
    
    /* Return whether or not the current list is empty
     * this function should simply call sizeOfList
     * @param[in] none
     * @return true or false depending on whether the list is empty
    */
    bool isListEmpty();
    
    
    /* Delete all the elements of the list
     * @param[in] none
     * @return none
    */
    void deleteList();
    
    
    /* Print the list's contents
     * @param[in] none
     * @return the actual list printed out
    */
    void printList();
    
    
};


template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    sizeOfList=0;
}


/* Delete all the elements of the list
 * @param[in] none
 * @return none
 */
template <class T>
void LinkedList<T>::deleteList() {
    nodePtr tmp=head;
    while (tmp!=nullptr) {
        deleteNode(tmp->data);
    }
}


/* Reverse a singly linked list by manipulation
 * of pointers, given a previous pointer
 * current pointer and next pointer
 * iterate through the list
 * and swap the contents of the pointers
 * @param[in] none;
 * @return the new head of the reversed list
 */
template<class T>
void LinkedList<T>::reverseList() {
    nodePtr prevRef;
    nodePtr currRef=head;
    nodePtr nextRef;
    if (head==NULL) {
        return;
    }
    while (currRef!=NULL) {
        nextRef=currRef->next;
        currRef->next=prevRef;
        prevRef=currRef;
        currRef=nextRef;
    }
    head=prevRef;
}


template<class T>
LinkedList<T>::~LinkedList(){
    deleteList();
}

/* A method to add a node into the list
 * We return a pointer to this node after insertion
 * @param[in] the string which the node encapsulates
 * @return a pointer to the node which was inserted
 */
template<class T>
void LinkedList<T>::insertNode(T nodeToInsert) {
    nodePtr curNodeToInsert=new Node();
    if (curNodeToInsert!=nullptr) {
        curNodeToInsert->data=nodeToInsert;
        curNodeToInsert->next=head;
        head=curNodeToInsert;
    }
    sizeOfList++;
}


/* Find the node we are looking for and return
 * a reference to this node
 * @param[in] nodeToFind
 * @return true or false depending on whether or not we found the node
 */
template<class T>
bool LinkedList<T>::findNode(T nodeToFind) {
    nodePtr tmpPtr=head;
    while (tmpPtr!=NULL) {
        T contents=tmpPtr->data;
        if (contents.compare(nodeToFind)==0) {
            return true;
        }
        tmpPtr=tmpPtr->next;
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
    nodePtr tmpPtr=NULL;
    if (head==NULL) {
        return;
    } else {
        tmpPtr=head;
    }
    if (tmpPtr->data.compare(nodeToDelete)==0) {
        head=head->next;
        if (tmpPtr!=NULL) {
            delete tmpPtr;
        }
        sizeOfList--;
        return;
    }
    while (tmpPtr!=NULL) {
        if ((tmpPtr->next->data.compare(nodeToDelete))==0) {
            nodePtr nodeToDelete = tmpPtr->next;
            tmpPtr->next=nodeToDelete->next;
            delete nodeToDelete;
            sizeOfList--;
        }
        tmpPtr=tmpPtr->next;
    }
}


/* Print the list's contents
 * @param[in] none
 * @return the actual list printed out
 */
template<class T>
void LinkedList<T>::printList() {
    nodePtr tmpPtr=head;
    while (tmpPtr!=NULL) {
        std::cerr<<tmpPtr->data<<std::endl;
        tmpPtr=tmpPtr->next;
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
    return (sizeOfList==0);
}


#endif /* defined(__DataStructures__LinkedList__) */
