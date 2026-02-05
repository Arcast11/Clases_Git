/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file main.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Jan 06 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include <algorithm>
#include <iostream>
#include <vector>

#include "rey.h"

int main() {
  std::vector<Rey> reyes{};
  reyes.reserve(10);
  Rey auxiliar_lectura{};
  while (std::cin >> auxiliar_lectura) {
    reyes.emplace_back(auxiliar_lectura);
  }
  std::sort(reyes.begin(), reyes.end());
  for (const Rey& rey : reyes) {
    std::cout << rey << ' ' << rey.DuracionReinado() << std::endl;
  }
  return 0;
}