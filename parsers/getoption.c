#include "../include/getoption.h"

options_t* parse_args(int argc, char* argv[], enum error_handler* err) {
    options_t* options = malloc(sizeof(options_t));
    if (options) {
        int opt, longIndex;
        char *opts = "c:p:r?";
        struct option longOpts[] = {
            {"config",  required_argument, NULL, CONFIG},
            {"path",    required_argument, NULL, FILEPATH},
            {"regular", no_argument,       NULL, REGULAR},
            {NULL, 0, NULL, 0 }
        };
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
        if (opt == -1) {
            print_help(PARSE_ARG_FUNC_NO_ARGS);
            *err = ERR_NOARGS;
        }
        else {
            while (opt != -1 && !*err) {
                switch (opt) {
                    case CONFIG:
                        if (!options->config) {
                            char* config = malloc(strlen(optarg)*sizeof(char));
                            if (config) {
                                strcpy(config, optarg);
                                options->config = config;
                            }
                            else {
                                *err = ERR_MEM;
                            }
                        }
                        else {
                            *err = ERR_EXTRAARGS;
                        }
                        break;

                    case REGULAR:
                        if (!options->config && !options->rel_filepath) {
                            options->config = "standard";
                            options->rel_filepath = "./src";
                        }
                        else {
                            *err = ERR_EXTRAARGS;
                        }
                        break;

                    case FILEPATH:
                        if (!options->rel_filepath) {
                            char* rel_filepath = malloc(strlen(optarg)*sizeof(char));
                            if (rel_filepath) {
                                strcpy(rel_filepath, optarg);
                                options->rel_filepath = rel_filepath;
                            }
                            else {
                                *err = ERR_MEM;
                            }
                        }
                        else {
                            *err = ERR_EXTRAARGS;
                        }
                        break;

                    case SHORTOPT_INCORRECT_FLAG:
                        print_help(PARSE_ARG_FUNC_INCORRECT_FLAG);
                        break;
                }
                opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
            }
        }
    }
    else {
        *err = ERR_MEM;
    }
    return options;
}