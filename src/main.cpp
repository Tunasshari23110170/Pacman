#include <iostream>
#include <thread>
#include <chrono>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <fstream>

using namespace std;
using namespace ftxui;

// Definición de la clase Archivo
class Archivo {
public:
    Archivo(const string& filePath) : filePath(filePath) {}

    Element GetElement() {
        std::ifstream file(filePath);
        return text(file);
    }

private:
    string filePath;
};

int main() {
    Archivo dComida("./assets/images/comida.txt");
    Archivo dFantasma("./assets/images/fantasma.txt");
    Archivo dPacman("./assets/images/pacman.txt"); 

    int fotograma = 0;
    while (true) {
        fotograma++;
        Element pacman = dPacman.GetElement() | bold | color(Color::Yellow1) | bgcolor(Color::Green1);
        Element fantasma = dFantasma.GetElement() | bold | color(Color::Green) | bgcolor(Color::Blue);
        Element comida = dComida.GetElement() | bold | color(Color::White) | bgcolor(Color::Black);
        Element lienzo = hbox({ pacman, comida, fantasma });

        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo));

        Render(pantalla, lienzo);
        pantalla.Print();
        cout << pantalla.ResetPosition();

        // Salir del bucle si se presiona 'q'
        if (getchar() == 'q') {
            break;
        }

        // Dormir el hilo durante 100 milisegundos
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}