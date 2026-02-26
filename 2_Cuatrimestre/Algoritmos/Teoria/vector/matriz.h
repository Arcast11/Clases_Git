#include "resize_ex.cpp"

namespace AYED {
class matriz : private vector {
 public:
  matriz(const size_t m, const size_t n) : vector(m * n), m_(m), n_(n){}
  
  
  double &at(const size_t i, const size_t j){
    const size_t k {pos_(i,j)};
    return vector::at(k);
  }

  double at(const size_t i, const size_t j){
    
  }
 
  private:
  size_t m_; // Filas
  size_t n_; // Columnas

  size_t pos_(const size_t i, const size_t j) const 
  {
    return (i - 1) * n_ + j - 1;
  }
};
}  // namespace Ayed