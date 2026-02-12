#/*
#Enunciado:
#Realizar un programa que cuente el número de veces que aparece un dígito en
#un número entero positivo.

#Por ejemplo si el usuario introduce como numero el valor 12242 y como dígito el valor 2,
#debe imprimir por la pantalla el número 3 (que es las veces que aparece 2 en 12242).

#Los pasos a seguir deben ser:

#1) Imprimir título
#2) Pedir un número
#3) Si el número es negativo salir del programa
#4) Pedir un dígito. Si está fuera del rango de 0 a 9, volver a preguntar
#5) Hace bucle que vaya obteniendo el dígito de las unidades, decenas, centenas.
#  Si coincide con el buscado, incrementar contador
#6) Mostrar por pantalla el contador con mensaje adecuado
#7) Volver al punto 2
#8) Terminar el programa con un mensaje de despedida.
#*/

##include <iostream>
#int main() {
#  std::cout << "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n";

#  while (true) {
#    int numero;
#    std::cout << "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): ";
#    std::cin >> numero;
#    if (numero < 0)
#      break;

#    int digito;
#    do {
#      std::cout << "Introduzca un digito (0-9): ";
#      std::cin >> digito;
#    } while ((digito < 0) || (digito > 9));
#    int cuenta = 0;
#    do {
#      int resto = numero % 10;
#      numero /= 10;
#      if ( resto == digito )
#        cuenta++;
#    } while ( numero != 0 );
#    std::cout << "El numero de veces que aparece el digito en el numero es: "
#        << cuenta << '\n';
#  }
#  std::cout << "\nFin del programa.\n";
#}

	.data
strPrograma:	.asciiz  "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n"
strElNumero:	.asciiz  "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): "
strInroDigito:	.asciiz  "Introduzca un digito (0-9): "
strElNumero:	.asciiz  "El numero de veces que aparece el digito en el numero es: "
strFin:			.asciiz  "\nFin del programa.\n"

############################################
# Tabla de asignación de registros
#  Variable 		registros
#  int numero		→ $s4
#  int digito		→ $s5
#  int cuenta		→ $s6
#  int resto		→ $t7

	.text

#int main() {

main:
#  std::cout << "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n";

	li	$v0,4
	la	$a0, strPrograma
	syscall

#  while (true) {

whileTrue:
	# No hace falta condicion porque siempre se cumple → siempre entra


#    int numero;
#    std::cout << "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): ";

	li	$v0,4
	la	$a0, strElNumero
	syscall

#    std::cin >> numero;

li	$v0,5
	syscall
	move	$s4,$v0

#    if (numero < 0)
#      break;

	bltz	$s4,whileFin

#    int digito;
#    do {

do_while_digito:

#      std::cout << "Introduzca un digito (0-9): ";

	li	$v0,4
	la	$a0,strInroDigito
	syscall

#      std::cin >> digito;

	li 	$v0,5
	syscall
	move 	$s5,$v0

#    } while ((digito < 0) || (digito > 9));

while_digitolt0_digitogt9

#    int cuenta = 0;
#    do {
#      int resto = numero % 10;
#      numero /= 10;
#      if ( resto == digito )
#        cuenta++;
#    } while ( numero != 0 );
#    std::cout << "El numero de veces que aparece el digito en el numero es: "
#        << cuenta << '\n';
#  }
	b	whileTrue

whileFin:
#  std::cout << "\nFin del programa.\n";
#}

	li	$v0,10
	syscall





