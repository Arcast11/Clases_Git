/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-2026
 *
 * @file class_complex.cc
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Dec 20 2025
 * @brief Descripción del archivo
 * @bug There are no known bugs
 * @see
 */

#include "class_complex.h"

/** Constructor de ComplexNumber
 *  @param real_part: parte real del numero complejo
 *  @param imaginary_part: parte imaginaria del número complejo
 */

ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
    : imaginary_part_{imaginary_part}, real_part_{real_part} {}


