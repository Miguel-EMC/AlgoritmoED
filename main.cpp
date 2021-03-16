#include <iostream>
#include <fstream>
#include "Heapsort.h"
using namespace std;
void heapsort(float b[],int n);



int main() {
  ofstream registro;
  registro.open("Heapsort”.txt",ios::app);
  registro<<"SIN ORDENAR"<<endl;
  float numerosuno[50];
 int numeros;
  cout<<"Ingrese el numero de elementos"<<endl;
  cin>>numeros;
  for(int i=1;i<=numeros;i++){
    cout<<"Numeros"<<endl;
    cin>>numerosuno[i];
  }
  for(int i=1;i<=numeros;i++){
    cout<<"|"<<numerosuno[i];
    registro<<"|"<<numerosuno[i]<<"|";
  }
  heapsort(numerosuno, numeros);
  registro<<endl;
  cout<<endl;
  registro<<"HEAPSORT"<<endl;
  cout<<"Ordenamiento"<<endl;
  
  for(int i=1;i<=numeros;i++){
    cout<<"|"<<numerosuno[i];
    registro<<"|"<<numerosuno[i]<<"|";
  }

}
