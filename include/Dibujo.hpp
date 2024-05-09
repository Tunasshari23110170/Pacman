#pragma once
#include <string>
#include <ftxui/screen/screen.hpp>
class Dibujo
{
    private:
    int posicionX;
    int posicionY;
    list <string> contenido;
    public:
    Dibujo(){
        this->posicionX = 0;
        this->posicionY = 0;
    }
    Dibujo(int posicionX, int posicionY){
        this->posicionX;
        this->posicionY;
    }
    Dibujo(list<string> contenido, int posicionX, int posicionY){
        this->contenido = contenido;
        this->posicionX = posicionX;
        this->posicionY = posicionY;
    }    
    void Dibujar(ftxui::Screen Pantalla){
     int posicionPalabraX = 0;
        int posicionPalabraY = 0;
        for (auto &&linea : contenido)
        {
            for (auto &&linea : contenido)
            { 
            int posicionFinalX = posicionInicialX + posicionPalabraX;
            int posicionFinalY = posicionInicialY + posicionPalabraY;

            Pantalla.PixelAt(
                posicionFinalX,
                posicionFinalY
            ).character = letra;
            posicionPalabraX++;
            }
           posicionPalabraY++;
        }   

    }
    void DesplazarX(int distancia){
        posicionX += distancia;
    }
    void DesplazarY(int Distancia){
        posicionY += distancia;
    }
    ~Dibujo() {}
};