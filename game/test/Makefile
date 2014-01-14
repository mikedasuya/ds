

INCLUDES= ../common \
	 -I../engine/hdr \
     -I../controller/hdr

SRC = ../engine/src/engine.cpp \
       ../controller/src/controller.cpp   

test:
	g++ -g  main.cpp ${SRC} -I${INCLUDES} -o test

lib:
	gcc -fPIC -g -c -Wall ${SRC} -I${INCLUDES}
	gcc -shared -Wl,-soname,libengine.so.1 \
		-o libengine.so.1.0.1 engine.o controller.o 

clean:
	rm -rf test \
	rm -rf lib*
