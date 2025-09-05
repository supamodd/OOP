using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP
{
    class Program
    {
        static void Main(string[] args)
        {
            Point point1 = new Point();
            //point.SetX(2);
            //point.SetY(3);
            //point.Print();
            
            point1.X = 7;
            point1.Y = 8;
            Console.WriteLine($"Первая точка: X = {point1.X}, Y = {point1.Y}");

            Point point2 = new Point();
            point2.X = 3;
            point2.Y = 5;
            Console.WriteLine($"Вторая точка: X = {point2.X}, Y = {point2.Y}");

            double distance = point1.Distance(point2);
            Console.WriteLine($"Расстояние между точками: {distance}");
        }
    }
}