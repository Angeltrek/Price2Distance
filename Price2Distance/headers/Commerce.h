/*
 * Proyecto Price2Distance
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 18/09/2023
 */

/*
 * Clase Commerce contiene datos para
 * crear objeto que contienen datos para
 * registrar un comercio.
 */

#ifndef COMMERCE_H_
#define COMMERCE_H_

#include <math.h>
#include <sstream>
#include <string>
#include <vector>

class Commerce {
private:
  const float EarthRadiusKm = 6371.0;

  // Métodos privados
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  float toRadians(float degree);

protected:
  // Variables iniciales
  // Complejidad O(1): Inicialización de variables constantes.
  std::vector<std::string> data;
  float longitude;
  std::string owner;
  float latitude;
  float distance;

public:
  // Constructor
  // Complejidad O(1): Inicialización de variables constantes.
  Commerce();

  // Métodos públicos
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  void setDistance(float latitude, float longitude);
};

// Constructor de la clase Commerce
// Recibe un vector de datos para inicializar el objeto
// Complejidad O(1): Inicialización de variables constantes.
Commerce::Commerce() {
  this->latitude = 0.0;
  this->longitude = 0.0;
  this->distance = 0.0;
  this->owner = "";
}

// Método para convertir grados a radianes
// Complejidad O(1): Realiza operaciones aritméticas simples.
float Commerce::toRadians(float degree) { return degree * M_PI / 180.0; }

// Método para calcular la distancia entre dos coordenadas
// Complejidad O(1): Realiza operaciones aritméticas simples.
void Commerce::setDistance(float latitude, float longitude) {
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  float dLat = toRadians(latitude - this->latitude);
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  float dLon = toRadians(longitude - this->longitude);

  // Complejidad O(1): Realiza operaciones aritméticas simples.
  float a = sin(dLat / 2) * sin(dLat / 2) + cos(toRadians(this->latitude)) *
                                                cos(toRadians(latitude)) *
                                                sin(dLon / 2) * sin(dLon / 2);
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  // Complejidad O(1): Realiza operaciones aritméticas simples.
  distance = EarthRadiusKm * c;
}

#endif
