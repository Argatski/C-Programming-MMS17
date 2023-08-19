#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int myValue = 7;

    pid_t child1, child2;

    child1 = fork();
    if (child1 == -1) {
        perror("Error creating child process 1");
        return 1;
    } else if (child1 == 0) {
        // Код на детския процес 1
        myValue *= 3;
        printf("Child 1: myValue = %d\n", myValue);

        child2 = fork();
        if (child2 == -1) {
            perror("Error creating child process 2");
            return 1;
        } else if (child2 == 0) {
            // Код на детския процес 2
            if (myValue % 2 == 0) {
                myValue *= myValue;
            } else {
                myValue /= 2;
            }
            exit(myValue);
        }

        // Детския процес 1 изчаква завършването на детския процес 2
        int status;
        waitpid(child2, &status, 0);

        printf("Child 1: myValue after child 2: %d\n", myValue);
        exit(0);
    }

    // Родителския процес изчаква завършването на детския процес 1
    wait(NULL);

    printf("Parent: Final result = %d\n", myValue);

    return 0;
}
