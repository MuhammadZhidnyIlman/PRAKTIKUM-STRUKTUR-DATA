//muhammad zhidny ilman
// nim: 22343062
// menampilkan bilangan prima pertama sampai ke n menggunakan pointer
//n dimasukan oleh user gunakan fungsi() untuk mengalokasikan ukuran memori yang baru dimana m dimasukan oleh user

#include <stdio.h>
#include <stdlib.h>

int i;
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int* get_primes(int n, int m) {
    int* result = (int*) malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    int count = 0;
    for (i = 2; count < n; i++) {
        if (is_prime(i)) {
            result[count++] = i;
            if (count == n) {
                break;
            }
            if (count == m) {
                m *= 2;
                result = (int*) realloc(result, m * sizeof(int));
                if (result == NULL) {
                    printf("Failed to reallocate memory.\n");
                    exit(1);
                }
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the initial value of m: ");
    scanf("%d", &m);

    int* primes = get_primes(n, m);

    printf("Prime numbers: ");
    for (i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
    return 0;
}
