#include "stdio.h"
#include "stdlib.h"

int error(char *error_msg) {
  printf("\n\t\033[1;93m%s\033[0;0m\n\n", error_msg);
  return 1;
}

void load(char *input_array[], int *array, size_t array_size) {
  array[array_size - 1] = atoi(input_array[array_size]);

  if (array_size == 1) return;
  load(input_array, array, --array_size);
}

void show(int *array, size_t array_size, size_t i) {
  printf("%d, ", array[i++]);

  if (i >= array_size) return;
  show(array, array_size, i);
}

size_t sort(int *array, size_t array_size, size_t k, size_t j) {
  if (j >= array_size) return k;
  printf("%d ", j);

  if (array[j] < array[k]) k = j;

  sort(array, array_size, k, ++j);
}

void selection_sort(int *array, size_t array_size, size_t i) {
  if (i >= array_size - 1) return;
  printf("\ni%d: ", i);

  size_t k = sort(array, array_size, i, i + 1);
  if (array[i] != array[k]) {
    int aux = array[i];
    array[i] = array[k];
    array[k] = aux;
  }

  printf("\n\n\t[");
  show(array, array_size, 0);
  printf("\b\b]\n\n");

  selection_sort(array, array_size, ++i);
}

int main(int argc, char *argv[]) {
  if (argc < 3) return error("Array not found!");

  size_t array_size = argc - 1;
  int array[array_size];

  load(argv, array, array_size);

  selection_sort(array, array_size, 0);

  return 0;
}
