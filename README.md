# Proyecto: Price2Distance
Price2Distance te ofrece la posibilidad de encontrar los precios más bajos o más altos de productos según la distancia. Los usuarios tienen la libertad de seleccionar si desean ver los productos más asequibles o los más exclusivos en su área cercana.

## Descripción del avance 1
En el primer avance se utilizan metodos de sorting (En este caso Merge Sort) para realizar un ordenamiento de los precios mas baratos a los mas caros con respecto a las gasolineras registradas en un archivo CSV.

## Descripción del avance 2
En el segundo avance, se utilizan estructuras de datos, en este caso, un Árbol Binario AVL, para ordenar los comercios en función de la distancia entre un usuario y el comercio. Esto permite que el usuario pueda visualizar los comercios más cercanos y conocer los precios de los productos que ofrecen. En este avance, se muestran tanto los productos más económicos como los más costosos de cada comercio registrado.

### Cambios sobre el primer avance
1. Cambio 1: Se cambió la función de getDistance, por setDistance, esto se hizo debido a que se requiere comparar la distancia del objeto en el arbol binario, por lo que es más facil calcular la distancia que hay entre el usuario y el comercio y compararla por medio de sobrecarga de operadores dentro de la estructura del AVL.
2. Cambio 2: En el avance anterior, se quería implementar un Árbol Binario de Búsqueda (BST) para ordenar los datos en función de la distancia. Sin embargo, se consideró que el código está hecho para funcionar con una gran cantidad de datos de comercios, por lo que el BST podría deformarse, lo que llevaría a ineficiencias en las búsquedas. Por lo tanto, se optó por utilizar un Árbol AVL para mantener la eficiencia.

## Descripción del avance 3
En este avance, se realiza un analisis de complejidad completo de cada parte del código, ademas se incluye una nueva clase para administrar los comercios. También, se incluyen funciones para poder registrar nuevos comercios dentro del archivo CSV, lo cual solo se puede hacer si se cuenta con una cuenta de administrador:

Email: "admin@example.com"
Contraseña: "password"

### Cambios sobre el segundo avance
1. Cambio 1: Se realizó un cambio en la forma de mostrar los datos dentro del main, ahora se cuenta con una interfaz por donde el usuario podrá interactuar con el sistema.
2. Cambio 2: Se implementó una nueva clase llamada 'ComerceAdmin' que ayuda a administrar la forma en que se registran o se obtienen datos de los distintos comercios que puedan existir.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -o price2distance main.cpp `

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./price2distance` 

## Descripción de las entradas del avance de proyecto

Las entradas principales del proyecto son archivos CSV que contienen datos sobre diversos comercios que pueden ser añadidos, como el nombre del propietario, el precio de sus productos, la latitud y la longitud.

En el proyecto, se espera principalmente este tipo de datos en formato CSV, ya que mi objetivo es demostrar el uso correcto de las estructuras de datos. Por lo tanto, el código no incluye funcionalidades de inicio de sesión, ya que simplemente busco demostrar cómo funciona cada estructura de datos implementada y quiero que el análisis de complejidad de cada clase sea claramente visible.

Se requiere de una cuenta de administrador para poder acceder a varias funciones como ordenar por distancia o agregar nuevos comercios:

Email: "admin@example.com"
Contraseña: "password"

## Descripción de las salidas del avance de proyecto
Las salidas del avance del proyecto es una lista de los comercios ordenados en PreOrder en el caso de el arbol AVL con respecto a la distancia que hay entre el comercio y el usuario, además se muestran los comercios con los precios más baratos y más caros de los productos ofrecidos mediante la lista ordenada.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
La lista de comercios se divide en mitades recursivamente hasta que cada subarreglo contenga solo un elemento; esto significa que la división de las listas tiene una complejidad O(log n).

Para poder ordenarlos, se requiere un tiempo lineal O(n), ya que es necesario comparar cada elemento.

Complejidad del Merge Sort: O(n log(n))

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
La inserción en un árbol AVL requiere la búsqueda de la ubicación adecuada para insertar un nuevo nodo y realizar rotaciones para mantener el equilibrio del árbol.

La búsqueda de la ubicación para la inserción en un árbol AVL tiene una complejidad de O(log n), donde "n" es el número de nodos en el árbol, esta complejidad también la tiene la función de busqueda.

Si es necesario realizar rotaciones para restaurar el equilibrio del árbol, la complejidad adicional es O(log n) ya que, en el peor caso, se debe recorrer desde el nodo insertado hasta la raíz del árbol.

El recorrido en PreOrder para el display tiene una complejidad de O(n), ya que se recorren todos los nodos del arbol.

Inserción: O(log n)
Busqueda: O(log n)
Display en PreOrder: O(n)

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Declaración de variables:

La declaración de variables tiene una complejidad constante (O(1)), ya que no implica bucles ni operaciones repetitivas.

Lectura de datos desde archivos CSV:

La complejidad para leer datos desde archivos CSV y crear objetos CommerceAdmin para gasolineras y cines es lineal (O(n)), asumiendo que la cantidad de datos en los archivos es 'n'.

Menú Principal y Acceso al Sistema:

La verificación de email y contraseña tiene una complejidad constante (O(1)), mientras que la inicialización de distancias para gasolineras y cines en función de la ubicación del usuario tiene una complejidad lineal (O(n)).

Menú de Ver Lista de Productos:

Para las opciones 1 y 2:

Aplicar funciones a gasolineras y cines tiene una complejidad lineal (O(n)).
Ordenar las listas tiene una complejidad log-lineal (O(n log n)).
Imprimir las listas tiene una complejidad lineal (O(n)).
Para la opción 3:

Aplicar función a gasolineras tiene una complejidad lineal (O(n)).
Construir el AVL tiene una complejidad de log-lineal (O(n log n)) y mostrar el árbol AVL tiene una complejidad lineal (O(n)).
Manejo de Errores para Entradas No Numéricas:

Cada bloque de manejo de errores tiene una complejidad constante (O(1)).

Menu de Agregar comercio

Aplica funciones para agregar comercios a un archivo CSV por lo que requiere acceder a cada elemento de un arreglo de strings, asi que tiene una complejidad de O(n) ya que por cada elemento que se quiere agregar, se tiene que recorrer el arreglo n veces.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Identifiqué que el problema requería ordenar un conjunto de datos, en este caso, los comercios, en función de sus precios. Esto es fundamental para proporcionar a los usuarios una lista ordenada y facilitar la desicion de a que gasolinera ir.

En este problema, usé el algoritmo Merge Sort debido a sus ventajas, Merge Sort destaca por su eficacia en listas largas, lo cual es especialmente útil cuando se trabaja con archivos extensos, como los archivos CSV que pueden contener grandes cantidades de datos.

Al seleccionar Merge Sort, tuve en cuenta que su complejidad de tiempo es de O(n log(n)), lo que significa que mantiene un rendimiento óptimo incluso con grandes conjuntos de datos. Esto asegura que el programa pueda manejar eficazmente la ordenación de una lista extensa de datos sin sacrificar la velocidad de procesamiento.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
En el proyecto, se requiere ordenar los comercios en función de los precios y la distancia que existe entre el usuario y el comercio. Para facilitar la búsqueda de información a los usuarios, se necesita que los comercios se ordenen de forma jerárquica con el fin de aumentar la eficiencia de la búsqueda.

Los usuarios ahora tendrán la posibilidad de elegir si desean ir al comercio que ofrece el producto más barato o más caro, o si prefieren acudir al comercio más cercano o más lejano. Previamente, utilizamos Merge Sort para ordenar los comercios en función de sus precios, pero ahora el usuario podrá visualizar la distancia que existe entre su ubicación y la del comercio de forma ordenada.

La lista ordenada y el Árbol Binario se complementan para llevar a cabo una búsqueda eficiente con respecto a los precios de los productos.

La ventaja de utilizar un Árbol Binario AVL es que la búsqueda de los comercios siempre será eficiente, con una complejidad de O(log n). Esto es adecuado para el problema planteado, ya que se considera que pueden existir demasiados comercios registrados debido al uso de un archivo CSV. Se emplea un AVL debido a que, al tratarse de una gran cantidad de datos registrados, el árbol puede deformarse, por lo que es necesario equilibrarlo para mantener la eficiencia de la búsqueda.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
He utilizado estructuras de datos apropiadas, como árboles AVL y listas ordenadas, para almacenar y organizar los datos, lo que facilita las consultas que pueden realizar los usuarios. También he implementado algoritmos de búsqueda que son apropiados para este caso, ya que, considerando que el proyecto puede manejar grandes cantidades de datos, los usuarios no van a leer toda la información que se despliegue, sino que van a buscar lo que quieren, por lo que en este caso, primero se van a desplegar los comercios más cercanos al usuario, pero el usuario puede buscar el precio del producto.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Considero que he desarrollado esta competencia al diseñar y aplicar mecanismos efectivos para leer y cargar datos desde archivos CSV a las estructuras de datos de manera precisa. He desarrollado funciones que permiten la lectura de los archivos CSV, lo que aseguran la integridad de los datos y su correcta inserción en las estructuras. Esto garantiza que los datos se carguen de manera precisa y estén listos para ser consultados por los usuarios.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En el proyecto, he implementado una funcionalidad que permite registrar nuevos comercios en un archivo CSV. Para llevar a cabo la sobrescritura del archivo, se ha establecido la necesidad de contar con una cuenta de administrador, medida que se considera completamente apropiada para evitar que cualquier persona pueda sobrescribir el archivo.
