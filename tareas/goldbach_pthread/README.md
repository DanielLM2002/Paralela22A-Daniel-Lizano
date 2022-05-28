
# TAREA 1
## GOLDBACH 
### primer ciclo 2022
#### --------

Este repositorio contiene el proyecto de las sumas de Goldbach seriales.
El problema consiste en que para todo número entero mayor que 5 suceden una de las siguientes dos cosas: 
```
Si el número es par, este se puede escribir como la suma de dos números primos.

    Ejemplos de esto se ven de la sigueinte manera: 6 = 3 + 3, 8 = 4 + 4

Si el número es impar, este se puede escribir como la suma de tres números primos.

    Ejemplos de esto se ven de la siguiente manera: 7 = 2 + 2 + 3, 9 = 2+ 2 + 5
```

Este proyecto no tiene como fin  demostrar la veracidad matemática de estas conjeturas, si no realizar los cálculos de todas las posibles sumas que pueden tener cada número y notificarle al usuario según lo que este desié cuantas hay y cuáles son.

El proyecto se realizará en en lenguage C y trabajará de manera que se leerá un archivo de texto através de la entrada estándar. La manera en la que entre el número en el .TXT hará que el programa despligue información diferente, si el número ingresado es positivo solo se desplegará la cantidad de sumas posibles, si el número es negativo se desplegará el número de sumas posibles y cuales son estas.

*EJEMPLO DE ENTRADA*
```
1
2
6
-6
9
-9
```

*SALIDA ESPERADA*
```
1: NA
2: NA
6: 1 SUMS
-6: 1 SUMS: 3+3
9: 2 SUMS
-9: 2 SUMS: 2+2+5, 3+3+3
```

Para poder correr el programa se usa un makefile incluido en los archivos del proyecto, este makefile compilará el programa y generará el ejecutable que quedará dentro de la carpeta Bin, usaremos la siguiente linea en la terminal.
```
bin\goldbach_serial < test/input001.txt
```
Siendo la barra de test los casos de prueba que se usarán para la revisión del programa. 

*Agradecimientos y créditos*
Gracias al profesor Jeisson por manetener la página de donde pude sacar información para este proyecto, y también por dar un ejemplo en java sobre como realizr los cálculos.
Obtenido de https://jeisson.ecci.ucr.ac.cr/principios/2013b/examenes/examen01/Goldbach2.java. 

Contáctame
Correo: daniel.lizanomorales@ucr.ac.cr
Teléfono: 83035686