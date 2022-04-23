#include <stdio.h>
#include <stdlib.h>

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

void part1(void) {
    FILE *input_file  = fopen("input.txt", "r");

    int nb_lines = get_num_lines_in_file(input_file);
    fseek(input_file, 0, SEEK_SET);

    char line[7];
    int input[nb_lines];

    for (int i = 0; i < nb_lines; i++) {
        fgets(line, sizeof(line), input_file);
        char *ptr;
        input[i] = (int) strtol(line, &ptr, 10);
    }

    fclose(input_file);

    int nb_increase = 0;
    for (int i = 0; i < nb_lines; i++) {
        if (i != 0 && input[i-1] < input[i]) {
            nb_increase++;
        }
    }

    printf("Nb of increases (part 1): %d\n", nb_increase);

}

void part2(void) {

    FILE *input_file  = fopen("input.txt", "r");

    int nb_lines = get_num_lines_in_file(input_file);
    fseek(input_file, 0, SEEK_SET);

    char line[7];
    int input[nb_lines];

    for (int i = 0; i < nb_lines; i++) {
        fgets(line, sizeof(line), input_file);
        char *ptr;
        input[i] = (int) strtol(line, &ptr, 10);
    }

    fclose(input_file);

    int increase = 0;
    int prev_sum = 0;
    for (int i = 0; i < nb_lines - 2; i++) {
        int sum = input[i] + input[i+1] + input[i+2];

        if (i != 0 && prev_sum < sum) {
            increase++;
        }
        prev_sum = sum;
    }

    printf("Nb of increases (part 2): %d\n", increase);
}

int main() {

    part1();
    part2();

    return 0;
}
