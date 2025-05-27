#include "../include/structures.h"
#include "../include/getoption.h"
#include "../include/text_parser.h"
#include "../include/input.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    enum error_handler err = ERR_OK;
    options_t* optionts = parse_args(argc, argv, &err);
    if (!err) {
        parse_code(optionts);
    }
    printf("%s\n%s\n", optionts->config, optionts->rel_filepath);
    return err;
}