#ifndef MENSAGEN_H
#define MENSAGEN_H

#include <string>


void show_usage(const std::string &prog_name);

struct Mensagem {

	std::string mensagem;

	void verificar_mensagen(const Mensagem);
	
};


#endif