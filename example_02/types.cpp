#include <iostream>
#include <cstdlib>

int main (int argc, char **argv)
{
    // variables
    int hedwigAge = 7;
    int kayleeAge = 7;
    int haileyAge = -10;

    // Playing with printout out the variables
    std::cout << "Hediwg's age is: " << hedwigAge << std::endl;
    std::cout << "Kaylee's age is: " << kayleeAge << std::endl;
    std::cout << "Hailey's age is: " << haileyAge * 2 << std::endl;
    std::cout << "Hailey's age is: " << haileyAge << std::endl;
    std::cout << "Hailey's age is: " << haileyAge * -1 << std::endl;

    // Change everyone's age to have a year pass
    hedwigAge = 8;
    kayleeAge = kayleeAge + 1;
    haileyAge++; // increment by 1

    // seeing how things have changed
    std::cout << "Hediwg's age is: " << hedwigAge << std::endl;
    std::cout << "Kaylee's age is: " << kayleeAge << std::endl;
    std::cout << "Hailey's age is: " << haileyAge << std::endl;

    // other types
    bool haileyIsAlive = true;
    bool houseHasPool = false;
    bool kayleeHasBrownHair = 50; // boolean when set will be 0 or 1
    bool hedwigHasLongBlackHair = -50; // boolean when set will be 0 or 1

    std::cout << "Hailey is alive: " << haileyIsAlive << std::endl;
    std::cout << "House has pool: " << houseHasPool << std::endl;
    std::cout << "kaylee has brown hair: " << kayleeHasBrownHair << std::endl;
    std::cout << "hedwig has long black hair: " << hedwigHasLongBlackHair << std::endl;

    return EXIT_SUCCESS;
}
