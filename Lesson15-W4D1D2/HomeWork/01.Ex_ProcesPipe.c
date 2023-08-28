#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe_A_to_parent[2]; // Pipe from A to parent
    int pipe_A_to_B[2];      // Pipe from A to B
    int pipe_B_to_parent[2]; // Pipe from B to parent

    if (pipe(pipe_A_to_parent) == -1 || pipe(pipe_A_to_B) == -1 || pipe(pipe_B_to_parent) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid_A, pid_B;

    pid_A = fork();
    if (pid_A == 0) {
        // Process A
        close(pipe_A_to_parent[0]); // Close read end of pipe A->parent
        close(pipe_A_to_B[0]);      // Close read end of pipe A->B
        close(pipe_B_to_parent[0]); // Close read end of pipe B->parent

        // Receive array size from parent
        int array_size;
        read(pipe_A_to_parent[1], &array_size, sizeof(int));

        int *array = (int *)malloc(array_size * sizeof(int));
        read(pipe_A_to_parent[1], array, array_size * sizeof(int));

        // Calculate sum of even numbers
        int even_sum = 0;
        for (int i = 0; i < array_size; i++) {
            if (array[i] % 2 == 0) {
                even_sum += array[i];
            }
        }

        // Send even sum to process B
        write(pipe_A_to_B[1], &even_sum, sizeof(int));

        close(pipe_A_to_parent[1]);
        close(pipe_A_to_B[1]);
        close(pipe_B_to_parent[1]);

        free(array);
        exit(0);
    } else {
        pid_B = fork();
        if (pid_B == 0) {
            // Process B
            close(pipe_A_to_parent[0]); // Close read end of pipe A->parent
            close(pipe_A_to_B[1]);      // Close write end of pipe A->B
            close(pipe_B_to_parent[0]); // Close read end of pipe B->parent

            int even_sum;
            read(pipe_A_to_B[0], &even_sum, sizeof(int));

            int even_sum_squared = even_sum * even_sum;

            // Send squared sum back to parent
            write(pipe_B_to_parent[1], &even_sum_squared, sizeof(int));

            close(pipe_A_to_parent[1]);
            close(pipe_A_to_B[0]);
            close(pipe_B_to_parent[1]);

            exit(0);
        } else {
            // Parent process
            close(pipe_A_to_parent[1]); // Close write end of pipe A->parent
            close(pipe_A_to_B[0]);      // Close read end of pipe A->B
            close(pipe_B_to_parent[1]); // Close write end of pipe B->parent

            int array_size = 10; // Change this value to desired array size
            int *array = (int *)malloc(array_size * sizeof(int));

            // Generate and send array to process A
            for (int i = 0; i < array_size; i++) {
                array[i] = rand() % 100; // Generate random number between 0 and 99
            }

            write(pipe_A_to_parent[0], &array_size, sizeof(int));
            write(pipe_A_to_parent[0], array, array_size * sizeof(int));

            // Receive even sum squared from process B
            int even_sum_squared;
            read(pipe_B_to_parent[0], &even_sum_squared, sizeof(int));

            printf("Sum of squares of even numbers: %d\n", even_sum_squared);

            close(pipe_A_to_parent[0]);
            close(pipe_A_to_B[0]);
            close(pipe_B_to_parent[0]);

            free(array);

            // Wait for child processes to finish
            waitpid(pid_A, NULL, 0);
            waitpid(pid_B, NULL, 0);
        }
    }

    return 0;
}
