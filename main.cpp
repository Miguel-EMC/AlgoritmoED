#include <iostream>
#include <fstream>

using namespace std;
void heapsort(float b[],int n);

int main() 
{
  ofstream registro;
  registro.open("Heapsort.txt",ios::app);
  registro<<"SIN ORDENAR"<<endl;

  float numerosuno[50];
  int numeros;
  cout<<"Ingrese el numero de elementos"<<endl;
  cin>>numeros;

  for(int i=1;i<=numeros;i++)
  {
    cout<<"Numero ["<<i<<"]"<<endl;
    cin>>numerosuno[i];
  }
  cout<<"arreglo de elementos originales"<<endl;
  registro<<"arreglo de elementos originales"<<endl;

  for(int i=1;i<=numeros;i++)
  {
    cout<<"|"<<numerosuno[i];
    registro<<"|"<<numerosuno[i]<<"|";
  }
  heapsort(numerosuno, numeros);
  registro<<endl;
  cout<<endl;

  registro<<"HEAPSORT"<<endl;
  cout<<"Ordenamiento"<<endl;
  cout<<"arreglo Heapsort"<<endl;

  for(int i=1;i<=numeros;i++)
  {
    cout<<"|"<<numerosuno[i];
    registro<<"|"<<numerosuno[i]<<"|";
  }

}

void heapsort(float b[],int n)
{
  int a;
  float temp,valor;
  for(int i=n;i>0;i--)
  {
    for(int j=1;j<=i;j++)
    {
      valor=b[j];
      a=j/2;
      while(a>0&&b[a]<valor)
    {
      b[j]=b[a];
      j=a;
      a=a/2;
    }

    b[j]=valor;

    }

    temp=b[1];
    b[1]=b[i];
    b[i]=temp;
  }
}