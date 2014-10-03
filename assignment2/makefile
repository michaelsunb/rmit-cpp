INCLUDE_PATH=src/
LIBS=$(wildcard $(INCLUDE_PATH)*)

exe: Debug
	g++  -Wall -Wextra -pedantic -std=c++11 $(INCLUDE_PATH)Assignment2.cpp Debug/* -I$(INCLUDE_PATH) -o exe

Debug:
	mkdir Debug/
	for dir in $(LIBS); do \
		if [ -d $$dir ]; then \
			cd $$dir; \
			g++  -Wall -Wextra -pedantic -std=c++11 -c *.cpp -I../; \
			mv *.o ../../Debug/; \
			cd -; \
		fi \
	done

clean:
	rm -rf Debug/ exe *.svg
