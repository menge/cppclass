#include <iostream>
#include <cstdlib>
#include <ctime>

void chooseNumbers(int *array, int size, int choice_limit);
void printTicket(int *array, int size);

void chooseNumbers(int *array, int size, int choice_limit)
{
    for (int i = 0; i < size; i++)
    {
        int choice = (rand() % choice_limit) + 1;
        array[i] = choice;

        // re-roll choice if it happens to match an already
        // rolled number until it is different.
        int j = 0;
        while (j < i)
        {
            if (array[j] == array[i])
            {
                int choice = (rand() % choice_limit) + 1;
                array[i] = choice;
                j = 0;
                continue;
            }
            j++;
        }
    }
}

#if 0
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 100  | | 101  | | 102  | | 200  | | 201  | | 202  | |??????| |      | |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        0        1        2        3        4        5

David
ticket                                                winning_ticket
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 0    | | 101  | | 102  | | 200  | | 201  | | 202  | | 0    | | 1    | |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        0        1        2        3        4        5

Alfred/Anthony
ticket                                                winning_ticket
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 100  | | 101  | | 102  | | 200  | | 201  | | 202  | |??????| |      | |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        0        1        2        3        4        5

David
ticket                                                winning_ticket
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 0    | | 101  | | 102  | | 200  | | 201  | | 202  | |??????| |      | |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        0        1        2        3        4        5

David2/Alfred2
ticket                                                         winning_ticket
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 0    | | 101  | | 102  | | 200  | | 201  | | 202  | | 0    | |      | |      | |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        6        0        1        2        3        4        5

David
ticket                                                
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
| 0    | | 101  | | 102  | | 200  | | 201  | | 202  | | 0    | |??????| |      | |      | |      | |      |
+------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+ +------+
0        1        2        3        4        5        

ticket[0] = 100;
ticket[1] = 101;
ticket[2] = 102;
ticket[3] = 200;
ticket[4] = 201;
ticket[5] = 202;
ticket[6] = 0;
ticket[7] = 1;

#endif

void printTicket(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }

    // This will cause a crash (seg fault core dump)
    // array[200000] = 0xdeadbeef;

    std::cout << std::endl;
}

int main (int argc, char **argv)
{
    srand(time(nullptr));

    const int NUM_PICKS = 6;
    const int NUM_CHOICES = 70;

    int winningTicket[NUM_PICKS];
    int ticket[NUM_PICKS];

    chooseNumbers(winningTicket, NUM_PICKS, NUM_CHOICES);
    chooseNumbers(ticket, NUM_PICKS, NUM_CHOICES);

    std::cout << "Winning Ticket: ";
    printTicket(winningTicket, NUM_PICKS);
    std::cout << "My Ticket: ";
    printTicket(ticket, NUM_PICKS);

    return EXIT_SUCCESS;
}
