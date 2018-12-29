#include <stdio.h>
#define FALSE  0
#define TRUE !FALSE

int main(int argc, char* argv[])
{
  FILE* f1 = fopen(argv[1], "r");
  FILE* f2 = fopen(argv[2], "w");

  if (f1 == NULL || f2 == NULL)
  {
    perror("Error opening one of the files");
  }

  int text[10000];
  int i= 0;
  do {
      text[i] = fgetc(f1);
      if (text[i] != EOF)
      {
        fputc((char)text[i], f2);
      }
      i++;
  } while(text[i] != EOF);

  if (ferror(f1) || ferror(f2))
  {
    perror("Error in file processing!");
  }
  fclose(f1);
  fclose(f2);
  return 0;
}
