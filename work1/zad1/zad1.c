#include <stdio.h>

void printcharsonnewline(char *s, int sizeLength) {
    char currentchar;
  for (int index = 0; index < sizeLength; index++) {
    currentchar = s[index];
    printf("%c\n", currentchar);
  }
}

int main() {
  char input[] = "someString";
  int size = sizeof(input)/sizeof(input[0]);

  printcharsonnewline(input, size);
  
  return 0;
}

