#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    char a;
    bool done = true;
    while(done){
        printf("Enter a number:\n> ");
        scanf("%c", &a); //Get char input from user and place in adress of a
        switch(a){
        case '1':
            printf("penis balse\n");
            break;
        case '6':
            printf("Cringe\n");
            break;
        case 'q':
            printf("Exiting...\n");
            sleep(5); //Sleeping for 5s
            done = false;
            break;
        default:
            printf("Hello, World!\n");
            break;
        }
    }
    return 0;
}
