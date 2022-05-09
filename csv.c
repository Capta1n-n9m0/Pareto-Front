#include "csv.h"
#include <stdlib.h>
#include <stdio.h>

static void error(const char *szMsg){
    fprintf(stderr, "%s\n", szMsg);
    exit(1);
}

static char *add_char_to_string(char *string, int *length, char c){
    string = realloc(string, (++*length)*sizeof(char ));
    string[*length-1] = c;
    return string;
}

char **split_string(const char *string, char separator){
    int res_size = 0;
    int token_size = 0;
    char **res = calloc(++res_size, sizeof (char *));
    puts(string);
    for(int i = 0; string[i]; i++){
        if(string[i] == separator){
            res[res_size-1] = add_char_to_string(res[res_size-1], &token_size, '\0');
            res = realloc(res, (++res_size)*sizeof (char *));
            token_size = 0;
            printf("%c\n", string[i]);
            continue;
        }
        res[res_size-1] = add_char_to_string(res[res_size-1], &token_size,string[i]);
    }
    res[res_size-1] = add_char_to_string(res[res_size-1], &token_size, '\0');
    res = realloc(res, (++res_size)*sizeof (char *));
    res[res_size-1] = NULL;
    return res;
}

char ***read_cvs_file(const char *filename, char separator){
    int res_size = 0;
    char ***res = NULL;
    char *buffer = NULL;
    size_t buffer_size, line_length;
    FILE *f = fopen(filename, "r");
    if(f == NULL) error("Couldn't open a file.");
    while ((line_length = getline(&buffer, &buffer_size, f)) != -1){
        if(buffer[0] == '\n') continue;
        buffer[line_length-1] = '\0';
        res = realloc(res, (++res_size)*sizeof(char **));
        res[res_size - 1] = split_string(buffer, separator);
    }
    res = realloc(res, (++res_size)*sizeof(char **));
    res[res_size-1] = NULL;
    fclose(f);
    free(buffer);
    return res;
}



