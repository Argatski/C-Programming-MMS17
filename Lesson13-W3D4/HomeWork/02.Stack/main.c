#include "linkedlist.h"
#include "stack.h"

Data d1;
int main() {
    Stack *s1 = init_queue();
    push((Data){10}, s1);
    print_queue(*s1);
    push((Data){20}, s1);
    print_queue(*s1);
    push((Data){30}, s1);
    print_queue(*s1);

    Data *d3 = malloc(sizeof(Data));
    (*d3).val = 100;
    d3->val = 200;
    // d3->val will be overwritten over 
    pop(d3, s1);

    print_queue(*s1);
    push((Data){40}, s1);
    print_queue(*s1);

    pop(&d1, s1);
    print_queue(*s1);
    pop(&d1, s1);
    print_queue(*s1);

    deinit_queue(s1);
    return 0;
}