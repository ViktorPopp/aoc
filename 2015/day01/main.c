#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r");
    if (!f)
    {
        fprintf(stderr, "\x1b[1;91merror\x1B[m: could not find `input.txt`\n");
        exit(EXIT_FAILURE);
    }
    fseek(f, 0L, SEEK_END);
    size_t sz = ftell(f);
    rewind(f);

    char *input = malloc(sz);
    fread(input, sz, 1, f);

    int current_floor = 0;
    int basement_char = 0;

    for (size_t p = 0; p <= sz; p++)
    {
        switch (input[p])
        {
        case '(':
            current_floor++;
            break;
        case ')':
            current_floor--;
            if (basement_char == 0 && current_floor == -1)
                basement_char = p + 1;
            break;
        default:
            break;
        }
    }

    printf("Part 1: %d\n", current_floor);
    printf("Part 2: %d\n", basement_char);

    return EXIT_SUCCESS;
}
