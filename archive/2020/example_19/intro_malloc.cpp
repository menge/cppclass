#include <iostream>
#include <cassert>
#include <cstdlib>

int main (int argc, char** argv)
{
    const int MAX_SIZE = 1<<22;
    //long long boo[MAX_SIZE];

    long long *array = static_cast<long long*>( malloc(MAX_SIZE * sizeof(long long)) );
    long long *item = static_cast<long long*>(malloc(sizeof(long long)));

    assert(array != nullptr);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = i;
    }

    free(array);
    free(item);
}

void cpp_heap_multi_allocation()
{
    const int MAX_SIZE = 1<<22;
    long long *array = new long long[MAX_SIZE];

    assert(array != nullptr);
    
    delete []array;
}

void cpp_heap_single_allocation()
{
    long long *item = new long long;

    delete item;
}
