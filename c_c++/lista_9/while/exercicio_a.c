#include <stdio.h>
 
int main() {
    float list[6], positives;
    int i = 0, j = 0;
    
    while(i < 6) {
        scanf("%f", &list[i]);
        
        if (list[i] > 0) {
            positives += list[i];
            j++;
        }
        
        i++;
    }
    i = 0;
    
    printf("%d valores positivos\n", j);
    printf("%.1f\n", positives/j);
 
    return 0;
}
