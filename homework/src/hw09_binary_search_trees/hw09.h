#pragma once

#include <cstddef> // for size_t

namespace cppclass {

template <typename T>
class BinarySearchTree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    /**
    * @brief An empty BinarySearchTree will be created.
    */
    BinarySearchTree();

    /**
    * @brief Constructor that initializes the tree with an array of values.
    * @param arr Pointer to an array of values.
    * @param size Size of the array.
    */
    BinarySearchTree(const T* arr, int size);

    /**
    * @brief Copy constructor for BinarySearchTree.
    * @param other Reference to BinarySearchTree to copy from.
    */
    BinarySearchTree(const BinarySearchTree& other);

    /**
    * @brief Move constructor for BinarySearchTree.
    * @param other R-value reference to another BinarySearchTree object.
    */
    BinarySearchTree(BinarySearchTree&& other);

    /**
    * @brief Destructor for BinarySearchTree.
    */
    ~BinarySearchTree();

    /**
    * @brief Inserts a value into the binary search tree.
    * @param value The value to insert. Cannot be a duplicate.
    * @return True if the value was inserted successfully, false if it already exists.
    */
    bool insert(T value);

    /**
    * @brief Removes a value from the binary search tree.
    * @param value The value to remove. Must be present in the tree.
    * @return True if the value was removed successfully, false if it was not found.
    */
    bool remove(T value);

    /**
    * @brief Checks if a value is contained in the binary search tree.
    * @param value The value to check.
    * @return True if the value is found, false otherwise.
    */
    bool contains(T value) const;

    /**
    * @brief Returns the size of the binary search tree.
    * @return The number of nodes in the tree.
    */
    size_t size() const;

    /**
    * @brief Checks if two binary search trees are equal.
    * @param other The other binary search tree to compare with.
    * @return True if the trees are equal, false otherwise.
    */
    bool operator==(const BinarySearchTree& other) const;

    /**
    * @brief Checks if the binary search tree is not equal to another tree.
    * @param other The other binary search tree to compare with.
    * @return True if the trees are not equal, false otherwise.
    */
    bool operator!=(const BinarySearchTree& other) const;

private:
    /**
    * @brief Prints the binary search tree in-order.
    */
    void print() const;

    /**
    * @brief Checks if the binary search tree is valid.
    * @return True if the tree is valid, false otherwise.
    */
    bool isValid() const;

    Node* m_root;
    size_t m_size;
};

} // namespace cppclass

