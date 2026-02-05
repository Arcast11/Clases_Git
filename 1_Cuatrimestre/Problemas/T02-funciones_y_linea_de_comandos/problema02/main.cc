/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date oct 28 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>
#include "funciones.h"

int main(){
  int valor_a {0}, valor_b {0};

  std::cin >> valor_a >> valor_b;
  std::cout << Maximo_Comun_Divisor(int& valor_a, int& valor_b) << std::endl;
  
  return 0;
}

