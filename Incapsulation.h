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

inline void print(A& a)
{
    a.print();
}

//замена поведения
class someBehavior
{
private:
    A* field;

public:
    explicit someBehavior(bool flag)
    {
        if (flag)
            field = new A();
        else
            field = new B();
    }

    A getField()
    {
        return *field;
    }
};

//расширение поведения
class IClock
        {
protected:
    int hour;
    int minute;
public:
    virtual void time () = 0;

    void setHour(int hour) {
        IClock::hour = hour;
    }

    void setMinute(int minute) {
        IClock::minute = minute;
    }
};

class clock24 : public IClock {
public:
    virtual void time () {
        if (minute < 10) {
            std::cout << hour << ":0" << minute;
        } else {
            std::cout << hour << ":" << minute;
        }
    }
};

class clock12 : public IClock {
private:
    bool midday;
    int day;

public:
    virtual void time () { // c. Расширения поведения
        if (midday) {
            if (minute < 10) {
                std::cout << hour << ":0" << minute << " AM";
            } else {
                std::cout << hour << ":" << minute << " AM";
            }
        } else {
            if (minute < 10) {
                std::cout << hour << ":0" << minute << " PM";
            } else {
                std::cout << hour << ":" << minute << " PM";
            }
        }
    }

    void set_day(int day)
    {
        this->day = day;
    }
};

#endif //UNTITLED_INCAPSULATION_H
