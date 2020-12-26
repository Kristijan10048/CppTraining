#include <stdio.h>
#include <cstdlib.h>
#include<iostream.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>


int main(void)
{
   FILE *stream;
   textcolor(LIGHTGREEN);
   struct date s;
   char path[50];
   getdate(&s);
  cout<<" Date:"<<s.da_day<<"-"<<s.da_mon<<"-"<<s.da_year;
   cprintf("\nenter file path:");
   cscanf("%20s",path);
   cprintf(path);
   system("pause");
   if ((stream = fopen(path, "r+")) == NULL) /* open file TEST.$$$ */
   {
      fprintf(stderr, "Cannot open output file.\n");
      return 1;
   }

   fwrite(path, strlen(path), 1, stream); /* write struct s to file */
   fclose(stream); /* close file */
   return 0;
}
