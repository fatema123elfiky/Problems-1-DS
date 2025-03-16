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
        return;
    }

    Node* currentNode = head;
    while(currentNode-> next != nullptr && currentNode->next->data < newNode->data)
        currentNode = currentNode->next;

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void SortedLinkedList::remove(int index) {
    if (head == nullptr)
        throw std::out_of_range("List is empty");

    Node* currentNode = head;
    if (index == 0) {
        head = head->next;
        delete currentNode;
        return;
    }

    for (int i = 0; i < index; i++) {
        if (currentNode == nullptr || currentNode->next == nullptr)
            throw std::out_of_range("Index out of range.");
        currentNode = currentNode->next;
    }

    Node* deletedNode = currentNode->next;
    currentNode->next = deletedNode->next;
    delete deletedNode;
}

std::ostream& operator<<(std::ostream& os, const SortedLinkedList& list){
    Node* currentNode = list.head;
    while(currentNode!= nullptr){
        os << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    os << std::endl;
    return os;
}

int SortedLinkedList::operator[](int index){
    Node* currentNode = head;

    if(index < 0)
        throw std::invalid_argument("No Negative number | Index out of range");

    for(int i = 0; i <= index; i++){
        if(currentNode == nullptr)
            throw std::out_of_range("Index out of range.");
        currentNode = currentNode->next;
    }

    return currentNode->data;
}

SortedLinkedList::~SortedLinkedList(){
    Node* currentNode = head;
    while(currentNode!= nullptr){
        Node* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
}

