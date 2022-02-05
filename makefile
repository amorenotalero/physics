build:
	gcc -Wall \
		-std=c99 \
		gameLoop.c \
		-I"C:\libsdl\include" \
		-L"C:\libsdl\lib" \
		-lmingw32 \
		-lSDL2main \
		-lSDL2 \
		-lm \
		-o game.exe
run:
	game.exe
clean:
	del *.exe