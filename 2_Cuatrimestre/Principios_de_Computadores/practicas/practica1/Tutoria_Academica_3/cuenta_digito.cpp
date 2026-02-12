/*
Enunciado:
Realizar un programa que cuente el número de veces que aparece un dígito en
un número entero positivo.

Por ejemplo si el usuario introduce como numero el valor 12242 y como dígito el valor 2,
debe imprimir por la pantalla el número 3 (que es las veces que aparece 2 en 12242).

Los pasos a seguir deben ser:

1) Imprimir título
2) Pedir un número
3) Si el número es negativo salir del programa
4) Pedir un dígito. Si está fuera del rango de 0 a 9, volver a preguntar
5) Hace bucle que vaya obteniendo el dígito de las unidades, decenas, centenas.
  Si coincide con el buscado, incrementar contador
6) Mostrar por pantalla el contador con mensaje adecuado
7) Volver al punto 2
8) Terminar el programa con un mensaje de despedida.

*/

#include <iostream>
int main() {
  std::cout << "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n";

  while (true) {
    int numero;
    std::cout << "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): ";
    std::cin >> numero;
    if (numero < 0)
      break;

    int digito;
    do {
      std::cout << "Introduzca un digito (0-9): ";
      std::cin >> digito;
    } while ((digito < 0) || (digito > 9));
    int cuenta = 0;
    do {
      int resto = numero % 10;
      numero /= 10;
      if ( resto == digito )
        cuenta++;
    } while ( numero != 0 );
    std::cout << "El numero de veces que aparece el digito en el numero es: "
        << cuenta << '\n';
  }
  std::cout << "\nFin del programa.\n";
}
