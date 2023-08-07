#include<stdio.h>
#include<stdlib.h>
typedef struct A {
    int data;
} A;
typedef struct Stack {
    A *arr;
    size_t capacity;
    size_t cur_elem_count;
} Stack;
// cur_elem_count - броя на елементите в стека
// capacity - максималния брой на елементи в стека
Stack init_stack(size_t max_elem_count) {
    // Заделя масив с max_elem_count на брой елементи в динамичната памет
    Stack res;

    res.capacity = max_elem_count;
    res.cur_elem_count = 0;
    res.arr = calloc(max_elem_count, sizeof(A));
    return res;
}

int push(Stack *s, A elem) {
    // Проверява дали има място в стека
    if(s->capacity == s->cur_elem_count) {
        return -1;
    }
    // Добавя елемент на първата свободна позиция
    s->arr[s->cur_elem_count] = elem;
    s->cur_elem_count++;
    return 0;
}

int pop(Stack *s, A *res) {
    // Проверяваме дали стекът е празен
    if(s->cur_elem_count == 0) {
        return -1;
    }
    // Премахва последния елемент на стека и го предава чрез указателя res, само ако res != NULL
    if(res) {
        *res = s->arr[s->cur_elem_count - 1];
    }
    s->cur_elem_count--;
    return 0;
}

void print_elems(Stack s) {
    // Печата елементите на стека
    for(size_t i = 0; i < s.capacity; i++) {
        if(i < s.cur_elem_count) {
            printf("%3d ", s.arr[i].data);
        } else {
            printf("___ ");
        }
    }
    printf("\n");
}
void deinit(Stack s) {
    free(s.arr);
}
int main() {
    Stack s1 = init_stack(10);
    push(&s1, (A){ .data = 10 });
    push(&s1, (A){ .data = 20});
    push(&s1, (A){ .data = 30});
    print_elems(s1);

    Stack s2 = init_stack(5);
    push(&s2, (A){ .data = 1 });
    push(&s2, (A){ .data = 2 });
    push(&s2, (A){ .data = 3 });
    print_elems(s2);
    deinit(s1);
    deinit(s2);
    return 0;
}