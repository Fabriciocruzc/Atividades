#include <iostream>
#include "../include/Diary.h"

Diary::Diary(const std::string& filename): messages_capacity(10), messages(nullptr), messages_size(0)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_capacity == messages_size) {
        std:: cout << "Nao suporta mais mensagens" << std::endl;
        
    }else {
        Message m;
        m.content = message;
        messages[messages_size] = m;
        messages_size++;
    }

    
}

void Diary::write()
{
    // gravar as mensagens no disco
}
