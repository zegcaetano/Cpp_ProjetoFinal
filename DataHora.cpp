
#pragma once

#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstring>
#include <ctime>      // 
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
using namespace std;





class DataEHoras {


public:

    //***************************************************************
    static const std::string currentDate() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        //tstruct = *localtime_s(&now);
        localtime_s(&tstruct, &now);
        strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);
        return buf;
    }

    


};



