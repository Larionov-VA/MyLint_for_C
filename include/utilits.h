#include "../include/structures.h"
#include <string.h>
#include <stdlib.h>

#define MAXIMUM_PATHNAME_SIZE 150

char* get_filepath(char* rel_path, char* filename, enum error_handler* err);
int is_file_correct(char* filename, int file_type);
void args_checker(options_t* opt, enum error_handler* err);