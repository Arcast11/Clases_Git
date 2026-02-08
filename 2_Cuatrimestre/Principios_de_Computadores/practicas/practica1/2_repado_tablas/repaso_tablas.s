# Armando Castro - 08/02/2026

# Tabla de asignación de variables
# numero:       -> $s0
# aciertos:     -> $s1
# resultado:    -> $s2
# porcentaje:   -> $s3

	.data
strtitulo:	.asciiz "Programa para repasar las tablas de multiplicar.\n"
strQueTbla:	.asciiz "¿Qué tabla desea repasar? Introduce un número (0 para salir): "
strX:		.asciiz " x "
strInterroga:	.asciiz " ? "
strPorcentaje:	.asciiz " % "
strTermina:	.asciiz "Termina el programa.\n"

# int main() {
#   std::cout << "Programa para repasar las tablas de multiplicar. \n";
#   int numero;  // Número del que quiero repasar la tabla
#   do {
#     std::cin >> numero;
#     if (numero == 0) break;
#     int aciertos = 0;  // si se introduce 0 para el bucle
#     for (int i = 1; i <= 10; i++) {
#       std::cout << i << " x " << numero << " ? ";
#       int resultado;
#       std::cin >> resultado;
#       if (resultado == (i * numero)) {
#         aciertos++;
#       }
#     }
#     int porcentaje = aciertos * 10;
#     std::cout << "Tu porcentaje de aciertos es del " << porcentaje << "%\n";
#   } while (numero != 0);
#   std::cout << "Termina el program.\n";
#   return 0;