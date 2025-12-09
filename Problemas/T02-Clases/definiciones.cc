/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file definiciones.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 09 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include "corona.h"
#include "reina.h"

std::ostream operator<<(std::ostream& out_stream, const Corona& corona) {
  out_stream << "Corona de: " << corona.corona_ << std::endl;
}

std::ostream operator<<(std::ostream& out_stream, const Reina& reina) {
  out_stream << reina.nombre_ << "tiene una corona" << reina.corona_
             << std::endl;
}

std::ostree
