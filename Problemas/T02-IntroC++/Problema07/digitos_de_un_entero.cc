/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file digitos_de_un_entero.cc
  * @author armando.castro.31@ull.edu.es
  * @date oct 04 2025
  * @brief Cálcula el número de digitos de un número entero utilizando logaritmos
  */

#include <iostream>
#include <cmath>

int main() {

  int number;
  
  std::cout << "Introduzca un número entero: ";
  std::cin >> number;
  std::cout << "El número de dígitos de " << number << " es: " 
                          << std::floor(log10 (number) + 1) << std::endl;
 
return 0;
}
