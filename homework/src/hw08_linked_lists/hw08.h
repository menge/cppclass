#pragma once

#include <cstddef>

class LinkedList {
public:
        /// @brief Node definition for the linked list.
        struct Node {
                int data;
                Node *next;
                Node *prev;

                /// @brief Default constructor
                Node() : data(), next(nullptr), prev(nullptr) {}
        };

        /// @brief Constructs an empty linked list.
        LinkedList();

        /**
         * @brief Constructs a linked list from an array.
         *
         * @param arr Pointer to the array.
         * @param size Number of elements in the array.
         */
        LinkedList(const int *arr, size_t size);

        /**
         * @brief Copy constructor.
         *
         * @param src Reference to the linked list to copy from.
         */
        LinkedList(const LinkedList &src);

        /**
         * @brief Move constructor.
         *
         * @param src R-value reference to the linked list to move from.
         */
        LinkedList(LinkedList &&src);

        /**
         * @brief Destructor.
         */
        ~LinkedList();

        /**
         * @brief Remove an element from the linked list.
         *
         * @param node Pointer to a valid node in this list. If nullptr, does nothing.
         */
        void erase(Node *node);

        /**
         * @brief Appends a new node after the specified node.
         *
         * @param data Data to store in the new node.
         * @param node Pointer to a valid node in the list to append after. If nullptr, appends at end.
         *
         * @return Pointer to the newly created node.
         */
        Node* append(int data, Node *node = nullptr);

        /**
          * @brief Inserts a new node before the specified node.
          *
          * @param data Data to store in the new node.
          * @param node Pointer to a valid node in the list to insert before. If nullptr, inserts at the beginning.
          * @return Pointer to the newly created node.
          */
        Node* insert(int data, Node *node = nullptr);

        /**
         * @brief Searches for the first node containing @p data.
         *
         * @param data Data to search for in the list.
         * @return Pointer to the first node found with @p data. If not found, returns nullptr.
         */
        Node* search(int data) const;

        /**
         * @brief Accesses element at the given index.
         *
         * @param index Zero-based index of a node.
         * @return Pointer to the node. If index is out of bounds, returns nullptr.
         */
        Node* at(unsigned int index) const;

        /**
         * @brief Returns number of nodes in the list.
         *
         * @return Current size of list.
         */
        size_t get_size() const;

private:
        Node *m_head; ///< Pointer to the first node.
        Node *m_tail; ///< Pointer to the last node.
        size_t m_size; ///< Number of elements in the list.
};
