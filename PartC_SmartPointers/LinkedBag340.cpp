//
//  LinkedBag340.cpp
//  LinkedBag
//
//  Created by Danish Siddiqui on 11/02/19.
//  Copyright © 2019 Danish Siddiqui. All rights reserved.
//

#include<iostream>
#include<ctime>
#include<cstddef>
#include<cstdlib>
#include"LinkedBag.h"

// Remove the second node
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340()
{
    shared_ptr<Node<ItemType>> secondNode = headPtr->getNext(); //gets the pointer to second node
    shared_ptr<Node<ItemType>> thirdNode = secondNode->getNext(); //gets the pointer to the third node
    headPtr->setNext(thirdNode); //links headPtr to third node
    secondNode->setNext(nullptr); //sets second node to null to isolate it
    return remove(secondNode->getItem()); //deletes the second node
}

// Add a node to the end of the linked list
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry){
    unique_ptr<Node<ItemType>> tempPtr = make_unique<Node<ItemType>>(); //creating new last node

    tempPtr->setItem(newEntry);
    tempPtr->setNext(nullptr); //making Ptr the last node that is to be added
    shared_ptr<Node<ItemType>> Ptr = headPtr;
    if(headPtr==nullptr) //check if list is empty
    {
        headPtr = move(tempPtr);
        return 0;
    }
    while (Ptr->getNext()!=nullptr) //traverse until we get to the last node
    {
        Ptr = Ptr->getNext();
    }
    Ptr->setNext(move(tempPtr)); //link last node to new node at the end
    itemCount++; //increase the list size by 1
    return true;
}

//gets the size of linked list iteratively
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const{
    int counter = 0;
  shared_ptr<Node<ItemType>> tempPtr = headPtr;
    while (tempPtr!=nullptr){  //traverse the list till the end
        counter++;             //increase counter by one
        tempPtr = tempPtr->getNext();
    }
    return counter;
}

//counts the number of nodes in list using indirect recursion
//this method calls the helper funtion
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    Node<ItemType> *tempPtr = headPtr.get(); //get function is the back door for shared pointer headPtr
    int counter;
    //base case
    if(tempPtr==nullptr) //if list is empty
    {
        tempPtr = headPtr.get();
        return 0;
    }
    else{
        //recursive case
        tempPtr= tempPtr->getNext().get();
        counter = getCurrentSize340RecursiveHelper(tempPtr); //calls the recursive helper funtion
    }
    return counter;
}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*) const {

    static Node<ItemType> *tempPtr = headPtr.get(); //get function is the back door for shared pointer headPtr
    int counter = 0;
    //Base Case
    if(tempPtr==nullptr) //if list is empty
    {
        tempPtr = headPtr.get();
        return 0;
    }
    else{
        //recursive case
        tempPtr = tempPtr->getNext().get();
        counter =  (1+ getCurrentSize340Recursive());  // returns 1 plus the rest of the nodes
    }
    return counter;
}

//counts the number of node with direct recursion
//this method uses no helper funtion
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    
    static Node<ItemType> *tempPtr = headPtr.get(); //get function is the back door for shared pointer headPtr
    int counter = 0;
    //Base case
    if (tempPtr==nullptr) //if list is empty
        return 0;
    
    else{
        //recursive case
        tempPtr = tempPtr->getNext().get();
        counter = (1+getCurrentSize340RecursiveNoHelper()); //returns 1 plus the rest of the nodes
    }
    return counter;
    
}

//counts the number of times an item occurs in the list with indirect recursion
//this method uses the helper function
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anItem) const{
    static Node<ItemType> *tempPtr = headPtr.get();
    if(tempPtr==nullptr)
    {
        tempPtr = headPtr.get();
        return 0;
    }
    else
        return getFrequencyOf340RecursiveHelper(tempPtr, anItem);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>*, const ItemType& anItem) const{
    static Node<ItemType> *tempPtr = headPtr.get();
    int frequency = 0;
    //Base case
    if(tempPtr==nullptr){ //if list is empty
        tempPtr = headPtr.get();
        return 0;
    }
    //recursive case
    else if(tempPtr->getItem()==anItem){
        tempPtr = tempPtr->getNext().get();
        frequency = (1+getFrequencyOf340Recursive(anItem)); //add 1 to rest of nodes containing the same item
        {
            return frequency;
        }
    }
    else{
        tempPtr= tempPtr->getNext().get();
        frequency = (getFrequencyOf340Recursive(anItem)); //gives item that occurs only once in the list
        {
            return frequency;
        }
    }
}

//counts the number of times an item occurs in the list with direct recursion
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anItem) const{
    static Node<ItemType> *tempPtr = headPtr.get();
    int frequency = 0;
    //base case
    if(tempPtr==nullptr){ //if list is empty
        tempPtr = headPtr.get();
        return 0;
    }
    //recursive case
    else if (tempPtr->getItem()==anItem){
        tempPtr = tempPtr->getNext().get();
        frequency = (1+ getFrequencyOf340RecursiveNoHelper(anItem)); //add 1 to rest of nodes containing the same item
        {
            return frequency;
        }
    }
    else
    {
        tempPtr= tempPtr->getNext().get();
        frequency = (getFrequencyOf340RecursiveNoHelper(anItem)); //gives item that occurs only once in the list
        {
            return frequency;
        }
    }
}

//this function randomly removes an item
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    ItemType item{};
    if(headPtr==nullptr) { //if list is empty
        return 0;
    }
    srand(static_cast<unsigned int>(time(0))); //using a seed value to not get same result on every run
    int maxNum = getCurrentSize340Iterative(); //storing the size of the list
    item = headPtr->getItem(); // item is the first node's item
    shared_ptr<Node<ItemType>> tempPtr = headPtr;
    int n;
    for(n=0; tempPtr!=nullptr; n++){
        if(rand() % maxNum ==0 )
       item = tempPtr->getItem();
       tempPtr=tempPtr->getNext();
    }
    remove(item);
    return item;
}







