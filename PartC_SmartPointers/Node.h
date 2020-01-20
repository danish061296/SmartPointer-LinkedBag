//    Node.h
//  Created by Frank M. Carrano and Timothy M. Henry.
//    Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once
#include <iostream>
using namespace std;
//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
class Node {
public:
    Node();
    Node(const ItemType&);
    Node(const ItemType&, shared_ptr<Node<ItemType>>);

    void setItem(const ItemType&);
    void setNext(shared_ptr<Node<ItemType>>);
    ItemType getItem() const;
    shared_ptr<Node<ItemType>>  getNext() const;
    ~Node();
private:
    ItemType        item;             // A data item
   shared_ptr<Node<ItemType>> next{ nullptr }; // Pointer to next node
};
