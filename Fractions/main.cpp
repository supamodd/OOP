#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Fraction 
{
//private:

public:
    int numerator;    // Числитель
    int denominator;  // Знаменатель

    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void reduce()
    {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }


    // Конструкторы

    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) 
    {
        if (denominator == 0)
        {
            cerr << "Ошибка: Знаменатель не может быть равен нулю.\n";
            numerator = 0;
            denominator = 1;
        }
        reduce();
    }

                                                                         // Методы доступа

    int getNumerator() const { return numerator; }    // Получить числитель
    int getDenominator() const { return denominator; }  // Получить знаменатель

    // Арифметические операторы
    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        if (other.numerator == 0)
        {
            std::cerr << "Ошибка: Деление на ноль.\n";
            return Fraction(0, 1); // Возвращаем 0/1 елси деление на ноль
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Операторы инкремента/декремента
    Fraction& operator++()
    { 
        numerator += denominator;
        reduce();
        return *this;
    }

    Fraction operator++(int)
    { 
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() 
    { 
        numerator -= denominator;
        reduce();
        return *this;
    }

    Fraction operator--(int) 
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    // Операторы составного присваивания
    Fraction& operator+=(const Fraction& other) 
    {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) 
    {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    Fraction& operator*=(const Fraction& other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) 
    {
        if (other.numerator == 0) 
        {
            cerr << "Ошибка: Деление на ноль.\n";
            numerator = 0;
            denominator = 1;
            return *this;
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        reduce();
        return *this;
    }

    // Операторы сравнения
    bool operator==(const Fraction& other) const 
    {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    bool operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return (double)numerator / denominator < (double)other.numerator / other.denominator;
    }

    bool operator>(const Fraction& other) const
    {
        return (double)numerator / denominator > (double)other.numerator / other.denominator;
    }

    bool operator<=(const Fraction& other) const
    {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const 
    {
        return !(*this < other);
    }

    
    friend ostream& operator<<(ostream& os, const Fraction& fraction)
    {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

void main() 
{
    
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
    
}