/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file minimo_comun_multiplo.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 21 2025
  * @brief explanation of the program 
  */

#include <iostream>

int main (){

  int number {0};

  std::cin >> number;
  int suma = (number * (number + 1)) / 2;

  std::cout << suma << std::endl;

  return 0;
}
