/*
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2025-2026
  *
  * @file polinomio_grado2.cc
  * @author Armando Castro armando.castro.31@ull.edu.es
  * @date oct 07 2025
  * @brief
  */

#include <iostream>

int main(){

  double a, b, c, x {0};

  std::cout << "Dame los valores reales para a,b,c y un valor para x: ";
  std::cin >> a >> b >> c >> x;

  std::cout << "Valor de a: " << a << "\n"
            << "Valor de b: " << b << "\n"
            << "Valor de c: " << c << "\n"
            << "f(" << x << ")"  << a * x * x + b * x + c << std::endl;

  return 0;
}
