#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int max (int a, int b) {
    return a > b ? a : b;
}

// Complete the commonChild function below.
int commonChild(char* s1, char* s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int mat[s1len + 1][s2len + 1];
    for (int i = 0; i <= s1len; i++) mat[i][0] = 0;
    for (int i = 0; i <= s2len; i++) mat[0][i] = 0;
    for (int i = 1; i <= s1len; i++)
        for (int j = 1; j <= s2len; j++) {
            mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) 
                mat[i][j] = max(mat[i - 1][j - 1] + 1, mat[i][j]);
        }
    return mat[s1len][s2len];
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s1 = readline();

    char* s2 = readline();

    int result = commonChild(s1, s2);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

