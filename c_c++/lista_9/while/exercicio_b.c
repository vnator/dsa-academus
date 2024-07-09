#include <stdio.h>
 
int main() {
    int a, b;
    
    while(a != b) {
        scanf("%d %d", &a, &b);
        
        if (a > b) {
            printf("Decrescente\n");
        }
        
        if (b > a) {
          printf("Crescente\n");
        }
    }
 
    return 0;
}

// second way
int main() {
    int a, b, i, j;
    char *r[30];
    
    while(a != b) {
        scanf("%d %d", &a, &b);
        
        if (a>b)
            r[i] = "Decrescente\n";
        
        if (b>a)
          r[i] = "Decrescente\n";
        
        i++;
    }
    
    while(j>i) {
        printf(r[j]);
        j++;
    }
 
    return 0;
}
