#include <stdio.h>
#define PARSE_ARG_FUNC_NO_ARGS 1
#define PARSE_ARG_FUNC_NO_ARGS_HELP_INFO "run with -r or --regular\n"
#define PARSE_ARG_FUNC_INCORRECT_FLAG 2
#define PARSE_ARG_FUNC_INCORRECT_FLAG_HELP_INFO "incorrect flag introduced, expected (-r/--regular, -c/--config, -p/--path)\n"

FILE* open_file(char* rel_filepath);
void print_help(int where);