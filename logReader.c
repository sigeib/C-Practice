#include <stdio.h>
#include <string.h>

#define FALSE  0
#define TRUE !FALSE

int main(int argc, char* argv[])
{
  FILE* f = fopen(argv[1], "r");
  if (f == NULL)
  {
    perror("Error opening file");
  }

  char string[300];
  while(fgets(string, 300, f) != NULL)
  {
    char month[5];
    char process[50];
    char message[100];
    int day, hour, min, sec;

    sscanf(string, "%s %d %d:%d:%d %s ", month, &day, &hour, &min, &sec, process);

    if(strstr(string, "fail") != NULL)
    {
      int seconds = (hour*3600 + min*60 + sec);
      char* ch;
      ch = strchr(string, ':');
      ch = strchr(ch + 1, ':');
      ch = strchr(ch + 1, ':');

      printf("%d seconds to %s \n", seconds, ch+2);
    }
  }

  fclose(f);
  return 0;
}
