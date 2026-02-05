/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file fibonacci_sequence.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 13 2025
  * @brief explanation of the program 
  */

#include <iostream>

int main () {
  
  std::cout << "Introduce los dígitos de la secuencia de fibonacci a mostrar: ";

  long long a = 0, b = 1;
  long long n = 0;
  
  std::cin >> n;

  for (int i = 1; i <=n; ++i) {
    std::cout << a << " ";
    long long auxiliar = a + b;
    a = b;                    //Le cambio el valor a las variables
    b = auxiliar;             //NO! poner el tipo de variable en este paso

  }

  std::cout << std::endl;
 
return 0;

}
  
