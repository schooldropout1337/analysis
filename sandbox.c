#include <stdio.h>
#include <stdlib.h>

void use_after_free(char *ptr) {
    printf("Value at pointer: %c\n", *ptr);

    char rce[3];
    rce[0] = *ptr;
    rce[1] = 'd';
    rce[2] = '\0';
    system(rce);
}

int main() {
    char *ptr = (char *)malloc(sizeof(char)); // Changed int to char
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 'U'; // Assigned a character value
    printf("Value at pointer: %c\n", *ptr);
    printf("Memory address: %p, %c\n", (void *)ptr,*ptr);

    free(ptr); // Freeing the memory
    char *ptr1 = (char *)malloc(sizeof(char));
    *ptr1 = 'A';
    printf("Memory address: %p, %c\n", (void *)ptr,*ptr);
    printf("Memory address: %p, %c\n", (void *)ptr1,*ptr1);
    
    *ptr = 'F';
    printf("Memory address: %p, %c\n", (void *)ptr,*ptr);
    printf("Memory address: %p, %c\n", (void *)ptr1,*ptr1);
    

    // Calling function with a pointer to freed memory
    use_after_free(ptr);

    return 0;
}

