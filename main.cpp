#include <iostream>
#include "Incapsulation.h"

int main()
{
    ////////////////////////////////////////////////////
    try
    {
        NoIncapsulation no_i(12);
        no_i.age_ = -124; // O_o

        Incapsulation i(42);
        i.setAge(18);
        i.setAge(-123); // throw logic_error
    }
    catch(std::logic_error& error)
    {
        std::cout << error.what() << std::endl;
    }

    try
    {
        IncapsulationUsingProtocols i_p;
        i_p.inc();
        i_p.inc();
        std::cout << i_p.getValue() << std::endl;

        IncapsulationUsingInterface i_i(12, 14, 15);
        std::cout << i_i.getArea() << std::endl;
        i_i.setEdges(100, 10, 10); // not nice, throw logic_error
    }
    catch(std::logic_error& error)
    {
        std::cout << error.what() << std::endl;
    }

    ////////////////////////////////////////////////////
    //Инкапсуляция поведения
    A a;
    B b;
    print(a);
    print(b);

    //замена поведения
    //можно ввести неопределённость путём ввода флага через консоль
    someBehavior some(true);
    some.getField().print();

    //расширение поведения
    clock24 clck1;
    clck1.time();

    clock12 clck2;
    clck2.time();
    clck2.set_day(2);

    return 0;
}
