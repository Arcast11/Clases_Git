#// Programa para evaluar polinomio tercer grado
#//Realiza un programa en ensamblador MIPS que evalúe un polinomio de tercer 
#//grado de la forma 
#//f(x) = a x^3 + b x^2 + c x + d
#//en un rango de valores enteros [r,s] y devuelva aquellos valores que 
#//son mayores de 2.5
#//El programa debe pedir por consola:
#//- cuatro números flotantes en simple precisión: a, b, c y d
#//- dos números enteros r y s comprobando que r <= s 

# Testear en
# https://codetest.iaas.ull.es/testeaPrinComp/testea/bbad44792ef4f0305d176

# #include <iostream>
# #include <iomanip>

# int main(void) {
#   std::cout << std::fixed << std::setprecision(8);  // Ignorar
#   float a,b,c,d;
#   std::cout << "\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
#             << " en un intervalo [r,s]\n";
#   std::cout << "\nIntroduzca coeficiente a: ";
#   std::cin >> a;
#   std::cout << "Introduzca coeficiente b: ";
#   std::cin >> b;
#   std::cout << "Introduzca coeficiente c: ";
#   std::cin >> c;
#   std::cout << "Introduzca coeficiente d: ";
#   std::cin >> d;
#   int r,s;
#   do {
#     std::cout << "\nLímite inferior r: ";
#     std::cin >> r;
#     std::cout << "Límite superior s: ";
#     std::cin >> s;
#   } while (r > s);

#   for (int x = r ; x <= s ; x++) {
#     // float f = x*x*x*a + x*x*b + x*c + d;
#     float f = d;
#     f += x*c;
#     f += x*x*b;
#     f += x*x*x*a;
#    if (f >= 2.5) {
#      std::cout << "f(" << x << ") = " << f;
#    } else {
#      std::cout << x << " no supera";
#    }
#    std::cout << '\n';
#   }
#   std::cout << "\n\nTermina el programa\n";
# }

	.data
strTitulo:	.ascii	"\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
		.asciiz	" en un intervalo [r,s]\n"
strIntroA:	.asciiz	"\nIntroduzca coeficiente a: "
strIntroB:	.asciiz	"Introduzca coeficiente b: "
strIntroC:	.asciiz	"Introduzca coeficiente c: "
strIntroD:	.asciiz	"Introduzca coeficiente d: "

strIntroR:	.asciiz	"\nLímite inferior r: "
strIntroS:	.asciiz	"Límite superior s: "

strF:		.asciiz	"f("
strIgual:	.asciiz	") = "
strNoSupera:	.asciiz	" no supera"
strSaltoLinea:	.asciiz	"\n"
strTermina:	.asciiz	"\n\nTermina el programa\n"

##### Tabla de asignación de variables ##############
# float 	a → $f20
# float 	b → $f22
# float  	c → $f24
# float 	d → $f26
# float		f → $f18
# int 		r → $s0
# int 		s → $s1
# int 		x → $s2
# float		x → $f28
#######################################################

	.text
# int main(void) {
main:
#   float a,b,c,d;
#   std::cout << "\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
#             << " en un intervalo [r,s]\n";
	li	$v0,4
	la	$a0,strTitulo
	syscall

#   std::cout << "\nIntroduzca coeficiente a: ";
	li	$v0,4
	la	$a0,strIntroA
	syscall
#   std::cin >> a;
	li	$v0,6
	syscall
	mov.s	$f20,$f0

#   std::cout << "Introduzca coeficiente b: ";
	li	$v0,4
	la	$a0,strIntroB
	syscall

#   std::cin >> b;
	li	$v0,6
	syscall
	mov.s	$f22,$f0

#   std::cout << "Introduzca coeficiente c: ";
	li	$v0,4
	la	$a0,strIntroC
	syscall
	
#   std::cin >> c;
	li	$v0,6
	syscall
	mov.s	$f24,$f0

#   std::cout << "Introduzca coeficiente d: ";
	li	$v0,4
	la	$a0,strIntroD
	syscall

#   std::cin >> d;
	li	$v0,6
	syscall
	mov.s	$f26,$f0

#   int r,s;
#   do {
do_while_rs:

#     std::cout << "\nLímite inferior r: ";
	li	$v0,4
	la	$a0,strIntroR
	syscall

#     std::cin >> r;
	li	$v0,5
	syscall
	move	$s0,$v0


#     std::cout << "Límite superior s: ";
	li	$v0,4
	la	$a0,strIntroS
	syscall

#     std::cin >> s;
	li	$v0,5
	syscall
	move	$s1,$v0

#   } while (r > s);
	bgt	$s0,$s1,do_while_rs

while_fin_rs:

#   for (int x = r ; x <= s ; x++) {
	move	$s2,$s0
for:
	bgt	$s2,$s1,for_fin
	
	mtc1	$s2,$f18
	cvt.s.w	$f30,$f18

#     // float f = x*x*x*a + x*x*b + x*c + d;

	mul.s	$f4,$f30,$f30	# $f4 = x * x
	mul.s	$f8,$f4,$f30	# $f8 = x * x * x
	mul.s	$f8,$f8,$f20	# $f8 = x*x*x*a
	
	mul.s	$f6,$f4,$f22	# $f6 = x * x * b
	
	mul.s	$f10,$f30,$f24	# $f10 = x * c
	
	add.s	$f28,$f8,$f6
	add.s	$f28,$f28,$f10
	add.s	$f28,$f28,$f26
	
#     float f = d;
	mov.s	$f28,$f26
	
#     f += x*c;
	add.s	$f28,$f28,$f10	# f = f + x*c

#     f += x*x*b;
	add.s	$f28,$f28,$f6	# f = f + x*x*b
#     f += x*x*x*a;
	add.s	$f28,$f28,$f8	# f = f + x*x*x*a

#    if (f >= 2.5) {
if:
	li.s	$f16,2.5
	c.le.s 	$f16,$f28
	bc1f	if_else
	
#      std::cout << "f(" << x << ") = " << f;
	li	$v0,4
	la	$a0,strF
	syscall
	
	li	$v0,1
	move	$a0,$s2
	syscall
	
	li	$v0,4
	la	$a0,strIgual
	syscall
	
	li	$v0,2
	mov.s	$f12,$f28
	syscall

	b	if_fin

#    } else {
if_else:
#      std::cout << x << " no supera";
	li	$v0,1
	move	$a0,$s2
	syscall
	
	li	$v0,4
	la	$a0,strNoSupera
	syscall
#    }
if_fin:
	li	$v0,4
	la	$a0,strSaltoLinea
	syscall

#    std::cout << '\n';
	addi	$s2,$s2,1
	b	for

for_fin:
#   }
#   std::cout << "\n\nTermina el programa\n";
	li	$v0,4
	la	$a0,strTermina
	syscall
# }
	li	$v0,10
	syscall

















