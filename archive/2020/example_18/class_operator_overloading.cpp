#include <cstring>
#include <iostream>

class Integer
{
public:
    Integer(int i)
        :
        _i(i)
    {
    }

    void print() const
    {
        std::cout << _i << std::endl;
    }

    Integer operator+(const Integer& other)
    {
        Integer retval(0);
        //std::cout << "Inside operator+" << std::endl;
        //other.print();
        //this->print();
        //std::cout << "Finishing operator+" << std::endl;
        retval._i = other._i + this->_i;
        retval._i = other._i + _i;
        return retval;
    }

private:
    int _i;
};

int main()
{
    Integer a(5);
    Integer b(15);

    a.print();
    b.print();

    //Integer e = a.foo(b);
    //Integer d = b.operator+(a);
    Integer c = a + b;

    c.print();
}
