// muhammad zhidny ilman
// nim: 22343062
//Tampilkan bilangan Fibonaci 
//Gunakan pengecekan pengalokasian dan fungsi free di akhir program
    

#include <stdio.h>
#include <stdlib.h>

int i;
int* fibonacci(int n) {
    int* result = (int*) malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            result[i] = 1;
        } else {
            result[i] = result[i-1] + result[i-2];
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int* fib = fibonacci(n);

    printf("Fibonacci series: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    free(fib);
    return 0;
}
