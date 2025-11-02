/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file all_divisors.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 13 2025
  * @brief explanation of the program 
  */

#include <iostream>

int main(){

  int numerador {0};

  std::cout << "Introduce un número entero: ";
  std::cin >> numerador;

  for (int denominador {1} ; denominador >= 1 ; ++denominador){
    if (numerador % denominador == 0){
      std::cout << denominador << " ";
    }
   }
  std::cout << std::endl;
  return 0;
}
