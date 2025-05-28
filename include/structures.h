#pragma once
 
typedef struct {
    char* rel_filepath;
    char* config;
}options_t;

enum error_handler {
    ERR_OK,
    ERR_MEM,
    ERR_NOARGS,
    ERR_EXTRAARGS,
    ERR_DIR,
    ERR_FILE
};

typedef struct {
    char* text;
    int number_of_lines;
    int count_of_symbols;
}text_t;

typedef struct {
    char* name;
    char** targets;
    int number_of_lines;
    int count_of_symbols;
}config_t;