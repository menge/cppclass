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
}
