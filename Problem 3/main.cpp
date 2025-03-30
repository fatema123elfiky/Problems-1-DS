#include <iostream>
#include <fstream>
#include "SortedLinkedList/SortedLinkedList.h"

using namespace std;

int main(){
    // TestCase 1 :
    SortedLinkedList list1;
    list1.insert(5);
    list1.insert(8);
    list1.insert(7);
    list1.insert(6);
    list1.insert(6);
    cout << list1;
    // =========================
    // Test Case 2
    cout << list1[2] << endl;
    try {
        cout << list1[10] << endl;
    }catch (exception& e) {
        cout << e.what() << endl;
    }
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
    // =========================
    // Test Case 4
    SortedLinkedList list4;
    list4.insert(5);
    list4.insert(1);
    list4.insert(3);
    cout << list4; // Expected Output: 1 3 5
    list4.remove(1);
    cout << list4; // Expected Output: 1 5

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

    // Test Case 8
    SortedLinkedList list8;
    list8.insert(100);
    list8.insert(50);
    list8.insert(75);
    cout << list8; // Expected Output: 50 75 100
    list8.remove(0);
    cout << list8; // Expected Output: 75 100

    // Test Case 9
    SortedLinkedList list9;
    list9.insert(7);
    list9.insert(1);
    list9.insert(9);
    cout << list9; // Expected Output: 1 7 9
    list9.remove(1);
    cout << list9; // Expected Output: 1 9

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
