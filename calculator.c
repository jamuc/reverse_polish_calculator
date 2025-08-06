#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 120
#define STACK_SIZE 120

char buffered_reader();
void buffered_writer(char c);

double pop();
void push(double c);

int main(void) {
  char in;
  printf("Reverse polish calculator");

  buffered_writer('f');
  printf("%c\n", buffered_reader());
  printf("%c\n", buffered_reader());

  return 0;
}

/*
 * Stack
 */
double stack[STACK_SIZE];
int sp = 0; /* Next free space on stack */

void push(double c) {
  if (sp == STACK_SIZE) {
    printf("Error!! The stack is full");
    exit(1);
  }

  stack[sp++] = c;
}

double pop() {
  if (sp == 0)
    return 0.0;

  return stack[--sp];
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
