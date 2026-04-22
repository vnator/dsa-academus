#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x, y, z;
} R3Vector;

double r3Distence(R3Vector a, R3Vector b);

int main() {
  int size;
  double shortDistance = 0;
  R3Vector twoPointsShortDistance[2];

  printf("Quantos elementos serao inseridos? ");
  scanf("%d", &size);

  R3Vector *vectorList = (R3Vector *)malloc(sizeof(R3Vector) * size);

  for (int i = 0; i < size; i++) {
    printf("Ponto %d, ex: 1 2 3.3, digite: ", i + 1);
    scanf("%lf %lf %lf", &vectorList[i].x, &vectorList[i].y, &vectorList[i].z);
  }

  for (int i = 0; i <= size; i++) {
    for (int j = i + 1; j < size; j++) {
      double currentDistance = r3Distence(vectorList[i], vectorList[j]);

      if ((i == 0 && j == 1) || currentDistance < shortDistance) {
        shortDistance = currentDistance;
        twoPointsShortDistance[0] = vectorList[i];
        twoPointsShortDistance[1] = vectorList[j];
      }
    }
  }

  printf("\nMenor distancia encontrada: %.4lf\n", shortDistance);
  printf("Entre o Ponto A(%.1f, %.1f, %.1f) e o Ponto B(%.1f, %.1f, %.1f)\n",
         twoPointsShortDistance[0].x, twoPointsShortDistance[0].y,
         twoPointsShortDistance[0].z, twoPointsShortDistance[1].x,
         twoPointsShortDistance[1].y, twoPointsShortDistance[1].z);

  free(vectorList);
  return 0;
}

double r3Distence(R3Vector a, R3Vector b) {
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}
