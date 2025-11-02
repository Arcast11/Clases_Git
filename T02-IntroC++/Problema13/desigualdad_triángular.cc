/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file igualdad_trigonomtrica.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 07 2025
  * @brief explanation of the programa
  */

#include <iostream>
#include <cmath>

int main(){

  double lado1, lado2, lado3 = 0;

  std::cout << "Introduzca lado 1: ";
  std::cin >> lado1;
  std::cout << "Introduzca lado 2: ";
  std::cin >> lado2;
  std::cout << "Introduzca lado 3: ";
  std::cin >> lado3;
  
  if ( ( lado1 + lado2 <= lado3) ||
       ( lado1 + lado3 <= lado2) ||
       ( lado2 + lado3 <= lado1 )) {
    std::cout << "No es un triángulo valido" << std::endl;
 } else {
    if ((lado1 == lado2) && (lado1 == lado3)) {
       std::cout << "El triángulo es equilatero" << std::endl;
   }else if ((lado1 == lado2) || (lado1 == lado3) || (lado2 == lado3)) {
      std::cout << "El triángulo es isosceles" << std::endl;
   }else {
      std::cout << "El triángulo es escaleno" << std::endl;
   }
 }

return 0;
}
