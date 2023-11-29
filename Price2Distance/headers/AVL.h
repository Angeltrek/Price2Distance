/*
 * Proyecto Price2Distance
 * Autor: Angel Mauricio Ramirez Herrera
 * A01710158
 * Fecha: 15/10/2023
 */

/*
 * Clase AVL contiene datos y funciones para
 * crear árboles AVL y realizar operaciones en ellos.
 */
#ifndef AVL_H_
#define AVL_H_

#include "Node.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

template <class T> class AVL {
private:
  // Variables iniciales
  Node<T> *root;

  // Métodos privados

  // Función auxiliar para insertar un nodo en el árbol AVL.
  // Complejidad O(log n), donde n es el número de nodos en el árbol.
  Node<T> *insertHelper(Node<T> *root, Node<T> node);

  // Función auxiliar para mostrar los nodos del árbol AVL en orden.
  // Complejidad O(n), donde n es el número de nodos en el árbol.
  void displayHelper(Node<T> *root);

  // Función auxiliar para realizar una rotación a la izquierda.
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  Node<T> *leftRotate(Node<T> *y);

  // Función auxiliar para realizar una rotación a la derecha.
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  Node<T> *rightRotate(Node<T> *x);

  // Función auxiliar para obtener el factor de equilibrio de un nodo.
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  int getBalance(Node<T> *node);

  // Función auxiliar para buscar un nodo con el valor proporcionado en el árbol
  // Complejidad O(log n)
  Node<T> *searchHelper(Node<T> *root, T data);

  // Función auxiliar para liberar la memoria de los nodos.
  // Complejidad O(n), donde n es el número de nodos en el árbol.
  void destroyTree(Node<T> *root);

public:
  // Constructor
  // Complejidad O(1): Inicialización de variables constantes.
  AVL() : root(nullptr) {}

  // Destructor
  // Complejidad O(n), donde n es el número de nodos en el árbol.
  ~AVL();

  // Metodos públicos
  // Inserta un nuevo nodo en el árbol AVL.
  // Complejidad O(log n), donde n es el número de nodos en el árbol.
  void insert(T data);

  // Muestra los datos de los nodos del árbol AVL en orden.
  // Complejidad O(n), donde n es el número de nodos en el árbol.
  void display();

  // Busca un nodo con el valor proporcionado en el árbol y devuelve el
  // valor si se encuentra.
  // Complejidad O(log n), donde n es el número de nodos en el árbol.
  T search(T data);
};

// Implementación del destructor
template <class T> AVL<T>::~AVL() { destroyTree(root); }

// Función auxiliar para liberar la memoria de los nodos.
// Complejidad O(n), donde n es el número de nodos en el árbol.
template <class T> void AVL<T>::destroyTree(Node<T> *root) {
  if (root != nullptr) {
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
  }
}

// Complejidad O(1): Inicialización de variables constantes.
template <class T> void AVL<T>::insert(T data) {
  root = insertHelper(root, Node<T>(data));
}

// Función auxiliar para insertar un nodo en el árbol AVL.
// Complejidad O(log n), donde n es el número de nodos en el árbol.
template <class T> Node<T> *AVL<T>::insertHelper(Node<T> *root, Node<T> node) {
  if (root == nullptr) {
    return new Node<T>(node); // Crea un nuevo nodo si el nodo actual es nulo
  }

  if (node.data < root->data) {
    root->left = insertHelper(root->left, node);
  } else if (node.data > root->data) {
    root->right = insertHelper(root->right, node);
  } else {
    return root; // En este caso, no se permiten duplicados!
  }

  // Actualiza la altura del nodo actual
  root->height = 1 + std::max((root->left ? root->left->height : 0),
                              (root->right ? root->right->height : 0));

  // Calcula el factor de equilibrio
  int balance = getBalance(root);

  // Casos de desequilibrio
  // Caso izquierda-izquierda
  if (balance > 1 && node.data < root->left->data) {
    return rightRotate(root);
  }
  // Caso derecha-derecha
  if (balance < -1 && node.data > root->right->data) {
    return leftRotate(root);
  }
  // Caso izquierda-derecha
  if (balance > 1 && node.data > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Caso derecha-izquierda
  if (balance < -1 && node.data < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root; // Retorna root si no hay desequilibrios
}

// Realiza una rotación a la izquierda en un nodo.
// Esta rotación corrige el desequilibrio cuando el subárbol izquierdo de un
// nodo es más alto que el subárbol derecho.
// Complejidad O(1): Realiza operaciones aritméticas simples.
template <class T> Node<T> *AVL<T>::leftRotate(Node<T> *y) {
  Node<T> *x = y->right;
  Node<T> *T2 = x->left;

  x->left = y;
  y->right = T2;

  // Actualiza las alturas de los nodos después de la rotación.
  y->height = 1 + std::max((y->left ? y->left->height : 0),
                           (y->right ? y->right->height : 0));

  x->height = 1 + std::max((x->left ? x->left->height : 0),
                           (x->right ? x->right->height : 0));

  return x;
}

// Realiza una rotación a la derecha en un nodo.
// Esta rotación corrige el desequilibrio cuando el subárbol derecho de un nodo
// es más alto que el subárbol izquierdo.
// Complejidad O(1): Realiza operaciones aritméticas simples.
template <class T> Node<T> *AVL<T>::rightRotate(Node<T> *x) {
  Node<T> *y = x->left;
  Node<T> *T2 = y->right;

  y->right = x;
  x->left = T2;

  // Actualiza las alturas de los nodos después de la rotación.
  x->height = 1 + std::max((x->left ? x->left->height : 0),
                           (x->right ? x->right->height : 0));

  y->height = 1 + std::max((y->left ? y->left->height : 0),
                           (y->right ? y->right->height : 0));

  return y;
}

// Obtiene el factor de equilibrio de un nodo en el árbol AVL.
// El factor de equilibrio se calcula como la diferencia entre la altura del
// subárbol izquierdo y la altura del subárbol derecho.
// Complejidad O(1): Realiza operaciones aritméticas simples.
template <class T> int AVL<T>::getBalance(Node<T> *node) {
  if (node == nullptr) {
    return 0;
  }
  return (node->left ? node->left->height : 0) -
         (node->right ? node->right->height : 0);
}

// Muestra los nodos del árbol en PreOrder.
// Complejidad O(n), donde n es el número de nodos en el árbol.
template <class T> void AVL<T>::display() { displayHelper(root); }

// Función auxiliar para mostrar los nodos del árbol en PreOrder.
// Complejidad O(n), donde n es el número de nodos en el árbol.
template <class T> void AVL<T>::displayHelper(Node<T> *root) {
  if (root != nullptr) {
    displayHelper(root->left);
    std::cout << root->data; // Imprime el valor del nodo.
    displayHelper(root->right);
  }
}

// Devuelve el valor si se encuentra.
// Complejidad O(log n), donde n es el número de nodos en el árbol.
template <class T> T AVL<T>::search(T data) {
  Node<T> *result = searchHelper(root, data);
  if (result) {
    return result->data;
  } else {
    return T();
  }
}

// Función auxiliar para buscar un nodo.
// Complejidad O(log n), donde n es el número de nodos en el árbol.
template <class T> Node<T> *AVL<T>::searchHelper(Node<T> *root, T data) {
  if (root != nullptr) {
    if (root->data == data) {
      return root; // Devuelve el nodo si se encuentra el valor.
    }

    if (data > root->data) {
      return searchHelper(root->right, data);
    } else {
      return searchHelper(root->left, data);
    }
  }

  return nullptr;
}

#endif
