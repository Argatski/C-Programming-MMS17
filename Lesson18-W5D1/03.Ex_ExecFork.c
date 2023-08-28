#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  while (1) {
    // Read symbols from stdin until newline is entered
    char line_buf[200];
    int char_c = 0;
    char cur_sym = '\0';
    while (cur_sym != '\n') {
      cur_sym = getc(stdin);
      line_buf[char_c++] = cur_sym;
    }
    line_buf[char_c - 1] = '\0';

    fwrite(line_buf, sizeof(char), char_c, stdout);

    // Split string into separate argumets
    char *exec_argv[10];
    exec_argv[0] = strtok(line_buf, " ");

    for (int i = 1; exec_argv[i - 1] != NULL; i++) {
      exec_argv[i] = strtok(NULL, " ");
    }

    int pid = fork();
    if (pid == -1) {
      perror("Could not fork");
      exit(-1);
    } else if (pid == 0) {
      // Child
      //  "ls" ["ls", "-la"]
      printf("%s", exec_argv[0]);
      printf("%s", exec_argv[1]);
      execvp(exec_argv[0], exec_argv);
      perror("Exec failed");
      exit(-1);

    } else {
      // parent
      //  Изчаква детето да приключи и печата статус кода му
      int wstatus;

      pid_t child_pid = wait(&wstatus);

      if (!WIFEXITED(wstatus)) {
        perror("Child dod not exit normally\n");
      }
      else {
      printf("Child return code: %d\n", WEXITSTATUS(wstatus));
      }
    }
  }
}