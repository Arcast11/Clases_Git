/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-2026
 *
 * @file Rey.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Jan 05 2026
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include "rey.h"

int Rey::DuracionReinado() const { return final_ - inicio_; }

/** Operador de comparación <
 * @param rey1: primer rey a comparar
 * @param rey2: segundo rey a comparar
 * @return bool devuelve verdadero si rey 1 es menor a rey 2
 */
bool operator<(const Rey& rey1, const Rey& rey2) {
  if (rey1.DuracionReinado() < rey2.DuracionReinado()) {
    return true;
  }
  return false;
}

/// Operador de inserción de flujo de salida
std::ostream& operator<<(std::ostream& out_stream, const Rey& rey) {
  out_stream << rey.GetNombre() << ' ' << rey.GetInicio() << ' '
             << rey.GetFinal();
  return out_stream;
}

/// Sobrecarga de operador de flujo de entrada
std::istream& operator>>(std::istream& in_stream, Rey& rey) {
  std::string nombre{""};
  int inicio{0}, final{0};
  in_stream >> nombre >> inicio >> final;
  rey.SetNombre(nombre);
  rey.SetInicio(inicio);
  rey.SetFinal(final);
  return in_stream;
}