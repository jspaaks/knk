#include <stdio.h>
#include <stdlib.h>

int * create_array (int n, int initial_value);

int * create_array (int n, int initial_value) {
  int * p = malloc(n * sizeof(int *));
  if (p == NULL) {
    printf("Memory allocation failed. Aborting.\n");
    exit(EXIT_FAILURE);
  }
  for (int * q = p; q < (p + n); q++) {
    *q = initial_value;
  }
  return p;
}

int main (void) {
  int n = 10;
  int * arr = create_array(n, 6);
  for (int i = 0; i < n; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
  free(arr);
  exit(EXIT_SUCCESS);
}
