# Armando Castro - 08/02/2026

# Tabla de asignación de variables
# numero:       -> $s0
# aciertos:     -> $s1
# i    			-> $s2
# resultado:	-> $s3
# porcentaje	-> $s4

	.data
strtitulo:		.asciiz "Programa para repasar las tablas de multiplicar.\n"
strQueTabla:	.asciiz "¿Que tabla desea repasar? Introduce un numero (0 para salir): "
strX:			.asciiz " x "
strInterroga:	.asciiz " ? "
strPorcentaje:	.asciiz " % "
strTermina:		.asciiz "Termina el programa.\n"

	.text
# int main() {
main:
#   std::cout << "Programa para repasar las tablas de multiplicar. \n";
	la $a0,strtitulo
	li $v0,4
	syscall
#   int numero;  // Número del que quiero repasar la tabla
#   do {
	do_while:
#	  std::cout >> "Que tabla deseas representar"
	la $a0,strQueTabla
	li $v0,4
	syscall
#     std::cin >> numero;
	li $v0,5
	syscall
	move $s0, $v0
#     if (numero == 0) break;
	beqz $s0, while_fin
#     int aciertos = 0;  // si se introduce 0 para el bucle
#     for (int i = 1; i <= 10; i++) {
	li $s2,1
	li $t0,1

for:
	ble $t0,10 for_dentro 

for_dentro:
#       std::cout << i << " x " << numero << " ? ";
	li $v0,4
	move $a0,$s2
	syscall
	
	li $v0,4
	move $a0,$s2
	syscall	
	
	li $v0,4
	move $a0,$s2
	syscall
	
	li $v0,4
	move $a0,$s2
	syscall
#       int resultado;
#       std::cin >> resultado;
#       if (resultado == (i * numero)) {
#         aciertos++;
#       }
#     }
#     int porcentaje = aciertos * 10;
#     std::cout << "Tu porcentaje de aciertos es del " << porcentaje << "%\n";
#   } while (numero != 0);
	bnez $s0,do_while
while_fin:
#   std::cout << "Termina el program.\n";
#   return 0;
	li $v0,10
	syscall