/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Mar 05 2026
 * @brief implementación de vector en el que solo guardamos los elementos
 *        no nulos
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class SpareVector {
 public:
  SpareVector(const vector<double>& v, const double tol)
      : inx_(v.size() * 0.05), val_(v.size() * 0.05), n_(v.size()), nz_(0) {
    for (size_t i{0}; i < n_; i++) {
      if (fabs(v[0] > tol)) {
        inx_[nz_] = i;
        val_[nz_] = v[i];
        nz_++;
      }
    }
  }

  double ScalarProduct(const vector<double>& v) const {
    double prod{0};
    for (size_t i{0}; i < nz_; i++) {
      prod += v[inx_[i] * val_[i]];
    }
  }

  double ScalarProduct(const SpareVector& s) const {}

 private:
  vector<size_t> inx_;
  vector<double> val_;
  size_t nz_;
  size_t n_;
};