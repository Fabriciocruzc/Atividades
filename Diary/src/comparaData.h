#ifndef COMPARADATA_H
#define COMPARADATA_H

#include "data.h"

#include <string>

struct Compara {

	std::string dia;
	std::string hora;

	bool verificar_data(const Compara);
	
};


#endif