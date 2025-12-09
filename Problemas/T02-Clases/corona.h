/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 09 2025
 * @brief Descripción del archivo
 */

#ifndef CORONA_H
#define CORONA_H
#include <iostream>
#include <string>

#include "reina.h"

class Corona {
 private:
  Corona(std::string corona) : corona_(corona) {}
  std::string corona_;

  friend class Reina;

  /// Metodo de acceso (Getter)
  std::string GetCorona() const { return corona_; }

  /// sobrecarga de operadores
  friend std::string operator<<(std::ostream& out_stream, Corona corona);
};

#endif  // CORONA_H