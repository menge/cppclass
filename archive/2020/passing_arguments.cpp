#include <cassert>
#include <cstdlib>
#include <iostream>


void pass_by_copy(int foo);
void pass_by_copy(int *foo);
void pass_by_reference(int &foo);
void quicksort(int *a, int size);
void swap(int *a, int size);


void pass_by_copy(int foo) 
{
    std::cout << "pre-inside pass_by_copy: " << foo << std::endl;
    foo = 10;
    std::cout << "inside pass_by_copy: " << foo << std::endl;
}

void pass_by_reference(int &foo) 
{
    foo = 100;
    std::cout << "inside pass_by_reference: " << foo << std::endl;
}

void pass_by_copy(int *foo) 
{
    *foo = 1000;
    std::cout << "inside pass_by_copy: " << *foo << std::endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *a, int size)
{
    if (size <= 1)
        return;

    int *left = a;
    int *right = a+size-2;
    int *pivot = a+size-1;

    while (left < right)
    {
        if (*left < *pivot)
        {
            left++;
        }
        else
        {
            swap(left, right);
            right--;
        }
    }
    if (*left < *pivot)
    {
        swap(left+1, pivot);
        pivot = left+1;
    }
    else
    {
        swap(left, pivot);
        pivot = left;
    }

    quicksort(a, pivot-a);
    quicksort(pivot + 1, size - (pivot-a) - 1);
}

int main(int argc, char **argv)
{
    int bar = 0;
    int foo = 1;
    int array[] = {1,2,3,4,500};

    std::cout << "main000: " << foo << std::endl;
    pass_by_copy(foo);
    std::cout << "main001: " << foo << std::endl;
    pass_by_reference(foo);
    std::cout << "main002: " << foo << std::endl;
    pass_by_copy(&foo);
    std::cout << "main003: " << foo << std::endl;
    //pass_by_copy(nullptr); //sementation fault
    //pass_by_reference(nullptr); // compilation error

    //pass_by_reference(foo);
    //pass_by_copy(&foo);

    std::cout << "main010: " << array[0] << std::endl;
    std::cout << "main011: " << array[1] << std::endl;
    std::cout << "main012: " << array[2] << std::endl;
    std::cout << "main013: " << array[3] << std::endl;
    std::cout << "main014: " << array[4] << std::endl;
    //pass_by_copy(array);
    //pass_by_copy(array[0]);
    //pass_by_reference(array[0]);
    //pass_by_reference(array);
    //pass_by_reference(*array);
    pass_by_copy(*array);
    pass_by_copy(array[4]);
    pass_by_copy(*(array+4));
    pass_by_copy(*array+4);
    std::cout << "main020: " << array[0] << std::endl;
    std::cout << "main021: " << array[1] << std::endl;
    std::cout << "main022: " << array[2] << std::endl;
    std::cout << "main023: " << array[3] << std::endl;
    std::cout << "main024: " << array[4] << std::endl;

    int a[] = {7,3,1,6,78,23,4,2,5,67,35,4,13,3,5};
    quicksort(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0 ; i < sizeof(a) / sizeof(a[0]) ; i++)
    {
        std::cout << "a[" << i << "]: " << a[i] << std::endl;
    }
}
