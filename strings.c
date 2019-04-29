#include <stdio.h>
//#include <ctype.h>
#include "string.h"

int input(char *delim, char *arr){
    char garbage;

    printf("delim: ");
    scanf("%c", delim);
    scanf("%c", &garbage);

    printf("paths: ");

    for (int i = 0, j = 0; i < 261; i++) {
      scanf("%c", &arr[i + j]);
      if (arr[i + j] == '\n') {
        arr[i + j] = '\0';
        break;
      }
      if ((arr[i + j] != '\n' && i == 260) || (j + i) > 999 ) {
        return -1;
      }
      if (arr[i + j] == *delim) {
        j += i;
        i = 0;
      }
    }


    return 0;
}

int check(char arr[4][10][30], int arrI[4][10]) {
  int z, j, i, point;

//

  for (z = 0; z < 4; z++) {
    for (j = 0; arrI[z][j] == 1 || arrI[z][j] == 2; j++) {
      for (i = 0, point = 0; arr[z][j][i] != '\0'; i++) {
        if ((arr[z][j][i] >= 'a' && arr[z][j][i] <= 'z') || (arr[z][j][i] >= 'A' && arr[z][j][i] <= 'Z') || (arr[z][j][i] >= '0' && arr[z][j][i] <= '9')) {
          continue;
        } else if (arr[z][j][i] == ':' && arr[z][j][i + 1] == '\0') {
          continue;
        } else if(arr[z][j][i] == '.' && point == 0) {
          point++;
          continue;
        } else {
          return -1;
        }
      }
      if (i == 0) {
        if (j == 0 && arrI[z][j] == 2) {
          continue;
        } else {
          return -1;
        }
      }
    }
  }

  return 0;

}

int progress(char arr[4][10][30], int arrI[4][10], char *arr2, char *delim) {
  int i, j, z, k, l;
  for (z = 0, k = 0, l = 0; z < 4; z++) {
    for (j = 0; arrI[z][j] == 1 || arrI[z][j] == 2; j++) {
      for (i = 0; arr[z][j][i] != '\0'; i++, k++) {
        //printf("!!! ");
        if (arr[z][j][1] == ':') {
                arr2[k + l] = '/';
                arr2[k + (++l)] = 'c';
                arr2[k + (++l)] = 'y';
                arr2[k + (++l)] = 'g';
                arr2[k + (++l)] = 'd';
                arr2[k + (++l)] = 'r';
                arr2[k + (++l)] = 'i';
                arr2[k + (++l)] = 'v';
                arr2[k + (++l)] = 'e';
                arr2[k + (++l)] = '/';
                arr2[k + (++l)] = arr[z][j][i] - 'C' + 'c';
                i++;
                continue;
        }
        arr2[k + l] = arr[z][j][i];

      }
      arr2[k + (l++)] = '/';
    }
    arr2[k + l - 1] = *delim;
  }
  arr2[k + l - 1] = '\0';




  return 0;
}

int stok123 (char arr[4][10][30], char *arr1, char *delim, int arrI[4][10]) {

  int i, j, z, k;
  for (i = 0, j = 0, z = 0, k = 0; arr1[k] != '\0'; k++, i++) {
    if (arr1[k] == '\\') {
      arr[z][j][i] = '\0';
      arrI[z][j] = 1;
      j++;
      i = -1;
      continue;
    }
    if (arr1[k] == '/') {
      arr[z][j][i] = '\0';
      arrI[z][j] = 2;
      j++;
      i = -1;
      continue;
    }
    if (arr1[k] == *delim || arr1[k] == '\0') {
      arr[z][j][i] = '\0';
      arrI[z][j] = 1;
      z++;
      j = 0;
      i = -1;
      continue;
    }
    //printf("%d %d %d ", i, j, z);
    arr[z][j][i] = arr1[k];
    //printf("%c\n", arr[z][j][i]);
  }
  arrI[z][j] = 1;
  arr[z][j][i] = '\0';

  return 0;
}
//
int process(char arr[4][10][30], char *arr2, char *arr1, char *delim, int arrI[4][10]) {

  stok123(arr, arr1, delim, arrI);




  // int i, j, z, k;
  // for (i = 0, j = 0, z = 0, k = 0; arr1[k] != '\0'; k++, i++) {
  //   if (arr1[k] == '\\') {
  //     arr[z][j][i] = '\0';
  //     arrI[z][j] = 1;
  //     j++;
  //     i = -1;
  //     continue;
  //   }
  //   if (arr1[k] == '/') {
  //     arr[z][j][i] = '\0';
  //     arrI[z][j] = 2;
  //     j++;
  //     i = -1;
  //     continue;
  //   }
  //   if (arr1[k] == *delim || arr1[k] == '\0') {
  //     arr[z][j][i] = '\0';
  //     arrI[z][j] = 1;
  //     z++;
  //     j = 0;
  //     i = -1;
  //     continue;
  //   }
  //   //printf("%d %d %d ", i, j, z);
  //   arr[z][j][i] = arr1[k];
  //   //printf("%c\n", arr[z][j][i]);
  // }
  // arrI[z][j] = 1;
  // arr[z][j][i] = '\0';

  //printf("%d\n", check(arr, arrI));
  check(arr, arrI);

  progress(arr, arrI, arr2, delim);

  return 0;

}
//
void output(char *arr2) {
  printf("\nnew paths: %s\n", arr2);
}





unsigned int slen(const char *s) {
    const char *sc = s;
    while (*sc != '\0') {
        ++sc;
    }
    return sc - s;
}




// char *stok(char **s, const char *ct) {
//     char *sbegin = *s;
//     const char *sc1, *sc2;
//
//     if (sbegin == NULL) {
//         return NULL;
//     }
//
//     for (sc1 = sbegin; *sc1 != '\0'; ++sc1) {
//         for (sc2 = ct; *sc2 != '\0'; ++sc2) {
//             if (*sc1 == *sc2) {
//                 return (char *)sc1;
//             }
//         }
//     }
//
//     return sbegin;
// }

short int scmp(const char *cs, const char *ct) {
    char c1, c2;

    while (1) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2) {
            return c1 < c2 ? -1 : 1;
        }
        if (!c1) {
            break;
        }
    }
    return 0;
}

unsigned int sspn(const char *string, const char *reject) {
    const char *p;
    const char *r;
    unsigned int count = 0;

    for (p = string; *p != '\0'; ++p) {
        for (r = reject; *r != '\0'; ++r) {
            if (*p == *r) {
                return count;
            }
        }
        ++count;
    }
    return count;
}

char *scpy(char *destination, const char *src) {
    char *temp = destination;

    while (*src != '\0') {
        *destination++ = *src++;
    }
    return temp;
}






































































































// #include <stdio.h>
// #include <ctype.h>
//
// int input(char *delim, char *arr) {
//   char garbage;
//
//   printf("delim: ");
//   scanf("%c", delim);
//   scanf("%c", &garbage);
//
//   printf("paths: ");
//
//   for (int i = 0, j = 0; i < 261; i++) {
//     scanf("%c", &arr[i + j]);
//     if (arr[i + j] == '\n') {
//       arr[i + j] = '\0';
//       break;
//     }
//     if ((arr[i + j] != '\n' && i == 260) || (j + i) > 999 ) {
//       return -1;
//     }
//     if (arr[i + j] == *delim) {
//       j += i;
//       i = 0;
//     }
//   }
//
//   return 0;
// }
// int check(char *delim, char *arr) {
//
//   if (*delim != ' ' && *delim != '+' && *delim != ':') {
//     return -1;
//   }
//
//   int i = 0;
//   int numberDelim = 1, numberDisk = 0, numberSlash1 = 0, numberSlash2 = 0,
//    numberTwoPoint = 0, numberPoint = 0, numberSymbol = 0;
//
//   for (; arr[i] != '\0'; i++) {
//
//     if (arr[i] >= 'A' && arr[i] <= 'Z' && numberDelim == 1) {
//       numberDelim = 0;
//       numberDisk++;
//       continue;
//     }
//
//     if (arr[i] == ':' && numberDisk == 1) {
//       numberDisk = 0;
//       numberTwoPoint++;
//       continue;
//     }
//
//     if (arr[i] == '\\' && numberTwoPoint == 1) {
//       numberTwoPoint = 0;
//       numberSlash1++;
//       continue;
//     }
//
//     if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSlash1 == 1) {
//       numberSlash1 = 0;
//       numberSymbol++;
//       continue;
//     }
//
//     if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSymbol > 0) {
//       numberSymbol++;
//       continue;
//     }
//
//     if (arr[i] == '\\' && numberSymbol > 0 && numberPoint == 0) {
//       numberSymbol = 0;
//       numberSlash1++;
//       continue;
//     }
//
//     if (arr[i] == '.') {
//       numberPoint++;
//       continue;
//     }
//
//     if (arr[i] == *delim && numberSymbol > 0) {
//       numberPoint = 0;
//       numberSymbol = 0;
//       numberDelim++;
//       continue;
//     }
//
//     if (arr[i] == '/' && numberDelim == 1) {
//       numberDelim = 0;
//       numberSlash2++;
//       continue;
//     }
//
//     if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSlash2 == 1) {
//       numberSlash2 = 0;
//       numberSymbol++;
//       continue;
//     }
//
//     if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSymbol > 0) {
//       numberSymbol++;
//       continue;
//     }
//
//     if (arr[i] == '/' && numberSymbol > 0 && numberPoint == 0) {
//       numberSymbol = 0;
//       numberSlash2++;
//       continue;
//     }
//
//     return -1;
//   }
//
//   if (numberSymbol == 0) {
//     return -1;
//   }
//
//   return 0;
// }
//
// void process(char *delim, char *arr, char *arr2) {
//
//   int j = 0, i;
//
//   for (i = 0; arr[i] != '\0'; i++) {
//     if (arr[i] == '\\') {
//       arr2[i + j] = '/';
//       continue;
//     }
//     arr2[i + j] = arr[i];
//     if (arr[i] == ':') {
//       arr2[i - 1 + j] = '/';
//       arr2[i + j] = 'c';
//       arr2[i + (++j)] = 'y';
//       arr2[i + (++j)] = 'g';
//       arr2[i + (++j)] = 'd';
//       arr2[i + (++j)] = 'r';
//       arr2[i + (++j)] = 'i';
//       arr2[i + (++j)] = 'v';
//       arr2[i + (++j)] = 'e';
//       arr2[i + (++j)] = '/';
//       arr2[i + (++j)] = tolower(arr[i - 1]);
//     }
//   }
//   arr2[i + j] = '\0';
//
// }
// void output(char *arr2) {
//
//   printf("\nnew paths: %s\n\n", arr2);
//
// }
