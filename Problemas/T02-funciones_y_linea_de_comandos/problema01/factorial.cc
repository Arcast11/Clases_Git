/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file factorial.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 04 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>

int factorial(int n){

  for (int i = n - 1  ; i > 0; i--){
   n *= i;
  }
  return n;
}

int main(int argc, char* argv[]){
  if (argc != 2){
    std::cout << "Debe llamar el programa de la siguinete manera: "
              << argv[0] << "un número entero" << std::endl;
    return 1;
  }
  int numero = std::atoi (argv[1]);
  int n = 1;

  for (int i = 0; i < numero ; i++){
    std::cout << factorial(n) << " ";
    n++;
  }
  std::cout << std::endl;
  return 0;
}
  
