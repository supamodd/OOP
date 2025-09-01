using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FractionCS
{
    internal class Program
    {
        static void Main(string[] args)
        {
           
            Fraction fraction1 = new Fraction(1, 2);
            Fraction fraction2 = new Fraction(3, 4);
            Fraction fraction3 = new Fraction(6); 
            Fraction fraction4 = new Fraction(); 

            Console.WriteLine($"Дробь 1: {fraction1}");
            Console.WriteLine($"Дробь 2: {fraction2}");
            Console.WriteLine($"Дробь 3: {fraction3}");
            Console.WriteLine($"Дробь 4: {fraction4}");

          
            fraction1.Numerator = 5;
            fraction1.Denominator = 10; 
            Console.WriteLine($"Дробь 1 после изменения: {fraction1}");

            try
            {
                Fraction invalidFraction = new Fraction(1, 0); 
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine($"Ошибка при создании дроби: {ex.Message}");
            }
        }
    }
}
