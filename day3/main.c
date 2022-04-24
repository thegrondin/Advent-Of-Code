#include <stdio.h>

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

typedef struct {
    unsigned int zero;
    unsigned int one;
} BitSummary;

void part1(void) {

    FILE *input_file  = fopen("input.txt", "r");

    int nb_lines = get_num_lines_in_file(input_file);
    fseek(input_file, 0, SEEK_SET);

    char line[256];
    BitSummary bit_sum[12] = {0};
    size_t size = sizeof(bit_sum) / sizeof(BitSummary);

    for (int i = 0; i < nb_lines; i++) {
        fgets(line, sizeof(line), input_file);

        for (int y = 0; y < size; y++) {
            if (line[y] == '0'){
                bit_sum[y].zero++;
            }
            else if (line[y] == '1') {
                bit_sum[y].one++;
            }
        }

    }

    int gamma = 0;
    int epsilon = 0;

    for (int i = 0; i < size; i++) {
        if (bit_sum[i].one > bit_sum[i].zero) {
            gamma |= (1 << (size-i-1));
        }
        else {
            epsilon |= (1 << (size-i-1));
        }
    }

    printf("Gamma : %d, Epsilon : %d, Gamma * Epsilon = %d", gamma, epsilon, gamma * epsilon);

    fclose(input_file);

}

void part2(void) {

}

int main() {
    part1();
    part2();
    return 0;
}
