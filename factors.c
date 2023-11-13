#include <stdio.h>

void factorize(long long n) {
    if (n <= 0) {
        printf("Unable to factorize %lld\n", n);
        return;
    }

    for (long long i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%lld=%lld*%lld\n", n, n / i, i);
            return;
        }
    }
    printf("Unable to factorize %lld\n", n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    long long num;
    while (fscanf(file, "%lld", &num) == 1) {
        factorize(num);
    }

    fclose(file);
    return 0;
}

