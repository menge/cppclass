#include <iostream>
#include <cstdlib>
#include <algorithm>

#include <unistd.h>
#include <term.h>

void ClearScreen()
{
    if (!cur_term)
    {
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if (result <= 0) return;
    }

    putp( tigetstr( "clear" ) );
}

void print_items(int *array, int num, int **markers = nullptr, int markers_size = 0)
{
    ClearScreen();

    int markers_current = 0;

    for (int i = 0; i < num; i++)
    {
        if (markers_current < markers_size)
        {
            if (array+i == markers[markers_current])
            {
                printf("* ");
                markers_current++;
            }
        }
        printf("%u ", array[i]);
    }
    printf("\n");
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    usleep(1000);
}

bool cmp(int& a, int& b)
{
    usleep(1000);
    return (a < b);
}

void bubble_sort(int *items, int size)
{
    for (int unsorted_item = 1; unsorted_item < size; unsorted_item++)
    {
        for (int k = unsorted_item; k > 0; k--)
        {
            if (cmp(items[k], items[k-1]))
            {
                swap(items[k-1], items[k]);
                print_items(items, size);
            }
            else
                break;
        }
    }
}

void quick_sort(int *items, int size, int *orig_base, int orig_size)
{
    // base cases
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (not cmp(items[0], items[1]))
        {
            swap(items[0], items[1]);
            print_items(orig_base, orig_size);
        }
    }

    int left = 0;
    int right = size - 2;
    int pivot = size - 1;

    while (left < right)
    {
        if (cmp(items[left], items[pivot]))
        {
            left++;
        }
        else
        {
            swap(items[left], items[right]);
            print_items(orig_base, orig_size);
            right--;
        }
    }
    if (cmp(items[left], items[pivot]))
    {
        swap(items[left+1], items[pivot]);
        print_items(orig_base, orig_size);
        pivot = left+1;
    }
    else
    {
        swap(items[right], items[pivot]);
        print_items(orig_base, orig_size);
        pivot = right;
    }
    quick_sort(items, pivot, orig_base, orig_size);
    quick_sort(items + pivot+1, size - pivot-1, orig_base, orig_size);
}

void cocktail_shaker_sort(int *items, int size)
{
    int *least = items;
    int *greatest = items + size - 1;
    int *active = least;
    int *markers[2];
    markers[0] = least;
    markers[1] = greatest+1;
    int *last_known_swap = least;

    while (least < greatest)
    {
        while (active < greatest)
        {
            if ( ! cmp( *active, *(active+1)))
            {
                swap(*active, *(active+1));
                print_items(items,size, markers, 2);
                last_known_swap = active + 1;
            }
            active++;
        }
        greatest = last_known_swap;
        active = greatest;
        markers[1] = greatest;

        while (active > least)
        {
            if ( cmp( *active, *(active-1)))
            {
                swap(*active, *(active-1));
                print_items(items,size, markers, 2);
                last_known_swap = active - 1;
            }
            active--;
        }
        least = last_known_swap;
        active = least;
        markers[0] = least+1;

        print_items(items,size, markers, 2);
    }
}

int main ()
{
    const int MAX_ITEMS = 256;
    int items[MAX_ITEMS];

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        //items[i] = rand() % 1000;
        items[i] = i;
        if (i > 0)
        {
            int victim = rand() % i;
            swap(items[i], items[victim]);
        }
    }

    //bubble_sort(items, MAX_ITEMS);
    //quick_sort(items, MAX_ITEMS, items, MAX_ITEMS);
    cocktail_shaker_sort(items, MAX_ITEMS);
}
