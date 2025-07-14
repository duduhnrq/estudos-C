#include <stdio.h>

void addone(int *n) {
    // n is local variable which only exists within the function scope
    (*n)++; // therefore incrementing it has no effect
}

int main() {
    int n;
    printf("Before: %d\n", n);
    addone(&n);
    printf("After: %d\n", n);
}