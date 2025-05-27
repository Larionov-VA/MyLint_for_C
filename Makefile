all: main.o getoption.o text_parser.o
	@gcc main.o getoption.o text_parser.o -o main

main.o: getoption.o text_parser.o include/structeres.h
	@gcc src/main.c -o main.o
getoption.o: include/structeres.h
	@gcc parsers/getoption.c -o getoption.o
text_parser.o: include/structeres.h
	@gcc parsers/text_parser.c -o text_parser.o
