#include <cstdlib>
int main ()
{
    int *a = new int[256];
    int *b = static_cast<int *>(malloc(256 * sizeof(int)));

    free(b);
    delete []a;

    const int NUM_OF_BOOKSHELVES = 1000;
    const int SHELVES_PER_BOOKSHELF = 6;
    const int BOOKS_PER_SHELF = 30;
    int bookshelves[NUM_OF_BOOKSHELVES][SHELVES_PER_BOOKSHELF][BOOKS_PER_SHELF];
    int (*foo)[SHELVES_PER_BOOKSHELF][BOOKS_PER_SHELF] = bookshelves;

    for (int bookshelf_id = 0; bookshelf_id < NUM_OF_BOOKSHELVES; bookshelf_id++)
    {
        for (int shelf = 0; shelf < SHELVES_PER_BOOKSHELF; shelf++)
        {
            for (int book = 0; book < BOOKS_PER_SHELF; book++)
            {
                bookshelves[bookshelf_id][shelf][book] = bookshelf_id*SHELVES_PER_BOOKSHELF*BOOKS_PER_SHELF + shelf*BOOKS_PER_SHELF + book;
            }
        }
    }

    struct Point {
        int x;
        int y;
    };

#if 0
    struct Rectangle{
        Point points[2];
    };
#endif
    const int NUM_OF_ITEMS = 8;
    int array[NUM_OF_ITEMS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < NUM_OF_ITEMS; i++) {};

    short array2[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++) {};

    Point rectangsles[][2] = 
    {
        {
            {.x = 0, .y = 0},
            {.x = 5, .y = 5},
        },
        {
            {.x = 0, .y = 0},
            {.x = 4, .y = 5},
        },
        {
            {.x = 0, .y = 0},
            {.x = 3, .y = 9},
        },
    };
}
