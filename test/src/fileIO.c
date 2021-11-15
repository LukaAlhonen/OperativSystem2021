#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char *lineptr = NULL;
    size_t line_sz;
    ssize_t ret;
    char **lines = NULL;
    size_t lines_sz = 11;
    size_t lines_len = 0;

    lines = realloc(lines, lines_sz * sizeof(char*));
    if(lines == NULL){
        perror("realloc()");
        return -1;
    }
    if(argc < 2){
        // read filename from stdin and open it
        char filename[25];
        printf("Enter filename:\n> ");
        fgets(filename, 25, stdin);
        fp = fopen(filename, "r");
        if(fp == NULL){
            printf("Error\n");
            exit(1);
        }
    } else if(argc == 2){
        // get filename from program arguments
        fp = fopen(argv[1], "r");
    }

    // read from file
    while((ret = getline(&lineptr, &line_sz, fp)) >= 0){
        // set line to lowercase
        for(int i = 0; i < line_sz; i++){
            lineptr[i] = tolower(lineptr[i]);
        }
        // add line to lines array
        lines[lines_len++] = lineptr;

        while(lines_len >= lines_sz){
            lines_sz += 11;
            lines = realloc(lines, lines_sz * sizeof(char*));
        }

        lineptr = NULL; // set lineptr to null so getline allocates memory for new buffer
    }
   
    for(int i = 0; i < lines_len; i++){
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}
