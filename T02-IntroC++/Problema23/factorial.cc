/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file factorial.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 21 2025
  * @brief explanation of the program 
  */

#include <iostream> 

long Factorial(int number) {
  long producto {1};
  for (int i {2}; i <= number; i++){
   producto *= i;
  }
return producto;
}

int main(){
  
  long number;

  std::cin >> number;
  for (int i {0}; number <= i; i++){
    std::cout << Factorial(number) << std::endl;
  }
  return 0;
}
  
  

