#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>
using namespace std;

void llenar();

int main () {
   clock_t start;
   start=clock();
   system("mkdir /tmp/disco");
   llenar();
   system("rm -r /tmp/disco");
   cout  << (clock()-start)/(double)CLOCKS_PER_SEC<< endl;    
   return 0;
}

void llenar(){
   
   for(int j=0;j<=25450;j++)
     {
	
	const char base[] = "/tmp/disco/temp";
	char filename [ FILENAME_MAX ];
	sprintf(filename, "%s%d", base, j);
	//cout << filename << " creado" <<endl;
	ofstream salida(filename);
	salida << j << endl;
	
     }
   //system("rm archivo*");
}


