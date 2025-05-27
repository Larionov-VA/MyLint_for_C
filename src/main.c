#include "include/structures.h"


int main(int argc, char* argv) {
    enum error_handler err;
    parse_args(argc, argv, err);
    if (!err) {

    }
    return err;
}