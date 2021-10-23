#include<iostream>
#include <cctype>
#include<string.h>
#include<string>
#include<fstream>
#include<conio.h>
#include<vector>
#include<iterator>


using namespace std;

ofstream Guardar; 
ifstream Leer; 


struct Palabra{
	char nombre[50];
	char traduccion[50];
	char funcionalidad[100];
};


const char *proyecto = "proyecto.data";
const char *temp = "temp.data";

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
		    void ingresar_palabra();
			 {
			
			Palabra palabra;
			Guardar.open("proyecto.data", ios::app); 
	
			if (Guardar.is_open()) {
			system("cls");
			cout << "==========INGRESO DE PALABRAS=======\n\n";
			cout << "Ingrese Nombre" << endl;
			cin >> palabra.nombre;
			cout << "Ingrese traducción" << endl;
			cin >> palabra.traduccion;   
			cout << "Ingrese funcionalidad" << endl;
			cin >> palabra.funcionalidad;
			Guardar << palabra.nombre << " " <<palabra.traduccion<<" "<<palabra.funcionalidad<<endl;
	
			cout << "........palabra agregada exitosamente.....\n";

			Guardar.close();
			system("pause");
			}
			else { 
			cout << "Error en el Archivo\n";
			}

			}

			break;
		case 2:
		void Mostrar_palabra();{
			Palabra palabra;
			
		    system("cls");
			Leer.open("proyecto.data", ios::in);
		
			
			if (Leer.is_open()) {
			while (!Leer.eof()) {
			Leer >> palabra.nombre >> palabra.traduccion>>palabra.funcionalidad;
			if (!Leer.eof()) {
				cout << "======================\n\n";
				cout << "Nombre:        " << palabra.nombre << endl;
				cout << "traduccion:    " << palabra.traduccion << endl;
				cout << "funcionalidad: " << palabra.funcionalidad << endl; 
				cout << endl;
				}
			}
			
			system("pause");
			Leer.close(); 
			}
			else {
			cout << "Error en el archivo\n";
			}
				}
		
			break;
			
		case 3:
			
				void actualizar();
			{
			system("cls");
            
			Palabra palabra;
			Palabra act;
			
			Leer.open("proyecto.data", ios::in);
	        Guardar.open("temp.data", ios::out);
	        
			if (Leer.fail())
	        {
		      cout<<"Error en el archivo"<<endl;
		      system("pause");
			  }
			else{
			char aux[30];
			
			 cout<<"Ingresar palabara a actualizar: ";
			 cin>>aux;
			 
			 Leer>>palabra.nombre;
			
			while(!Leer.eof()){
			
				Leer>>palabra.traduccion>>palabra.funcionalidad;
			
			if(strcmp(aux,palabra.nombre)==0){
				
				cout<<"Ingresar nuevo nombre:"<<endl;
				cin>>act.nombre;
				cout<<"Ingresar nueva traduccion:"<<endl;
				cin>>act.traduccion;
				cout<<"Ingresar nueva funcionalidad:"<<endl;
				cin>>act.funcionalidad;
				Guardar<<act.nombre<<" "<<act.traduccion<<" "<<act.funcionalidad<<endl; 
				
			
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
		      
		  
		}
	    
				
			break;
			
		case 4:
			void borrarPalabra(); {
				
			system("cls"); 
            Palabra palabra;
			Leer.open("proyecto.data", ios::in);
	        Guardar.open("temp.data", ios::out);
	        if (Leer.fail())
	        {
		      cout<<"Error en el archivo"<<endl;
		      system("pause");
			  }
			else{
			char aux[30];
			
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
