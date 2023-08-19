#include <stdio.h>
#include <stdlib.h>

//Поради липсата на файл програмата не е тествана

struct Student {
  char name[16];
  double avg_grade;
};

int main(int argc, char **argv) {
  FILE *f = fopen("student.bin", "r");

  if (f == NULL) {
    perror("Error opening the file");
    exit(-1);
  }

  struct Student avg;
  avg.avg_grade = 0;

  int size = 1000;

  for (int i = 0; i < size; i++) {
    struct Student currentStudent;
    fread(&currentStudent, sizeof(struct Student), 1, f);

    if (currentStudent.avg_grade > avg.avg_grade) {
      avg = currentStudent;
    }
  }

  fclose(f);
    printf("Student with biggest grade:\n");
    printf("Name: %s\n", avg.name);
    printf("Average Grade: %lf\n", avg.avg_grade);

  return 0;
}