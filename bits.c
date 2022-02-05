#include <stdio.h>

int main() {
    int arch = 8*sizeof(void*);
    printf("Numero %d", arch);
    return 0;
}