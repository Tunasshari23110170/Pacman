#pragma once
#include <fstream>
#include <list>
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

class Archivo
{
private:
    fstream archivo;
    list<string> contenido;
public:
    Archivo(string path)
    {
        archivo(string path)
        while (!archivo.eof())
        {
            string linea;
            getline(archivo, linea);
            contenido.push_back(linea);
        }
        archivo.close();
    }
    Dibujo CrearDibujo(){
        Dibujo temp;
        return temp;
    }
    }
    ~Archivo() {}
};