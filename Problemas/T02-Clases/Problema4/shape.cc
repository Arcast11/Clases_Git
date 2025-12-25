/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file shape.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 25 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include "shape.h"

/** operador de comparación de áreas
 *  @param Shape : forma que va a comparar
 *  @return bool (true o false)
 */
bool Shape::operator<(const Shape& shape) {
  if (area_ < shape.area_) {
    return true;
  }
  return false;
}

/** Operador de flujo de salida
 *  @param shape: forma que vamos a imprimir por pantalla
 *  @return out_stream : flujo de salida
 */
std::ostream& operator<<(std::ostream& out_stream, const Shape& shape) {
  out_stream << shape.graph_ << shape.area_;
  return out_stream;
}