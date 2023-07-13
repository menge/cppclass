#include <cstring>
#include <iostream>

void addStudent()
{
    std::cout << "Hello!!" << std::endl;
}

struct Classroom
{
    char teacherName[64];
    unsigned int numStudents;
    bool windowsOpened;
    bool doorOpened;

    void assignTeacher(const char* teacherName)
    {
        strcpy(this->teacherName, teacherName);
    }

    void addStudent()
    {
        numStudents++;
    }
    void introspect(const Classroom *p)
    {
        if (this == p)
        {
            std::cout << "I am myself" << std::endl;
        }
        if (this != p)
        {
            std::cout << "I do not see myself" << std::endl;
        }
    }

    void openWindows()
    {
        // this->numStudents = 0;
        // (*this).numStudents = 0;
        windowsOpened = true;
        addStudent(); //Some students outside will jump inside the classroom to join it
    }

    void closeWindows()
    {
        windowsOpened = false;
    }

    void closeDoor() 
    {
        doorOpened = false;
    }

    void openDoor() 
    {
        doorOpened = true;
        numStudents = 0;
    }

    void debugPrint()
    {
        std::cout << "The teacher for this classrom is: " << teacherName << std::endl;
        std::cout << "The number of students is: " << numStudents << std::endl;
        std::cout << "The window is opened: " << windowsOpened << std::endl;
        std::cout << "The door is opened: " << doorOpened << std::endl;
    }
};

int main()
{
    Classroom fun;
    Classroom boring;

#if 0
    Classroom dry;

    &fun == fun.this;
    &boring == boring.this;

    boring.numStudents = 30;
    Classroom *classroom_ptr = &boring;
    classroom_ptr->numStudents = 20;
    (*classroom_ptr).numStudents = 20;
    classroom_ptr = &fun;
    (*classroom_ptr).numStudents = 20;

    Classroom *classroom_ptrs[] = { &fun, &boring, &dry};
    for (int i = 0; i < 3; i++)
    {
        Classroom *p = classroom_ptrs[i];
        p->numStudents = 10;
    }
#endif

    fun.assignTeacher("Anthony Cardon");
    fun.numStudents = 0;
    fun.addStudent();
    fun.addStudent();
    fun.addStudent();
    fun.addStudent();
    fun.addStudent();
    fun.closeWindows();
    fun.closeDoor();

    fun.debugPrint();

    fun.openDoor();
    fun.debugPrint();

    Classroom guitar;
    //fun.introspect(&fun);
    //fun.introspect(&guitar);
    //guitar.introspect(&guitar);
    //guitar.introspect(&fun);
    guitar.introspect(nullptr);

    char f = '\0';
}
