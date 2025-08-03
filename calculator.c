#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 120

char buffered_reader();
void buffered_writer(char c);

int main(void) {
  char in;
  printf("Reverse polish calculator");

  buffered_writer('f');
  printf("%c\n", buffered_reader());
  printf("%c\n", buffered_reader());

  return 0;
}

/*
 * Buffer
 */
char buffer[BUFFER_SIZE];
int bp = 0; /* The next free space in the buffer */

char buffered_reader() {
  if (bp > 0)
    return buffer[--bp];

  return getchar();
}

void buffered_writer(char c) {
  if (bp == BUFFER_SIZE) {
    printf("Error!! The buffer is full!!");
    exit(1);
  }

  buffer[bp++] = c;
}
