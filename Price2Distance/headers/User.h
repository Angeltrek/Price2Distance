/*
 * Proyecto Price2Distance
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 12/10/2023
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>

class User {
private:
  // Variables iniciales
  std::string name;
  std::string email;
  std::string password;
  float latitude;
  float longitude;

public:
  // Variables iniciales
  std::pair<float, float> coords;

  // Constructor
  // Complejidad O(1): Realiza asignaciones de variables constantes.
  User();

  // Constructor con parámetros
  // Complejidad O(1): Realiza asignaciones de variables constantes.
  User(std::string, std::string, std::string, float, float);

  // Complejidad O(1): Regresa el email.
  std::string getEmail();

  // Complejidad O(1): Regresa la contraseña.
  std::string getPassword();
};

// Constructor
// Complejidad O(1): Realiza asignaciones de variables constantes.
User::User() {
  name = "";
  email = "";
  password = "";
  latitude = 0.0;
  longitude = 0.0;
  coords.first = latitude;
  coords.second = longitude;
}

// Constructor con parámetros
// Complejidad O(1): Realiza asignaciones de variables constantes.
User::User(std::string name, std::string email, std::string password,
           float latitude, float longitude) {
  this->name = name;
  this->email = email;
  this->password = password;
  this->latitude = latitude;
  this->longitude = longitude;
  this->coords.first = this->latitude;
  this->coords.second = this->longitude;
}

// Complejidad O(1): Regresa el email.
std::string User::getEmail() { return email; }

// Complejidad O(1): Regresa la contraseña.
std::string User::getPassword() { return password; }

#endif
