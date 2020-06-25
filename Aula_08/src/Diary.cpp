#include "../include/Diary.h"
#include "../include/Util.h"
#include <iostream>


Diary::Diary(const std::string& name): filename(name) , messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    if (messages_capacity == messages_size) {
        return;
        
    }

    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());


    messages[messages_size] = m;
    messages_size++;
    
    
}

void Diary::write()
{
    // gravar as mensagens no disco
}