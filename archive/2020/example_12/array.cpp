#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <iostream>

void printGrades(double *grades, int size);
void increaseAllGrades(double *grades, int size, double amount);

void printGrades(double *grades, int size)
{
    std::cout << "Grades are: ";
    for (int i = 0; i < size; i++)
    {
        //std::cout << grades[i] << ", ";
        //std::cout << *(grades + i) << ", ";
        std::cout << *grades << ", ";
    }
    std::cout << std::endl;
}

void increaseAllGrades(double *grades, int size, double amount)
{
    for (int i = 0; i < size; i++)
    {
        grades[i] = std::min(100.0, grades[i] + amount);
    }
}

int main (int argc, char **argv)
{
    {
        const int NUM_GRADES = 10;
        double grades[NUM_GRADES];
        grades[0] = 100.0;
        grades[1] = 100.0;
        grades[2] = 100.0/3.0;
        grades[3] = 55.0;
        grades[4] = 65.0;
        grades[5] = 75.0;
        grades[6] = 0.1;
        grades[7] = 7.2;
        grades[8] = 80.3;
        grades[9] = -2.0;
    }
    double grades[] = {100.0, 100.0, 100.0/3.0, 55.0, 65.0, 75.0, 0.1, 7.2, 80.3};
    //float grades[] = {100.0, 100.0, 100.0/3.0, 55.0, 65.0, 10.0, 24e5, 17.0, M_PI, M_PI * 2};

    std::cout << "Sizeof grades: " << sizeof(grades) << std::endl;
    std::cout << "Number of elements in grades: " << sizeof(grades)/sizeof(grades[0]) << std::endl;
    const int NUM_ELEMENTS_IN_GRADES = sizeof(grades) / sizeof(grades[0]);

#if 1
    printGrades(grades, NUM_ELEMENTS_IN_GRADES);
    increaseAllGrades(grades, NUM_ELEMENTS_IN_GRADES, 10.0);
    printGrades(grades, NUM_ELEMENTS_IN_GRADES);
#endif

    return EXIT_SUCCESS;
}
