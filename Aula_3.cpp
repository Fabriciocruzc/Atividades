#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]) {
    

    if (argc == 1) {
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

      std::string action = argv[1];

    if (action != "add") {
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;

    }

      std::string mensagem;

    if (argc == 2){
        std::cout << "Informe amensagem" << std::endl;
        std::getline(std::cin, mensagem);
    }else{
        mensagem = argv[2];
    }

    std::ofstream arquivo("arquivo.txt", std::ios::app);
    arquivo << mensagem << std::endl;


    std::cout << "Mensagem adicionada" << std::endl;

    return 0;
}