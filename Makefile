all: main.o getoption.o text_parser.o io.o
	@gcc binary_objects/main.o binary_objects/getoption.o binary_objects/text_parser.o binary_objects/io.o -o main

main.o: getoption.o text_parser.o
	@gcc src/main.c -c -o binary_objects/main.o

getoption.o: include/getoption.h include/io.h 
	@gcc parsers/getoption.c -c -o binary_objects/getoption.o

text_parser.o: include/text_parser.h
	@gcc parsers/text_parser.c -c -o binary_objects/text_parser.o

io.o: include/io.h
	@gcc io/io.c -c -o binary_objects/io.o

clean:
	@rm -rf binary_objects/*.o main