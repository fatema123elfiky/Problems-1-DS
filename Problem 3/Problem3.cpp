/**
 * @file Problem3.cpp
 * @brief A sorted linked list implementation with basic operations such as insertion, deletion, and access.
 *
 * This class provides a sorted singly linked list where elements are inserted in ascending order, and nodes can be
 * removed by index. It includes a destructor for clean-up and overloaded operators for easy access and display.
 *
 * @author Aly El-Deen Yasser Ali
 * @id     20231109
 *
 * @version 1.5
 * @date   2025-04-03
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * @class Node
 * @brief A class representing a node in a linked list.
 */
class Node {
public:
    int data;
    Node* next;

    /**
     * @brief Constructor to initialize a node with a given value.
     * @param val The integer value to store in the node.
     */
    Node(int val);
};

Node::Node(int val) {
    this->data = val;
    this->next = nullptr;
}

/**
 * @class SortedLinkedList
 * @brief A class representing a sorted singly linked list.
 *
 * This class maintains a linked list in sorted order, allowing insertion and removal
 * of elements while keeping the list sorted.
 */
class SortedLinkedList {
private:
    Node* head;

public:
    /**
     * @brief Default constructor that initializes an empty sorted linked list.
     */
    SortedLinkedList();

    /**
     * @brief Inserts a new element into the sorted linked list while maintaining order.
     * @param data The integer value to be inserted.
     */
    void insert(int data);

    /**
     * @brief Removes an element from the sorted linked list if it exists.
     * @param data The integer value to be removed.
     */
    void remove(int data);

    /**
     * @brief Overloads the stream insertion operator to display the linked list.
     * @param os The output stream object.
     * @param list The sorted linked list to be displayed.
     * @return The output stream reference after inserting the list representation.
     */
    friend std::ostream& operator<<(std::ostream& os, const SortedLinkedList& list);

    /**
     * @brief Overloads the subscript operator to access an element at a given index.
     * @param index The position of the element in the linked list (0-based index).
     * @return The integer value at the specified index.
     * @note No bounds checking is implemented in this function.
     */
    int operator[](int index);

    /**
     * @brief Destructor that deallocates memory and cleans up the linked list.
     */
    ~SortedLinkedList();
};

SortedLinkedList::SortedLinkedList(){
    head = nullptr;
}

void SortedLinkedList::insert(int data){
    Node* newNode = new Node(data);
    if(head == nullptr || head->data >= newNode->data){
        newNode->next = head;
        head =  newNode;
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

    for (int i = 0; i < index-1; i++) {
        if (currentNode == nullptr || currentNode->next == nullptr)
            throw std::out_of_range("Index out of range.");
        currentNode = currentNode->next;
    }

    Node* deletedNode = currentNode->next;
    if (deletedNode == nullptr)
        throw std::out_of_range("Index out of range.");
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
    if(index < 0)
        throw std::invalid_argument("No Negative number | Index out of range");

    Node* currentNode = head;
    for(int i = 0; i < index; i++){
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
    head = nullptr;
}

int main(){
    // TestCase 1 :
    SortedLinkedList list1;
    list1.insert(5);
    list1.insert(8);
    list1.insert(7);
    list1.insert(6);
    list1.insert(6);
    cout << list1;
    cout << endl;
    // =========================
    // Test Case 2
    cout << list1[2] << endl;
    try {
        cout << list1[10] << endl;
    }catch (exception& e) {
        cout << e.what() << endl;
    }
    cout  << endl;
    // =========================
    // Test Case 3
    cout << list1;
    list1.remove(0);
    cout << list1;
    try {
        list1.remove(100);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    cout << list1;
    list1.remove(2);
    cout << list1;
    list1.remove(2);
    cout << list1;
    cout  << endl;
    // =========================
    // Test Case 4
    SortedLinkedList list4;
    list4.insert(5);
    list4.insert(1);
    list4.insert(3);
    cout << list4; // Expected Output: 1 3 5
    list4.remove(1);
    cout << list4; // Expected Output: 1 5
    cout  << endl;

    // Test Case 5
    SortedLinkedList list5;
    list5.insert(10);
    list5.insert(20);
    list5.insert(30);
    cout << list5; // Expected Output: 10 20 30
    list5.remove(0);
    cout << list5; // Expected Output: 20 30
    list5.remove(1);
    cout << list5; // Expected Output: 20
    cout  << endl;

    // Test Case 6
    SortedLinkedList list6;
    list6.insert(2);
    list6.insert(4);
    list6.insert(6);
    list6.insert(8);
    cout << list6; // Expected Output: 2 4 6 8
    list6.remove(2);
    cout << list6; // Expected Output: 2 4 8
    list6.remove(1);
    cout << list6; // Expected Output: 2 8
    cout  << endl;

    // Test Case 7
    SortedLinkedList list7;
    list7.insert(15);
    list7.insert(5);
    list7.insert(25);
    list7.insert(10);
    cout << list7; // Expected Output: 5 10 15 25
    try {
        list7.remove(10);
    } catch (exception& e) {
        cout << e.what() << endl; // Expected Output: Index out of range.
    }
    cout << list7; // Expected Output: 5 10 15 25
    cout  << endl;

    // Test Case 8
    SortedLinkedList list8;
    list8.insert(100);
    list8.insert(50);
    list8.insert(75);
    cout << list8; // Expected Output: 50 75 100
    list8.remove(0);
    cout << list8; // Expected Output: 75 100
    cout  << endl;

    // Test Case 9
    SortedLinkedList list9;
    list9.insert(7);
    list9.insert(1);
    list9.insert(9);
    cout << list9; // Expected Output: 1 7 9
    list9.remove(1);
    cout << list9; // Expected Output: 1 9
    cout  << endl;

    // Test Case 10
    SortedLinkedList list10;
    list10.insert(40);
    list10.insert(30);
    list10.insert(20);
    list10.insert(50);
    list10.insert(10);
    cout << list10; // Expected Output: 10 20 30 40 50
    list10.remove(2);
    cout << list10; // Expected Output: 10 20 40 50
    list10.remove(0);
    cout << list10; // Expected Output: 20 40 50
    list10.remove(1);
    cout << list10; // Expected Output: 20 50
    try {
        list10.remove(5);
    } catch (exception& e) {
        cout << e.what() << endl; // Expected Output: Index out of range.
    }
    cout << list10; // Expected Output: 20 50
return 0;
}
