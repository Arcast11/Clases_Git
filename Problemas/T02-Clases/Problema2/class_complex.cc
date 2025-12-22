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

/** Constructor del número complejo
 *  @param real_part: parte real del número complejo
 *  @param impaginary_part: parte imaginaria del número complejo
 *
 */
ComplexNumber::ComplexNumber(double real_part, double imaginary_part)
    : real_part_{real_part}, imaginary_part_{imaginary_part} {}

/** Sobrecarga de operador menos
 * @return mismo complejo en negativo
 */
ComplexNumber ComplexNumber::operator-() {
  return {-GetReal(), -GetImaginary()};
}

/** Conjugado de un número complejo
 * @return Conjugado del complejo
 */
ComplexNumber ComplexNumber::Conjugate() {
  return {real_part_, -imaginary_part_};
}

/** Metodo inverso
 * @return: devuelve el inverso de un número complejo
 */
ComplexNumber ComplexNumber::Reverse() {
  double square_modulus{(real_part_ * real_part_) +
                        (imaginary_part_ * imaginary_part_)};
  return {Conjugate() / square_modulus};
}

/** Sobrecarga de Operador suma
 * @param left: el número complejo a sumar
 * @param right:
 * @return suma de dos números complejos
 */
ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right) {
  return {left.GetReal() + right.GetReal(),
          left.GetImaginary() + right.GetImaginary()};
}

/** Spbrecarga de operador resta
 * @param left: minuendo
 * @param right: sustraendo
 * @return left menos right
 */
ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right) {
  return {left.GetReal() - right.GetReal(),
          left.GetImaginary() - right.GetImaginary()};
}

/** Sobrecarga de operador * complejo por escalar
 * @param complex: complejo
 * @param scalar: escalar
 * @return parte real e imaginaria multiplicada por el escalar
 */
ComplexNumber operator*(const ComplexNumber& complex, const double scalar) {
  return {complex.GetReal() * scalar, complex.GetImaginary() * scalar};
}

/** Multiplicación de complejo por complejo
 * @param left : primer factor
 * @param right : segundo factor
 */
ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right) {
  return {left.GetReal() * right.GetReal() -
              left.GetImaginary() * left.GetImaginary(),
          left.GetReal() * right.GetImaginary() +
              left.GetReal() * left.GetImaginary()};
}

/** División por un escalar
 * @param complex : numerador (número complejo)
 * @param scalar : denominador (escalar)
 * @return: complejo entre escalar
 */
ComplexNumber operator/(const ComplexNumber& complex, const double scalar) {
  return {complex.GetReal() / scalar, complex.GetImaginary() / scalar};
}

/** División de complejos
 * @param left: númerador
 * @param right: denominador
 * @return resultado de division de complejos
 */
ComplexNumber operator/(const ComplexNumber& left, ComplexNumber& right) {
  return left * right.Reverse();
}

/** Operador de flujo de salida
 * @param: número coplejo
 * @return: flujo de salida
 */
std::ostream& operator<<(std::ostream& out_stream,
                         const ComplexNumber complex) {
  out_stream << "(" << complex.GetReal() << ", " << complex.GetImaginary()
             << ")";
  return out_stream;
}
