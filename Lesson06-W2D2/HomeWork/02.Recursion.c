#include <stdio.h>
#include <stdbool.h>

// Функция за пресмятане на степен
int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

// Функция за пресмятане на израза
int evaluate_expression(const char *expr, int *index) {
    int num = 0;
    int result = 0;
    char op = '+';

    while (true) {
        char current_char = expr[*index];

        if (current_char == '(') {
            (*index)++;
            num = evaluate_expression(expr, index);
        } else if (current_char >= '0' && current_char <= '9') {
            num = current_char - '0';
        } else if (current_char == '^') {
            // Handle power operation separately
            (*index)++;
            int next_index = *index;
            int exp = evaluate_expression(expr, &next_index);
            num = power(num, exp);
            *index = next_index; // Update index after evaluating exponent
        } else if (current_char == '+' || current_char == '*' || current_char == ')' || current_char=='^' || current_char == '\0') {
            // Handle operators and end of expression
            if (op == '+') {
                result += num;
            } else if (op == '*') {
                result *= num;
            }
            else {
          
            }

            if (current_char == ')' || current_char == '\0') {
                break;
            }

            op = current_char;
        }

        (*index)++;
    }

    return result;
}

int main() {
    char expr[100];
    printf("Enter the expression: ");
    scanf("%[^\n]", expr);

    int index = 0;
    int result = evaluate_expression(expr, &index);

    printf("Result: %d\n", result);

    return 0;
}


