#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>


void run();
void handleCommand(char *input);
void pwd();
void ls();

int main() {
    run();
    return 0;
}

void run() {
    char *input;
    input = malloc(sizeof(char));
    int stop = 0;

    while(stop != 1) {
        printf("$ ");
        gets(input);
        handleCommand(input);
    }
}


void handleCommand(char *input) {
    if (strcmp(input, "ls") == 0) {
       ls();
    } else if(strcmp(input, "pwd") == 0){
        pwd();
    } else {
        printf("-bash: %s: command not found\n", input);
    }
}

void pwd() {
    char input[PATH_MAX];
    if (getcwd(input, sizeof(input)) != NULL) {
        printf("%s\n", input);
    } else {
        printf("ERROR: getcwd()");
    }
}

void ls() {
    DIR *dir = opendir(".");
    struct dirent * entry;

    while((entry = readdir(dir)) != NULL) {
        printf("%s ", entry->d_name);
    }

    printf("\n");
}