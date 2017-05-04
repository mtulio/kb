/* Exercicio IDEA */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   unsigned char chave[16]={0xFE,0x01,0x23,0x45,0x67,0x89,0xFD,0xC1,
                            0xF1,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF}; /*16 x 8 = 128 bits */
   unsigned short int k[6];
   unsigned short int i;
   unsigned short int x1,x2,x3,x4,t0,t1,t2,a;

   system("cls");
   for(i=0;i<6;i++)
   {
      k[i]=chave[2*i];
      k[i]=(k[i]<<8) + chave[2*i + 1];
   }
   /* como no exercicio o texto é a primeira parte da chave, tem-se que x1=k0,x2=k1...*/ 
   x1=((unsigned long int)((unsigned long int)k[0] * (unsigned long int)k[0]))% 65537;
   x2=((unsigned long int)((unsigned long int)k[1] + (unsigned long int)k[1]))% 65536;
   x3=((unsigned long int)((unsigned long int)k[2] + (unsigned long int)k[2]))% 65536;
   x4=((unsigned long int)((unsigned long int)k[3] * (unsigned long int)k[3]))% 65537;
   t0=((unsigned long int)k[4] * (x1 ^ x3)) % 65537;
   t1=((unsigned long int)k[5] * (((unsigned long int)t0 + (x2 ^ x4))%65536)) % 65537;
   t2=((unsigned long int)((unsigned long int)t0 + (unsigned long int) t1))% 65536;
   x1=t1 ^ x1;
   a = t2 ^ x2;
   x2 = t1 ^ x3;
   x3 = a;
   x4 = t2 ^ x4;
   printf("%x  - %x  - %x  - %x\n",x1,x2,x3,x4);
    printf("%d - %d - %d - %d\n",x1,x2,x3,x4);
   system("pause");
   return 0;
}


