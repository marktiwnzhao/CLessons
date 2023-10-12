//
// Created by 赵政杰 on 2021/10/25.
//
#include <stdio.h>
#include <math.h>

int main() {
    int max = 0;
    scanf("%d", &max);

    for (int i = 2; i <= max; i++) {
        int is_prime = 1;
        for (int j = 2; j <= floor(sqrt(i)); j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d ", i);
        }
    }
    return 0;
}

