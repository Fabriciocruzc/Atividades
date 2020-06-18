#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char *argv[]) {

	if (argc == 1) {
		std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return -1;
	}

	std::string action = argv[1];

	if (action == "add") {
		std::string mensagem;

		if (argc == 2) {

			std::cout << "Informe a mensagem" << std::endl;

			std::getline(std::cin, mensagem);

		}else{
			mensagem = argv[2];
    	}

    	std::ofstream arquivo("arquivo.txt", std::ios::app);

	    if (!arquivo.is_open()) {
	    	std::cerr << "O arquivo nao pede ser criado." << std::endl;
	    	return -1;
	    }

    	arquivo << mensagem << std::endl;


    	std::cout << "Mensagem adicionada" << std::endl;

	}else if (action == "list") {


		std::ifstream file("arquivo.txt");

		if (!file.is_open()) {
			std::cerr << "O arquivo nao pede ser criado." << std::endl;
	    	return -1;
		}

		std::string listar;
		int line_number = 0;

		while (!file.eof()) {
			++line_number;
			std::getline(file, listar);

			if (listar.size() == 0) {
				continue;
			}

			std::cout << line_number << ". " << listar << std::endl;

		}

		file.close();
	
		}else{
			std::cout << "Uso: " << argv[0] << " add ou list" << std::endl;
	        return -1;
		}

	return 0;
}