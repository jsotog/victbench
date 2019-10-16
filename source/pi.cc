#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printout(void);
void atan10(long denom);
void atan239(long denom);
void atan515(long denom);

int *term;
long *sum, firstword, words;

int main(int argc, char *argv[])
{
   
   int remainder;
   long denom, digits = 0, x;
   //clock_t end,start;
   clock_t start; //Inicializo el reloj
   start=clock(); //Setear a tiempo cero
   
   if(argc != 2)
     {
	
	//printf("\nusage: pi50 NumberOfDigits > OutputFile\n\n");
     }
   
   else
     {
	
	digits = atol( argv[1] );
     }
   
   
   if( digits<50 || digits>210000 )
     {
	
	//printf("Setting default to 1140000 digits.\n");
	digits=100000;
     }
   
   /* Allocate array space and initialize */
   words = digits / 4 + 3;
   sum = (long *)calloc( words + 2, sizeof(long) );
   term = (int *)calloc( words + 2, sizeof(int) );
   if( sum == NULL || term == NULL ) 
     {
	
	//printf("Memory allocation failed. Try fewer digits.\n");
	exit(EXIT_FAILURE);
     }
   
   
   /* ----- 32*atan(1/10) -------*/ 
   start = clock();
   denom = 3; sum[1] = 32;
   
   for (firstword=2; firstword<=words; firstword++) 
     {
	
	atan10(denom);
	denom += 4;
     }
   
   /* ----- -4*atan(1/239) ------- */
   firstword = 2; denom = 3; remainder = 40;
   
   for( x=2; x<=words; x++)
     {
	
	digits = (long)remainder * 10000;
	term[x] = digits / 239;                     /* first term */
	remainder = digits % 239;                    
	sum[x] -= term[x];
     }
   
   
   while( firstword<words )
     {
	
	atan239(denom);
	denom += 4;
     }
   
   /* ----- -16*atan(1/515) ------- */
   firstword = 2; denom = 3; remainder = 160;
   
   for( x=2; x<=words; x++)
     {
	
	digits = (long)remainder * 10000;
	term[x] = digits / 515;                     /* first term */
	remainder = digits % 515;                    
	sum[x] -= term[x];
     }
   
   
   while( firstword<words )
     {
	
	atan515(denom);
	denom+=4;
     }
   
   
   for(x=words; x>=1; x--) 
     {
	/*release carries & borrows*/
	if (sum[x]<0) 
	  {
	     
	     sum[x-1] += sum[x] / 10000;
	     sum[x] = sum[x] % 10000;
	     sum[x-1]--; sum[x] += 10000;
	  }
	
	if (sum[x] >= 10000) 
	  {
	     
	     sum[x-1] += sum[x] / 10000;
	     sum[x] = sum[x] % 10000;
	  }
	
     }
   
   
   //end = clock();                                    /* -----Finish up */
   
   std::cout << (clock()-start)/(double)CLOCKS_PER_SEC << std::endl;
   
   
   
   /*printout();
    printf("\nComputation time = %6.2f seconds\n",
    (float)(end-start)/(float)CLOCKS_PER_SEC );
    free(sum); free(term); exit(0);
    */
}

/*-----------------------------------------------------------------*/
void atan10(long denom) 
{
   
   int remainder1, remainder2;
   long dividend, denom2 = denom+2, x;
   
   sum[firstword] -= 3200 / denom;
   remainder1 = 3200 % denom;
   
   sum[firstword] += 32 / denom2;
   remainder2 = 32 % denom2;
   
   for( x=firstword+1; x<=words; x++) 
     {
	
	dividend = (long)remainder1 * 10000;
	sum[x] -= dividend / denom;
	remainder1 = dividend % denom;
	
	dividend = (long)remainder2 * 10000;
	sum[x] += dividend / denom2;
	remainder2 = dividend % denom2;
     }
   
}

/*---------------------------------------------------------------*/
void atan239(long denom) 
{
   
   int remainder1 = term[firstword++],  /*perform 1st divide implicitly*/
     remainder2 = 0, remainder3 = 0,
     remainder4 = 0;
   long dividend, denom2 = denom+2, temp, x;
   
   for( x=firstword; x<=words; x++) 
     {
	
	temp = term[x];
	
	dividend = (long)remainder1 * 10000 + temp;    /*add next term*/
	temp = dividend / 57121;
	remainder1 = dividend % 57121;
	
	dividend = (long)remainder2 * 10000 + temp;
	sum[x] += dividend / denom;
	remainder2 = dividend % denom;          
	
	dividend = (long)remainder3 * 10000 + temp;  /*subtract next term*/
	temp = dividend / 57121;
	remainder3 = dividend % 57121;
	
	dividend = (long)remainder4 * 10000 + temp;
	sum[x] -= dividend / denom2;
	remainder4 = dividend % denom2;
	term[x] = temp;
     }
   
   
   firstword++;
   if( term[firstword] == 0 ) firstword++;
}

/*---------------------------------------------------------------*/
void atan515(long denom) 
{
   
   long remainder1 = term[firstword++], /*perform 1st divide implicitly*/
     remainder2 = 0, remainder3 = 0, x,
     remainder4 = 0, dividend, denom2 = denom + 2, temp;
   
   for( x=firstword; x<=words; x++) 
     {
	
	temp = term[x];
	if( remainder1<214745 ) 
	  {
	     
	     dividend = remainder1*10000 + temp;      /*add next term*/
	     temp = dividend / 265225;
	     remainder1 = dividend % 265225;
	  }
	
	else 
	  {
	     
	     remainder1 -= 53045;
	     dividend = remainder1 * 10000 + temp;
	     temp = dividend / 265225;
	     remainder1 = dividend % 265225;
	     temp += 2000;
	  }
	
	
	dividend = remainder2 * 10000 + temp;
	sum[x] += dividend / denom;
	remainder2 = dividend % denom;          
	
	if( remainder3<214745 ) 
	  {
	     /*subtract next term*/
	     dividend = remainder3 * 10000 + temp; 
	     temp = dividend / 265225;
	     remainder3 = dividend % 265225;
	  }
	
	else 
	  {
	     
	     remainder3 -= 53045;
	     dividend = remainder3 * 10000 + temp;
	     temp = dividend / 265225;
	     remainder3 = dividend % 265225;
	     temp += 2000;
	  }
	
	
	dividend = remainder4 * 10000 + temp;
	sum[x] -= dividend / denom2;
	remainder4 = dividend % denom2;
	term[x] = temp;
     }
   
   
   firstword++;
   if( term[firstword] == 0 ) firstword++;
}

/*---------------------------------------------------------------*/
/*void printout(void)
{
   
   long int i;
   printf("pi=3.1\n");
   
   for(i=2; i<words; i+=3) 
     {
	
	printf(" %.4ld%.4ld%.4ld", sum[i], sum[i+1], sum[i+2]);
	if( (i+1)%15 == 0) printf("  : %ld\n", 4*(i+1));
     }
   
   for(i=3*(words/3)+2; i<words; i++) printf(" %.4ld", sum[i]);
}
*/
