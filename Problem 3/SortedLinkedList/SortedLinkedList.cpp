#include "SortedLinkedList.h"

#include <iostream>

SortedLinkedList::SortedLinkedList(){
    head = nullptr;
}

void SortedLinkedList::insert(int data){
    Node* newNode = new Node(data);
    if(head == nullptr || head->data >= newNode->data){
        newNode->next = head;
        head = newNode;
    }

    Node* current = head;
    while(current-> next != nullptr && current->next->data < newNode->data)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
    delete newNode;
}

void SortedLinkedList::remove(int data){
    Node* current = head;
    if(current!= nullptr && current->data == data){
        head = current->next;
        delete current;
        return;
    }

    while(current->next != nullptr && current->next->data == data)
        current = current->next;

    if(current->next!= nullptr){
        Node* removedNode = current->next;
        current->next = removedNode->next;
        delete removedNode;
    }
    else
        std::cout << "Data not found in the list." << std::endl;

    delete current;
}


std::ostream& operator<<(std::ostream& os, const SortedLinkedList list){
    Node* current = list.head;
    while(current!= nullptr){
        os << current->data << " ";
        current = current->next;
    }
    os << std::endl;
    delete current;
    return os;
}

int SortedLinkedList::operator[](int index){
    Node* current = head;
    for(int i = 0; i < index; i++){
        if(current == nullptr)
            throw std::out_of_range("Index out of range.");
        current = current->next;
    }
    return current->data;
}

SortedLinkedList::~SortedLinkedList(){
    Node* current = head;
    while(current!= nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
    delete head;
}

