ge#// Programa para evaluar polinomio tercer grado
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
#######################################################
