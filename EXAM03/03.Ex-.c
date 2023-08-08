#include <stdio.h>
struct Product
{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[20];
}Product;


//Function sort products by assending type
int compareByType(char a, char b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

//Function sort products by id 
int compareById(unsigned int a, unsigned int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

//Function sort products by price by ne price - old price
int compareByPrice(double a, double b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
    {
        return 0;
    }
}



int main(int argc, char *argv[]) 
{
  

    return 0;
}