#include <iostream>
using namespace std;
#include <fstream>

void menudeOpciones();
void escribirArchivo();
void leerArchivo();


int main(){
  
 menudeOpciones();
  
}

void menudeOpciones(){

int opc;

do{
 cout<<"\t\t\t******MENU**********"<<endl;
 cout<<"  \t\t1- INGRESAR DATOS"<<endl;
 cout<<"  \t\t2- MOSTRAR DATOS"<<endl;
 cout<<"Ingrese el numero de su opcion: "<<endl;
 cin>>opc;
  switch(opc){
  case  1:

   escribirArchivo();

  break;

  case 2:

    leerArchivo();
  break;
  }

} while (opc != 2);

}

void escribirArchivo()
{
  
   string nombre;
   string apellido;
   string carrera;
   int edad;
   char n;
    ofstream archivoprueba;
    string nombrearchivo;
    cout<<"EL NOMBRE DE SU LIBRETA ES >> libreta.txt << \n";
    cout<<"INGRESE NOMBRE DEL ARCHIVO \n";
    while(getchar()!='\n'); 
    getline(cin,nombrearchivo);
    archivoprueba.open(nombrearchivo.c_str(),ios::out );

  do{
    cout<<"---------------------------------------------\n";
   cout<<"INGRESE EL NOMBRE: ";
   getline(cin,nombre);

   cout<<"INGRESE EL APELLIDO: ";
   getline(cin,apellido);

   cout<<"INGRESE LA CARRERA: ";
   getline(cin,carrera);

   cout<<"INGRESE LA EDAD: ";
   cin>>edad;
   
   archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
   cout<<"---------------------------------------------\n";
   cout<<"DESEA INGRESAR OTRO CONTACTO S/N ";
   cin>>n;
   cin.ignore();

  }while(n=='s');
   
   archivoprueba.close();
}


void leerArchivo()
{
 string nombre;
 string apellido;
 string carrera;
 int edad;

 ifstream archivolectura("libreta.txt");
 string texto;
   cout<<"---------------------------------------------\n";
   cout<<"\t\t*** CONTACTOS REGISTRADOS *** \n";
 while(!archivolectura.eof())
 {
  archivolectura>>nombre>>apellido>>carrera>>edad;

  if (!archivolectura.eof()){

   
   cout<<"\t>> NOMBRE "<<nombre<<endl;
   cout<<"\t>> APELLIDO "<<apellido<<endl;
   cout<<"\t>> CARRERA "<<carrera<<endl;
   cout<<"\t>> EDAD "<<edad<<endl;
  cout<<"---------------------------------------------\n";
  }

 }

archivolectura.close();
}

