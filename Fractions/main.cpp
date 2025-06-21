#define _CRT_SECURE_NO_WARNINGS  // Чтобы strtok не выдавал предупреждения
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
#define delimiter "---------------------------------"

using namespace std;

class Fraction 
{
//private:

public:
    int integer;
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

    friend istream& operator>>(istream& is, Fraction& fraction)
    {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        if (fraction.denominator == 0)
        {
            fraction.denominator = 1;
        }
        fraction.reduce();
        return is;
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction) 
    {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

class String
{
//private:
   

public:
    char* data;
    size_t length;
                                    // Конструкторы
    String() : data(nullptr), length(0) {}
    String(const char* str)
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }

    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }

                                // ДЕКонструктор
    ~String()
    {
        delete[] data;
    }

                                                     // Оператор присваивания
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy_s(data, length + 1, other.data);
        }
        return *this;
    }

                                    // Оператор обьединения
    String operator+(const String& other) const
    {
        String newString;
        newString.length = length + other.length;
        newString.data = new char[newString.length + 1];
        strcpy_s(newString.data, length + 1, data);
        strcpy_s(newString.data + length, other.length + 1, other.data);
        return newString;
    }

                                         // Оператор выходного потока
    friend ostream& operator<<(ostream& os, const String& str)
    {
        if (str.data) 
        {
            os << str.data;
        }
        return os;
    }

    
};

//std::istream& operator>>(std::istream& cin, Fraction& obj)
//{
//    /*
//    ------------------
//    5
//    1/2
//    2(3/4)
//    3 4/5
//    3.4/5
//    3,4/5
//    ------------------
//    */
//
//    const int SIZE = 32;
//    char sz_input[SIZE] = {};	//sz_ - String Zero (Строка, заканчивающаяся нулем)
//    //is >> sz_input;
//    cin.getline(sz_input, SIZE);	//Ввод строки с пробелами
//    //cout << sz_input << endl;
//    const char delimiters[] = { '(', '/', ')', ' ', '.', ',', 0 };
//    int numbers[3] = {};
//    int n = 0;
//
//    /*
//    ---------------------------
//    Функция strtok() разбивает строку на токены;
//    Разделители (delimiters) - это символы, по которым нужно делить строку;
//    Токены (tokens) - это элементы, которые нужно достать из строки (это все что НЕ разделители);
//    Функция strtok() возвращает указатель на найденный токен, если токен не найден,
//    то функция возвращает 'nullptr';
//    pch - Pointer to Character, содержит указатель на первый символ токена.
//    ---------------------------
//    */
//    //https://legacy.cplusplus.com/reference/cstring/strtok/
//    for (char* pch = strtok(sz_input, delimiters); pch && n < 3; pch = strtok(NULL, delimiters))
//        numbers[n++] = atoi(pch);	//https://legacy.cplusplus.com/reference/cstdlib/atoi/
//    /*
//    ---------------------------
//    Функция atoi() ASCII to Integer, принимает строку ASCII-сиволов, и возвращает целое число,
//    соответствуюзее этой строке.
//    ---------------------------
//    */
//
//    //for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;
//
//    switch (n)
//    {
//    case 1:obj = numbers[0]; break;
//    case 2:obj = Fraction(numbers[0], numbers[1]); break;
//    case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
//    }
//
//    return cin;
//}
/*
------------------------------
Функция strtok() разбивает строку на токены.
Разделители (delimiters) - это символы, по которым нужно делить строку
Токены(tokens) - это элементы, которые нужно достать ( это все что НЕ разделители);
При поиске разделителей, стрток разделяет строку.
Стрток находит не за один вызов, а за последовательность вызовов. При чем входная строка (сз_инпут, передается только при первом вызове
в след вызовах в кач. 1го параметра передается NULL. Если при последующих вызывах передавать входную строку,
то стрток начинает поиск сначала.
Функция стрток() возвращает указатель на найденный тоекн, если токен не найдет, то функция возвращает 'nullptr'
pch - Pointer to Character, содержит указатель на первый символ токена.
------------------------------
Функция atoi() ASCII to Integer, принимает строку ASCII-символов, и возвращает целое число, соответствующее этой строке.
*/

void main() 
{
    setlocale(LC_ALL, "");
    Fraction A;
    cout << "Введите простую дробь: "; cin >> A;
    cout << A << endl;
    cout << delimiter << endl;

    String str1 = "ООП";
    String str2 = "ООП2";
    String str3 = str1 + str2;
    cout << str3 << endl;
    cout << delimiter << endl;

    cout << (Fraction(1, 2) >= Fraction(5, 6)) << endl;
    cout << delimiter << endl;
}