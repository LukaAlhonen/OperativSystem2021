#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Jag delar mig\n");
    pid = fork();
    if(pid == -1){
        printf("Error!\n");
    } else if(pid == 0){
        printf("Jag är föräldern\n");
    } else {
        printf("Jag är barnet och min pid är %d\n", pid);
    }

    return 0;
}
