#include <iostream>
#include <fstream>
using namespace std;

int mitad (int arr[], int pinicial, int pfinal);

void ordenar(int arr[], int pinicial, int pfinal);



int main()
{
  ofstream registro;
  registro.open("Quicksort.txt",ios::app);
    int A[10]={88, -6, 69, -33, 98, 7, 23, -5, 0, 100};
    registro<<"Quicksort"<<endl;
    for (int i=0; i<10;i++)
    {

      registro<<"|"<<A[i]<<"|";
        cout<<"|"<<A[i]<<"|";
    }
    registro<<endl;
    ordenar(A,0,9);
    for (int i=0; i<10;i++)
    {
      registro<<"|"<<A[i]<<"|";
        cout<<"|"<<A[i]<<"|";
    }

    return 0;
}



