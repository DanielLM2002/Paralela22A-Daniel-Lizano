# **Reporte**

## Optimización #1: Implementación de mapeo dinámico

La primera optimización hecha fue la de sustituir el método de mapeo empleado, pasando de utilizar mapeo por bloque a utilizar mapeo dinámico para la repartición de los cálculos entre los hilos. Este mapeo dinámico implementado sigue el patrón **productor-consumidor** donde el hilo principal es el productor y los hilos secundarios los consumidores.

Para seguir el patrón productor-consumidor se decidió usar seguridad condicional, los hilos consumidores trabajan en una celda del arreglo de objetos de tipo **goldbach_t**, un hilo obtiene el número de celda a trabajar de la variable **position** de la estructura de datos compartidos **solver**, una vez que obtiene el número de celda en el que va a trabajar se incrementa esta misma variable para que otro hilo consumidor no trabaje en una celda donde ya se está trabajando. El programa dejará de repartir celdas del arreglo cuando la variable contadora tenga el mismo valor que el tamaño del arreglo en cuestión. Para evitar condiciones de carrera y demás errores, el proceso de lectura e incremento de la variable contadora se ha protegido con un mutex para que solo un hilo a la vez haga ese proceso.

Después de implementar el mapeo dinamico se obtuvo los siguientes resultados para el caso de prueba [input020.txt](../test/input020.txt):

|                  | goldbach_pthread | Optimización #1  |
|------------------|------------------|------------------|
|Hilos             | 10               | 10               |
|Tiempo            | 439.12 segudos         | 216.8 segundos         |
|Velocidad         | 2.91            | 5.60             |
|Eficiencia        | 0.363             | 0.70             |

Como podemos ver debidoa como teniamos implementado el programa, el usar le mapo denimacio ah aumentado de gran manera la eficiiencia del programa. Esto debido a que por la gran cantidad de estructuras que usamos el mapeo dinamico es superior en resolver estos casos.
## Optimizacion #2: Modificación del algoritmo de validación de números primos

En esta tercera optimización se analizó el método **validate_number** y se concluyó que el algoritmo utilizado para verificar si el número que se ingresa por parámetro es primo es bastante inefciente y **kcachegrind** reveló que era el método que más CPU consumía de todos. Se decidió cambiar el algoritmo incial por el algoritmo de AKS, por lo que este método pasa de tener una complejidad computacional de O(n) inicial a tener una complejidad de 0(logᵏ n).
![imagen de Kcachegrind](https://github.com/DanielLM2002/Paralela22A-Daniel-Lizano/blob/main/tareas/goldbach_omp_mpi/images/resultado_kcachegrind_op1.png)



Después de implementada esta optimización se obtuvo los siguientes resultados para el caso de prueba [input020.txt](../test/input020.txt):

|                  | Optimización #1  | Optimización #2  |
|------------------|------------------|------------------|
|Hilos             | 12               | 12               | 
|Tiempo            | 216.8 segundos         | 190.8 segundos           |
|Velocidad         | 5.60             | 6.43           |
|Eficiencia        | 0.70             | 0.83            |


## Comparación #1: Optimización

A continuación se presenta una tabla con los distintos datos recabados de **goldbach_serial**, **goldbach_pthread**, **optimización #1** y **optimización #2** para hacer un contraste entre todas las versiones y ver la evolución de la velocidad y eficiencia en cada etapa. Se empleó el caso de prueba [input020.txt](../test/input020.txt) para tomar los datos.



|                  | goldbach_serial  | goldbach_pthread | Optimización #1  | Optimización #2  |
|------------------|------------------|------------------|------------------|------------------|
|Hilos             | 1                | 10              | 10               | 10               |
|Tiempo            | 1278.32 segundos         | 439.12segundos         | 216.8 segundos         | 190.8 segundos           |
|Velocidad         | 1.00             | 2.91             | 5.60             | 6.43           |
|Eficiencia        | 1.00             | 0.363             | 0.70             | 0.83            |

Es evidente que el mayor incremento en la velocidad y la eficiencia del programa se dio en la optimización #2 al replantear el algoritmo de cálculo que era sumamente ineficiente. Estos datos se pueden ver reflejados de mejor manera en los siguientes gráficos:

![Gráfico de Comparación #1: Optimización](https://github.com/DanielLM2002/Paralela22A-Daniel-Lizano/blob/main/tareas/goldbach_optimization/images/comparacion1.jpeg)

En este grafico se puede apreciar la importante caída en la duración de ejecución del programa con la tarea #2 que fue donde se implementó la versión concurrente y en la optimización #2 en la que se modificó el ineficiente algoritmo de cálculo y en donde se vió el mayor aumento de velocidad con respecto a la versión serial.

![Gráfico de Comparación #2: optimización](https://github.com/DanielLM2002/Paralela22A-Daniel-Lizano/blob/main/tareas/goldbach_optimization/images/comparacion2.jpeg)

Del anterior gráfico se puede concluir que la eficiencia crece en la misma medida que se da los aumentos de velocidad.

## Comparación #2: Concurrencia

A continuación se muestra una tabla con los datos obtenidos en corridas de **goldbach_serial** y **optimización #3** con diferentes cantidades de hilos para hacer un contraste entre de la velocidad y la eficiencia de estas versiones en diferentes situaciones. Se usó el caso de prueba [input020.txt](../test/input020.txt) para tomar los datos.
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

La comparacion de esto se puede encontrar en el archivo **grado de concurrencia.xlsx** que se encuentra en el repositorio, de ntro de la misma carpeta de  **REPORT**

Esta información se puede observar más claramente en el siguiente gráfico:

![Gráfico de Comparación #2: Concurrencia](https://github.com/DanielLM2002/Paralela22A-Daniel-Lizano/blob/main/tareas/goldbach_optimization/images/comparacion3.jpeg)

Como se puede apreciar en el gráfico el mayor incremento de velocidad se da cuando se trabaja con la cantidad de hilos equivalentes a CPU disponibles, a partir de ahí utilizar más hilos no dará más aumentos de velocidad y por el contrario vuleve menos eficiente el programa sin tener beneficios. Por otro lado, se observa que la versión más cercana al punto de equilibrio entre incremento de velocidad y eficiencia es cuando se utilizan la cantidad de hilos equivalente a la mitad de CPU existentes. **El punto de óptimo de incremento de velocidad - eficiencia se encuentra al emplear la cantidad de hilos equivalente a un tercio de CPU disponibles**, que para el equipo donde se hicieron las pruebas serían cuatro hilos.



## Open MP vs Pthreads
Para continuar con la investigacion de la concurrencia, se realizó una comparación entre OpenMP y Pthreads para ver si es mejor utilizar una solución declarativa o no.
Para esta comparación se usó el cosde de prueba input020.txt, ya que este cuenta con un tamaño considerable, por lo que se podrá hacer que los hilos trabajen a su maxima capacidad siempre usando el mismo tipo de mapeo. El mapeo a usar es el dinámico.

|                  | Pthread Optimizado| Open MP  |
|------------------|------------------|------------------|
|Hilos             | 10               | 10               |
|Tiempo            | 190.8 segundos         | 188.32 segundos         |
|Velocidad         | 5.60            | 5.612             |
|Eficiencia        | 0.70             | 0.705             |

Los resultados de dicha tabla se pueden ver en el grafico siguiente con el cual tambien se compara con las versiones pasadas del codigo

![Gráfico de Comparación #4: Comparacion con demás versiones](https://github.com/DanielLM2002/Paralela22A-Daniel-Lizano/blob/main/tareas/goldbach_omp_mpi/images/comparacion4.png)
