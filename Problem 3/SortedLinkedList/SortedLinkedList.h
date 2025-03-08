#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <ostream>
#include "Node/Node.h"

/**
 * @class SortedLinkedList
 * @brief A class representing a sorted singly linked list.
 *
 * This class maintains a linked list in sorted order, allowing insertion and removal
 * of elements while keeping the list sorted.
 */
class SortedLinkedList {
private:
    Node* head;  // (first node) of the linked list.

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
    friend std::ostream& operator<<(std::ostream& os, const SortedLinkedList list);

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

#endif // SORTEDLINKEDLIST_H
