#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>



std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }


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

			for(int m = 0; m < mensagem.length(); m++){
				if(mensagem[m] == '#'){
					std::cout << "Mensagem não pode ter #" << std::endl;
					return -1;
				}
			}


		}else {

			mensagem = argv[2];

			for(int k = 0; k < mensagem.length(); k++){
				if(mensagem[k] == '#'){
					std::cout << "Mensagem não pode ter #" << std::endl;
					return -1;
				}
			}

		}

		std::ofstream arquivo("arquivo.txt", std::ios::app);

		if (!arquivo.is_open()) {

			std::cerr << "O arquivo nao pode ser criado." << std::endl;
			return -1;

		}

		std::ifstream leitura("arquivo.txt");

		if (!leitura.is_open()) {

			std::cerr << "O arquivo nao pode ser aberto" << std::endl;
			return -1;

		}

		std::string verificar;

		std::string dia = "# " + get_current_date(); 
		std:: string hora = get_current_time();

		bool existe = false;

		while (!leitura.eof()) {
			std::getline(leitura, verificar);

			if (dia == verificar){
				existe = true;
			}

		}

		if (existe == true) {
			arquivo << "- " << hora << " " << mensagem << std::endl;
		}else{
			arquivo << dia << std::endl;
			arquivo << "- " << hora << " " << mensagem << std::endl;
			
		}
	

	}else if (action == "list") {

		std::ifstream file("arquivo.txt");

		if (!file.is_open()) {

			std::cerr << "O arquivo nao pode ser aberto" << std::endl;
			return -1;

		}

		std::string texto;

		while (!file.eof()) {
			std::getline(file, texto);
			
			if (texto.size() == 0) {
				continue;
			}

			int n = texto.length();

			char letras [n + 1];

			strcpy(letras, texto.c_str());

			for (int i = 0; i < n; i++) {
				if (letras[i] == '-') {
					std::cout << letras << std::endl;
				}
			}

					
		}

	}else{

		std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return -1;

	}





	return 0;

}





