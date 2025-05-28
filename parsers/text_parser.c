#include "../include/text_parser.h"

void parse_config(options_t* opt, enum error_handler* err) {
    FILE* config_file = fopen("configs/config.json", "r");
    if (config_file) {
        text_t *text = read_from_file(config_file, err);
        
        for (int i = 0; i < text->count_of_symbols; ++i) {
            char current_char = text->text[i];
            printf("%c", current_char);
        }
        fclose(config_file);
    }
    else {
        *err = ERR_FILE;
    }
}

void parse_code(options_t* opt, enum error_handler* err, const char* path_to_file) {
    FILE* file = fopen(path_to_file, "r");
    if (file) {
        fclose(file);
    }
    else {
        *err = ERR_FILE;
    }
}

void parse_dir(options_t* opt, enum error_handler* err) {
    DIR* dir = opendir(opt->rel_filepath);
    if (dir) {
        struct dirent *de = readdir(dir);
        parse_config(opt, err);
        while (de) {
            if (is_file_correct(de->d_name, de->d_type)) {
                char *path_to_file = get_filepath(opt->rel_filepath, de->d_name, err);
                if (!*err) {
                    parse_code(opt, err, path_to_file);
                    free(path_to_file);
                }
            }
            de = readdir(dir);
        }
        closedir(dir);
    }
    else {
        *err = ERR_DIR;
    }
}