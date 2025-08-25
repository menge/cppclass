#include <string>
#include <iostream>
#include <math.h>
#include <vector>

class Car
{
public:
    Car(Car& other) = delete;
    Car(Car&& other) = delete;

    bool at_target_speed()
    {
        return (speed >= target_speed);
    }

    void set_target_speed(double speed)
    {
        target_speed = speed;
    }

    virtual void set_inertial_speed(double speed)
    {
        inertial_speed = speed;
    }

    void tick(double time)
    {
        if (speed < target_speed)
        {
            speed += acceleration * time;
            accumulated_pollution += pollution_rate * pow(10, acceleration);
            time_running += time;
        }
        printf("%s has been running %f sec, current speed: %f pollution: %f\n",
               name.c_str(), time_running, speed, accumulated_pollution);
    }

protected:
    Car(std::string name, double normal_acceleration, double pollution_rate)
        : name(name)
        , speed(0.0)
        , target_speed(0.0)
        , acceleration(normal_acceleration)
        , pollution_rate(pollution_rate)
        , accumulated_pollution(0.0)
        , time_running(0.0)
        , inertial_speed(0.0)
    {
    }

protected:
    std::string name;
public:
    double speed;
protected:
    double target_speed;
    double acceleration;
    double pollution_rate;
    double accumulated_pollution;
    double time_running;
    double inertial_speed;
};

class Honda : public Car
{
public:
    Honda () : Car("Honda", 5.0, 1.0)
    {
    }
    Honda(Honda& other) = delete;
    Honda(Honda&& other) = delete;
};

class Volkswagon : public Car
{
public:
    Volkswagon () : Car("Volkswagon", 5.0, 2.0)
    {
    }

    virtual void set_inertial_speed(double speed) override
    {
        Car::set_inertial_speed(speed);
        if (inertial_speed == 0)
        {
            acceleration = 0.1;
            std::cout << "Volkswagon: engieering the truth" << std::endl;
        }
        else
        {
            acceleration = 5.0;
        }
    }
};

class Highway
{
public:
    Highway(std::vector<Car *> cars)
        : cars(cars)
    {
    }
    Highway(Highway &other) = delete;
    Highway(Highway &&other) = delete;

    void run()
    {
        for (auto &car : cars)
        {
            car->set_target_speed(60);
            while (not car->at_target_speed())
            {
                car->tick(0.1);
                car->set_inertial_speed(car->speed);
            }
        }
    }
private:
    std::vector<Car *> cars;
};

class Treadmill
{
public:
    Treadmill(std::vector<Car *> cars)
        : cars(cars)
    {
    }
    Treadmill(Treadmill &other) = delete;
    Treadmill(Treadmill &&other) = delete;

    void run()
    {
        for (auto &car : cars)
        {
            car->set_target_speed(60);
            while (not car->at_target_speed())
            {
                car->tick(0.1);
                car->set_inertial_speed(0);
            }
        }
    }
private:
    std::vector<Car *> cars;
};

int main()
{
    Honda origloo;
    Volkswagon crasher;

    std::vector<Car *> cars;
    cars.push_back(&origloo);
    cars.push_back(&crasher);

    //Highway highway(cars);
    //highway.run();

    Treadmill treadmill(cars);
    treadmill.run();
}
