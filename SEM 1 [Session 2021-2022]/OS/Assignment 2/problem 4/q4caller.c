#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "wait.h"
#include <time.h>
#include <unistd.h>

int main() {
    printf("---------------------CALLER---------------------------------\n");
    char * myfifo = "myfifo";
    if (mkfifo(myfifo, 0777) == -1) {
            perror("Fifo file could not be created\n");
            return 1;
    }
    int fn = open(myfifo, O_WRONLY);
    char* str;
    int len;
    while (1) {
        printf("Enter data to be sent to receiver: ");
        fgets(str, 100, stdin);
        str[strlen(str) - 1] = '\0';
        len = strlen(str) + 1;
        if (write(fn, &len, sizeof(int)) == -1) {
            printf("Error while writing length of string\n");
            return 0;
        }
        if (write(fn, str, sizeof(char) * len) == -1) {
            printf("Error while writing string\n");
            return 0;
        }
        if (strcmp(str, "end") == 0) {
            break;
        }
        printf("Message has been sent\n");
    }
    printf("CONVERSATION ENDED\n");
    close(fn);
    return 0;
};
