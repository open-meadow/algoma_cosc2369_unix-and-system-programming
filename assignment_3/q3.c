#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 256

// Modify the code so it accept input data as command-line arguments.
int main(int argc, char *argv[]) {
  int position = 0;
  char memory[ALLOCSIZE];
  
  for(int i = 1; i < argc; i++) {
      if(argv[i][0] == '>') {
          position = (position == 255) ? position : (position + 1);;
      } else if (argv[i][0] == '<') {
          position = (position == 0) ? position : (position - 1);
      } else {
          char c = atoi(argv[i]);
          if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            memory[position] = c;
          }
      }
    }
  
  printf("Memory: \n");
  for(int i = 0; i < ALLOCSIZE; i++) {
      printf("%c", memory[i]);
  }
}