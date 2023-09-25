#include "Vaquita.h"
#include <string>
#include <iostream>

Vaquita::Vaquita(std::string nombre, int _leche) : raza{ nombre }, leche{ _leche } {}

std::string Vaquita::get_raza() {
	return raza;
}

int Vaquita::get_leche() {
	return leche;
}

void Vaquita::Imprimir() {
	std::cout << "Vaquita " << get_raza() << ": " << get_leche() << " litros." << std::endl;
}