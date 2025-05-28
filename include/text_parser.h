#include "../include/structures.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#define MAXIMUM_PATHNAME_SIZE 150

void parse_config(options_t* opt, enum error_handler* err);
void parse_code(options_t* opt, enum error_handler* err, const char *path_to_file);
void parse_dir(options_t* opt, enum error_handler* err);