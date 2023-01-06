#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// I wrote this ages ago, didn't work for a while and kept core dumping
// They should change the name of C to "shoot my foot with a gun"

int transform(int n, int p)
{
  // Convert into string
  char s[10];
  sprintf(s, "%d", n);

  // Find the Pth digit
  int pthDigit = s[strlen(s) - p] - '0';

  // Build transformed number as string
  char transformed[0] = "";
  for (int i = 0; i < strlen(s); i++)
  {
    int digit = s[i] - '0';
    if (i < strlen(s) - p)
    {
      sprintf(transformed, "%s%d", transformed, (digit + pthDigit) % 10);
    }
    else if (i > strlen(s) - p)
    {
      sprintf(transformed, "%s%d", transformed, abs(digit - pthDigit));
    }
    else
    {
      sprintf(transformed, "%s%c", transformed, s[i]);
    }
  }

  return atoi(transformed);
}

int main()
{
  FILE *file = fopen("input.txt", "r");
  if (file == NULL)
  {
    fprintf(stderr, "Error: Could not open file.\n");
    return 1;
  }

  // Read the input
  char line[20];
  while (fgets(line, sizeof(line), file))
  {
    int n, p;
    sscanf(line, "%d %d", &n, &p);
    printf("%d\n", transform(n, p));
  }

  return 0;
}