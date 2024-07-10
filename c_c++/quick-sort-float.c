#include <stdio.h>

int partition(float *V, int start, int end){
  int left, right;
  float center, aux;

  left = start;
  right = end;
  center = V[start];

  while(left < right) {
    while(V[left] <= center)
      left++;
    while(V[right] > center)
      right--;
    if(left<right){
      aux = V[left];
      V[left] = V[right];
      V[right] = aux;
    }
  }

  V[start] = V[right];
  V[right] = center;

  return right;
}

void quickSort(float *V, int start, int end) {
  if (end > start) {
    int center = partition(V, start, end);
    quickSort(V, start, center-1);
    quickSort(V, center+1,  end);
  }
}
