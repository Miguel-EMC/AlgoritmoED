#include <iostream>

using namespace std;
#define tam 50

void ingresar (int a[],int n);

void ordenar (int a[], int n);

void imprimir (int a[], int n);



int main()
{
    int arreglo1[tam];

    int n;
    cout<<"INGRESR EL TAMAÑO DEL ARREGLO: ";
    cin>>n;


    ingresar(arreglo1, n);
    cout<<endl;
    imprimir(arreglo1, n);
    cout<<endl;
    ordenar(arreglo1, n);
    cout<<endl;
    imprimir(arreglo1,n);

    return 0;
}


void ingresar (int a[],int n)
{
    int i;

    for (int i=0 ; i<n ; i++)
    {
        cout<<"INGRESA LOS ELEMENTOS AL ARREGLO: "<< i+1<<endl;
        cin>>a[i];

    }

}
void ordenar (int a[], int n)
{


    int aux;
    for (int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if (a[j]<a[i])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}

void imprimir (int a[], int n)
{

    for (int i=0 ; i<n ; i++)
    {
        cout<<"|"<<a[i]<<"|";
    }

}




