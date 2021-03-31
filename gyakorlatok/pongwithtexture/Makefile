all:
	gcc -Iinclude/ src/callbacks.c src/texture.c src/draw.c src/main.c src/ball.c src/game.c src/init.c src/pad.c -lSOIL -lobj -lopengl32 -lglu32 -lglut32 -lm -o pong.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/callbacks.c src/texture.c src/draw.c src/main.c src/ball.c src/game.c src/init.c src/pad.c -lSOIL -lobj -lGL -lGLU -lglut -lm -o pong -Wall -Wextra -Wpedantic