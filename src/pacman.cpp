#include <iostream>
#include <ftxui/component/component.hpp>
#include<ftxui/component/screen_interactive.hpp>
#include <Dibujo.hpp>
#include <thread>
#include <experimental/random>
using namespace std;
using namespace ftxui;


int main(int argc, char const *argv[])
{
    list<Dibujo> dibujos;
    for(int i=0; 1 < 20;)
    {
        list<string> c;
        c.push_back("Pacman:" + to_string(i));
        c.push_back("--------");
        c.push_back("|     O  \");
        c.push_back("|     ____)");
        c.push_back("|      \");
        c.push_back("|______)");
        Dibujo contenido(
        c,
        experimental::randint(0,100), //PosX
        experimental::randint(0,100) //PosY   
        );
    dibujos.push_back(contenido);
    }

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);
    for(auto &&i : dibujos)
    {
        i.DesplazarX(experimental::randint(-1,1));
        i.DesplazarY(experimental::randint(-1,1));
    }
    for(auto &&i : dibujos)
    {
        i.Dibujar(Pantalla);
    }
    Pantalla.Print();
    cout << Pantalla.ResetPosition();

    }
    return 0;
}