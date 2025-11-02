/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file power_of_two.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 13 2025
  * @brief explanation of the program 
  */

#include <iostream>
#include <cmath>

int main () {

  int exponente {0};

  std::cout << "Añade el exponente: ";
  std::cin >> exponente;
  
  for (int i {0} ; i <= exponente  ; ++i){
    std::cout << pow (2, i) << " ";
  }

  std::cout << std::endl;

return 0;
}
