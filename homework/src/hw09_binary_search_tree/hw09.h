#pragma once

namespace cppclass {
class BinarySearchTree {
public:
    struct node {
        int data;
        node* left;
        node* right;

        node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    /**
    * @brief Default constructor for BinarySearchTree.
    */
    BinarySearchTree();
    /**
    * @brief Constructor that initializes the tree with an array of integers.
    * @param arr Pointer to an array of integers.
    * @param size Size of the array.
    */
    BinarySearchTree(const int* arr, int size);
    /**
    * @brief Copy constructor for BinarySearchTree.
    *
    * @param other Refrence to BinarySearchTree to copy from.
    */
    BinarySearchTree(const BinarySearchTree& other);
    /**
    * @brief Move constructor for BinarySearchTree.
    * @param other R-value reference to another BinarySearchTree object.
    */
    BinarySearchTree(BinarySearchTree&& other);
    /**
    * @breif Destructor for BinarySearchTree.
    */
    ~BinarySearchTree();
    /**
    * @breif Inserts a value into the binary search tree.
    * @param value The integer value to insert.
    */
    void insert(int value);
    /**
    * @breif Removes a value from the binary search tree.
    * @param value The integer value to remove.
    */
    void remove(int value);
    /**
    * @breif Checks if a value is contained in the binary search tree.
    * @param value The integer value to check.
    * @return True if the value is found, false otherwise.
    */
    bool contains(int value) const;
    /**
    * @breif Prints the binary search tree in-order.
    */
    void print() const;
    /**
    * @breif Returns the size of the binary search tree.
    * @return The number of nodes in the tree.
    * */
    int size() const;
    /**
    * @breif Checks if the binary search tree is empty.
    * @return True if the tree is empty, false otherwise.
    */
    bool operator==(const BinarySearchTree& other) const;
    /**
    * @breif Checks if the binary search tree is not equal to another tree.
    * @return True if the trees are not equal, false otherwise.
    */
    bool operator!=(const BinarySearchTree& other) const;

private:
    node* m_root;
    int m_size;
};
}
