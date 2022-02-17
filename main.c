#include "stdio.h"

void run();
void handleCommand(*char input);

int main() {
    run();
    return 0;
}

void run() {
    const int INPUT_SIZE = 256
    char input[INPUT_SIZE];
    int stop = 0;

    while(stop != 1) {
        printf("$ ");
        fgets(input, INPUT_SIZE, stdin);
        printf("Your entered: %s\n", input);
    }
}


*char handleCommand(*char input) {

}
