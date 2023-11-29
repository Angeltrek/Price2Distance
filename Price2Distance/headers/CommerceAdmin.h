/*
 * Proyecto Price2Distance
 * Autor: Angel Mauricio Ramirez Herrera
 * A01710158
 * Fecha: 12/11/2023
 */

/*
 * Clase CommerceAdmin contiene datos para
 * crear vectores de objetos y administrar
 * sus funciones y parametros.
 */

#include "AVL.h"
#include "CSVParser.h"
#include "Sort.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#ifndef COMMERCEADMIN_H_
#define COMMERCEADMIN_H_

template <class T> class CommerceAdmin {
private:
  std::vector<T> commerceList;
  std::string route;
  CSVParser<T> parser;
  Sort<T> sorter;
  AVL<T> avltree;

public:
  // Constructor
  // Complejidad O(n), donde n es el tamaño del archivo CSV.
  CommerceAdmin(std::string);

  // Convierte la lista de comercios a un árbol AVL.
  // Complejidad O(n log n), donde n es el tamaño de la lista de comercios.
  void makeAVL();

  // Muestra los datos de los nodos del árbol AVL en orden.
  // Complejidad O(n), donde n es el tamaño de la lista de comercios.
  void displayAVL();

  // Obtiene el comercio más barato.
  // Complejidad O(log n), donde n es el número de nodos en el árbol AVL.
  void getCheapest();

  // Obtiene el comercio más caro.
  // Complejidad O(log n), donde n es el número de nodos en el árbol AVL.
  void getMostExpensive();

  // Aplica una función a cada comercio en la lista.
  // Complejidad O(n), donde n es el tamaño de la lista de comercios.
  void applyFunction(std::function<void(T &)>);

  // Ordena la lista de comercios utilizando el algoritmo de Merge Sort.
  // Complejidad O(n log n), donde n es el tamaño de la lista de comercios.
  void sort();

  // Obtiene la lista de comercios.
  // Complejidad O(1): Devuelve la referencia a la lista de comercios.
  std::vector<T> &getCommerceList();

  // Agrega un nuevo comercio tanto a la lista como al archivo CSV.
  // Complejidad O(n): Ya que agrega un nuevo elemento al CSV
  void addCommerce(std::vector<std::string>);
};

// Constructor
// Complejidad O(n), donde n es el tamaño del archivo CSV.
template <class T>
CommerceAdmin<T>::CommerceAdmin(std::string route) : route(route) {
  parser.csvToObject(route, commerceList);
}

// Convierte la lista de comercios a un árbol AVL.
// Complejidad O(n log n), donde n es el tamaño de la lista de comercios.
template <class T> void CommerceAdmin<T>::makeAVL() {
  avltree = AVL<T>();

  for (T &commerce : commerceList) {
    avltree.insert(commerce);
  }
}

// Muestra los datos de los nodos del árbol AVL en orden.
// Complejidad O(n), donde n es el tamaño de la lista de comercios.
template <class T> void CommerceAdmin<T>::displayAVL() { avltree.display(); }

// Obtiene el comercio más barato.
// Complejidad O(1), ya que solo obtiene el elemento al inicio de la lista.
template <class T> void CommerceAdmin<T>::getCheapest() {
  if (commerceList.empty()) {
    std::cout << "\nLa lista de comercios está vacía.\n";
  } else {
    std::cout << "\nCheapest: \n";
    std::cout << commerceList.front();
  }
}

// Obtiene el comercio más caro.
// Complejidad O(1), ya que solo obtiene el elemento al final de la lista.
template <class T> void CommerceAdmin<T>::getMostExpensive() {
  if (commerceList.empty()) {
    std::cout << "La lista de comercios está vacía.\n";
  } else {
    std::cout << "Most expensive: \n";
    std::cout << commerceList.back();
  }
}

// Ordena la lista de comercios utilizando el algoritmo de Merge Sort.
// Complejidad O(n log n), donde n es el tamaño de la lista de comercios.
template <class T> void CommerceAdmin<T>::sort() {
  sorter.mergeSort(commerceList);
}

// Aplica una función a cada comercio en la lista.
// Complejidad O(n), donde n es el tamaño de la lista de comercios.
template <class T>
void CommerceAdmin<T>::applyFunction(std::function<void(T &)> func) {
  for (T &commerce : commerceList) {
    func(commerce);
  }
}

// Obtiene la lista de comercios.
// Complejidad O(1): Devuelve la referencia a la lista de comercios.
template <class T> std::vector<T> &CommerceAdmin<T>::getCommerceList() {
  return commerceList;
}

// Agrega un nuevo comercio tanto a la lista como al archivo CSV.
// Complejidad O(n): Ya que agrega un nuevo elemento al CSV
template <class T>
void CommerceAdmin<T>::addCommerce(std::vector<std::string> new_item) {
  // Abrir el archivo CSV en modo de escritura (append)
  std::ofstream archive(route, std::ios::app);

  if (archive.is_open()) {
    // Construir una línea con los nuevos datos
    std::ostringstream nueva_linea;
    nueva_linea << "\n";
    for (int i = 0; i < new_item.size(); i++) {
      if (i < new_item.size() - 1) {
        nueva_linea << new_item[i] << ", ";
      } else {
        nueva_linea << new_item[i];
      }
    }

    // Escribir la nueva línea en el archivo
    archive << nueva_linea.str();

    std::cout << "\nDatos agregados correctamente al archivo CSV.\n"
              << std::endl;

    // Se implementa al vector
    commerceList.push_back(T(new_item));

    // Cerrar el archivo
    archive.close();
  } else {
    std::cerr << "\nError al abrir el archivo CSV.\n" << std::endl;
  }
  return;
}

#endif
