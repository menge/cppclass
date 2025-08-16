#pragma once

#include <vector> // for std::vector
#include <cstddef> // for size_t

namespace cppclass {
template <typename T> class Heap {
public:
    /// @brief Constructs an empty heap.
    Heap();

    /**
     * @brief Constructs a heap from an array.
     *
     * @param arr Pointer to the array.
     * @param size Size of the array.
     */
    Heap(const T *arr, size_t size);

    /**
     * @brief Copy constructs a heap from another heap.
     *
     * @param other Reference to the heap to copy from.
     */
    Heap(const Heap &other);

    /**
     * @brief Copy assignment operator.
     *
     * @param other Reference to the heap to copy from.
     * @return Reference to this heap after assignment.
     */
    Heap& operator=(const Heap &other);

    /**
     * @brief Move constructs a heap from another heap.
     *
     * @param other R-Value reference to the heap to move from.
     */
    Heap(Heap &&other);

    /**
     * @brief Move assignment operator.
     *
     * @param other R-Value reference to the heap to move from.
     * @return Reference to this heap after assignment.
     */
    Heap& operator=(Heap &&other);

    /// @brief Destroys the heap.
    ~Heap();

    /**
     * @brief Peek at the root of the heap.
     *
     * @return The root of the heap.
     */
    const T& top() const;

    /**
     * @brief Removes and returns the root of the heap.
     *
     * @return The root of the heap.
     */
    T pop_back();

    /**
     * @brief Inserts @p data to the heap.
     *
     * @param data Data to insert into the heap.
     */
    void push_back(const T &data);

    /// @brief Returns the number of elements in the heap.
    size_t size() const;

    /**
     * @brief Equality comparison.
     *
     * @param other The heap to compare with.
     * @return True if the heaps do not differ in order or value.
     */
    bool operator==(const Heap &other) const;

    /**
     * @brief Inequality comparison.
     *
     * @param other The heap to compare with.
     * @return True if the heaps differ in order or value.
     */
    bool operator!=(const Heap &other) const;

private:
    std::vector<T> m_arr; ///< Container to hold the heap's elements.

    /**
     * @brief Checks the validity of the heap.
     *
     * @return True if valid, false if invalid.
     */
    bool is_valid();

    /**
     * @brief Restores the heap property by moving the element at @p index up.
     *
     * @param index Index of the element to move up.
     */
    void heapify_up(size_t index);

    /**
     * @brief Restores the heap property by moving the element at @p index down.
     *
     * @param index Index of the element to move down.
     */
    void heapify_down(size_t index);
};
} // namespace cppclass
