#/*
#Enunciado:
#Realizar un programa que cuente el número de veces que aparece un dígito en
#un número entero positivo.

#Por ejemplo si el usuario introduce como numero el valor 12242 y como dígito el valor 2

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
strPrograma:		.asciiz  "\nPrograma que cuenta el numero de veces que aparece un digito en numero entero positivo.\n"
strIntroNumero:		.asciiz  "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): "
strInroDigito:		.asciiz  "Introduzca un digito (0-9): "
strElNumero:		.asciiz  "El numero de veces que aparece el digito en el numero es: "
strFin:				.asciiz  "\nFin del programa.\n"

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

	li		$v0,4
	la		$a0, strPrograma
	syscall

#  while (true) {

while_true:
	# No hace falta condicion porque siempre se cumple → siempre entra


#    int numero;
#    std::cout << "\nIntroduzca un numero entero positivo (negativo para finalizar el programa): ";

	li		$v0,4
	la		$a0, strIntroNumero
	syscall

#    std::cin >> numero;

	li		$v0,5
	syscall
	move	$s4,$v0

#    if (numero < 0)
#      break;

	bltz	$s4,while_fin

#    int digito;
#    do {

do_while_digito:

#      std::cout << "Introduzca un digito (0-9): ";

	li		$v0,4
	la		$a0,strInroDigito
	syscall

#      std::cin >> digito;

	li 		$v0,5
	syscall
	move 	$s5,$v0

#    } while ((digito < 0) || (digito > 9));
	bltz 	$s5, do_while_digito
	li 		$t0, 9
	bgt 	$s5, $t0, do_while_digito


#    int cuenta = 0;

	li 		$s6, 0

do_while_contar:

#    do {
#      int resto = numero % 10;

	li 		$t1, 10

#      numero /= 10;

	div 	$s4, $t1
	mfhi	$t7
	mflo	$s4

#      if ( resto == digito )

if_resto_eq_digito:

	bne		$t7, $s5, while_num_neqz

#        cuenta++;

	addi 	$s6, $s6, 1

#    } while ( numero != 0 );

while_num_neqz:

	bnez	$s4, do_while_contar

#    std::cout << "El numero de veces que aparece el digito en el numero es: "

	li 		$v0, 4
	la		$a0, strElNumero
	syscall

#        << cuenta << '\n';

	li		$v0, 1
	move 	$a0, $s6
	syscall

#  }

	b	while_true

while_fin:
#  std::cout << "\nFin del programa.\n";

    li $v0, 4
    la $a0, strFin
    syscall

#}

	li		$v0,10
	syscall





