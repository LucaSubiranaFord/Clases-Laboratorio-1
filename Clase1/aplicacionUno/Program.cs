using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace aplicacionUno
{
    class Program
    {
        static void Main(string[] args)
        {
            int numero;
            int contador;
            contador = 0;
            int numeroMayor;
            numeroMayor = 0;
            int numeroMenor;
            numeroMenor = 0;
            int acumulador = 0;
            float promedio;
            promedio = 0;

            while (contador < 7)
            {
                Console.Write("Ingrese un numero: ");
                while (!int.TryParse(Console.ReadLine(), out numero))
                {
                    Console.Write("Ingrese un numero: ");
                }
                if (contador == 0)
                {
                    numeroMayor = numero;
                    numeroMenor = numero;
                }
                else
                {
                    if (numeroMayor < numero)
                    {
                        numeroMayor = numero;
                    }
                    if (numeroMenor > numero)
                    {
                        numeroMenor = numero;
                    }
                }

                acumulador += numero;
                promedio = acumulador / 7;
                contador++;
            }
            Console.WriteLine("El numero mayor es: "+numeroMayor);
            Console.WriteLine("El numero menor es: " +numeroMenor);
            Console.WriteLine("El promedio es: " +promedio);
            Console.Read();
        }
    }
}
