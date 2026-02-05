/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 25 2025
 * @brief
 */

#ifndef CLASS_COMPLEX_H
#define CLASS_COMPLEX_H

#include <iostream>

class ComplexNumber {
 public:
  ComplexNumber(double real_part, double imaginary_part);
  double GetReal() const { return real_part_; }
  double GetImaginary() const { return imaginary_part_; }
  ComplexNumber operator-();
  ComplexNumber Conjugate();
  ComplexNumber Reverse();

 private:
  double real_part_;
  double imaginary_part_;
};

ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator-(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator*(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator*(const ComplexNumber&, const double);
ComplexNumber operator/(const ComplexNumber&, ComplexNumber&);
ComplexNumber operator/(const ComplexNumber&, const double);
std::ostream& operator<<(std::ostream& out_stream, const ComplexNumber complex);

#endif  /// CLASS_COMPLEX_H