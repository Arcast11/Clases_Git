/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file igualdad_trigonométrica.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 13 2025
  * @brief explanation of the program
  */

#include <iostream>
#include <cmath>

int main(){

  double angle = 0;

  std::cout << "Introduzca un ángulo en radianes: ";
  std::cin >> angle;
  std::cout << (pow ((sin (angle)), 2)) + (pow ((cos (angle)), 2)) << std::endl;

  return 0;
}
