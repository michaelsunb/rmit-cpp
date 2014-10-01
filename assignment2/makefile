LIBS=Maze DepthBuilder
INCLUDE_PATH=/

exe: ofiles
	g++  -Wall -Wextra -pedantic -std=c++11 Assignment2.cpp ofiles/* -I$(INCLUDE_PATH) -o exe

ofiles:
	mkdir ofiles/
	for dir in $(LIBS); do \
		cd $$dir; \
		g++  -Wall -Wextra -pedantic -std=c++11  -c *.cpp -I../; \
		mv *.o ../ofiles/; \
		cd -; \
	done

clean:
	rm -rf ofiles/ exe
