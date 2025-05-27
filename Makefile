all: main.o getoption.o text_parser.o input.o
	@gcc binary_objects/main.o binary_objects/getoption.o binary_objects/text_parser.o binary_objects/input.o -o main

main.o: getoption.o text_parser.o
	@gcc src/main.c -c -o binary_objects/main.o

getoption.o: include/getoption.h include/input.h 
	@gcc parsers/getoption.c -c -o binary_objects/getoption.o

text_parser.o: include/text_parser.h
	@gcc parsers/text_parser.c -c -o binary_objects/text_parser.o

input.o: include/input.h
	@gcc io/input.c -c -o binary_objects/input.o

clean:
	@rm -rf binary_objects/*.o main