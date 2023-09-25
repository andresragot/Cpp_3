#include "Gallinita.h"
#include <iostream>

Gallinita::Gallinita(int _numero, int _huevos) : numero{ _numero }, huevos { _huevos } {}


int Gallinita::get_numero() {
	return numero;
}

int Gallinita::get_huevo() {
	return huevos;
}

void Gallinita::Imprimir() {
	std::cout << "Gallinita " << get_numero() << ": " << get_huevo() << " huevos." << std::endl;
}
