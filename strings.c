#include <stdio.h>
#include <ctype.h>

int input(char *delim, char *arr) {
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
int check(char *delim, char *arr) {

  if (*delim != ' ' && *delim != '+' && *delim != ':') {
    return -1;
  }

  int i = 0;
  int numberDelim = 1, numberDisk = 0, numberSlash1 = 0, numberSlash2 = 0,
   numberTwoPoint = 0, numberPoint = 0, numberSymbol = 0;

  for (; arr[i] != '\0'; i++) {

    if (arr[i] >= 'A' && arr[i] <= 'Z' && numberDelim == 1) {
      numberDelim = 0;
      numberDisk++;
      continue;
    }

    if (arr[i] == ':' && numberDisk == 1) {
      numberDisk = 0;
      numberTwoPoint++;
      continue;
    }

    if (arr[i] == '\\' && numberTwoPoint == 1) {
      numberTwoPoint = 0;
      numberSlash1++;
      continue;
    }

    if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSlash1 == 1) {
      numberSlash1 = 0;
      numberSymbol++;
      continue;
    }

    if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSymbol > 0) {
      numberSymbol++;
      continue;
    }

    if (arr[i] == '\\' && numberSymbol > 0 && numberPoint == 0) {
      numberSymbol = 0;
      numberSlash1++;
      continue;
    }

    if (arr[i] == '.') {
      numberPoint++;
      continue;
    }

    if (arr[i] == *delim && numberSymbol > 0) {
      numberPoint = 0;
      numberSymbol = 0;
      numberDelim++;
      continue;
    }

    if (arr[i] == '/' && numberDelim == 1) {
      numberDelim = 0;
      numberSlash2++;
      continue;
    }

    if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSlash2 == 1) {
      numberSlash2 = 0;
      numberSymbol++;
      continue;
    }

    if (((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) && numberSymbol > 0) {
      numberSymbol++;
      continue;
    }

    if (arr[i] == '/' && numberSymbol > 0 && numberPoint == 0) {
      numberSymbol = 0;
      numberSlash2++;
      continue;
    }

    return -1;
  }

  return 0;
}

void process(char *delim, char *arr, char *arr2) {

  int j = 0, i;

  for (i = 0; arr[i] != '\0'; i++) {
    if (arr[i] == '\\') {
      arr2[i + j] = '/';
      continue;
    }
    arr2[i + j] = arr[i];
    if (arr[i] == ':') {
      arr2[i - 1 + j] = '/';
      arr2[i + j] = 'c';
      arr2[i + (++j)] = 'y';
      arr2[i + (++j)] = 'g';
      arr2[i + (++j)] = 'd';
      arr2[i + (++j)] = 'r';
      arr2[i + (++j)] = 'i';
      arr2[i + (++j)] = 'v';
      arr2[i + (++j)] = 'e';
      arr2[i + (++j)] = '/';
      arr2[i + (++j)] = tolower(arr[i - 1]);
    }
  }
  arr2[i + j] = '\0';

}
void output(char *arr2) {

  printf("\nnew paths: %s\n\n", arr2);

}
