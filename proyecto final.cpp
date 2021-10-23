#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<conio.h>
#include<vector>
#include<iterator>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::copy;
using namespace std;
ofstream Guardar; 
ifstream Leer; 
struct Palabra{
	char nombre[50];
	char traduccion[50];
	char funcionalidad[100];
};
void ingresar_palabra();
 void Mostrar_palabra();
 void menu_();
 void eliminar();
 void traduccion();
const char *proyecto = "proyecto.data";
const char *temp = "temp.data";

ofstream Tem;
int main(){
	int opcion;
	do{
		system("cls");
		cout<<"Bienvenido"<<endl;
		cout<<"1. Ingresar un palabra nueva"<<endl;
		cout<<"2. Ver las palabras ingresadas"<<endl;
		cout<<"3. Modificar alguna Palbra"<<endl;
		cout<<"4. Borrar palabra"<<endl;
		cout<<"5. Realizar la traduccion de algun codigo en C++"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
		case 1:
		     void ingresar_palabra();{
				system("cls");
				char continuar;
				FILE* archivo = fopen(proyecto,"ab");
				Palabra palabra[100];
				Palabra palabra2;
				int i=0;
				string nombre,traduccion,funcionalidad;
				do{
				fflush(stdin);
				cout<<"Ingrese el Nombre de la Palabra:";
				fgets(palabra[i].nombre,10000,stdin);
				cout<<"Ingrese su traduccion:";
				getline(cin,traduccion);
				strcpy(palabra[i].traduccion,traduccion.c_str());
				cout<<"Ingrese su Funcionalidad:";
				int i=0;
				fgets(palabra[i].funcionalidad,10000,stdin);
				fwrite(&palabra,sizeof(Palabra),1,archivo);
				cout<<"Dese Agregar otro Estudiante (s/n):";
				cin>>continuar;
				} while ( (continuar=='s') || (continuar=='S') );
				fclose(archivo);
				}
			break;
		case 2:
		void Mostrar_palabra();{
		    system("cls");
			FILE* archivo = fopen(proyecto,"rb");	
			if (!archivo){
			archivo = fopen(proyecto,"w+b");	
			}
			Palabra palabra;
			fread(&palabra,sizeof(Palabra),1,archivo);
			do{
			cout<<"____________________________________________"<<endl;
			cout<<"Palabra: "<<palabra.nombre;
			cout<<"Tradduccion: "<<palabra.traduccion<<endl;
			cout<<"Funcionalidad: "<<palabra.funcionalidad<<endl;	
			fread(&palabra,sizeof(Palabra),1,archivo);	
			}while(feof(archivo)==0);
			fclose(archivo);
			cout<<endl;
			system("PAUSE");
			}
			break;
		case 3:
			void actualizar();
			{
			FILE* archivo = fopen(proyecto,"r+b");
			Palabra palabra[100];
			string nombre,traduccion,funcionalidad;
			string palabra1;
			int i=0;
			cout<<"Ingrese el nombre de la palabra que desea modificar"<<endl;
			cin>>palabra1;
			fflush(stdin);
				cout<<"Ingrese el Nombre de la Palabra:";
				fgets(palabra[i].nombre,10000,stdin);
				cout<<"Ingrese su traduccion:";
				getline(cin,traduccion);
				strcpy(palabra[i].traduccion,traduccion.c_str());
				cout<<"Ingrese su Funcionalidad:";
				fgets(palabra[i].funcionalidad,10000,stdin);
				fwrite(&palabra,sizeof(Palabra),1,archivo);
				fclose(archivo);
		}

			break;
		case 4:
			void eliminar();
			{
			FILE* archivo = fopen(proyecto,"r+b");
			char aux[30];
			Palabra palabra;
			cout<<"Ingresar palabara a eliminar: ";
			cin>>aux;
			Leer>>palabra.nombre;
			
			while(!Leer.eof()){
			
				Leer>>palabra.traduccion>>palabra.funcionalidad;
			
			if(strcmp(aux,palabra.nombre)==0){
				
				cout<<"Registro eliminado";
				 getch();
			
			}
			else{
				Guardar<<palabra.nombre<<" "<<palabra.traduccion<<" "<<palabra.funcionalidad<<endl;
			} 
			
			Leer>>palabra.nombre;
			
			}
			Leer.close();
		    Guardar.close();
		    
			remove("proyecto.data");
			rename("temp.data","proyecto.data" );
			}  
			break;
		case 5:
		
			break;
		case 6:
			return 0;
			break;
	}
	cout<<"Precione cualquier tecla para regresar al menu principal"<<endl;
}while(opcion);

}



