/*
 * Proyecto Price2Distance
 * Autor: Angel Mauricio Ramirez Herrera
 * A01710158
 * Fecha: 15/10/2023
 */

/*
 * Clase Cinema que contiene datos para
 * crear objetos que almacenan precios de
 * boletos normales, VIP o 4D
 * además de las coordenadas de los cines.
 */

#ifndef CINEMA_H_
#define CINEMA_H_

#include "Commerce.h"
#include <sstream>
#include <string>
#include <vector>

class Cinema : public Commerce {
private:
  // Variables iniciales
  float normalPrice;
  float vipPrice;
  float fourDPrice;
  bool normal;
  bool vip;
  bool fourD;

public:
  // Constructor
  Cinema();
  Cinema(std::vector<std::string> data);

  // Métodos
  std::string toString() const;
  void isNormal();
  void isVip();
  void isDistance();
  void isFourD();

  // Sobrecarga del operador "<"
  // Complejidad O(1) ya que no compara un conjunto de datos
  bool operator<(const Cinema &other) const {
    // Si se está buscando el precio normal, retorna true si es más barato que
    // el de 'other'.
    if (normal) {
      return normalPrice < other.normalPrice;
    } else if (vip) {
      // Si se está buscando el precio VIP, retorna true si es más barato que el
      // de 'other'.
      return vipPrice < other.vipPrice;
    } else if (fourD) {
      // Si se está buscando el precio 4D, retorna true si es más barato que el
      // de 'other'.
      return fourDPrice < other.fourDPrice;
    } else {
      // Si no se está buscando precio de boletos, retorna la comparación por
      // distancia.
      return distance < other.distance;
    }
    return false;
  }

  // Sobrecarga del operador ">"
  // Complejidad O(1) ya que no compara un conjunto de datos
  bool operator>(const Cinema &other) const {
    // Compara por distancia, retorna true si 'distance' es mayor que el de
    // 'other'.
    return distance > other.distance;
  }

  // Sobrecarga del operador "=="
  bool operator==(const Cinema &other) const {
    // Compara por distancia y retorna true si son iguales.
    return distance == other.distance;
  }

  friend std::ostream &operator<<(std::ostream &out, const Cinema &cinema);
};

std::ostream &operator<<(std::ostream &out, const Cinema &cinema) {
  out << cinema.toString();
  return out;
}

// Constructor vacío
Cinema::Cinema() {
  this->owner = "";
  this->latitude = 0.0;
  this->longitude = 0.0;
  this->normalPrice = 0.0;
  this->vipPrice = 0.0;
  this->fourDPrice = 0.0;
  this->normal = false;
  this->vip = false;
  this->fourD = false;
}

// Obtiene los datos de un vector de tipo String
// Almacena los datos en sus respectivas variables
Cinema::Cinema(std::vector<std::string> data) {
  this->owner = data[0];
  this->latitude = std::stof(data[1]);
  this->longitude = std::stof(data[2]);
  this->normalPrice = std::stof(data[3]);
  this->vipPrice = std::stof(data[4]);
  this->fourDPrice = std::stof(data[5]);
}

// Regresa un string con todos los datos del objeto
// Complejidad O(1) ya que la operación es constante
std::string Cinema::toString() const {
  std::stringstream line;
  if (distance) {
    line << "\n\nOwner: " << this->owner << " \nDistance(km): " << distance
         << " \nNormal Price: " << normalPrice << " \nVIP Price: " << vipPrice
         << " \n4D Price: " << fourDPrice << "\n";
  } else {
    line << "\n\nOwner: " << this->owner << " \nLatitude: " << latitude
         << " \nLongitude: " << longitude << " \nNormal Price: " << normalPrice
         << " \nVIP Price: " << vipPrice << " \n4D Price: " << fourDPrice
         << "\n";
  }
  return line.str();
}

// Asigna true al bool 'normal'
void Cinema::isNormal() {
  normal = true;
  vip = false;
  fourD = false;
}

// Asigna true al bool 'vip'
void Cinema::isVip() {
  normal = false;
  vip = true;
  fourD = false;
}

// Asigna true al bool 'fourD'
void Cinema::isFourD() {
  normal = false;
  vip = false;
  fourD = true;
}

// Asigna false a 'normal', 'vip', y 'fourD' para permitir la comparación por
// distancia
void Cinema::isDistance() {
  normal = false;
  vip = false;
  fourD = false;
}

#endif
