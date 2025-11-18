/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file cadena_alfabetica.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 11 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */
#include <iostream>
#include <vector>
#include <string>

std::string ToString(const std::vector<int>& enteros){
  std::string salida;

  for(const auto& valor: enteros){
    salida += ' ' +std::to_string(valor) + ',';
  }
  salida.front() = '{';
  salida.back() = '}';
  return salida;
}
int main(){

  // Al declarar el vector con parentesis, estas colocando 3 sietes
  std::vector<int> vector1(3, 7), vector2{3, 7};
  std::cout << ToString(vector1) << std::endl
            << ToString(vector2) << std::endl
            << ToString({3, 7}) << std::endl;
  return 0;
}


