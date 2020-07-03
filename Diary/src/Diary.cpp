#include <iostream>
#include <sstream>
#include <string>

#include "../include/Diary.h"
#include "../include/Util.h"


Diary::Diary(const std::string &filename) : filename(filename)//, messages(nullptr), messages_size(0), messages_capacity(10)
{
  //messages = new Message[messages_capacity];

  std::ifstream reading;

  reading.open(filename);

  if (!reading.is_open())
  {
    std::cout << "Arquivo nao pode ser aberto" << std::endl;
  }

  std::string reading_line;
  int line_cont = 0;
  std::string current_date = "";


  while (!reading.eof()){

    line_cont++;

    std::getline(reading, reading_line);

    if (reading_line.size() == 0){
      continue;
    }

    if ((reading_line.find("#") != std::string::npos)){

      std::stringstream stream(reading_line);
      char discard;

      stream >> discard;
      stream >> current_date;

    }else{

      Message m;
      m.date.set_from_string(current_date);

      std::stringstream stream(reading_line);
      char discard;
      std::string current_time;

      stream >> discard;
      stream >> current_time;

      m.time.set_from_string(current_time);
      getline(stream, m.content);

      m.content = m.content.substr(1);
      add(m);
    }
  }

  reading.close();
  
}

Diary::~Diary()
{
  //delete[] messages;
}

void Diary::add(const std::string &message)
{
  /*if (messages_size >= messages_capacity)
  {
    messages_capacity *= 2;
    Message *messages2 = new Message[messages_capacity];

    for (size_t i = 0; i < messages_size; i++)
    {
      messages2[i] = messages[i];
    }

    delete[] messages;
    messages = messages2;
  }*/

  Message m;
  std::string current_date = get_current_date();
  std::string current_time = get_current_time();

  m.content = message;
  m.date.set_from_string(current_date);
  m.time.set_from_string(current_time);

  messages.push_back(m);
  //messages_size++;
}

void Diary::write(){
  
  std::ofstream arquivo;
  arquivo.open(filename, std::ofstream::out | std::ofstream::trunc);
  arquivo.close();
  std::string current_date = "";


  for (size_t i = 0; i < messages.size(); i++)
  {
    Message m = messages[i];
    std::string dia = m.date.to_string();
    std::string hora = m.time.to_string();

    if (m.date.to_string() != current_date)
    {
      std::ofstream file(filename, std::ios::app);
      file << "# " << dia << std::endl;
    }

    std::ofstream file(filename, std::ios::app);
    file << "- " << hora << " " << m.content << std::endl;

    current_date = dia;
  }
}


void Diary::add(const Message& message)
{
  /*if (messages_size >= messages_capacity)
  {
    messages_capacity *= 2;
    Message *messages2 = new Message[messages_capacity];

    for (size_t i = 0; i < messages_size; i++)
    {
      messages2[i] = messages[i];
    }

    delete[] messages;
    messages = messages2;
  }*/

  messages.push_back(message);
  //messages_size++;
}


std::vector<Message*> Diary::search(const std::string& check){

    std::vector<Message*> found;
    
    for (auto i = 0; i < messages.size(); ++i)
    {
        //std::size_t search = messages[i].content.find(check);
        if (messages[i].content.find(check) != std::string::npos) {
            found.push_back(&messages[i]);
        }
    }

    return found;
}



