#include <stdio.h>

int add(int a, int b); // Declaration
int mult(int x, int y);

int main() {
    int output = add(4, 5);
    printf("Output: %d\n", output);
    
    int multoutput = mult(8, 5);
    printf("Mult output: %d\n", multoutput);
}

int add(int a, int b) { // Definition
    int result = a + b;
    return result;
}

int mult(int x, int y) {
    int result = 0;
    int i = 0;
    for (i = 0; i < x; i++) 
        result += y;
    return result;
}