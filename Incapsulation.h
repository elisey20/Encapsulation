//
// Created by elisey on 29.05.2021.
//

#ifndef UNTITLED_INCAPSULATION_H
#define UNTITLED_INCAPSULATION_H

#include <iostream>
#include <cmath>

//отсутствие инкапсуляции
class NoIncapsulation
{
public:
    int age_;

    explicit NoIncapsulation(int age) : age_(age) {};
};

//инкапсуляция с помощью set/get
class Incapsulation
{
private:
    int age_;

public:
    explicit Incapsulation(int age) : age_(age) {};

    void setAge(int age)
    {
        if (age < 0 || age > 99)
            throw std::logic_error("Недопустимый возраст");
        else age_ = age;
    }

    int getAge() const
    {
        return age_;
    }
};

//инкапсуляция с помощью специализированных протоколов/методов
class IncapsulationUsingProtocols
{
private:
    int counter_;

public:
    IncapsulationUsingProtocols() : counter_(0) {};

    void inc()
    {
        counter_++;
    }

    int getValue() const
    {
        return counter_;
    }
};

//интерфейс определяющий фигуру на плоскости
class Figure
{
public:
    virtual void setEdges() = 0;
    virtual float getArea() = 0;
};

//интерфейс определяющий треугольник на плоскости
class FigureForTriangle : public Figure
{
private:
    void setEdges() override {};

public:
    virtual void setEdges(float a, float b, float c) = 0;
    virtual float getArea() override = 0;
};

//инкапсуляция за счёт абстракций
class IncapsulationUsingInterface : public FigureForTriangle
{
private:
    //стороны треугольника
    float a_, b_, c_;

public:
    IncapsulationUsingInterface(float a, float b, float c)
    {
        if (a + b < c || a + c < b || b + c < a)
            throw std::logic_error("Неверные параметры сторон треугольника");

        this->a_ = a;
        this->b_ = b;
        this->c_ = c;
    };

    void setEdges(float a, float b, float c) override
    {
        if (a + b < c || a + c < b || b + c < a)
            throw std::logic_error("Неверные параметры сторон треугольника");

        this->a_ = a;
        this->b_ = b;
        this->c_ = c;
    }

    float getArea() override
    {
        float p = (a_ + b_ + c_) / 2;
        return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
};

//инкапсуляция поведения за счет позднего связывания
class A
{
public:
    virtual void print()
    {
        std::cout << "Its A" << std::endl;
    }
};

class B: public A
{
public:
    void print() override
    {
        std::cout << "Its B" << std::endl;
    }
};

void print(A& a)
{
    a.print();
}

//замена поведения


//расширение поведения

//разобраться с расширением поведения

#endif //UNTITLED_INCAPSULATION_H
