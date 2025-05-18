#include <stdio.h>

#define MAX 100

int main() {
  int disk[MAX] = {0};
  printf("Enter no of files: ");
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("File %d - Enter start block and lengh: ", i);
    int start;
    int len;
    scanf("%d %d", &start, &len);
    int flag = 1;
    for (int j = start; j < start + len; j++) {
      if (j >= MAX || disk[j]) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      printf("File allocation failed!\n");
    } else {
      int j;
      printf("File %d allocated at blocks:\n", i);
      for (j = start; j < start + len; j++) {
        disk[j] = 1;
        printf("%d ", j);
      }
    }
    printf("\n");
  }
  return 0;
}
