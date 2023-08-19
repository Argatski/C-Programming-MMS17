#include <stdio.h>
#include <pthread.h>

#define NUM_TRANSACTIONS 100
#define NUM_THREADS 10

double balance = 0.0;

void *deposit(void *arg) {
    double dep_amount = *(double *)arg;
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        balance += dep_amount;
        printf("Depositing %.2lf. New balance: %.2lf\n", dep_amount, balance);
    }
    pthread_exit(NULL);
}

void *withdraw(void *arg) {
    double withdr_amount = *(double *)arg;
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        if (balance >= withdr_amount) {
            balance -= withdr_amount;
            printf("Withdrawing %.2lf. New balance: %.2lf\n", withdr_amount, balance);
        } else {
            printf("Insufficient balance for withdrawal of %.2lf\n", withdr_amount);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    double dep_amount = 200.0;
    double withdr_amount = 100.0;

    for (int i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, deposit, &dep_amount);
        } else {
            pthread_create(&threads[i], NULL, withdraw, &withdr_amount);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final balance: %.2lf\n", balance);

    return 0;
}
