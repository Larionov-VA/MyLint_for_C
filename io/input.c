#include "../include/input.h"

FILE* open_file(char* rel_filepath){

}

void print_help(int where) {
    switch (where) {
        case PARSE_ARG_FUNC_NO_ARGS:
            printf(PARSE_ARG_FUNC_NO_ARGS_HELP_INFO);
            break;
        case PARSE_ARG_FUNC_INCORRECT_FLAG:
            printf(PARSE_ARG_FUNC_INCORRECT_FLAG_HELP_INFO);
            break;
        
        default:
            break;
    }
}