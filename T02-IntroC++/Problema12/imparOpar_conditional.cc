**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file imparOpar_conditional.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 06 2025
  * @brief explanation of the program
  */

#include <iostream>
#include <string>

int main () {

  int number;

  std::cout << "introduzca un numero: ";
  std::cin >> number;

  std::string result = (number % 2 == 0) ? "El número es par":
                                           "El número es impar";
  
  std::cout << result << std::endl; 

return 0;
}
