/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file raices_de_polinomio.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 07 2025
  * @brief explanation of the program 
  */

#include <iostream>
#include <cmath>

int main(){

  double a, b, c;

  std::cout << "Introduce los valores de a,b,c: ";
  std::cin >> a >> b >> c;

  std::cout << "x1: " <<  ((-b - (sqrt(b * b - 4 * a * c) )) / 2 * a) << std::endl;
  std::cout << "x2: " << ((-b + (sqrt(b * b - 4 * a * c) )) / 2 * a) << std::endl;

  return 0;
}
