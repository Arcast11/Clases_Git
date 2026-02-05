/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file min_bits.cpp
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Jan 29 2026
 * @brief El programa calcula cuantos bits necesitas para
 *        representar todas las letras del abecedario
 */

#include <string>
#include <cmath>
#include <iostream>
#include <bitset>

int GetWordSize(int n_elements) {

  /// Con el logaritmo base 2, hallamos cuantos bits necesitamos usar
  const float flog = log2(n_elements);
  const int ilog = static_cast<int>(flog);

  if ((flog - ilog) == 0.0f) {
    return ilog;
  } else {
    return ilog + 1;
  }
}

int main() {
  std::string alfabeto {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  
  const int n = GetWordSize((alfabeto.size()));
  size_t code = 0;

  std::cout << "Alfabeto con " << alfabeto.size() << " caracteres" << std::endl;
  std::cout << "Usando " << n << " bits por codigo" << std::endl;
  std::cout << std::endl;

  for (char c : alfabeto) {
    std::bitset<32> code_bits(code);
    std::cout << "Caracter: " << c << " -> Codigo: " 
              << code_bits.to_string().substr(32 - n, n)
              << " (" << code << " decimal)" << std::endl;
    
    code++;  
  }
  
  return 0;
}
