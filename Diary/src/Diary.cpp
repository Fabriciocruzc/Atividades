#include <iostream>
#include <fstream>
#include <algorithm>
#include "../include/Diary.h"
#include "../include/Util.h"

Diary::Diary(const std::string& filename):filename(filename) , messages(nullptr), messages2(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];

    std::ifstream leitura(filename);

    if (not leitura or not leitura.is_open()) {

        std::cerr << "O arquivo nao pode ser aberto" << std::endl;
        return;
    }

    std::string linha;
    std::string linha_date;

    while (std::getline(leitura, linha)) {
        if(linha.length() == 0) {
            continue;
        }

        if (linha.rfind("#", 0) == 0){
            linha_date == linha.substr(2);
            continue;
        } 

        std::string linha_message("");
        std::string linha_message_content("");

        if (linha.rfind("-", 0) == 0) {
            linha_message = linha.substr(2, 8);
        }

        linha_message_content = linha.substr(11);

        Message m;
        m.content = linha_message_content;
        m.date.set_from_string(linha_date);
        m.time.set_from_string(linha_message);

        add(m);
    }

}

Diary::~Diary() {
    write();
    delete[] messages;
    
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_capacity == messages_size) {
        messages2 = new Message[messages_size * 2];
       for (size_t i = 0; i < messages_capacity; i++) {
            messages2[i] = messages[i];
       }
        delete[] messages;
        messages = messages2;

       

        
    }

    Message m;
    m.content = message;

    std::string format_deta = get_current_date();
    std::string format_time = get_current_time();

    m.date.set_from_string(format_deta);
    m.time.set_from_string(format_time);

    messages[messages_size] = m;
    messages_size++;
   

    
}

void Diary::add(const Message& message){
    if (messages_size = messages_capacity) {
        messages2 = new Message[messages_size * 2];
        for (size_t i = 0; i < messages_capacity; i++) {
            messages2[i] = messages[i];
        }

        delete[] messages;
        messages = messages2;
    }

    messages[messages_size] = message;
    messages_size++;
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

Message* Diary::search(const std::string& verificar){
    for (size_t i = 0; i < this->messages_size; ++i){

        std::string const& message_content = this->messages[i].content;

        if(message_content.find(verificar) != std::string::npos){
            return this->messages + i;
        }
       
    }

    return nullptr;
}



