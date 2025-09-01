using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FractionCS
{
    internal class Fraction
    {
        // Поля:
       internal int numerator;   // Числитель
       internal int denominator; // Знаменатель

                                                                       // Конструкторы:
        public Fraction(int numerator, int denominator)
        {
            if (denominator == 0)
            {
                throw new ArgumentException("Знаменатель не может быть равен нулю.");
            }

            this.numerator = numerator;
            this.denominator = denominator;
            Simplify(); // Упрощаем дробь при создании
        }

        public Fraction(int numerator) : this(numerator, 1) { }

        public Fraction() : this(0, 1) { } 

                                                             // Свойства:
        public int Numerator
        {
            get { return numerator; }
            set { numerator = value; }
        }

        public int Denominator
        {
            get { return denominator; }
            set
            {
                if (value == 0)
                {
                    throw new ArgumentException("Знаменатель не может быть равен нулю.");
                }
                denominator = value;
                Simplify(); 
            }
        }

                                            // Методы
        private void Simplify()
        {
            int gcd = GreatestCommonDivisor(Math.Abs(numerator), Math.Abs(denominator));
            numerator /= gcd;
            denominator /= gcd;

            if (denominator < 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        private int GreatestCommonDivisor(int a, int b)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        public override string ToString()
        {
            if (denominator == 1)
            {
                return numerator.ToString();
            }
            else
            {
                return $"{numerator}/{denominator}";
            }
        }
    }
}