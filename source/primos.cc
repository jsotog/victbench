#include <iostream>
#include <cmath>
#include <list>

using namespace std;

void erasto(int);//deberia encontrar los primos desde 1 hasta el argumento

int main (int argc, char * const argv[]) {
   clock_t start; //Inicializo el reloj
   start=clock(); //Setear a tiempo cero
   erasto(25000);
   std::cout << (clock()-start)/(double)CLOCKS_PER_SEC << std::endl;
   return 0;
}

void erasto(int n)
{
	list<int> lista;
	int i;//para crear la lista
	for(i=2; i<= n; i++)
	{
		lista.push_back(i);
	}
	int p, q;//primos...
		for(p=2; p<n; p++)
		{
			q=p+1;
			while(q<=n)
			{
				if(q%p==0)
				{
					lista.remove(q);
				}
				q++;
			}
		}
//	list<int>::iterator theIterator;
//	for( theIterator = lista.begin(); theIterator != lista.end(); theIterator++ ) {
//		//cout << *theIterator << " ";
//	}            
}
