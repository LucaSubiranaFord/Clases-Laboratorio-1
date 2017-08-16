using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace primerPrograma
{
    class Program
    {
        static void Main(string[] args)
        {
            int numeroUno;
            int numeroDos;
            //bool flag;
            //string datoAParsear;
            int resultado;

            Console.Write("Ingrese el primer numero: ");
            //datoAParsear = Console.ReadLine();
           // flag = int.TryParse(Console.ReadLine(), out numeroUno);

            while (!int.TryParse(Console.ReadLine(), out numeroUno))
            {
                Console.Write("Ingrese el primer numero: ");
                //datoAParsear = Console.ReadLine();
                //flag = int.TryParse(Console.ReadLine(), out numeroUno);
            }

            Console.Write("Ingrese el segundo numero: ");
            //datoAParsear = Console.ReadLine();
            //flag = int.TryParse(Console.ReadLine(), out numeroDos);
            while (!int.TryParse(Console.ReadLine(), out numeroDos))
            {
                Console.Write("Ingrese el segundo numero: ");
                //datoAParsear = Console.ReadLine();
               //flag = int.TryParse(Console.ReadLine(), out numeroDos);
            }
            resultado = numeroUno + numeroDos;

            Console.Write("El resultado es: "+resultado);
            Console.Read();
       
        }
    }
}
