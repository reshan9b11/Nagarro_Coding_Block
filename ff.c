#include <stdio.h>
#include <stdlib.h>
void B()
{
printf("\nin B()"); 
exit(0);
}

void A()
{
printf("\nin A()");
char buffer[8] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,0xff,0xff};
unsigned char *pI = buffer;
/*for (int i=0; i <80;++i) 
{
if (!(i % 8))
{
printf("%p: (+%2d)", pI+i,i);
}
printf(" %02x", pI[i]);
if (i%8 == 7) 
{
printf("\n");
}
}*/
*(void**)(pI + 24 ) = (unsigned char*)&B;
  
 }
int main()
{
//printf("&main(): %p\n", &main);
printf("call A():");
A();
printf("Again in Main()");
return 0;
}
