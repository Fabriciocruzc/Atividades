    #include "../include/Date.h"
    #include "../include/Diary.h"

    #include <iostream>
    #include <sstream>
    #include <string>

    int main(int argc, char* argv[])
    {
        std::string date = "25/06/2020 asdf asdf asdf";
        Date d;

        std::stringstream stream(date);
        char discard;

        stream >> d.day;
        stream >> discard; //
        stream >> d.month;
        stream >> discard;
        stream >> d.year;

        std::cout << d.day << std::endl;
        std::cout << d.month << std::endl;
        std::cout << d.year << std::endl;

        return 0;
    }