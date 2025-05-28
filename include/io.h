#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structures.h"
#define PARSE_ARG_FUNC_NO_ARGS 1
#define PARSE_ARG_FUNC_NO_ARGS_HELP_INFO "run with -r or --regular\n"
#define PARSE_ARG_FUNC_INCORRECT_FLAG 2
#define PARSE_ARG_FUNC_INCORRECT_FLAG_HELP_INFO "incorrect flag introduced, expected (-r/--regular, -c/--config, -p/--path)\n"
#define TEXT_BUFFER_SIZE 100
text_t* read_from_file(FILE* file, enum error_handler* err);
void print_help(int where);