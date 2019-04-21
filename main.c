#include <stdio.h>
#include "strings.h"

int main()
{
  char delim;
  char arr[1000];
  char arr2[1500];

  if (input(&delim, arr) != 0) {
    printf("\nWrong input data!\n");
    return -1;
  }

  if (check(&delim, arr) != 0) {
    printf("\nWrong input data!\n");
    return -1;
  }

  process(&delim, arr, arr2);

  output(arr2);

  return 0;
}
