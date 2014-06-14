//
//  BinaryTree.h
//  A representation of a binary search tree using an internal
//  generic linkedlist
//  DataStructures
//
//  Created by Saikat Kanjilal on 1/22/14.
//  Copyright (c) 2014 Saikat Kanjilal. All rights reserved.
//

#ifndef DataStructures_BinaryTree_h
#define DataStructures_BinaryTree_h
#include "LinkedList.h"
template <class T>
class BinaryTree {
    
private:
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode *leftChild;
        BinaryTreeNode *rightChild;
    };
    typedef BinaryTreeNode * binaryTreeNodePtr;
    binaryTreeNodePtr root;
    int sizeOfTree;
    LinkedList<T> * linkedListPtr;
public:
    
    /* Constructor that initializes the root node
     * to be null
     * @param[in] none
     * @return none
     */
    BinaryTree(T);
    
    /* Destructor that calls a helper method to get
     * rid of all the nodes in the tree
     * @param[in] none
     * @return none
     */
    ~BinaryTree();
    
    
    /* A method to add a node to the binary tree
     * we first need to search for where the node
     * needs to exactly go and then perform the insert
     * operation
     * @param[in] the value for the node to be inserted
     * @return none
     */
    void insertNode(T nodeToInsert);
    
    
    /* Find the node we are looking for and return
     * whether or not we found the node
     * @param[in] nodeToFind
     * @return true or false depending on whether or not we found the node
     */
    bool findNode(T nodeToFind);
    
    
    /* Deleting a leaf (node with no children): Deleting a leaf is removing it from the tree.
     * Deleting a node with one child: Remove the node and replace it with its child.
     * Deleting a node with two children: Call the node to be deleted N. Do not delete N. Instead, choose either its in-order successor
     * node or its in-order predecessor node, R. Replace the value of N with the value of R, then delete R.
     * Broadly speaking, nodes with children are harder to delete. As with all binary trees, a node's in-order successor is its right
     * subtree's left-most child, and a node's in-order predecessor is the left subtree's right-most child. In either case, this node will
     * have zero or one children. Delete it according to one of the two simpler cases above.
     * @param[in] nodeToDelete the node that we are trying to delete
     * @return true or false depending on whether we could delete the node
     */
    void deleteNode(T nodeToDelete);
    
    
    /* Return the number of nodes in the binary tree
     * @param[in] none
     * @return the current size of the tree
     */
    int size();
    
    
    /* Return whether or not the current tree is empty
     * this function should simply call sizeOfList
     * @param[in] none
     * @return true or false depending on whether the list is empty
     */
    bool isTreeEmpty();
    
    
    /* Delete all the elements of the tree
     * @param[in] none
     * @return none
     */
    void deleteTree();
    
    
    /* Print the tree using inorder traversal (left-root-right)
     * @param[in] none
     * @return the actual list printed out
     */
    void inorderTraverse();
    
    /* Print the tree using preorder traversal (root-left-right)
     * @param[in] none
     * @return the actual list printed out
     */
    void preorderTraverse();
    
    
    /* Print the tree using inorder traversal (left-right-node)
     * @param[in] none
     * @return the actual list printed out
     */
    void postorderTraverse();
    
};


/* Constructor that initializes the root node
 * to be null
 * @param[in] none
 * @return none
 */
template <class T>
BinaryTree<T>::BinaryTree(T rootVal) {
    linkedListPtr=new LinkedList<T>();
    if (root==NULL) {
        root=new BinaryTreeNode();
        root->data=rootVal;
    }
}


/* Destructor that calls a helper method to get
 * rid of all the nodes in the tree
 * @param[in] none
 * @return none
 */
template <class T>
BinaryTree<T>::~BinaryTree() {
    linkedListPtr->deleteList();
}


/* A method to add a node to the binary tree
 * we first need to search for where the node
 * needs to exactly go and then perform the insert
 * operation
 * @param[in] the value for the node to be inserted
 * @return none
 */
template <class T>
void BinaryTree<T>::insertNode(T nodeToInsert) {
    
    
}


/* Find the node we are looking for and return
 * whether or not we found the node
 * @param[in] nodeToFind
 * @return true or false depending on whether or not we found the node
 */
template <class T>
bool BinaryTree<T>::findNode(T nodeToFind) {
    
}


/* Deleting a leaf (node with no children): Deleting a leaf is removing it from the tree.
 * Deleting a node with one child: Remove the node and replace it with its child.
 * Deleting a node with two children: Call the node to be deleted N. Do not delete N. Instead, choose either its in-order successor
 * node or its in-order predecessor node, R. Replace the value of N with the value of R, then delete R.
 * Broadly speaking, nodes with children are harder to delete. As with all binary trees, a node's in-order successor is its right
 * subtree's left-most child, and a node's in-order predecessor is the left subtree's right-most child. In either case, this node will
 * have zero or one children. Delete it according to one of the two simpler cases above.
 * @param[in] nodeToDelete the node that we are trying to delete
 * @return true or false depending on whether we could delete the node
 */
template <class T>
void BinaryTree<T>::deleteNode(T nodeToDelete) {
    
}


/* Return the number of nodes in the binary tree
 * @param[in] none
 * @return the current size of the tree
 */
template <class T>
int BinaryTree<T>::size() {
    
}


/* Return whether or not the current tree is empty
 * this function should simply call sizeOfList
 * @param[in] none
 * @return true or false depending on whether the list is empty
 */
template <class T>
bool BinaryTree<T>::isTreeEmpty() {
    
}


/* Delete all the elements of the tree
 * @param[in] none
 * @return none
 */
template <class T>
void BinaryTree<T>::deleteTree() {
    
}


/* Print the tree using inorder traversal (left-root-right)
 * @param[in] none
 * @return the actual list printed out
 */
template <class T>
void BinaryTree<T>::inorderTraverse() {
    
}


/* Print the tree using preorder traversal (root-left-right)
 * @param[in] none
 * @return the actual list printed out
 */
template <class T>
void BinaryTree<T>::preorderTraverse() {
    
}

/* Print the tree using inorder traversal (left-right-node)
 * @param[in] none
 * @return the actual list printed out
 */
template <class T>
void BinaryTree<T>::postorderTraverse() {
    
}



#endif
