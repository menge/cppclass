#include <cstdlib>
#include <iostream>

bool allMatch(int *array, int size);
int sumDice(int *array, int size);
#if 0
+----+----+----+----+----+----+
| 13 | 52 | 23 | XX | XX | XX |
+----+----+----+----+----+----+
  ^
  |
  array

  array[2]
#endif

bool allMatch(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] != array[i+1])
        {
            return false;
        }
    }
    return true;
}

int sumDice(int *array, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }

    return sum;
}

int productDice(int *array, int size)
{
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        product = product * array[i];
    }

    return product;
}

int main(int argc, char **argv)
{
    const int NUM_DICE = 5;
    int dice[NUM_DICE];

    const int DIE_SIDES = 6;
    const int LIMIT = 100000;
    const bool PRINT_INDIVIDUAL_DICE_VALUES = false;

    // Hold the statistics of the number of times we see each
    // sum and pairs that are rolled
    // for 2 dice: 14 spots, [0,...,13]; wasted: <0, 1, 13>
    // for 3 dice: 21 spots, [0,...,20]: wasted: <0, 1, 2, 19, 20>
    // for 4 dice: 28 spots, [0,...,27]: wasted: <0, 1, 2, 3, 25, 26, 27>
    int wasted_space = NUM_DICE - 1;
    int sum_counts[((DIE_SIDES+1) * NUM_DICE) - wasted_space] = {0};
    int matching[(DIE_SIDES+1)] = {0};

    // seed the random number generator with the current time
    unsigned int current_time = time(nullptr);
    srand(current_time);

    for (int i = 0; i < LIMIT; i++)
    {
        // rand() is pseudo random number generator that returns a 
        // 32 bit item where all the bits are randmoly set between
        // 0 and 1

        // roll all the dice
        for (int j = 0; j < NUM_DICE; j++)
        {
            dice[j] = (rand() % DIE_SIDES) + 1;

            if (PRINT_INDIVIDUAL_DICE_VALUES)
            {
                std::cout << "Die[" << j << "] value: " 
                          << dice[j] << std::endl;
            }
        }

        bool allMatching = allMatch(dice, NUM_DICE);
        if (allMatching)
        {
            matching[dice[0]] += 1;
        }

        int sum = sumDice(dice, NUM_DICE);
        sum_counts[sum] += 1;
    }
    if (not PRINT_INDIVIDUAL_DICE_VALUES)
    {
        std::cout << "Pairs:" << std::endl;
        for (int i = 1; i <= DIE_SIDES; i++)
        {
            std::cout << "AllMatch[" << i << "]: " << matching[i] << std::endl;
        }

        std::cout << "Sums:" << std::endl;
        for (int i = NUM_DICE; i <= DIE_SIDES*NUM_DICE; i++)
        {
            std::cout << "Sums[" << i << "]: " << sum_counts[i] << std::endl;
        }
    }
}
