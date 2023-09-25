#pragma once
#include <string>

class Vaquita {
private:
	std::string raza;
	int leche;

public:
	Vaquita(std::string, int);
	void Imprimir();
	std::string get_raza();
	int get_leche();
	void set_leche(int value) { leche = value; }
};