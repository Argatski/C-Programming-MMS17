#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const uint8_t COUNT = 2;

typedef struct Book
{
    char title[150];
    char author[100];
    uint16_t pages;
    float price;
}Book;


//Sort the books by title accending order
int comp_sortTitle(const void* a, const void* b)
{
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}
//Sort the books by title descending order
int comp_sortTitleDesc(const void* a, const void* b)
{
    return strcmp(((Book *)b)->title, ((Book *)a)->title);
}

//Sort the books by author accending order
int comp_sortAuthor(const void* a, const void* b)
{
    return strcmp(((Book *)a)->author, ((Book *)b)->author);
}

//Sort the books by author decssending order
int comp_sortAuthorDesc(const void* a, const void* b)
{
    return strcmp(((Book *)b)->author, ((Book *)a)->author);
}

//Sort the books by page count
int comp_page(const void* a,const void* b)
{
    return ((Book *)a)->pages - ((Book *)b)->pages;
}
//Sort the books by page count descending order
int comp_pageDesc(const void* a, const void* b)
{
    return ((Book *)b)->pages - ((Book *)a)->pages;
}

//Sort the books by price
int comp_price(const void* a,const void* b)
{
    return ((Book *)a)->price - ((Book *)b)->price;
}

//Sort the books by price decssing order
int comp_priceDesc(const void* a, const void* b)
{
    return ((Book *)b)->price - ((Book *)a)->price;
}


//Print sort books 
void printBooks(Book *books)
{
    //Length of of arrays books
    for (int i = 0; i < COUNT; i++)
    {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: %.2f\n\n", books[i].price);
    }
}

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

void random_data(Book *books)
{
    //Generate random seeds
    srand(time(NULL));

    for (size_t i=0; i<COUNT; i++) {
        generateRandomString(books[i].title, 10,20);
        generateRandomString(books[i].author, 10,20);
        books[i].pages = 5 + rand() % 2000+1;
        books[i].price = (double)rand() /RAND_MAX*(1000.-1.0)+1.0 ;
    }
}

//Initialize books structure
void initBooks(Book *books)
{
    for (size_t i=0; i<COUNT; i++) {
        books[i].title[0] = '\0';
        books[i].author[0] = '\0';
        books[i].pages = 0;
        books[i].price = 0.0;
    }
}

int main() 
{
    Book *books;

    books = (Book *)malloc(sizeof(Book) * COUNT);
    random_data(books);

    //Sort by title(accsending order)
    printf("::::::TITLE SORT ACCSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_sortTitle);
    printBooks(books);

    //Sort by title(descending order)
    printf("::::::TITLE SORT DECSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_sortTitleDesc);
    printBooks(books);

    //Sort by author(accsending order)
    printf("::::::AUTHOR SORT ACCSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_sortAuthor);
    printBooks(books);

    //Sort by author(descending order)
    printf("::::::AUTHOR SORT DECSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_sortAuthorDesc);
    printBooks(books);

    //Sort by page count
    printf("::::::PAGE SORT ACCSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_page);
    printBooks(books);

    //Sort by page descending order
    printf("::::::PAGE SORT DECSENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_pageDesc);
    printBooks(books);


    //Sort by price(ascending order)
    printf("::::::PRICE SORT ASCENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_price);
    printBooks(books);

    //Sort by price(descending order)
    printf("::::::PRICE SORT DESCENDING ORDER:::::::\n");
    qsort(books, COUNT, sizeof(Book), comp_priceDesc);
    printBooks(books);

    free(books);



    return 0;
}