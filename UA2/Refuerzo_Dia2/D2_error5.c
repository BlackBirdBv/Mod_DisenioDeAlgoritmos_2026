#include <stdio.h>
void duplicar(int x) {
    x = x * 2;
    printf("dentro de x = %d\n", x);
}
int main(void) {
    int n = 8;
    duplicar(n);
    printf("n = %d\n", n);
    return 0;
}
