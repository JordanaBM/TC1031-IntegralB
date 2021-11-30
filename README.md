# *TC1031-IntegralB*

## SICT0302B: Toma decisiones

### Usa grafos para hacer analisis de información

Para analizar la información del problema se empleó un grafo de lista de Adyacencia, de modo que se podrán visualizar los arcos que se forman entre los municipios de Guanajuato *(los caminos que te llevan de una ciudad a otra y su distancia)*, esto con la función printGrafo en el archivo Grafos.h en la linea 191.
* *Se incorporan las funciones ciudadesMenosDist y ciudadesAlfabeticamente en el archivo Grafos.h líneas 358 y 424 respectivamente, donde se identifican los arcos pero ordenados de menor a mayor o por orden alfabético*

### Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema

El problema que se plantea es encontrar la ruta más rápida entre una ciudad y otra, esto a través de Breadth-first search, donde busca por nivel hasta encontrar la ciudad destino y traza la ruta, la función implementada es BFS ubicada en el archivo Grafos.h en la línea 211.

## SEG0702A: Tecnologías de Vanguardia

### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.

Se empleó un nuevo algoritmo de ordenamiento, se implementaron dos funciones de Shell Sort.
* La primera para números flotantes ShellSortFloat ubicada en el archivo Grafos.h en la línea 358, que se complementa para ordenar la información del grafo con ciudadesMenosDist ubicada en el mismo archivo linea 391.
* La segunda para orden alfabético ShellSortString ubicada en el archivo Grafos.h en la línea 424, que se complementa para ordenar la información del grafo con ciudadesAlfabeticamente ubicada en el mismo archivo linea 457.

### Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos.

El Shell sort es una generalización del ordenamiento por inserción, teniendo en cuenta dos observaciones:

* El ordenamiento por inserción es eficiente si la entrada está "casi ordenada".
* El ordenamiento por inserción es ineficiente, en general, porque mueve los valores solo una posición cada vez.

El algoritmo Shell sort mejora el ordenamiento por inserción comparando elementos separados por un espacio de varias posiciones. Esto permite que un elemento haga "pasos más grandes" hacia su posición esperada. Los pasos múltiples sobre los datos se hacen con tamaños de espacio cada vez más pequeños. El último paso del Shell sort es un simple ordenamiento por inserción, pero para entonces, ya está garantizado que los datos del vector están casi ordenados. [Ordenamiento Shell Wikipedia](https://es.wikipedia.org/wiki/Ordenamiento_Shell)

#### Pasos para realizar un shell sort

Supongamos que tenemos un array sin ordenar A[] que contiene n elementos. Utilizaremos la secuencia original del shell para ordenar el array.

1. Calcula el valor del gap según la secuencia.
2. Para cada subarray en un intervalo igual al gap haz lo siguiente:
3. Ordenar utilizando la ordenación por inserción.
4. Repite el proceso anterior hasta que el array completo esté ordenado.
[Ordenamiento Shell Delftstack](https://www.delftstack.com/es/tutorial/algorithm/shell-sort/)

#### Ejemplo de funcionamiento

*Supongamos que tenemos el array (9, 8, 3, 7). Vamos a ordenarlo utilizando el algoritmo de ordenación en cascarón y utilizando la secuencia original del cascarón para reducir los intervalos de separación.*

* **Primera iteración**
n = 4.

n/2 = 2 , los elementos que se encuentran en el intervalo 2 se comparan y se intercambian.

A[0] > A[2] == 9 > 3 sí → intercambiamos, (3,8,9,7).

A[1] > A[3] == 8 > 7 sí  → intercambiamos, (3,7,9,8).

El array se convierte en: (3,7,9,8).

* **Segunda Iteración**
n = 2.

n/2 = 1, los elementos que se encuentran en el intervalo 1 se comparan y se intercambian.

A[0] > A[1] == 3 > 7 no → No intercambiamos, (3,7,9,8).

A[1] > A[2] == 7 > 9 no  → No intercambiamos, (3,7,9,8).

A[2] > A[3] == 9 > 8 sí  → intercambiamos, (3,7,8,9).

A[0] > A[1] > A[2] > A[3] == 3 > 7 > 8 > 9  no  → No intercambiamos, (3,7,8,9).

**El array queda como (3,7,8,9)**

#### Análisis asintótico

**Time Complexity**

La complejidad en el peor de los casos en O(n^2) <-- Cuadrática, donde el array/ vector tenga valores muy desacomodados y tenga que estar realizando un swap en cada gap que se va generando.

La complejidad en el mejor de los casos es Ω(n*log n) <-- El tiempo sube linealmente mientras que el n sube exponencialmente.* Esto quiere decir que van a existir veces que en los gaps o no se realicen swaps, especialmente para cuando los datos ya están más o menos ordenamos. 

**Space Complexity**
La complejidad de espacio para el shell sort es O(1) <-- constante, ya que solo ocupamos el array o vector que se tiene y se realizan los swaps dentro del mismo .
[Shell Sort Algorithm Programiz](https://www.programiz.com/dsa/shell-sort/)
