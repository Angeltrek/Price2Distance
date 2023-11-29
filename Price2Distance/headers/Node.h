/*
 * Proyecto Price2Distance
 * Autor: Angel Mauricio Ramirez Herrera
 * A01710158
 * Fecha: 15/10/2023
 */

/*
 * Clase Node que contiene los datos necesarios
 * para crear nodos de un árbol.
 */
#ifndef NODE_H_
#define NODE_H_

template <class T> class Node {
public:
  // Variables iniciales
  T data;         // Almacena los datos del nodo
  Node<T> *left;  // Puntero al nodo izquierdo
  Node<T> *right; // Puntero al nodo derecho
  int height;     // Altura del nodo en el árbol

  // Constructor
  Node(T data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

#endif
