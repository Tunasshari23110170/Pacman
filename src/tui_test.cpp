#include<ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <iostream>
int main(void){

using namespace ftxui;
Element document =
hbox({
    text("left") | border,
    text("middle") | border | flex,
    text("right") | border,
});

    //crea la pantalla y establece el contenido.
    auto screen = Screen::Create(
        Dimension::Full (),
        Dimension::Fit(document)
    );
    Render(screen,document);
    screen.Print();
    return EXIT_SUCCESS;
}