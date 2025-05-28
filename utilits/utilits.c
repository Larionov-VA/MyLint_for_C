#include "../include/utilits.h"

char* get_filepath(char* rel_path, char* filename, enum error_handler* err) {
    char *path_to_file = calloc(MAXIMUM_PATHNAME_SIZE, sizeof(char));
    if (path_to_file && (strlen(rel_path) + strlen(filename)) < MAXIMUM_PATHNAME_SIZE) {
        strcpy(path_to_file, rel_path);
        strcat(path_to_file, filename);
    }
    else {
        *err = ERR_MEM;
    }
    return path_to_file;
};

int is_file_correct(char* filename, int file_type) {
    int filename_len = strlen(filename);
    char format[3] = "";
    if (filename_len > 3) {
        strcpy(format, filename+strlen(filename)-2);
    }
    return file_type == 8 && !strcmp(format, ".c"); //DT_REG = 8
}

void args_checker(options_t* opt, enum error_handler* err) {
    if (!opt->config || !opt->rel_filepath) {
        *err = ERR_NOARGS;
    }
}