#include "hanoi.h"

void solve(cppclass::Hanoi &tower, int size, int orig, int dest, int temp)
{
    if (size == 0)
        return;

    solve(tower, size-1, orig, temp, dest);
    tower.move(orig, dest);
    tower.print();
    solve(tower, size-1, temp, dest, orig);
}

void solve2(cppclass::Hanoi &tower, int size, int orig, int dest, int other)
{
    if (size == 0)
    {
        return;
    }

    solve2(tower, size-1, orig, other, dest);
    tower.move(orig, dest);
    tower.print();
    solve2(tower, size-1, other, dest, orig);
}

int main()
{
    const int TOWER_SIZE = 11;
    cppclass::Hanoi tower(TOWER_SIZE);

#if 0
    tower.print();
    tower.move(0, 2);
    tower.print();
    tower.move(0, 1);
    tower.print();
    tower.move(2, 1);
    tower.print();
    tower.move(0, 2);
    tower.print();
    tower.move(1, 0);
    tower.print();
    tower.move(1, 2);
    tower.print();
    tower.move(0, 2);
    tower.print();
    tower.move(0, 1);
    tower.print();
    tower.move(2, 1);
    tower.print();
    tower.move(2, 0);
    tower.print();
    tower.move(1, 0);
    tower.print();
    tower.move(2, 1);
    tower.print();
    tower.move(0, 2);
    tower.print();
    tower.move(0, 1);
    tower.print();
    tower.move(2, 1);
    tower.print();
    tower.move(0, 2);
    tower.print();
    //solve(tower, 4, 1, 2, 0);

    //solve(tower, TOWER_SIZE, 0, 2, 1);
#endif
    solve2(tower, TOWER_SIZE, 0, 2, 1);
}
