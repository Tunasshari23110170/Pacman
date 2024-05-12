bin/test : src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/pac : src/main.cpp
	g++ src/main.cpp -o bin/pac -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

bin/pacman: src/juego.cpp
	g++ src/juego.cpp -o bin/pacman-std=c++2a -lftxui-screen -lftxui-component -lftxui-dom -Iinclude

runtTest : bin/test
	./bin/test
 
runpacman: bin/juego
	./bin/juego

run : bin/pac
	./bin/pac