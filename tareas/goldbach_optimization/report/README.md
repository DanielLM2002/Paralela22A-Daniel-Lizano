# Comparaciones de versiones

En esta parte se realizan las comparaciones de versiones de los repositorios del programa que se encarga de encontrar todas las posibles sumas de goldbach para una cantidad de numeros dada atraves de un archivo .txt. 

## VERSION 1.0 (SERIAL)
La version serial fue el primer programa entregado y el menos optimizado. En ella se realiza una suma de goldbach de manera serial, es decir, se calcula solo una suma a la vez, lo que hace que le programa sea lento y llegue a tardar mas de 20 minutos en ciertos casos de prueba. La siguiente tabla ilustra esto:

| Duracion | Speed up | Eficiencia | Hilos |
| -------- | -------- | ---------- | ----- |
| 21.328 minutos | 1.0x | 1.0x | 1.0x |

## Version 2.0 (PARALELIZADA)
La version paralelizada fue el segundo programa entregado, este cuenta con un sistema de mapero por bloques, que lo hace mas rapido y eficiente que la version serial. En ella se realiza una suma de goldbach de manera paralelizada, es decir, se calcula una suma a la vez, lo que hace que le programa sea mas rapido y llegue a tardar menos que el serial en una manera considerable si este llega a usar todos los hilos disponibles en la maquina. La siguiente tabla ilustra esto:      
| Duracion | Speed up | Eficiencia | Hilos |
| -------- | -------- | ---------- | ----- |
| 7.328 minutos | 2.91 | 0.363 | 8 |

## version 3.0 (MAPEO DINAMICO)
Para esta version usaremos un mapeo diferente, a diferencia de la version anterior que uso un sistema de mapeo por bloque esta version cuenta con un mapeo dinamico, que se asegura que todos los hilos disponibles siempre esten trabajando.
| Duración | Speedup | Eficiencia | Hilos |
|----------|:-------:|:----------:|:-----:|
| 3.802 minutos| 5.60 | 0,70| 8 | 

## version 3.1 (MAPEO DINAMICO + OPTIMIZACION)

Los resultados de KCachegrind muestran que el programa tiene dura una gran cantidad de tiempo en el periodo de calculo de los primos y su insercion en la lista, ya que esta lista agrega elementos y la sobreescribe, esto es muy tardado, para solucionar esto en esta entrega contamos con una estructura adicional que se encargara de guardar las sumas unicamente.
| Duración | Speedup | Eficiencia | Hilos |  
|----------|:-------:|:----------:|:-----:|
| 3.315 minutos | 6,43 | 0,803 | 8 |  

# Grado de concurrencia
Para averiguar la mejor solucion analisamos los resultados con diferentes pruebas, para este usaremos el test input020.txt de los test medianos.
| Prueba | Hilos |
|--------|:-------:|
| S | 1 |
| hC | 4 |
| 1C | 8 |
| 2C | 16 |
| 4C | 32 |
| D | 25 |
Como podemos ver en las imagenes que vinen incluidas en el reporte podemos concluir que la mayor eficiencia la alcanzamos al usar 1C, osea la misma cantidad de hilos que de nucleos de procesador, en este caso siendo 8.
![comparacion 3](images/comparacion3)


## Graficos de comparacion
En el primer grafico de comparacion podemos ver en azul el tiempo de duracion de cada version del código mientras que en naranja el speedup.
![comparacion 1](images/comparacion1)


En el segundo grafico podemos ver en azul el speed up de cada version del código mientras que en naranja la eficiencia.
![comparacion 2](images/comparacion2)

## Analisis de resultados

Podemos ver que en el analisis de concurrencia, cuando obtenemos la mejor eficiencia es cuando usamos la misma cantidad de hilos que de nucleos de procesador, en este caso 8. El caso C permite al programa aprovechar los hilos al maximo, tambien podemos observar que el aumentar hilos hace que la eficiencia baje en algunos casos hasta de manera considerable.
