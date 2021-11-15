#include <stdio.h>
#include <string.h>

struct person {
    char name[10];
    int age;
};

void removeNewLine(char *str) {
    if (str == NULL)
        return;
    int length = strlen(str);
    if (str[length-1] == '\n')
        str[length-1]  = '\0';
}


int main(){
    struct person man;
    struct person *ptr = &man;

    printf("Enter your name\n> ");
    fgets(man.name, 10, stdin);
    removeNewLine(ptr->name);
    fflush(stdin);
    printf("Enter your age\n> ");
    scanf("%d", &man.age);
    getchar();
    printf("Your name is %s and you are %d years old\n", ptr->name, ptr->age);
    
    return 0;
}
