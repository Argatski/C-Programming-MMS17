#include<stdio.h>
void subseq(int arr[], int n, int dest[], int *new_n) {
    int cur_start = 0,
        max_start = 0,
        max_length = 1;

    for(size_t i = 1; i < n; i++) {
        if(arr[i-1] < arr[i]) {
            int cur_length = i - cur_start;
            if(cur_length > max_length) {
                max_length = cur_length;
                max_start = cur_start;
            }
            cur_start = i;
        }
    }

    int cur_length = n - cur_start;
    if(cur_length > max_length) {
        max_length = cur_length;
        max_start = cur_start;
    }
    *new_n = max_length;
    for(size_t i = 0; i < max_length; i++) {
        *(dest++) = arr[max_start + i];
    }
}
int main() {
    int N;
    int src[30];
    scanf("%d", &N);
    for(size_t i = 0; i < N; i++) {
        scanf("%d", src+i);
    }
    int dest[30],
        newN;
    subseq(src, N, dest, &newN);
    for(size_t i = 0; i < newN; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
}