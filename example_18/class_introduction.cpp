#include <cstring>
#include <iostream>

class Car
{
public:
    //Car() = delete;
    Car(const char *make, const char *model)
    {
        strcpy(_make, make);
        strcpy(_model, model);
        _gasAmount = 5;
        _gasCapacity = 50;
    }

    void foo()
    {
        strcpy(_make, "EMIL");
    }

    void addGas(float amount) {
        _gasAmount += amount;
        _gasAmount = std::min(_gasCapacity, _gasAmount);
    }

    void drive(/*Point b*/);
    void debug()
    {
        std::cout << "Make: " << _make << std::endl
                  << "Model: " << _model << std::endl
                  << "Gas: " << _gasAmount << std::endl
                  << "Gas Capacity: " << _gasCapacity << std::endl;
    }

    // Something you probably don't want
    float& getGasAmount()
    {
        return _gasAmount;
    }

private:
    char _make[16];;
    char _model[16];;
    float _gasAmount;
    float _gasCapacity;

    void _feedGasIntoEngine(float amount);
    void _changeMakeToEmil()
    {
        strcpy(_make, "EMIL");
    }
};

int main()
{
    Car myCar("Toyota", "Camary");
    myCar.debug();

    myCar.foo();
    myCar.debug();

    // something you don't want to do
    //float& gas = myCar.getGasAmount();
    //gas = 100;
    //myCar.debug();

    myCar.addGas(10);
    myCar.debug();

    myCar.addGas(50);
    myCar.debug();
}
