#include "pathfinder.h"

// This function checks if the given number of islands matches the actual one
void mx_check_if_nums_match(char *file) {
    char *island1 = NULL;
    char *island2 = NULL;
    char **islandsArr = NULL;
    int arr_size = 0;
    int counter = 0;

    int fd = open(file, O_RDONLY);
    int distance, givenIslands = mx_get_num_of_islands(fd), expectedIslands = 0;

    while (1) {
        int test = mx_parse_islands(&distance, &island1, &island2, fd);
        if (test == 1) break;

        // Resize array
        if (counter + 2 > arr_size) {
            arr_size = (arr_size == 0) ? 4 : arr_size * 2;
            char **newArr = mx_realloc(islandsArr, arr_size * sizeof(char*));
            if (!newArr) {
                for (int i = 0; i < counter; ++i) {
                    free(islandsArr[i]);
                }
                free(islandsArr);
                free(island1);
                free(island2);
                mx_printerr("Memory allocation error\n");
                exit(1);
            }
            islandsArr = newArr;
        }

        islandsArr[counter] = mx_strdup(island1, mx_strlen(island1));
        islandsArr[counter + 1] = mx_strdup(island2, mx_strlen(island2));
        counter += 2;
    }

    for (int i = 0; i < counter; ++i) {
        bool unique = true;
        for (int j = 0; j < i; ++j) {
            if (mx_strcmp(islandsArr[i], islandsArr[j]) == 0) {
                unique = false;
                break;
            }
        }
        if (unique) {
            expectedIslands++;
        }
    }

    for (int i = 0; i < counter; ++i) {
        free(islandsArr[i]);
    }
    free(islandsArr);
    free(island1);
    free(island2);

    if (expectedIslands != givenIslands) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
