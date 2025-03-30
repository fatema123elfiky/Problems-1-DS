#ifndef NODE_H
#define NODE_H

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

#endif