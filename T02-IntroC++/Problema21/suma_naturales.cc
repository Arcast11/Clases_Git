/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file suma_naturales.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 21 2025
  * @brief explanation of the program 
  */

#include <iostream>

int main (){

  int number {0};
  int sumatorio {0};

  std::cin >> number;
  for (int i {1}; i <= number; i++){
    sumatorio += number;
  }
  std::cout << "sumatorio de 1 hasta " << number << " = " << sumatorio 
            << std::endl;
  return 0;
}
