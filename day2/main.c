#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_num_lines_in_file(FILE * file) {
    char ch;
    int lines = 0;
    while(!feof(file))
    {
        ch = (char) fgetc(file);
        if(ch == '\n')
        {
            lines++;
        }
    }

    return lines+1;
}

typedef enum {
    FORWARD,
    DOWN,
    UP,
}MoveNames;

typedef struct {
    MoveNames name;
    int units;
} Move;

MoveNames get_type_from_char(char c) {
    switch (c) {
        case 'f':
            return FORWARD;
        case 'd':
            return DOWN;
        case 'u':
            return UP;
        default: {
            return 100;
        }
    }
}

void part1(void) {
    FILE *input_file  = fopen("input.txt", "r");

    int nb_lines = get_num_lines_in_file(input_file);
    fseek(input_file, 0, SEEK_SET);

    char line[256];
    Move input[nb_lines];

    for (int i = 0; i < nb_lines; i++) {
        fgets(line, sizeof(line), input_file);
        char *ptr;

        input[i].name = get_type_from_char(strtok (line," ")[0]);
        input[i].units = (int) strtol(strtok (NULL, " "), &ptr, 10);
    }

    fclose(input_file);

    int horizontal = 0;
    int depth = 0;
    for (int i = 0; i < nb_lines; i++) {
        Move cur_input = input[i];

        switch (cur_input.name) {
            case FORWARD:
                horizontal += cur_input.units;
                break;
            case DOWN:
                depth += cur_input.units;
                break;
            default:
                depth -= cur_input.units;
        }
    }

    printf("(part1) Results : %d (horizontal) * %d (depth) = %d", horizontal, depth, horizontal * depth);
}

void part2(void) {

}

int main() {
    part1();
    part2();
    return 0;
}
