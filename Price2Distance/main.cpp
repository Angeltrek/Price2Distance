/*
 * Proyecto Price2Distance
 * Autor: Angel Mauricio Ramirez Herrera
 * A01710158
 * Fecha: 18/09/2023
 */

#include "headers/Cinema.h"
#include "headers/CommerceAdmin.h"
#include "headers/GasStation.h"
#include "headers/User.h"
#include <iostream>

int main() {
  // Inicialización de variables
  int option = 0, op1 = 0, op2 = 0, op3 = 0; // O(1)
  std::string email = "", password = "";     // O(1)
  std::string ow = "", lat = "", lon = "";   // O(1)
  std::string mag = "", prem = "";           // O(1)
  std::string nor = "", vip = "", fd = "";   // O(1)
  bool login = false;                        // O(1)

  // Lectura de datos desde archivos CSV y creación de objetos
  CommerceAdmin<GasStation> gasStations("data/GasStations.csv"); // O(n)
  CommerceAdmin<Cinema> cinemas("data/Cinemas.csv");             // O(n)

  User user("admin", "admin@example.com", "password", 30.7634,
            -95.2354); // O(1)

  while (option < 4) {
    // Menú principal
    std::cout << "\n1) Acceder \n";
    std::cout << "2) Ver lista de productos \n";
    std::cout << "3) Agregar comercio \n";
    std::cout << "4) Salir \n";
    std::cout << "Proporciona la opcion (Número): \n";

    // Manejo de errores para entradas no numéricas
    while (!(std::cin >> option)) {
      std::cin.clear();           // Limpia el estado de error
      std::cin.ignore(100, '\n'); // Ignora hasta 100 caracteres o hasta el
                                  // siguiente salto de línea
      std::cout << "Entrada no válida. Proporciona un número: \n";
    }

    switch (option) {
    case 1:
      // Acceso al sistema
      std::cout << "\nEmail: \n";
      std::cin >> email; // O(1)

      std::cout << "\nPassword: \n";
      std::cin >> password; // O(1)

      if (email == user.getEmail() && password == user.getPassword()) {
        login = true; // O(1)

        // Inicialización de distancias para gasolineras y cines
        for (GasStation &gasStation : gasStations.getCommerceList()) {
          gasStation.setDistance(user.coords.first, user.coords.second); // O(n)
        }

        for (Cinema &cinema : cinemas.getCommerceList()) {
          cinema.setDistance(user.coords.first, user.coords.second); // O(n)
        }

        std::cout << "\nHas accedido correctamente \n";
      } else {
        std::cout << "\nEmail o contraseña incorrectos \n";
      }
      break;
    case 2:
      std::cout << "\n1) Ver lista de gasolineras \n";
      std::cout << "2) Ver lista de cines \n";

      // Manejo de errores para entradas no numéricas
      while (!(std::cin >> op1)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Entrada no válida. Proporciona un número: \n";
      }

      switch (op1) {
      case 1:
        std::cout << "\n1) Ordenar por precio de Magna \n";
        std::cout << "2) Ordenar por precio de Premium \n";

        // Manejo de errores para entradas no numéricas
        while (!(std::cin >> op2)) {
          std::cin.clear();
          std::cin.ignore(100, '\n');
          std::cout << "Entrada no válida. Proporciona un número: \n";
        }

        switch (op2) {
        case 1:
          // Ordenar gasolineras por precio de Magna
          gasStations.applyFunction(
              [](GasStation &gasStation) { gasStation.isMagna(); }); // O(n)
          gasStations.sort(); // O(n log n)

          // Imprimir la lista de gasolineras
          for (GasStation gasStation : gasStations.getCommerceList()) {
            std::cout << gasStation.toString(); // O(n)
          }
          break;
        case 2:
          // Ordenar gasolineras por precio de Premium
          gasStations.applyFunction(
              [](GasStation &gasStation) { gasStation.isPremium(); }); // O(n)
          gasStations.sort(); // O(n log n)

          // Imprimir la lista de gasolineras
          for (GasStation gasStation : gasStations.getCommerceList()) {
            std::cout << gasStation.toString(); // O(n)
          }
          break;
        }

        std::cout << "\n1) Ver precio más bajo \n";
        std::cout << "2) Ver precio más alto \n";
        std::cout << "3) Ver comercios más cercanos \n";

        // Manejo de errores para entradas no numéricas
        while (!(std::cin >> op3)) {
          std::cin.clear();
          std::cin.ignore(100, '\n');
          std::cout << "Entrada no válida. Proporciona un número: \n";
        }

        switch (op3) {
        case 1:
          // Obtener la gasolinera más barata
          gasStations.getCheapest(); // O(1)
          break;
        case 2:
          // Obtener la gasolinera más cara
          gasStations.getMostExpensive(); // O(1)
          break;
        case 3:
          if (!login) {
            std::cout << "\nNecesitas acceder\n";
            break;
          } else {
            // Seleccionar gasolineras por distancia
            gasStations.applyFunction([](GasStation &gasStation) {
              gasStation.isDistance();
            });                       // O(n)
            gasStations.makeAVL();    // O(n log n)
            gasStations.displayAVL(); // O(n)
          }
          break;
        }
        break;
      case 2:
        std::cout << "\n1) Ordenar por precio de boleto Normal \n";
        std::cout << "2) Ordenar por precio de boleto VIP \n";
        std::cout << "3) Ordenar por precio de boleto 4D \n";

        // Manejo de errores para entradas no numéricas
        while (!(std::cin >> op2)) {
          std::cin.clear();
          std::cin.ignore(100, '\n');
          std::cout << "Entrada no válida. Proporciona un número: \n";
        }

        switch (op2) {
        case 1:
          // Ordenar cines por precio de boleto Normal
          cinemas.applyFunction(
              [](Cinema &cinema) { cinema.isNormal(); }); // O(n)
          cinemas.sort();                                 // O(n log n)

          // Imprimir la lista de cines
          for (Cinema cinema : cinemas.getCommerceList()) {
            std::cout << cinema.toString(); // O(n)
          }
          break;
        case 2:
          // Ordenar cines por precio de boleto VIP
          cinemas.applyFunction([](Cinema &cinema) { cinema.isVip(); }); // O(n)
          cinemas.sort(); // O(n log n)

          // Imprimir la lista de cines
          for (Cinema cinema : cinemas.getCommerceList()) {
            std::cout << cinema.toString(); // O(n)
          }
          break;
        case 3:
          // Ordenar cines por precio de boleto 4D
          cinemas.applyFunction(
              [](Cinema &cinema) { cinema.isFourD(); }); // O(n)
          cinemas.sort();                                // O(n log n)

          // Imprimir la lista de cines
          for (Cinema cinema : cinemas.getCommerceList()) {
            std::cout << cinema.toString(); // O(n)
          }
          break;
        }
        std::cout << "\n1) Ver precio más bajo \n";
        std::cout << "2) Ver precio más alto \n";
        std::cout << "3) Ver comercios más cercanos \n";

        // Manejo de errores para entradas no numéricas
        while (!(std::cin >> op3)) {
          std::cin.clear();
          std::cin.ignore(100, '\n');
          std::cout << "Entrada no válida. Proporciona un número: \n";
        }

        switch (op3) {
        case 1:
          // Obtener el cine más barato
          cinemas.getCheapest(); // O(1)
          break;
        case 2:
          // Obtener el cine más caro
          cinemas.getMostExpensive(); // O(1)
          break;
        case 3:
          if (!login) {
            std::cout << "\nNecesitas acceder\n";
            break;
          } else {
            // Seleccionar cines por distancia
            cinemas.applyFunction(
                [](Cinema &cinema) { cinema.isDistance(); }); // O(n)
            cinemas.makeAVL();                                // O(n log n)
            cinemas.displayAVL();                             // O(n)
          }
          break;
        }
        break;
      }
      break;
    case 3:
      // Agregar comercio
      if (!login) {
        std::cout << "\nNecesitas acceder\n";
        break;
      }
      std::cout << "\n1) Agregar gasolinera \n";
      std::cout << "2) Agregar cine \n";

      // Manejo de errores para entradas no numéricas
      while (!(std::cin >> op1)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Entrada no válida. Proporciona un número: \n";
      }

      switch (op1) {
      case 1:
        std::cout << "\nPropietario: \n";
        std::cin >> ow; // O(1)

        std::cout << "\nLatitud: \n";
        std::cin >> lat; // O(1)

        std::cout << "\nLongitud: \n";
        std::cin >> lon; // O(1)

        std::cout << "\nPrecio de Magna: \n";
        std::cin >> mag; // O(1)

        std::cout << "\nPrecio de Premium: \n";
        std::cin >> prem; // O(1)

        gasStations.addCommerce({ow, lat, lon, mag, prem}); // O(n)
        break;
      case 2:
        std::cout << "\nPropietario: \n";
        std::cin >> ow; // O(1)

        std::cout << "\nLatitud: \n";
        std::cin >> lat; // O(1)

        std::cout << "\nLongitud: \n";
        std::cin >> lon; // O(1)

        std::cout << "\nPrecio del boleto normal: \n";
        std::cin >> nor; // O(1)

        std::cout << "\nPrecio del boleto VIP: \n";
        std::cin >> vip; // O(1)

        std::cout << "\nPrecio del boleto 4D: \n";
        std::cin >> fd; // O(1)

        cinemas.addCommerce({ow, lat, lon, nor, vip, fd}); // O(n)
        break;
      }
      break;
    }
  }

  return 0;
}
