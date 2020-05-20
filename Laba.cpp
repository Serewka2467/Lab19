#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file in> <file out>\n", argv[0]);
        return 1;
    }

    FILE *fin, *fout;

    if ((fin = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        return 2;
    }

    if ((fout = fopen(argv[2], "w")) == NULL)
    {
        fclose(fin);
        perror(argv[2]);
        return 3;
    }

    size_t lines = 0;
    while (!feof(fin))
    {
        int k = fgetc(fin);
        if (k == '\n')
            lines++;
    }

    char buffer[256];
    char **a = malloc(sizeof(char *) * lines);
    assert(a);
    fseek(fin, 0L, SEEK_SET);

    size_t i = 0;
    while (!feof(fin))
    {
        if (fgets(buffer, sizeof(buffer), fin) != NULL)
        {
            size_t len = strlen(buffer);
            a[i] = malloc(len + 1);
            assert(a[i]);
            memcpy(a[i], buffer, len + 1);
            i++;
        }
    }

    for (long i = lines - 1; i >= 0; i--)
    {
        fprintf(fout, "%s", a[i]);
        free(a[i]);
    }
    free(a);

    fclose(fin);
    fclose(fout);

    return 0;
}