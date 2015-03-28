SRC = $(wildcard src/*.cpp)
OBJ = obj/shar.o obj/sharfun.o obj/sharinit.o obj/sharsimplelib.o obj/shaturtlegraph.o

libsharo.a: $(OBJ)
	$(info $(OBJ))
	ar rcs libsharo.a $(OBJ)

obj/shar.o: src/shar.cpp 
	g++ -std=gnu++11 -c $^ -o $@

obj/sharfun.o: src/sharfun.cpp
	g++ -std=gnu++11 -c $^ -o $@

obj/sharinit.o: src/sharinit.cpp
	g++ -std=gnu++11 -c $^ -o $@

obj/sharsimplelib.o: src/sharsimplelib.cpp
	g++ -std=gnu++11 -c $^ -o $@

obj/shaturtlegraph.o: src/shaturtlegraph.cpp
	g++ -std=gnu++11 -c $^ -o $@
