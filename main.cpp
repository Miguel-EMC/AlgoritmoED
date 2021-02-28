#include <iostream>
#include<fstream>
using namespace std;
void algoritmo(int arre[100],int t);
//funciones 1
void datos();
void imprimir();
void ejercicio2();
int vector2[6],x,i=0, j;
//funciones 2
int menu();
void escribirArchivo();
void ingresarDinero(int arrg[], int t);
int consultarDinero(int arr[], int t, int dato);
int main()
{
    int option,contenido,i=0;
    int valores[100];
    do
    {
        cout<<"-----------------------------------";
        cout<<"\nMenu"<<endl;
        cout<<"1.Intercambiar posiciones de un vector"<<endl;
        cout<<"2.Ordenamiento de un vector"<<endl;
        cout<<"3.Cuenta de ahorro"<<endl;
        cout<<"4.Salir"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            datos();
            imprimir();
            break;
        case 2:
            ejercicio2();
            break;
        case 3:
            menu();
            break;
        case 4:
            cout<<"Gracias poliamigo"<<endl;
            break;
        }
    }
    while(option!=4);
}
void algoritmo(int arre[100],int t)
{
    int i=0,j=0,min,aux;
    for(i=0; i<t; i++)
    {
        min=i;
        for(j=i+1; j<t; i++)
        {
            if(arre[i]<arre[min])
            {
                min=j;
            }
        }
        aux=arre[i];
        arre[i]=arre[min];
        arre[min]=aux;
    }
    for(i=5; i>=0; i--)
    {
        cout<<arre[i];
    }
} //funciones ejercicio 1
void datos()
{
    do
    {
        cout<<"Ingrese los elementos del vector \n";
        cin>>x;
        i++;
        if (x!=0)
        {
            vector2[6-i]=x;
        }
    }
    while (i<6);
}
void imprimir()
{
    ofstream archivo;
    archivo.open("Intercambiar.txt", ios::app);
    if (i>0)
    {
        cout<<"Valores inversos: \n";
        for (j=6-i; j<6; j++)
        {
            cout<<"/"<<vector2[j]<<"/";
            archivo <<"/"<<vector2[j]<<"/";
        }
        archivo.close();
    }

} //funciones ejercicio 2
void ejercicio2()
{
    int num,positivo,negativo,cero,cant,i;
    positivo=0;
    negativo=0;
    cero=0;
    int a[100];
    cout<<"Introduzca la cantidad de numeros a evaluar:";
    cin>>cant;
    for(i=0; i<cant; i++)
    {
        cout<<"Introduzca un Numero:";
        cin>>a[i];
        if (a[i]>0)
        {
            positivo+=+1;
        }
        else if(a[i]<0)
        {
            negativo+=+1;
        }
        else cero+=+1;
    }
    int aux, j;
    for ( i=0; i<cant; i++)
    {
        for (int j =i+1; j<cant; j++)
        {
            if (a[j] < a [i])
            {
                aux = a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
    ofstream archivo1;
    archivo1.open("Ordemamiento.txt", ios::app);
    cout << "\nArreglo ordenado: \n";
    archivo1 << "\nArreglo ordenado: \n";
    for (int i=0; i<cant; i++)
    {
        cout << " "<<a[i]<< " ";
        archivo1<< " "<<a[i]<< " ";
    }
    cout<<"\nLa cantidad de numeros positivos son:"<<positivo<<endl;
    archivo1<<"\nLa cantidad de numeros positivos son:"<<positivo<<endl;
    cout<<"\nLa cantidad de numeros negativos son:"<<negativo<<endl;
    archivo1<<"\nLa cantidad de numeros negativos son:"<<negativo<<endl;
    cout<<"\nLa cantidad de Ceros Son:"<<cero<<endl;
    archivo1<<"\nLa cantidad de Ceros Son:"<<cero<<endl;
    archivo1.close();
    ifstream doc;
    string docu;
    doc.open("Ordemamiento",ios::in);
    if(doc.fail())
    {
        cout<<"warning";
    }
    else
    {
        while(!doc.eof())
        {
            getline(doc,docu);
            cout<<docu<<endl;
        }
    }
}
//funciones ejercicio 3
int menu()
{
    ofstream cuentas;
    cuentas.open("cuentas.txt",ios::out);
    int opc;
    do
    {
        cout<<"__BANCO DE PICHINCHA__"<<endl;
        cout<<"1- DEPOSITO DE DINERO"<<endl;
        cout<<"2- CONSULTA DE DINERO"<<endl;
        cout<<"3- SALIR"<<endl;
        cout<<"Ingrese una opcion ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            int a[100];
            int n,b,i;
            cout <<"Ingrese los numeros de meses del año que va a depositar: ";
            cin >>n;
            ingresarDinero(a,n);
            break;
        case 2:
            char comp ='F';
            cout << "Ingrese la cantidad de su deposito : ";
            cin >> b;
            consultarDinero(a, n, b);
            while((comp=='F')&&(i<=n))
            {
                if(a[i]==b)
                {
                    comp='V';
                }
                i++;
            }
            if(comp =='F')
            {
                cout<<"inexistencia de esa cantidad de dinero"<<endl;
                cuentas<<"inexistencia de esa cantidad de dinero"<<endl;
            }
            else if(comp =='V')
            {
                cout<<"SU DEPOSITO FUE ECHO EN EL MES DE: "<<i-1<<endl;
                cuentas<<"SU DEPOSITO FUE ECHO EN EL MES DE: "<<i-1<<endl;
            }
            break;
        }
    }
    while(opc!=3);
    return opc;
    ifstream archivaso1;
    string test;
    archivaso1.open("cuentas.txt",ios::in);
    if(archivaso1.fail())
    {
        cout<<"Warning"<<endl;
    }
    else
    {
        while(!archivaso1.eof())
        {
            getline(archivaso1,test);
            cout<<test<<endl;
        }
    }
}
void ingresarDinero(int arrg[], int t)

{
    for (int i=1; i<=t; i++)
    {
        cout << "Ingrese el valor de deposito del mes "<<i<< ": " ;
        cin >> arrg[i];
    }
    cout<<"* SU DEPOSITO INGRESADO FUE UN EXITO *"<<endl;
}
int consultarDinero(int arr[], int t, int dato)
{


    int i;
    for( i=1 ; i<t ; i++)
    {
        if(arr[i]==dato)
        {
            return i;
        }
    }
    return -1;
    return 0;
}