#include "../include/App.h"
#include "../include/Message.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        if (argc == 2) {
            search();
        }else {
            search(argv[2]);
        }
    } else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);
    std::cout << "Message adicionada" << std::endl;
    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

void App::search(){
    std::string verificar;
    std::cout << "Digite apalavra que voce quer pesquisa:" << std::endl;
    std::getline(std::cin, verificar);

    search(verificar);
}

void App::search(const std::string& verificar){
    Message* m = diary.search(verificar);

    if (m) {
        std::cout << "Mensagem encontrada." << std::endl;
        
        return;
    }

    std:: cout << "Mensagem nao encontrada." << std::endl;
}

int App::show_usage()
{
    return 1;
}