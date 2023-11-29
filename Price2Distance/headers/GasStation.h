/*
 * Proyecto Price2Distance
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 18/09/2023
 */

/*
 * Clase GasStation contiene datos para
 * crear objetos que contienen precios de
 * gasolina y coordenadas de la gasolinera.
 */

#ifndef GASSTATION_H_
#define GASSTATION_H_

#include "Commerce.h"
#include <sstream>
#include <string>
#include <vector>

class GasStation : public Commerce {
private:
  // Variables iniciales
  float magnaPrice;
  float premiumPrice;
  bool magna;
  bool premium;

public:
  // Constructor
  // Complejidad O(1) ya que las asignaciones son operaciones constantes.
  GasStation();

  // Constructor que toma un vector de cadenas como parámetro.
  // Complejidad O(1) ya que las asignaciones son operaciones constantes.
  GasStation(std::vector<std::string>);

  // Métodos
  // Complejidad O(1) ya que realiza operaciones constantes sin recorrer
  // conjuntos de datos.
  std::string toString() const;

  // Establece la bandera 'magna' a true.
  // Complejidad O(1) ya que es una asignación constante.
  void isMagna();

  // Establece la bandera 'premium' a true.
  // Complejidad O(1) ya que es una asignación constante.
  void isPremium();

  // Establece las banderas 'magna' y 'premium' a false.
  // Complejidad O(1) ya que son asignaciones constantes.
  void isDistance();

  // Sobrecarga del operador "<"
  // Complejidad O(1) debido a que no compara un conjunto de datos.
  bool operator<(const GasStation &other) const {
    // Realiza comparaciones directas basadas en condiciones simples.
    if (magna) {
      return magnaPrice < other.magnaPrice;
    } else if (premium) {
      return premiumPrice < other.premiumPrice;
    } else {
      // Si no se está buscando precio de gasolinas, retorna distancia.
      return distance < other.distance;
    }

    return false;
  }

  // Sobrecarga del operador ">"
  // Complejidad O(1) debido a que no compara un conjunto de datos.
  bool operator>(const GasStation &other) const {
    // Realiza comparaciones directas basadas en condiciones simples.
    return distance > other.distance;
  }

  // Sobrecarga del operador "=="
  bool operator==(const GasStation &other) const {
    // Realiza comparaciones directas basadas en condiciones simples.
    return distance == other.distance;
  }

  // Sobrecarga del operador de inserción "<<"
  // Complejidad O(1) ya que solo imprime la representación textual del objeto.
  friend std::ostream &operator<<(std::ostream &out,
                                  const GasStation &gasStation);
};

// Sobrecarga del operador de inserción "<<"
// Complejidad O(1) ya que solo imprime la representación textual del objeto.
std::ostream &operator<<(std::ostream &out, const GasStation &gasStation) {
  out << gasStation.toString();
  return out;
}

// Constructor vacío
GasStation::GasStation() {
  // Inicializa todas las variables miembro.
  this->owner = "";
  this->latitude = 0.0;
  this->longitude = 0.0;
  this->magnaPrice = 0.0;
  this->premiumPrice = 0.0;
  this->magna = false;
  this->premium = false;
}

// Obtiene los datos de un vector de tipo String
// Almacena los datos en sus respectivas variables
GasStation::GasStation(std::vector<std::string> data) {
  // Inicializa las variables miembro a partir de los datos proporcionados.
  this->owner = data[0];
  this->latitude = std::stof(data[1]);
  this->longitude = std::stof(data[2]);
  this->magnaPrice = std::stof(data[3]);
  this->premiumPrice = std::stof(data[4]);
}

// Regresa un string con todos los datos del objeto
// Complejidad O(1) debido a que la operación es constante.
std::string GasStation::toString() const {
  std::stringstream line;

  if (distance) {
    // Construye el string basado en condiciones simples y concatenación de
    // cadenas.
    line << "\n\nOwner: " << this->owner << " \nDistance(km): " << distance
         << " \nMagna Price: " << magnaPrice
         << " \nPremium Price: " << premiumPrice << "\n";
  } else {
    // Construye el string basado en condiciones simples y concatenación de
    // cadenas.
    line << "\n\nOwner: " << this->owner << " \nLatitude: " << latitude
         << " \nLongitude: " << longitude << " \nMagna Price: " << magnaPrice
         << " \nPremium Price: " << premiumPrice << "\n";
  }

  return line.str();
}

// Asigna true al bool 'magna'
void GasStation::isMagna() {
  magna = true;
  premium = false;
}

// Asigna true al bool 'premium'
void GasStation::isPremium() {
  magna = false;
  premium = true;
}

// Asigna false a 'magna' y 'premium' para permitir comparar distancia.
void GasStation::isDistance() {
  magna = false;
  premium = false;
}

#endif
