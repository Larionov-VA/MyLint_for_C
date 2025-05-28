#include "../include/io.h"

text_t* read_from_file(FILE* file, enum error_handler* err) {
    text_t* text = malloc(sizeof(text_t));
    char* text_buffer = calloc(TEXT_BUFFER_SIZE, sizeof(char));
    text->number_of_lines = 1;
    int symbols_in_buffer = 0;
    char current_char = fgetc(file);
    while (current_char != EOF) {
        if(current_char == '\n') {
            ++text->number_of_lines;
        }
        if ((symbols_in_buffer - 1) >= TEXT_BUFFER_SIZE) {
            text_buffer = realloc(text_buffer, symbols_in_buffer + TEXT_BUFFER_SIZE);
        }
        text_buffer[symbols_in_buffer] = current_char;
        ++symbols_in_buffer;
        current_char = fgetc(file);
    }
    text_buffer[symbols_in_buffer] = '\0';
    text->text = text_buffer;
    text->count_of_symbols = symbols_in_buffer;
    return text;
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