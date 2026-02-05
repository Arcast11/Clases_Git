/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file countvowels.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date nov 10 2025
 * @brief 
 * @bug There are no known bugs
 * @see 
 */

#include <iostream>
#include <string>

int CountVowels(const std::string& cadena){
  int count = 0;
  for (char c : cadena){
    char lower_c = std::tolower(c);
    if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || 
        lower_c == 'o' || lower_c == 'u'){
      count ++;
    }
  }
  return count;
}

int main(){
  std::string cadena;

  std::getline(std::cin, cadena);
  std::cout << "La cadena tiene: " << CountVowels(cadena) << " vocales"
            << std::endl;
  return 0;
}

