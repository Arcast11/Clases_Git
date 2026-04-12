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
# float		f → $f28
# int 		r → $s0
# int 		s → $s1
# int 		x → $s2
# float		x → $f18
###################################################

	.text

# int main(void) {
main:
#   std::cout << std::fixed << std::setprecision(8);  // Ignorar
#   float a,b,c,d;
#   std::cout << "\nEvaluacion polinomio f(x) = a x^3 + b x^2 + c x + d"
#             << " en un intervalo [r,s]\n";

	la 	$a0, strTitulo
	li 	$v0, 4
	syscall

#   std::cout << "\nIntroduzca coeficiente a: ";
	la 	$a0, strIntroA
	li 	$v0, 4
	syscall
	
#   std::cin >> a;
	li 	$v0,6
	syscall
	mov.s	$f0, $f20
	
#   std::cout << "Introduzca coeficiente b: ";
	la 	$a0, strIntroB
	li 	$v0, 4
	syscall
	
#   std::cin >> b;
	li	 $v0,6
	syscall
	mov.s	$f0,$f22
	
#   std::cout << "Introduzca coeficiente c: ";
	la	$a0, strIntroC
	li	$v0, 4
	syscall

#   std::cin >> c;
	li	$v0,6
	syscall
	mov.s	$f0,$f24
#   std::cout << "Introduzca coeficiente d: ";
	la	$a0, strIntroB
	li	$v0, 4
	syscall
	
#   std::cin >> d;
	li	$v0,6
	syscall
	mov.s	$f0,$f26
	
#   int r,s;
#   do {
do:

#     std::cout << "\nLímite inferior r: ";
	la 	$a0, strIntroR
	li 	$v0, 4
	syscall
	
#     std::cin >> r;
	li 	$v0,5
	syscall 
	move 	$v0,$s0
	
#     std::cout << "Límite superior s: ";
	la 	$a0, strIntroS
	li 	$v0, 4
	syscall
	

#     std::cin >> s;
	li 	$v0,5
	syscall 
	move 	$v0,$s1

#   } while (r > s);
while_r_gt_s:
	blt	$s0,$s1,do

#   for (int x = r ; x <= ,s;s ; x++) {
for:
	bge	$s2, $s1,for_fin
	b 	for_dentro
	
for_dentro:

#     // float f = x*x*x*a + x*x*b + x*c + d;
	




#     float f = d;
	mov.s 	$f28, $f26
	
# Convertimos x de entero a flotante al registro $f18
	mtc1	$s2, $f18
	cvt.s.w	$f18, $f18
	

#     f += x*c;
	mul.s	$f4, $f18, $f24 #	x*c → $f4
	add.s	$f28, $f28, $f4


#     f += x*x*b;
	mul.s 	$f6,$f4,$f4		# 	x * x → $f6
	mul.s 	$f7,$f6,$f22		# 	x * x * c → $f7
	add.s 	$f28, $f28, $f7

#     f += x*x*x*a;
	mul.s	$f8,$f6,$f20
	add.s 	$f28,$f28,$f8
	
#    if (f >= 2.5) {
if_f_25:
	li.s	$f4, 2.5
	c.lt.s	$f28,$f4
	bc1t	if_f_25_else
	
if_f_25_then:

#      std::cout << "f(" << x << ") = " << f;
	li	$v0,4
	la	$a0, strF
	syscall
	
#	Convertimos x a entero de nuevo
	mfc1	$s2,$f18
	
	li	$v0,1
	move	$s2,$a1
	syscall

	li	$v0,4
	la	$a0, strIgual
	syscall

	b	if_f_25_fin

#    } else {
if_f_25_else:

#      std::cout << x << " no supera";
	li	$v0,4
	la	$a0, strNoSupera
	syscall
#    }
if_f_25_fin:

#    std::cout << '\n';
	li	$v0,4
	la	$a0, strSaltoLinea
	syscall

#   }
	b	for
for_fin:

#   std::cout << "\n\nTermina el programa\n";
# }




