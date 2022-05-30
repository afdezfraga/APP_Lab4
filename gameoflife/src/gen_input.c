#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FORMAT_RLE   0
#define FORMAT_CELLS 1

int main(int argc, char *argv[])
{
  char *filename = argv[1];
  FILE * infile;
  int width = atoi(argv[2]);
  int height = atoi(argv[3]);
  int format;

  if (strstr(filename, ".rle") != NULL)
  {
    format = FORMAT_RLE;
    printf("Input file in RLE format\n");
  }
  else if (strstr(filename, ".cells") != NULL)
  {
    format = FORMAT_CELLS;
    printf("Input file in CELLS format\n");
  }
  else
  {
    printf("Unknown file format\n");
    return 1;
  }

  infile = fopen(filename, "r");
  char buf[1000];
  int pat_h, pat_w;
  if (format == FORMAT_RLE)
  {
    printf("GoRead\n");
    while (fscanf(infile, "#%[^\n]\n", buf) > 0)
    {
      printf("Read %s\n", buf);
    }
    fscanf(infile, "x = %d, y = %d%*[^\n]\n", &pat_h, &pat_w);
    printf("Size = %d x %d\n", pat_h, pat_w);
    while (fscanf(infile, "%[^$]$\n", buf) > 0)
    {
      printf("Read %s %ld\n", buf, strlen(buf));
      if (buf[strlen(buf)-1] == '\n')
      {
        printf("Done\n");
        break;
      }
    }
  }

  fclose(infile);
  return 0;
}
