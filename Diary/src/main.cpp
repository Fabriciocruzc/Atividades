#include "App.h"

int main(int argc, char const *argv[])
{
  App aplication("diary.md");

  aplication.run(argc, argv);
  return 0;
}