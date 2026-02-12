/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2026-
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Feb 11 2026
 * @brief Descripción del archivo
 */

#include <iostream>
#include <cmath>

class Trapecio {
 public:
  Trapecio (const int B, const int b, const int h) : B_(B), b_(b), h_(h) {}

  // Getters 

  int getB() const {return B_;}
  int Getb() const {return b_;}
  int geth() const {return h_;}

  // Setters
  
  void setB(const int B) {B_ = B;}
  void setb(const int b) {b_ = b;}
  void setB(const int h) {h_ = h;}

  // Metodos

  int Area() const { return (B_ + b_) * h_ * 0,5;}
  double Perimetro() const { return (B_ + b_) * h_ * 2 * Hipotenusa();}


  // Destructor
  ~Trapecio() {
    std::cout << "destructor trapecio" << std::endl;
  }


 private:
  int B_;
  int b_;
  int h_;

  double Hipotenusa() const {return std::sqrt(std::pow(2,(B_ - b_) / 2) + std::pow(2, h_));}
};

class Rectangle : protected Trapecio {
 public: 
  Rectangle(const int B, const int h) : Trapecio(B,B,h) {}
  ~Rectangle() {}

  int setB() const { return Trapecio::getB();}
  int seth() const { return Trapecio::geth();}
  int setArea() const { return Trapecio::Area();}
};

class Square : protected Rectangle {
 Square (const int l) : Rectangle(l,l) {}
 ~Square(){}
 int setArea() const { return Trapecio::Area(); }
 int set_l() const { return Rectangle::setB(); }
};