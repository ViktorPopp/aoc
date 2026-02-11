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

    /* write code here */

    return EXIT_SUCCESS;
}
