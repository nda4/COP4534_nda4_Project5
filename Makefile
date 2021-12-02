make:
	g++ p1.cpp p2.hpp p2.cpp main.cpp
	./a.out
	make clean
clean:
	rm p2.hpp.gch a.out