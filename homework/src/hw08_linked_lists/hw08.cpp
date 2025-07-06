#include <cstddef>
#include <cstdlib>

#include "hw08.h"

namespace cppclass{
/// @brief Constructs an empty linked list.
LinkedList::LinkedList() {

}

/**
 * @brief Constructs a linked list from an array.
 *
 * @param arr Pointer to the array.
 * @param size Number of elements in the array.
 */
LinkedList::LinkedList(const int *arr, size_t size) {

}

/**
 * @brief Copy constructor.
 *
 * @param src Reference to the linked list to copy from.
 */
LinkedList::LinkedList(const LinkedList &src) {

}

/**
 * @brief Move constructor.
 *
 * @param src R-value reference to the linked list to move from.
 */
LinkedList::LinkedList(LinkedList &&src) {

}

/**
 * @brief Destructor.
 */
LinkedList::~LinkedList() {

}

/**
 * @brief Remove an element from the linked list.
 *
 * @param node Pointer to a valid node in this list. If nullptr, does nothing.
 */
void LinkedList::erase(Node *node) {

}

/**
 * @brief Appends a new node after the specified node.
 *
 * @param data Data to store in the new node.
 * @param node Pointer to a valid node in the list to append after. If nullptr, appends at end.
 *
 * @return Pointer to the newly created node.
 */
LinkedList::Node* LinkedList::append(int data, Node *node) {
    return nullptr;
}

/**
  * @brief Inserts a new node before the specified node.
  *
  * @param data Data to store in the new node.
  * @param node Pointer to a valid node in the list to insert before. If nullptr, inserts at the beginning.
  * @return Pointer to the newly created node.
  */
LinkedList::Node* LinkedList::insert(int data, Node *node) {
    return nullptr;
}

/**
 * @brief Searches for the first node containing given data.
 *
 * @param data Data to search for in the list.
 * @return Pointer to the first node found with @p data. If not found, returns nullptr.
 */
LinkedList::Node* LinkedList::search(int data) const {
    return nullptr;
}

/**
 * @brief Accesses element at the given index.
 *
 * @param index Zero-based index of a node.
 * @return Pointer to the node. If index is out of bounds, returns nullptr.
 */
LinkedList::Node* LinkedList::at(unsigned int index) const {
    return nullptr;
}

/**
 * @brief Returns number of nodes in the list.
 *
 * @return Current size of list.
 */
size_t LinkedList::get_size() const {
    return 0;
}
/**
 * @brief Returns equality between two linked lists
 *
 * @return true if all elements in linked list are equal to each other in order and value
 */
bool LinkedList::operator==(const LinkedList &other) const {
    return false;
}

/**
 * @brief Returns non-equality between two linked lists
 *
 * @return false if all elements in linked list are equal to each other in order and value
 */
bool LinkedList::operator!=(const LinkedList &other) const {
    return false;
}
}
