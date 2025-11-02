/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file imparOpar_ifElse.cc
  * @author armando Castro  armando.castro.31@ull.edu.es
  * @date oct 04 2025
  * @brief El programa te dice si el numero introducido es par o impar
  */

#include <iostream>

int main() {

  int number;

  std::cout << "Introduzca un número: ";
  std::cin >> number;
  
  if (number % 2 == 0 ) {
    std::cout << "El número es par" << std::endl;
  } else {
    std::cout << "El número es impar" << std::endl;
  }

return 0;
}
