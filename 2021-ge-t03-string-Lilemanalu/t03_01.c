// 12S20017 - Lile Manalu
// 12S20031 - Daniel Andres Simangunsong

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argv, char **_argc) {
    
    char a[60];
    scanf("%c", a);

    int b = strlen(a); // b adalah jumlah semua angka
    int i, j;
     
    for (i = 0; i <= b/3-1; i++) {
        char c[60/3];
        for (j = i * 3; j <= (i + 1) * 3 - 1; j++) {
            c[i] = a[j];
        }
        printf("%c",atoi(c));
    }
    
return 0;
}
