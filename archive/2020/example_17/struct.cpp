#include <iostream>
#include <cstring>

struct FishTank {
    //char name[40];
    const char *name;
    float capacity;
    int numFish;
};
struct FishTankv2 {
    char name[40];
    int capacity;
    int numFish;
};

struct UserInterface {
    char theme[40];
    bool darkInterface;
    int pageVists;
    bool searchBarExists;
    double costOfPage;
};

struct PlayStructv1 {
    char b[1];
    double a[2];
};
PlayStructv1 myStructs[10];

struct PlayStruct {
    double a[2];
    char b[1];
    int c;
    char d[1];
};

int main(int argc, char** argv)
{
#if 0
    FishTank waterWaster;
    //strcpy(waterWaster.name, "Water Waster 2000");
    waterWaster.name = "Water Waster 2000";
    const char *foo = "Water Waster 2000";

    strcpy((char *)foo, "Hello World");

    waterWaster.capacity = 50.0;
    waterWaster.numFish = 1;
#endif

    FishTankv2 newWaterWaster;
    strcpy(newWaterWaster.name, "Water Waster 2000");
    newWaterWaster.capacity = 50.0;
    newWaterWaster.numFish = 1;

    newWaterWaster.name[48] = 'h';
    std::cout << "name: " << newWaterWaster.name << std::endl;
    std::cout << "capacity: " << newWaterWaster.capacity << std::endl;
    std::cout << "numFish: " << newWaterWaster.numFish << std::endl;

    UserInterface ui;
    std::cout << "sizeof theme: " << sizeof(ui.theme) << std::endl;
    std::cout << "sizeof darkInterface: " << sizeof(ui.darkInterface) << std::endl;
    std::cout << "sizeof pageVists: " << sizeof(ui.pageVists) << std::endl;
    std::cout << "sizeof searchBarExists: " << sizeof(ui.searchBarExists) << std::endl;
    std::cout << "sizeof costOfPage: " << sizeof(ui.costOfPage) << std::endl;
    std::cout << "sizeof UserInterface: " << sizeof(ui) << std::endl;

    PlayStruct ps;
    std::cout << "sizeof PlayStruct: " << sizeof(ps) << std::endl;
}
