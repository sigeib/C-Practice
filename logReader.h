#include <stdio.h>
#define FALSE  0
#define TRUE !FALSE

int main(int argc, char* argv[])
{
  FILE* f = fopen(argv[1], "r");
  if (f == NULL)
  {
    perror("Error opening file");
  }

  char line
  do {

  } while( != EOF);

  return 0;
}
