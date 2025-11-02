/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file teorema_de_pitagoras.cc
  * @author armando.castro.31@ull.edu.es
  * @date oct 04 2025
  * @brief Introduces los lados de un triángulo rectángulo, y se cálcula
  *        el teorema de pitagoras.
 */

#include <iostream>
#include <cmath>

int main() {

  double catetoA;
  double catetoB;

  std::cout << "introduzca cateto a: ";
  std::cin >> catetoA;
  std::cout << "Introduzca el cateto b; ";
  std::cin >> catetoB;
  std::cout << "El valor de la hipotenusa es: " << std::hypot(catetoA,catetoB)
                                                                 << std::endl;
return 0;
}
  
 
