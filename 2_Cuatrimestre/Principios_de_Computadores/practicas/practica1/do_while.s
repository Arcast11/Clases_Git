# Armando Castro

# asignación de variables a registros
# numero	-> $s0
# suma		-> $s1
# maximo 	-> $s2 

# tabla de assignación

	.data
titulo:		.asciiz "Principios de computadores ex_do_while.\n"
alumno:		.asciiz "Armando Castro.\n"
maximo:		.word 100
fin:		.asciiz "bucle terminado. Resultado: "

# int main(){
	.text
main:
# std::cout "Principios de comutadores ex_do_while\n"
la $a0,titulo
li $v0,4
syscall
# std::cout "Armando Castro\n"
la $a0,alumno
li $v0,4
syscall
# int maximo = 100;
lw $s2,maximo
# do {
do_while:
#	std::cin >> numero;
li $v0,5
syscall
move $s0,$v0
#	suma += numero
add $s1,$s1,$s0
# } while (suma < maximo);
blt $s1,$s2,do_while

while_fin:
# std::cout >> "bucle terminado. Resultado: "
la $a0,fin
li $v0,4
syscall
# std::cout >> suma;
move $a0,$s1
li $v0,1
syscall

# return 0; }
li $v0,10

