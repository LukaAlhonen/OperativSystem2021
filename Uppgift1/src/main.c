#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int writeToFile(const char **words, size_t words_len, const char *filename){
    // function for writing words to a file
    FILE *output;
    int ret_val = 0;
    int nl_count = 0;
    if((output=fopen(filename, "wx")) == NULL){
        // if file could not be opened set return value to -1 and jump to exit 2
        ret_val = -1;
        goto exit2;
    } else{
        // write words to file
        for(int i = 0; i < words_len; i++){
            if(nl_count == 10){
                nl_count = 0;
                fprintf(output, "%s", "\n");
            }
            if((fprintf(output, "%s", words[i])) < 0){
                ret_val = -1;
                goto exit1;
            }
            nl_count++;
        }
    }
    exit1:
        fclose(output);
    exit2:
        return ret_val;
}

static int strcmp_ptr(const void *p1, const void *p2){
    // dereference and cast arguments to pointers to char for strcmp() to work
    return(strcmp(*(char * const *) p1, *(char * const *) p2));
}

int main(int argc, char *argv[]){
    FILE *fp;
    char *lineptr = NULL; // pointer to hold line buffer
    size_t line_sz; // line size
    ssize_t ret; // to hold return value from getline()
    char *wordptr = NULL; // pointer to hold word
    char **words = NULL; // array to store words
    size_t words_len = 0;
    size_t words_sz = 10;
    const char extension[] = ".sorted";

    // allocate memory for words array
    words = realloc(words, words_sz * sizeof(char*));
    if(words == NULL){
        perror("realloc()");
        return -1;
    }
    if(argc < 2){
        printf("No arguments given\n");
        exit(1);
    } else if(argc > 2){
        printf("Too many arguments\n");
        exit(1);
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
        // separate words from line and put into words array
        while((wordptr = strsep(&lineptr, " .,-:;\n\t")) != NULL){
            if(wordptr == NULL){
                continue;
            } else if(wordptr[0] == '\0'){
                continue;
            }
            // put word in words array
            words[words_len++] = wordptr;
            // make more room for words array
            while(words_len >= words_sz){
                words_sz += 10;
                words = realloc(words, words_sz * sizeof(char*));
            }
        }
        free(lineptr); // free buffer after use
        lineptr = NULL; // set lineptr to null so getline allocates memory for new buffer
    }
    // close file after use
    fclose(fp);
    // sort words
    qsort(words, words_len, sizeof(char *), strcmp_ptr);
    // append .sorted to input file filename for output file filename
    char filename[(int) (strlen(argv[1]) + strlen(extension))]; // outputfile filename
    strcpy(filename, argv[1]);
    strcat(filename, extension);
    writeToFile((const char **)words, words_len, filename);

    free(words); // free words array after use

    return 0;
}
