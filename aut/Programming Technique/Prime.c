#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 1) {
        printf("2\n");
        return 0;
    }
    
    int count = 1; 
    int num = 3; 
    
    while (count < n) {
        if (IsPrime(num)) {
            count++;
        }
        if (count < n) {
            num += 2;
        }
    }
    
    printf("%d\n", num);
    return 0;
}