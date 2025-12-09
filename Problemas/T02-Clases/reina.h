/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 09 2025
 * @brief Descripción del archivo
 */

#ifndef REINA_H
#define REINA_H

#include <iostream>
#include <string>

#include "corona.h"

class Reina {
 public:
  Reina(std::string nombre, std::string corona)
      : nombre_(nombre), corona_(corona) {}

  /// Metodos de acceso (getters)
  Corona GetNombre() { return corona_; }

  /// sobrecarga de operadores

  friend std::ostream operator<<(std::ostream& out_stream, const Reina& cadena);

 private:
  std::string nombre_;
  Corona corona_;
};

#endif  // REINA_H
