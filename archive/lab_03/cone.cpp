#include <cmath>
#include <iostream>

double cone_volume(double radius, double height, int depth, double rh_radius = 0.0);

int main()
{
    double radius = 100;
    double height = 1000;
    for (int i = 0 ; i < 24; i++)
    {
        auto cv = cone_volume(radius,height,i);
        std::cout << "Cylinder volume: " << cv << " Ratio: " << cv / cone_volume(radius,height,0) << std::endl;
    }
    //volume(1,1,10);
    return EXIT_SUCCESS;
}

double cone_volume(double radius, double height, int depth, double rh_radius)
{
    if (depth == 0)
    {
        return radius * radius * M_PI * height;
    }

    double mid_radius = radius - ((radius - rh_radius) / 2.0);
    return cone_volume(radius    , height/2.0, depth-1, mid_radius) +
           cone_volume(mid_radius, height/2.0, depth-1, rh_radius);
}
