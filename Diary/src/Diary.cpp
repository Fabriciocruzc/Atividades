#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/Diary.h"



std::string get_right_of_delim(std::string const& str, std::string const& delim){

  return str.substr(str.find(delim) + delim.size());
}


Diary::Diary(const std::string& filename):filename(filename) , messages(nullptr), messages2(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];

}

Diary::~Diary() {
    delete[] messages;
    delete[] messages2;
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_capacity == messages_size) {
        messages2 = new Message[messages_capacity * 2];
       for (size_t i = 0; i < messages_capacity; i++) {
            messages2[i] = messages[i];
       }
    messages2 = messages;
    delete[] messages;

    Message m;
    m.content = message;

    std::string format_deta = get_current_date();
    std::string format_time = get_current_time();

    m.date.set_from_string(format_deta);
    m.time.set_from_string(format_time);

    messages2[messages_size] = m;
    messages_size++;

    
        
    }else {

        Message m;
        m.content = message;

        std::string format_deta = get_current_date();
        std::string format_time = get_current_time();

        m.date.set_from_string(format_deta);
        m.time.set_from_string(format_time);

        messages[messages_size] = m;
        messages_size++;
    
    }
   

    
}


void Diary::write()
{
   
   std::ofstream arquivo(filename, std::ios::app); 

   if (!arquivo.is_open()) {

        std::cerr << "O arquivo nao pode ser criado." << std::endl;
        
    }

    Message m;
    

    std::ifstream leitura(filename);

        if (!leitura.is_open()) {

         std::cerr << "O arquivo nao pode ser aberto" << std::endl;

    }

    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());

    std::string verificar;

    std::string dia = "# " + m.date.to_string();
    std::string hora = m.time.to_string();

  
    bool existe = false;

        while (!leitura.eof()) {
            std::getline(leitura, verificar);

            if (dia == verificar){
                existe = true;
            }

        }

        if (existe == true) {
            arquivo << "- " << hora << " " << messages->content << std::endl;
        }else{
            arquivo << dia << std::endl;
            arquivo << "- " << hora << " " << messages->content << std::endl;
            
        }


}

void Diary::write_add(const Message& message){

    int j = 0;

    std::ifstream leitura(filename);

        if (!leitura.is_open()) {

            std::cerr << "O arquivo nao pode ser aberto" << std::endl;

        }

        std::string texto;

        while (!leitura.eof()) {

            ++j;

            std::getline(leitura, texto);
            
            if (texto.size() == 0) {
                continue;
            }

            
            message = get_right_of_delim(texto, "-");
       
        }
}




