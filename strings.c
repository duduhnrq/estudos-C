#include <stdio.h>
#include <string.h>

int main() {
    char * name = "John Doe";
    char * address = "123 Main St, Springfield, USA";
    char * phone = "123-456-7890";

    printf("Name: %s\n", name);
    printf("Address: %s\n", address);
    printf("Phone: %s\n", phone);
    printf("-------------------------\n");
    printf("%d\n",strlen(name));

    if (strncmp(name, "John Doe", 8) == 0) {
        printf("Name matches!\n");
    } else {
        printf("Name does not match.\n");
    }

    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);
    
    return 0;
}