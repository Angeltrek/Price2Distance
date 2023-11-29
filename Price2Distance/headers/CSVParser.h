/*
 * Proyecto Price2Distance
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 18/09/2023
 */

/*
 * CSVParser contiene metodos para convertir los datos de un
 * CSV a elementos de un objeto.
 */

#ifndef CSVPARSER_H_
#define CSVPARSER_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <class T> class CSVParser {
private:
  // Variables iniciales
  std::string route;
  std::string header;
  std::vector<std::string> data;
  std::string line, word, temp;
  int lineSize, ctr;

  // Metodos privados
  bool csvExists(std::ifstream &);
  void csvToObjectHelper(std::ifstream &, std::vector<T> &);

public:
  // Metodos publicos
  // Complejidad O(n) debido a que depende del tamaño del archivo csv.
  void csvToObject(std::string, std::vector<T> &);
};

// Evalua si el archivo CSV existe en la ruta especificada
template <class T> bool CSVParser<T>::csvExists(std::ifstream &fin) {
  // Complejidad O(1): Verificar si el flujo de archivo está abierto.
  if (!fin.is_open()) {
    return false;
  }
  return true;
}

// Obtiene la ruta del archivo csv y el vector de objetos
// en el cual se van a almacenar los datos
// Complejidad de O(n) debido a que depende del tamaño del archivo csv.
template <class T>
void CSVParser<T>::csvToObject(std::string route, std::vector<T> &v) {
  std::ifstream fin(route);

  // Verifica si el archivo se abrió correctamente.
  if (!fin.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo CSV." << std::endl;
    return;
  }

  // Continúa con la lectura y conversión del archivo.
  csvToObjectHelper(fin, v);
}

// Obtiene el file input y el vector de objetos
template <class T>
void CSVParser<T>::csvToObjectHelper(std::ifstream &fin, std::vector<T> &v) {
  // Obtiene la primer línea del csv y la almacena en la variable header
  // Complejidad O(m), donde m es la longitud del encabezado.
  std::getline(fin, header);

  // Cuenta el numero de elementos en el header y los almacena en la variable
  // linesize, esto sirve para acceder al numero correcto de datos en el futuro.
  // Complejidad O(m), donde m es la longitud del encabezado.
  std::stringstream headerLine(header);
  while (std::getline(headerLine, word, ',')) {
    lineSize++; // Complejidad O(m), donde m es la longitud del encabezado.
  }

  // Si aun existen líneas por obtener dentro del csv
  // el ciclo sigue funcionando
  // Complejidad O(n * m), donde n es el número de líneas y m es la longitud del
  // encabezado.
  while (std::getline(fin, line)) {
    // Complejidad O(n * m), donde n es el número de líneas y m es la longitud
    // del encabezado. Se borran los datos de data para poder almacenar nuevos
    // datos
    data.clear();

    // Se reinicia el contador para obtener el numero correcto de palabras
    // dentro de cada línea.
    // Complejidad O(1): Restablecer el contador.
    ctr = lineSize;

    std::stringstream s(line);

    // Obtiene los datos dentro de cada línea y se almacenan
    // dentro del vector "data".
    // Complejidad O(m), donde m es la longitud de la línea.
    while (std::getline(s, word, ',')) {
      // Complejidad O(m), donde m es la longitud de la línea.
      if (ctr > 0)
        data.push_back(word);
      else
        break;
      ctr--;
    }

    // Se almacenan los datos en el vector de objetos.
    // Complejidad O(m), donde m es la longitud del encabezado.
    v.push_back(T(data));
  }
}

#endif
