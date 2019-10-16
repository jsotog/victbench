#include <iostream>
#include <time.h>

using namespace std;

void doolittle(int, double**);

int main (int argc, char * const argv[]) {
   int width; 
   int height; 
   width = 950; 
   height = width; 
   double ** matriz = new double * [width]; 
   for (int i=0;i<width;i++){ 
      matriz[i] = new double[height]; 
   } 
   for (int i=0;i<width;i++){ 
      for (int j=0;j<height;j++){ 
	 matriz[i][j] = 1; 
      } 
   } 
   
   for (int i=0;i<width;i++){ 
      for (int j=0;j<height;j++){ 
	 matriz[i][j] = 1+(i*j)*(10/(i+j+2)); 
      } 
   }
   clock_t start;
   start=clock();
   doolittle(height, matriz);
   cout << (clock()-start)/(double)CLOCKS_PER_SEC << endl;
   
   for (int i=0;i<width;i++){ 
      delete [] matriz[i]; 
   } 
   delete [] matriz; 
   
   return 0;
}

void doolittle(int n, double **a)
{
   int i,j,k,s;
   for (k=0;k<n;k++)
     {
	for (j=k;j<n;j++)
	  for (s=1;s<k;s++) a[k][j] -= a[k][s]*a[s][j];
	for (i=k+1;i<n;i++)
	  {
	     for (s=1;s<k;s++){
		a[i][k] -= a[i][s]*a[s][k];
	     }
	     a[i][k] /= a[k][k];
	  }
     }
}
