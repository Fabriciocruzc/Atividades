#if !defined(APP_H)
#define APP_H

#include "Diary.h"

#include <string>

struct App
{
  Diary diary;

  App(const std::string& filename);

  int run(int argc, char const *argv[]);
  int show_help(const std::string& main_name);
  void add();
  void add(const std::string & message);
  void list_messages();
   void search();
  void search(const std::string& what);
};

#endif