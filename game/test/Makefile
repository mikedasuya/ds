

INCLUDES= ../common \
	 -I../engine/hdr \
     -I../controller/hdr

SRC = ../engine/src/engine.cpp \
       ../controller/src/controller.cpp   

test:
	g++ main.cpp ${SRC} -I${INCLUDES} -o test

clean:
	rm -rf test 
