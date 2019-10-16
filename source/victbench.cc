#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <time.h>  
using namespace std;


int main()
{
   cout   << endl; 
   cout   << "  ############################################################" << endl; 
   cout   << "  #                                                          #"<< endl; 
   cout   << "  #        VictBench, The Benchmark for the rest of us       #" << endl; 
   cout   << "  #                                                          #"<< endl; 
   cout   << "  ############################################################" << endl;
   cout  << endl; 
   cout   << endl; 
   
//   system("./pruebas/euler > /tmp/eu.txt"); 
//   ifstream euler("/tmp/eu.txt");
//   double eu;
//   euler >> eu;
//   double pteu = 2051/eu;
//   cout << "Su puntaje en Euler es " << pteu << endl; 
//   system("rm /tmp/eu.txt"); 
   
   system("./pruebas/primos > /tmp/pri.txt"); 
   ifstream primos("/tmp/pri.txt");
   double pri;
   primos >> pri;
   double ptpri = 927/pri;
   cout << "Su puntaje en Primos es " << ptpri << endl; 
   primos.close();
   system("rm /tmp/pri.txt"); 
   
   system("./pruebas/pi > /tmp/pi.txt"); 
   ifstream Pi("/tmp/pi.txt");
   double pi;
   Pi >> pi;
   double ptpi = 2013/pi;
   cout << "Su puntaje en Pi es " << ptpi << endl; 
   Pi.close();
   system("rm /tmp/pi.txt"); 
   
   system("./pruebas/quicksort > /tmp/quick.txt"); 
   ifstream quicksort("/tmp/quick.txt");
   double quick;
   quicksort >> quick;
   double ptquick = 1505/quick;
   cout << "Su puntaje en Quicksort es " << ptquick << endl; 
   quicksort.close();
   system("rm /tmp/quick.txt"); 
   
   system("./pruebas/disco > /tmp/disk.txt");
   ifstream disco("/tmp/disk.txt");
   double disk;
   disco >> disk;
   double ptdisk = 659/disk;
   cout << "Su puntaje en Disco es " << ptdisk<< endl; 
   disco.close();
   system("rm /tmp/disk.txt");

   system("./pruebas/factor > /tmp/fac.txt");
   ifstream factor("/tmp/fac.txt");
   double fac;
   factor >> fac;
   double ptfac = 858/fac;
   cout << "Su puntaje en Factor es " << ptfac << endl;
   factor.close();
   system("rm /tmp/fac.txt");
   
   system("./pruebas/ludesc > /tmp/lu.txt");
   ifstream ludesc("/tmp/lu.txt");
   double lu;
   ludesc >> lu;
   double ptlu = 299/lu;
   cout << "Su puntaje en Ludesc es " << ptlu << endl;
   ludesc.close();
   system("rm /tmp/lu.txt");


   double promedio = (ptpri+ptpi+ptquick+ptdisk+ptfac+ptlu)/6;
   
   cout   << endl; 
   cout   << endl; 
   cout   << "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<< endl; 
   cout   << "         |                                            |" << endl; 
   cout   << "         |    Su puntaje final es de "<< promedio << " puntos   |" << endl; 
   cout   << "         |                                            |" << endl; 
   cout   << "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
   cout   << endl; 
   cout   << endl; 
   
   return 0;
}

