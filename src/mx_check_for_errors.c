#include "pathfinder.h"

// This function wraps all error checking function
void mx_check_for_errors(int argc, char *file) {
    mx_file_errors(argc, file);
    mx_check_number_of_islands(file);
    mx_check_line_format(file);
    mx_check_duplicate(file);
    mx_check_if_nums_match(file);
    mx_check_for_duplicate_bridges(file);
    mx_check_numbers(file);
}
