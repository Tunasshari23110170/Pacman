bin/test : src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/space : src/main.cpp
	g++ src/main.cpp -o bin/space -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/juego : src/juego.cpp
	g++ src/juego.cpp -o bin/juego
 -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

runtTest : bin/test
	./bin/test
 
runjuego : bin/juego
	./bin/juego


run : bin/space
	./bin/space