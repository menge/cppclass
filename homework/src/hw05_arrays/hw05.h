#pragma once

#include <cstddef>

// Pre-conditions: none
// Post-conditions: none
// Returns: the pointer to where the first instance of 0 is found.
//          if no instance of 0s exist within the valid size, return nullptr
const int* find_first_zero(const int *src, size_t size);

// Pre-conditions: none
// Post-conditions: none
// Returns: the pointer to where the last instance of 0 is found.
//          if no instance of a 0 exists within the valid size, return nullptr
const int* find_last_zero(const int *src, size_t size);

// Pre-conditions: none
// Post-conditions: none
// Returns: the number of times the key passed in exists in the array passed in
size_t find_num_keys(const int *src, size_t size, int key);

// Pre-conditions: none
// Post-conditions: result will contain the mean value of src
// Returns: true when there exists a valid value for result
//          false for when there are no items, or nullptr is passed in
bool mean_of_array(const double *src, size_t size, double &result);

// Pre-conditions: dst array size would be at least the size of src
// Post-conditions: contents of src copied into dst for size elements
// Returns: number of items that were copied
// 
// Note: dst or src could be nullptr, and if so, do not attempt any copy
size_t copy_array(int *dst, const int *src, size_t size);

// Pre-conditions: dst array size would be at least the size of src
// Post-conditions: contents of dst will be the reverse of what is contained in src
// Returns: nothing, but dst will be changed
//
// if either dst or src is nullptr, do nothing
//
// e.g.: if src: [0,1,2,3,4,5] -> dst: [5,4,3,2,1,0]
void reverse_array(int *dst, const int *src, size_t size);

// Pre-conditions: none
// Post-conditions: contents of array will be the reverse of what was originally passed in
// Returns: nothing, but array is reversed
//
// e.g.: if array: [0,1,2,3,4,5] -> array: [5,4,3,2,1,0]
void reverse_in_place(int *array, size_t size);
