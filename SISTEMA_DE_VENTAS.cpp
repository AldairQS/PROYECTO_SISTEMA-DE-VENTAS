#include <iostream>  
#include <conio.h>      
#include <string.h>    
#include <fstream>     
#include <stdlib.h>
using namespace std;

int i,cantprod,cantproductos,acuptotal,acuptotalmostrar;
int j=0,k=0,l=0,m=0,x=0;
int posventa,cventa[10000][10000],cant[10000][10000];
float pventa[10000][10000],ptotal[10000],ganancia=0;
int contador[10000];
//escribir en el fichero
int cod[10000];
float precio[10000],precio1[10000];
string nombre[10000],marca[10000],tipo[10000],tamanio[10000],texto[10000],linea;
//leer del fichero
int cod1[10000];
string nombre1[10000],marca1[10000],tipo1[10000],tamanio1[10000];
//nombres para el registro de ventas
string nomreg[10000][1000],marreg[10000][1000],tamreg[10000][1000];

void anadir();
void leerVariables();
void agregarVenta();
int verificar(int a);
void registroVentas();
	
int main () {
	char opc='0';
	do {system("color 1f");cout<<endl;//color menu azul (fondo) letras (blanco brillante)
		cout<<"            # # # # # # # # # # # # # # # # # # # # # # #"<<endl;
		cout<<"            #                                           #"<<endl;
		cout<<"            #     S I S T E M A   D E   V E N T A S     #"<<endl;
		cout<<"            #                                           #"<<endl;
		cout<<"            # # # # # # # # # # # # # # # # # # # # # # #"<<endl;
		cout<<"            #                                           #"<<endl;	
		cout<<"            #          [1] AÑADIR PRODUCTOS             #"<<endl;
		cout<<"            #                                           #"<<endl;	
		cout<<"            #          [2] AGREGAR VENTA                #"<<endl;
		cout<<"            #                                           #"<<endl;	
		cout<<"            #          [3] VER REGISTRO                 #"<<endl;
		cout<<"            #                                           #"<<endl;	
		cout<<"            #          [4] CERRAR PROGRAMA              #"<<endl;
		cout<<"            #                                           #"<<endl;	
		cout<<"            # # # # # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
		cout<<" --> Seleccione una opción 1 al 4"<<endl<<endl;
		cout<<" Opción: ";
		cin>>opc;cout<<endl;system("cls");
		switch (opc){
		default : system("color 8f");cout<<endl<<" ¡Opción Inválida, ingrese un número correcto!"<<endl<<endl<<" OPCIONES : [1] [2] [3] [4]"<<endl<<endl;cout<<" ";system("pause");system("cls");break;
		case '1': system("color e0");anadir();cout<<endl;cout<<" ";system("pause");system("cls");break;
		case '2': system("color 4f");agregarVenta();cout<<endl<<" ";system("pause");system("cls");break;
		case '3': system("color b0");registroVentas();cout<<endl<<" ";system("pause");system("cls");break;		
		case '4': system("color 5f");cout<<endl<<" -- FIN DEL PROGRAMA -- . . . ¡hasta luego!";break;
		}
	} while (opc!='4');	
	cout<<" ";getch();return 0;
}
	
void anadir(){
	ofstream lista,variables;
	lista.open("Catalogo Visual.txt",ios::out);//abriendo archivo
	if (lista.fail()){
		cout<<" ¡No se pudo abrir el archivo!";
		exit (1);
	}
	cout<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl;
	cout<<"      #                                   #"<<endl;
	cout<<"      #   A Ñ A D I R   P R O D U C T O   # "<<endl;
	cout<<"      #                                   #"<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
	cout<<" ¿Cuántos Productos va añadir? ---> ";cin>>cantprod;cout<<endl;
	for (i=0;i<cantprod;i++){
		cout<<"   ********** "<<i+1<<"° PRODUCTO **********"<<endl<<endl;
		cout<<"       > Código : ";cin>>cod[i];cin.ignore();
		cout<<"       > Nombre : ";getline(cin,nombre[i]);
		cout<<"       > Marca  : ";getline(cin,marca[i]);
		cout<<"       > Tipo   : ";getline(cin,tipo[i]);
		cout<<"       > Tamaño : ";getline(cin,tamanio[i]);
		cout<<"       > Precio : ";cin>>precio[i];cin.ignore();cout<<endl;
		cout<<"   *********************************"<<endl<<endl<<endl;
	lista<<"        ********** "<<i+1<<"° PRODUCTO **********"<<endl<<endl;
	lista<<"              > Código : "<<cod[i]<<endl;
	lista<<"              > Nombre : "<<nombre[i]<<endl;
	lista<<"              > Marca  : "<<marca[i]<<endl;
	lista<<"              > Tipo   : "<<tipo[i]<<endl;
	lista<<"              > Tamaño : "<<tamanio[i]<<endl;
	lista<<"              > Precio : S/. "<<precio[i]<<endl<<endl;
	lista<<"       *********************************"<<endl<<endl;
	}
	lista.close();
	variables.open("Variables.txt",ios::out);
	if (variables.fail()){
			cout<<" ¡No se pudo abrir el archivo!";
			exit (1);
	}
	variables<<cantprod<<endl;
	for (i=0;i<cantprod;i++){
		variables<<cod[i]<<"\n"<<nombre[i]<<"\n"<<marca[i]<<"\n"<<tipo[i]<<"\n"<<tamanio[i]<<"\n"<<precio[i]<<"\n";
	}
	variables.close();
}
	
void mostrarCatalogo(){
	ifstream lista1;
	lista1.open("Catalogo Visual.txt",ios::in);
	if (lista1.fail()){
		cout<<" ¡No se pudo abrir el archivo!";
		exit (1);
	}
	cout<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl;
	cout<<"      #                                   #"<<endl;
	cout<<"      #     P  R  O  D  U  C  T  O  S     # "<<endl;
	cout<<"      #                                   #"<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
	if (x==0){
		while (getline(lista1,linea)){
			texto[x]=texto[x]+linea+"\n";
		}
	}
	lista1.close();
	cout<<texto[0]<<endl;
	x++;
}
	
void leerVariables(){
	ifstream lectura;
	lectura.open("Variables.txt",ios::in);
	if (lectura.fail()){
		cout<<" ¡No se pudo abrir el archivo!";
		exit (1);
	}
	lectura>>cantproductos;lectura.ignore();
	for(i=0;i<cantproductos;i++){
		lectura>>cod1[i];lectura.ignore();
		getline(lectura,nombre1[i]);
		getline(lectura,marca1[i]);			
		getline(lectura,tipo1[i]);			
		getline(lectura,tamanio1[i]);			
		lectura>>precio1[i];lectura.ignore();
	}
	lectura.close();
}
	
void agregarVenta(){
	string seguir;
		float acuptotal=0;
		mostrarCatalogo();
		leerVariables();
		cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl;
		cout<<"      #                                   #"<<endl;
		cout<<"      #       C A R R I T O   N ° "<<m+1<<"       # "<<endl;
		cout<<"      #                                   #"<<endl;
		cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
		do {
			cout<<"      --> Código de Producto: ";cin>>cventa[l][j];
			while (verificar(cventa[l][j])!=1){
				cout<<"      ¡ERROR! No se encuentra el código del producto"<<endl<<endl;
				cout<<"      --> Código de Producto: ";cin>>cventa[l][j];
			}
			cout<<"      --> Cantidad a llevar: ";cin>>cant[l][j];cout<<endl;
			pventa[l][j]=cant[l][j]*precio1[posventa];
			cout<<"      - "<<nombre1[posventa]<<" "<<marca1[posventa]<<" "<<tamanio1[posventa]<<" x "<<cant[l][j]<<" uni. --- S/. "<<pventa[l][j]<<endl<<endl;
/*Mostrar*/	nomreg[l][j]=nombre1[posventa];marreg[l][j]=marca1[posventa];tamreg[l][j]=tamanio1[posventa];
			acuptotal+=pventa[l][j];
			cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
			j++;k++;
			cin.ignore();
			cout<<"       ¿Agregar otro producto (Si/No)?: ";getline(cin,seguir);cout<<endl;
		} while (seguir=="si" || seguir=="SI" || seguir=="Si");
		ptotal[l]=acuptotal;
		contador[l]=k;
		cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
		cout<<"        $$$ Total a pagar $$$ ---> S/. "<<ptotal[l]<<endl<<endl;
		cout<<"      # # # # # # # # # # # # # # # # # # #"<<endl;
		l++;m++;
}
	
void registroVentas(){
	int a=0,b=0;
	cout<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # # # # #"<<endl;
	cout<<"      #                                         #"<<endl;
	cout<<"      #   R E G I S T R O   D E   V E N T A S   # "<<endl;
	cout<<"      #                                         #"<<endl;
	cout<<"      # # # # # # # # # # # # # # # # # # # # # #"<<endl<<endl;
	do {
		cout<<"  *************** V E N T A   N ° "<<a+1<<" ***************"<<endl<<endl;
		do {
			cout<<"   --> "<<nomreg[a][b]<<" "<<marreg[a][b]<<" "<<tamreg[a][b]<<" x "<<cant[a][b]<<" "<<" --- S/. "<<pventa[a][b]<<endl<<endl;
			b++;
		} while (b<contador[a]);
		cout<<"  *************************************************"<<endl<<endl;
		cout<<"    GANANCIA VENTA N° "<<a+1<<" ---> S/. "<<ptotal[a]<<endl<<endl;
		cout<<"  *************************************************"<<endl<<endl<<endl;
		ganancia+=ptotal[a];
		a++;
	} while (a<m);
	cout<<" > > > V E N T A S   R E A L I Z A D A S (durante la ejecución del programa) : "<<m<<endl<<endl;
	cout<<" > > > ¡ G A N A N C I A   O B T E N I D A ! : S/. "<<ganancia<<endl;
}
	
int verificar(int a){
	int band=0;
	for (i=0;i<cantproductos;i++){
		if (a==cod1[i]){
			posventa=i;
			band=1;
		}
	}
	return band;
}
