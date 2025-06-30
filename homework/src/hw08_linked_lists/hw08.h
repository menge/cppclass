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

        /// @brief Default constructor.
        LinkedList();

        /**
         * @brief Parameterized constructor.
         *
         * @param arr Pointer to the array.
         * @param size Number of elements in the array.
         */
        LinkedList(const int *arr, size_t size);

        /**
         * @brief Copy constructor.
         *
         * @param src Reference to the LinkedList to copy from.
         */
        LinkedList(const LinkedList &src);

        /**
         * @brief Move constructor.
         *
         * @param src R-value reference to the LinkedList to move from.
         */
        LinkedList(LinkedList &&src);

        /**
         * @brief Destructor.
         */
        ~LinkedList();

        /**
         * @brief Destroy an element from the linked list.
         *
         * @param node Pointer to a node (node has to be valid within this linked list)
         *             does nothing if nullptr is passed in.
         */
        void erase(Node *node);

        /**
         * @brief Create an item to the end of the linked list.
         *
         * @param data The data to add to the linked list.
         * @param node Pointer to the node inserting after (node has to be valid within this linked list)
         *             if node = nullptr, append at end.
         *
         * @return A pointer to the node that was created.
         */
        Node* append(int data, Node *node = nullptr);

        /**
         * @brief Create an item before a specific node.
         *
         * @param data The data to add to the linked list.
         * @param node Pointer to the node inserting before (node has to be valid within this linked list)
         *             if node = nullptr, insert at beginning
         *
         * @return A pointer to the node that was created.
         */
        Node* insert(int data, Node *node = nullptr);

        /**
         * @brief Searches for node with @p data.
         *
         * @param data The data to search for.
         *
         * @return A pointer to the first node found with @p data
         *         if not found return nullptr.
         */
        Node* search(int data) const;

        /**
         * @brief Accesses element at position @p index.
         *
         * @param index The index of an item.
         *
         * @return A pointer to the node
         *         return nullptr if index is out of bounds.
         */
        Node* at(unsigned int index) const;

        /**
         * @brief Returns size of linked list.
         *
         * @return Size of linked list.
         */
        size_t get_size() const;

private:
        Node *m_head;
        Node *m_tail;
        size_t m_size;
};
