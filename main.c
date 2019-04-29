#include <stdio.h>
#include "strings.h"

int main()
{
  char delim;
  char arr1[1000];
  char arr[4][10][30];
  int arrI[4][10];
  char arr2[1000];

  //char reject[10] = {'\\', ':', '*', '?', '\"', '<', '>', '|'};

  input(&delim, arr1);

  process(arr, arr2, arr1, &delim, arrI);

  //printf("!%s!\n", arr[2][4]);



  output(arr2);

  return 0;
}



















//
// int main()
// {
//   char delim;
//   char arr[1000];
//   char arr2[1500];
//
//   if (input(&delim, arr) != 0) {
//     printf("\nWrong input data!\n");
//     return -1;
//   }
//
//   if (check(&delim, arr) != 0) {
//     printf("\nWrong input data!\n");
//     return -1;
//   }
//
//   process(&delim, arr, arr2);
//
//   output(arr2);
//
//   return 0;
// }
