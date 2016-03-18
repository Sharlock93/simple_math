SRC = $(wildcard src/*.cpp)
OBJ = obj/shar.o obj/sharfun.o obj/sharinit.o obj/sharsimplelib.o obj/shaturtlegraph.o obj/sh_camera3D.o obj/sh_shapes.o obj/sh_circle.o obj/sh_diamond_square.o

FLAG = -Wall

libsharo.a: $(OBJ)
	$(info $(OBJ))
	ar rcs libsharo.a $(OBJ)
	move /Y libsharo.a ..\..\lib-sharo\

obj/shar.o: src/shar.cpp 
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sharfun.o: src/sharfun.cpp
	g++  $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sharinit.o: src/sharinit.cpp
	g++  $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sharsimplelib.o: src/sharsimplelib.cpp
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/shaturtlegraph.o: src/shaturtlegraph.cpp
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sh_camera3D.o: src/sh_camera3D.cpp
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sh_shapes.o: src/sh_shapes.cpp
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sh_circle.o: src/sh_circle.cpp
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@

obj/sh_diamond_square.o: src/sh_diamond_square.cpp 
	g++ $(FLAG) -std=gnu++11 -c $^ -o $@
