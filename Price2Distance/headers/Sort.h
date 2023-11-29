/*
 * Proyecto Price2Distance
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 18/09/2023
 */

/*
 * Clase Sort contiene el metodo Merge
 * para ordenar datos en orden ascendente
 */

#ifndef SORT_H_
#define SORT_H_

#include <list>
#include <string>
#include <vector>

template <class T> class Sort {
private:
  // Metodos privados
  // Complejidad O(n), donde n es la suma del tamaño de left y right.
  std::vector<T> merge(const std::vector<T> &, const std::vector<T> &);

public:
  // Metodos publicos
  // Complejidad O(n log n) en promedio
  void mergeSort(std::vector<T> &);
};

// Complejidad: O(n log n) en promedio
// El método mergeSort realiza una clasificación por mezcla en un vector dado.
// Divide el vector en partes más pequeñas recursivamente y luego combina las
// partes ordenadas en un solo vector ordenado.
template <class T> void Sort<T>::mergeSort(std::vector<T> &v) {
  // Realiza un return si se terminan de
  // hacer las divisiones del vector
  // ya que se considera que los datos
  // se encuentran ordenados.
  // Complejidad O(1): Verificación de tamaño del vector.
  if (v.size() <= 1) {
    return;
  }

  // Obtiene la posición de la mitad del vector
  // Complejidad O(1): Cálculo de la mitad del vector.
  int middle = v.size() / 2;
  // Divide el vector en izquierda y derecha
  // Complejidad O(n), donde n es el tamaño del vector.
  std::vector<T> left(v.begin(), v.begin() + middle);
  std::vector<T> right(v.begin() + middle, v.end());

  // Llama de forma recursiva a mergeSort para ambas partes
  // Complejidad O(log n): Recursión en cada nivel.
  mergeSort(left);
  mergeSort(right);

  // Combina las partes ordenadas en un solo vector
  // Complejidad O(n), donde n es la suma de los tamaños de left y right.
  v = merge(left, right);
}

// Complejidad: O(n)
// El método merge combina dos vectores ordenados en uno solo ordenado.
// Itera a través de los dos vectores y selecciona el elemento más pequeño en
// cada paso.
template <class T>
std::vector<T> Sort<T>::merge(const std::vector<T> &left,
                              const std::vector<T> &right) {

  // Se declara un vector para el resultado del ordenamiento
  // Complejidad O(1): Inicialización de variables.
  std::vector<T> result;
  int leftIndex = 0, rightIndex = 0;

  // El ciclo continúa mientras no se hayan comparado todas las
  // posiciones de ambos vectores
  // Complejidad O(n), donde n es la suma de los tamaños de left y right.
  while (leftIndex < left.size() && rightIndex < right.size()) {
    // Compara cuál es el menor dato entre ambas listas y
    // lo almacena en el resultado
    // Complejidad O(1): Comparación de elementos.
    if (left[leftIndex] < right[rightIndex]) {
      result.push_back(left[leftIndex]);
      leftIndex++;
    } else {
      result.push_back(right[rightIndex]);
      rightIndex++;
    }
  }

  // Si aún quedan elementos por comparar,
  // entonces los almacena en el vector de resultados
  // Complejidad O(n), donde n es la suma de los tamaños de left y right.
  while (leftIndex < left.size()) {
    result.push_back(left[leftIndex]);
    leftIndex++;
  }

  while (rightIndex < right.size()) {
    result.push_back(right[rightIndex]);
    rightIndex++;
  }

  return result;
}

#endif
