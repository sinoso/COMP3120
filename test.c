#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *fp;
fp=fopen("testtext.txt","w");
fprintf(fp,"abc123");
fclose(fp);
return 0;
}
