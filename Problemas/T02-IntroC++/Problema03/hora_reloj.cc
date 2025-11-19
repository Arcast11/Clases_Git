#include <iostream>

int main() {

 int horaActual;
 int hoursAdd;

 std::cout << "inserte la hora actual";
 std::cin >> horaActual;
 std::cout << "Cantidad de horas añadidas";
 std::cin >> hoursAdd;

 int newHour = (horaActual + hoursAdd) % 12;
 if (newHour == 0) {
     newHour = 12;
 }
 std::cout << "En " << hoursAdd << "horas, el reloj marcará las " << newHour << std::endl;

return 0;

}
