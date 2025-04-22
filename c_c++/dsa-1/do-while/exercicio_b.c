#include <stdio.h>
 
int main() {
    int i = 1, highest = 0, highest_index = 0, entrace;
 
    do {
        scanf("%d", &entrace);
        
        if (entrace>highest) {
            highest = entrace;
            highest_index = i;
        }
        
        i++;
    } while(i<=100);
    
    printf("%d\n%d\n", highest, highest_index);
    
    return 0;
}
