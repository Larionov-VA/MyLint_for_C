#include "../include/structures.h"
#include "../include/input.h"
#include "getopt.h"
#include <stdlib.h>
#include <string.h>

#define CONFIG   'c'
#define FILEPATH 'p'
#define REGULAR  'r'
#define SHORTOPT_INCORRECT_FLAG '?'

options_t* parse_args(int argc, char* argv[], enum error_handler* err);