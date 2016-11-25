# include <limits.h>
# include <string.h>
# include <stdio.h>
#include <time.h>

 # define NO_OF_CHARS 256
 int max (int a, int b) {
 return (a > b)? a: b; 
}
 void badCharHeuristic( char *str, int size, int badchar[NO_OF_CHARS])
{
  int i;
  for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;
  for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}
 void search( char *txt,  char *pat)
{
	time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  int m = strlen(pat);
  int n = strlen(txt);
  int badchar[NO_OF_CHARS];
  badCharHeuristic(pat, m, badchar);
  int s = 0;  
 while(s <= (n - m))
    {
  int j = m-1;
 
 while(j >= 0 && pat[j] == txt[s+j])
            j--;
 if (j < 0)
        {
   printf("\n pattern occurs at shift = %d \n", s);
   printf("***ATTENTION REQUIRED: MALICIOUS ACTIVITY DETECTED***");
   printf ( "\n  Date and Time of event: %s", asctime (timeinfo) );
   s += (s+m < n)? m-badchar[txt[s+m]] : 1;
        }
 else
   s += max(1, j - badchar[txt[s+j]]);
    }
}
 void main()
{

  char *arr[3];
  arr[0]="<script>";
  arr[1]="/usr/bin/perl";
  arr[2]="</script>"; 
  char txt[] = "shubhi /usr/bin/perlhgygygy";
  char pat[10];
  int i;
for( i=0;i<2;i++){ 
  strcpy(pat,arr[i]);
  search(txt, pat);
  
}
  
}
 
