#pragma once
#include <string>

class Gallinita {
private:
	int huevos, numero;

public:
	Gallinita(int, int);
	void Imprimir();
	int get_numero();
	int get_huevo();
	void set_huevos(int value) { huevos = value; }
};