#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_LEN 10
#define COUNT 10

// Person structure
typedef struct Person {
  char name[100];
  char id[ID_LEN];
  unsigned short birthYear;
  char birthMonth;
  unsigned char birthDay;
  char gender;
} Person;

// People array structure
Person people[COUNT];

// Random identifier generator
char genRandomID(char *str, char *name) {
  for (int i = 0; i < ID_LEN; i++) {
    size_t j = rand() % 26;
    // If name is odd, then identity use little symbol
    if (*name % 2 == 0) {
      str[i] = j + 'a';
    } else {
      str[i] = j + 'a';
    }
  }
  str[ID_LEN] = '\0';
  return *str;
}


int addPerson(char name, unsigned short birthYear, char birthMonth,unsigned char birthDay,
              char gender) {
  int k = 0;
  for (int i = 0; i < COUNT; i++) {
    if (strcmp(people[i].name, &name) == 0) {
      return k = -1;
    } else {
      Person currPerson = {name, genRandomID(people[i].id, &name),birthYear, birthMonth, birthDay, gender};
      people[i] = currPerson;
      return k = 0;
    }
  }
  return k;

}


void readPerson() {
//   // Read Person date from standard input
//   printf("Input name: ");
//   char name[ID_LEN];
//   scanf("%s", people->name);

//   uint16_t birthYear;
//   printf("Input birthYear: ");
//   scanf("%hu", &people->birthYear);
  
//   uint8_t birthMonth;
//   printf("Input birthMonth: ");
//   scanf("%hhu", &people->birthMonth);

//   uint8_t birthDay;
//   printf("Input birthDay: ");
//   scanf("%hhu", &people->birthDay);

//   char gender;
//   printf("Input gender: ");
//   scanf("%c", &people->gender);

  printf("Input name: ");
  char name[ID_LEN];
  scanf("%s",name);

  unsigned short birthYear;
  printf("Input birthYear: ");
  scanf("%hu", &birthYear);
  
  char birthMonth;
  printf("Input birthMonth: ");
  scanf("%s", &birthMonth);

  unsigned char birthDay;
  printf("Input birthDay: ");
  scanf("%hhu", &birthDay);

  char gender;
  printf("Input gender: ");
  scanf("%hhu", &gender);
  
  
          //    char currID=  genRandomID(people[i]->id);
      //     *people[i]->name = *name;
      //     people[i]->birthYear = birthYear;
      //     people[i]->birthMonth = birthday;
      //     people[i]->birthDay = birthday;
      //     people[i]->gender = gender;


    //   Person currentPerson = {*name, genRandomID(people->id, name), birthYear,birthMonth,
    //                           birthDay, gender};

addPerson(*name, birthYear, birthMonth,birthDay,gender);


  // scanf("%s %hu %c %c", people->name, &people->birthYear,  &people->birthDay,
  // &people->gender);
}


void printPerson(char *id) {
  // Print Person date to standard output

  for (int i = 0; i < COUNT; i++) {
    if (strcmp(people[i].id, id)==0) {
      printf("Name: %s\n", people->name);
      printf("ID: %s\n", people->id);
      printf("Birth Year: %hu\n", people->birthYear);
      printf("Brith month: %hu\n", people->birthDay);
      printf("Birth Day: %c\n", people->birthDay);
      printf("Gender: %c\n", people->gender);
      return;
    }
  }
}

int removePerson(char *id) {

  for (int i = 0; i < COUNT; i++) {
    if (strcmp(people[i].id, id) == 0) {
      remove(people->id);
      return 0;
    }
  }
    return -1;
}

  int main(int argc, char *argv[]) {

    //Size of structure 


    printf("size: %d\n",sizeof(Person));

    //Add people in structure
    for (int i = 0; i < COUNT; i++) {
     readPerson();
      //addPerson(people->name, people->birthYear, people->birthDay,people->gender);
    }

    //Print people in structure
    for (int i = 0; i < COUNT; i++) {
      printPerson(people->id);
    }

    //Remove people in structure
    for (int i = 0; i < COUNT; i++) {
      removePerson(people->id);
    }

    //Print people in structure
    for (int i = 0; i < COUNT; i++) {
      printPerson(people->id);
    }

    return 0;    
   
  }