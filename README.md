#include <iostream>
#include <fstream>
using namespace std;

void algoritmoInserccion(int a[], int n);

void algoritmoInterpolacion (int a[], int n);

void impirmirElementos(int a[], int n);
void ingresar (int a[], int n);

int main()
{
    fstream archivo;
    archivo.open("insercion.txt", ios::app);
    int n, cont;
    int A[100];
    cout << "Ingrese el tamanio del arreglo: ";
    cin >>n;
    archivo << "El tamanio del arreglo: " <<n;
    for (int i=0;  i<n; i++)
    {
      cout << "Ingrese el elemento: ";
      cin >> A[i];
      cont= cont + A[i];
    }
    archivo << "\nLa suma del arreglo es: " <<cont;
    impirmirElementos (A,n);
    cout<<"\n";
    algoritmoInserccion(A,n);
    cout<<"\n";
    impirmirElementos (A,n);
    cout<<"\n";
    algoritmoInterpolacion(A,n);


}


void impirmirElementos(int a[], int n)
{
    fstream archivo;
    archivo.open("insercion.txt", ios::app);
    for(int i=0; i<n; i++)
    {
        archivo<<"|"<<a[i]<<"|";
        cout<<"|"<<a[i]<<"|";
    }
    archivo<<endl;
    archivo.close();
}


void algoritmoInserccion(int a[], int n)
{
    int pos,aux;
    for(int i=0; i<n; i++)
    {
        pos=i;

        aux=a[i];

        while((pos>0)&&(a[pos-1]>aux))
        {
            a[pos] = a[pos-1];

            pos--;

        }

        a[pos]=aux;
    }


}


void algoritmoInterpolacion (int a[], int n)
{
    fstream archivo;
    archivo.open("interpolacion.txt", ios::app);
    int primero = 0;

    int ultimo = n-1;

    int medio;

    int cont=0;

    int num;
    cout <<"Ingrese numero a buscar: ";
    cin >> num;
    archivo << "Numero a buscar : " <<num;
    while(a[primero] != num && cont<=7 )
    {
        medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        {
            primero = medio +1;
        }
        else if(a[medio]>num)
        {
            ultimo = medio-1;
        }
        else
        {
            primero = medio;
        }
        cont++;
    }
    if(a[primero]==num)
    {
        archivo<<"\nELEMENTO ENCONTRADO EN LA POSICION -> " << primero;
        cout<<"ELEMENTO ENCONTRADO EN LA POSICION -> "<< primero;;
    }
    else
    {
        archivo<<"\nELEMENTO NO ENCONTRADO";
        cout<<"ELEMENTO NO ENCONTRADO";
    }
    archivo.close();
}