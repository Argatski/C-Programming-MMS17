#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 5

typedef struct Book
{
    char title[150];
    char author[100];
    uint16_t pages;
    float price;
}Book;

typedef struct LL
{
    Book book;
    struct Bode *next;
} LL;


void generateRandomString(char* str,int minLen,int maxLen)
{
    int len = rand() % (maxLen - minLen + 1) + minLen;
    for (int i = 0; i < len; i++) {
        size_t r =  rand() % 52;
        if (r<=25) {
            str[i] = 'a'+r;
        }
        else {
            str[i] = 'A'+(52-r);
        }
    }
    str[len] = '\0';
}
LL *bookList[COUNT];

LL* init_linked_list() {
    for(size_t i = 0; i < COUNT; i++) {
       bookList[i] = malloc(sizeof(Book));
        generateRandomString(bookList[i]->book.title, 10, 20);
        generateRandomString(bookList[i]->book.author, 10, 20);
        bookList[i]->book.pages = 5 + rand() % 2000+1;
        bookList[i]->book.price = (double)rand() /RAND_MAX*(1000.-1.0)+1.0 ;
    }
    return 0;
}

int cmpBookList(const void* a, const void* b)
{
    return strcmp(((Book*)a)->title , ((Book*)b)->title);
}



void printBooks() {
    for(size_t i = 0; i < COUNT; i++) {
        printf("Book %zu\n", i+1);
        printf("Title: %s\n", bookList[i]->book.title);
        printf("Author: %s\n", bookList[i]->book.author);
        printf("Page: %d\n", bookList[i]->book.pages);
        printf("Price: %.2f\n", bookList[i]->book.price);
        printf("\n");
    }
}

int main ()
{
    LL *ll = init_linked_list();
    printBooks();     


    qsort(ll, COUNT, sizeof(Book), cmpBookList);

    printBooks(); 

    free(ll);    

return 0;
}
