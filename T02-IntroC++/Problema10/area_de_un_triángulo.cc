/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file area_de_un_triángulo.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 07 2025
  * @brief explanation of the program
  */

#include <iostream>
#include <cmath>

int main(){

  double a, b, c = 0;

  
  std::cout << "intruduce los lados de un triángulo: ";
  std::cin >> a >> b >> c;
  
  double s = (a + b + c) / 2;

  std::cout << "El área del triángulo es: ";
  std::cout << sqrt (s * (s - a) * (s - b) * (s - c)) << std::endl;
  
  return 0;
}

