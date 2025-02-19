#include <stdio.h>

int main() {
  int array[] = {1, 3, 5, 7, 9};
  int n = sizeof(array) / sizeof(array[0]);

  int lengths[n];
  for (int i = 0; i < n; i++) {
    lengths[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {

      if (array[i] > array[j]) {
        lengths[i] = lengths[i] > lengths[j] + 1 ? lengths[i] : lengths[j] + 1;
      }
    }
  }

  int longest_length = 0;
  for (int i = 0; i < n; i++) {
    if (lengths[i] > longest_length) {
      longest_length = lengths[i];
    }
  }

  printf("Дължината на най-дългата нарастваща подредица е %d.\n", longest_length);

  return 0;
}