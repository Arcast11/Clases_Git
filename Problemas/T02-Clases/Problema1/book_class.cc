/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica 2025-${CURRENT_YEAR+1}
 *
 * @author Armando Castro armando.castro.31@ull.edu.es
 * @date Nov 25 2025
 * @brief clase representación de libros
 */

#include "book_class.h"

/**Constructor de la clase
 *  @param title: título del libro
 *  @param publish_date: Año de publicación
 *  @param price: precio de venta
 */

Books::Books(std::string title, int publish_date, double price)
    : title_{title}, publish_date_{publish_date}, price_{price} {}

/** Cálculo del precio de venta con impuestos
 *  @param taxes: impuesto de venta
 *  @return precio con impuestos
 */

double Books::CalcTaxes(const double taxes) {
  return price_ * (1 + taxes / 100);
}

/** Operador de inserción de flujo de salida para la clase book
 *  @param out_stream: Flujo de salida
 *  @param book: libro
 *  @return Referencia del flujo de salida
 */
std::ostream& operator<<(std::ostream& out_stream, const Books& book) {
  out_stream << book.title_ << ", " << book.publish_date_ << ", "
             << book.price_;
  return out_stream;
}