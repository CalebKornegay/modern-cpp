all: bs

bs: bs.cpp
	g++ --std=c++23 bs.cpp -o bs

clean:
	rm -f bs

rebuild: clean all
