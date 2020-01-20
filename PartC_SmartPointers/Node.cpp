

//  Node.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//    Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "Node.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
Node<ItemType>::Node() : next(nullptr) {}

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, const shared_ptr<Node<ItemType>> nextNodePtr) :
item(anItem), next(nextNodePtr) {}

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<typename ItemType>
void Node<ItemType>::setNext(shared_ptr<Node<ItemType>> nextNodePtr) {
    next = nextNodePtr;
}

template<typename ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<typename ItemType>
shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const {
    return next;
}

template<typename ItemType>
 Node<ItemType>::~Node(){
    cout << " Destroying the node: " << item << endl;
}

