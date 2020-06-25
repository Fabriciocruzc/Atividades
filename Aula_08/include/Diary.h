#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();
    
    std::string filename;
    Message* messages;
    size_t messages_size; //Quantidade
    size_t messages_capacity; // Capacidade

    void add(const std::string& message);
    void write();
};
#endif