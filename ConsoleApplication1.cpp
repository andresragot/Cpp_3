#include <cstddef>   // std::size_t
#include <string>
#include <iostream>
#include <stdexcept> // std::runtime_error{}
#include <cstdlib>   // std:.rand()
#include "Vaquita.h"
#include "Gallinita.h"

void mostrar_granja(Vaquita vaquitas[], std::size_t num_vaquitas,
	Gallinita gallinitas[], std::size_t num_gallinitas) {
	std::cout << std::endl << "Estado de la granja:" << std::endl;

	/* COMPLETAR

	   Debe mostrar el nombre y litros disponibles de cada vaquita del array.
	   Debe mostrar el número y huevos disponibles de cada gallinita del array.

	   Ejemplo de formato para las vacas:

		 Vaquita Campanera: 2 litros.

	   Ejemplo de formato para las gallinitaS:

		 Gallinita 2: 3 huevos.
	*/
	/*HECHO*/
	std::cout << std::endl << "Vaquitas: " << std::endl;
	for (std::size_t i=0; i < num_vaquitas; i++) {
		vaquitas[i].Imprimir();
	}


	std::cout << std::endl << "Gallinitas: " << std::endl;
	for (std::size_t i=0; i < num_gallinitas; i++) {
		gallinitas[i].Imprimir();
	}
}

/*HECHO*/
std::size_t get_rondas() {

	/* COMPLETAR

	   Debe pedirle al usuario un número entre 0 y 20, repitiendo la solicitud
	   si el usuario introduce un número mayor que 20. La función devuelve el
	   número menor que 20 obtenido.

	*/

	std::size_t ronda;

	std::cout << "Dame un número del 0 al 20" << std::endl;
	std::string ronda_string;

	do {

		std::cin >> ronda_string;

		ronda = std::stoi(ronda_string);

		if (ronda > 20) {
			std::cout << "Vuelve a darme un número del 0 al 20";
		}
	} while (ronda > 20);

	return ronda;
}

int main() {
	const std::size_t num_vaquitas{ 3 };
	const std::size_t num_gallinitas{ 7 };
	std::size_t i{ 0 };


	/* Crear un array con tres vaquitas:

	   - Campanera con capacidad de 10 litros.
	   - Barrueca  con capacidad de 15 litros.
	   - Berraka   con capacidad de 20 litros.
	*/
	/*HECHO*/
	Vaquita vaquitas[num_vaquitas]{ Vaquita("Campanera", 10), Vaquita("Barrueca", 15), Vaquita("Berraka", 20) };

		/* Crear un array con 7 gallinitas

		   - Las 7/2 primeras con capacidad para 12 huevos.
		   - Las restantes con capacidad para 6 huevos
		*/
	/*HECHO*/
	Gallinita gallinitas[num_gallinitas]{ Gallinita(1, 12), Gallinita(2, 12), Gallinita(3, 12), Gallinita(4, 6), Gallinita(5, 6), Gallinita(6, 6), Gallinita(7, 6) };

	std::size_t rondas{ get_rondas() };


	while (rondas > 0) {

		std::size_t semilla{ static_cast<std::size_t>(rand() % 10 + 1) };

		mostrar_granja(vaquitas, num_vaquitas, gallinitas, num_gallinitas);

		try {

			/* COMPLETAR

			   - Ordeñar la cantidad 'semilla' de las vaquitas si tienen litros
				 suficientes. Si no tienen litros suficientes entonces alimentarlas
				 con 'semilla'.

			   - Mostrar por std::cout un mensaje indicando qué vaca se ha
				 ordeñado con qué cantidad, y qué vaca se ha alimentado con qué
				 cantidad.

			   - Recolectar las gallinitas si tienen suficientes huevos. Si no
				 tienen entonces alimentarlas con 'semilla'.

			   - Mostrar por std::cout un mensaje indicando qué gallinita se ha
				 recolectado con qué cantidad, y qué gallinita se ha alimentado con
				 qué cantidad.
			*/


			std::cout << std::endl;
			for (int i = 0; i < num_vaquitas; i++) {
				if (vaquitas[i].get_leche() < semilla) {
					vaquitas[i].set_leche(vaquitas[i].get_leche() + semilla);
					std::cout << "La vaquita " << vaquitas[i].get_raza() << "se ha alimantado con una cantidad de " << semilla << " ahora tiene " << vaquitas[i].get_leche() << " litros." << std::endl;
				}
				else {
					vaquitas[i].set_leche(vaquitas[i].get_leche() - semilla);
					std::cout << "La vaquita " << vaquitas[i].get_raza() << "se ha ordeñado con una cantidad de " << semilla << " ahora tiene " << vaquitas[i].get_leche() << " litros." << std::endl;
				}
			}


			std::cout << std::endl;
			for (int i = 0; i < num_gallinitas; i++) {
				if (gallinitas[i].get_huevo() < semilla) {
					gallinitas[i].set_huevos(gallinitas[i].get_huevo() + semilla);
					std::cout << "La gallinita " << gallinitas[i].get_numero() << "se ha alimantado con una cantidad de " << semilla << " ahora tiene " << gallinitas[i].get_huevo() << " huevos." << std::endl;
				}
				else {
					gallinitas[i].set_huevos(gallinitas[i].get_huevo() - semilla);
					std::cout << "La gallinita " << gallinitas[i].get_numero() << "se le ha recolectado con una cantidad de " << semilla << " ahora tiene " << gallinitas[i].get_huevo() << " huevos." << std::endl;
				}
			}

			--rondas;

		}
		catch (std::runtime_error& e) {

			std::cout << e.what() << std::endl;
		}
	}
	mostrar_granja(vaquitas, num_vaquitas, gallinitas, num_gallinitas);
	std::cout << "FIN" << std::endl;
}