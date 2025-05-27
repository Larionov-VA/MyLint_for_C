#include "../include/structures.h"
#include "../include/getoption.h"
#include "../include/text_parser.h"

int main(int argc, char* argv) {
    enum error_handler err = ERR_OK;
    parse_args(argc, argv, err);
    if (!err) {
        
    }
    return err;
}