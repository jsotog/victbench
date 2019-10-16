#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void quickSort(int[], int);
void q_sort(int[], int, int);


int main (int argc, char * const argv[]) {
	srand(979803);
    clock_t start;
	start=clock();
	for(int j=0;j<69;j++){
		int * lista1 = new int[1000000];
		
		for(int i=0;i<1000000;i++){
			lista1[i]=rand();
		}

		quickSort(lista1, 1000000);

		delete [] lista1;
	}
	cout << (clock()-start)/(double)CLOCKS_PER_SEC << endl;
    return 0;
}


void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}


void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}
