SOURCES:= $(wildcard *.c) $(wildcard *.h) $(wildcard */*/*.h) $(wildcard */*/*.h)
OBJECTS:= $(wildcard *.c) $(wildcard */*/*.c)
OUT:= bin/main
main: $(SOURCES)
	cc -g -W -Wall -o $(OUT) $(OBJECTS) -lssl -lcrypto
