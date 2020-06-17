    #include <iostream>
    #include <string>

    

    int main(int argc, char *argv[]) {
      /*std::string nome = "add";
      std::string mensagem;*/

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

      std::cout << "Mensagem adicionada" << std::endl;

      
      /*if(argv[1] != nome){
          std::cout << "Uso: " << argv[0] <<  " add <mensagem>" << std::endl;
          return -1;
        }

      if(argc < 3){
          std::cout <<"Insira uma mensagem" << std::endl;
          std::getline(std::cin, mensagem);
          std::cout << "Mensagem adicionada";

        }

      if (argc == 3){
        if(argv[1] == nome){
           std::cout << "Mensagem " << argv[2] << " adicionada" << std::endl; 
        }
      }*/


      return 0;
    }