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

void printTicket(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ", ";
    }
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
