#pragma once
 
typedef struct {
    char* rel_filepath;
    char* config;
}options_t;

enum error_handler {
    ERR_OK,
    ERR_MEM,
    ERR_NOARGS,
    ERR_EXTRAARGS
};