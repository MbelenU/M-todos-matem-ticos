#include <iostream>
#include "conio.h"
#include "stdlib.h"
#include <iomanip> // setprecision
#include <cmath>
#define PRECISION 6  //Defino la precisión en 6 para que el sistema pare

using namespace std;

void Gauss();  
int Biseccion();   
double f(double x);     //f(x)
void imprimePuntos(double a, double b);

int main(){

int opcion;
//creo un menu para seleccionar que deseo hacer
do{
    cout << "\n\n-----Bienvenido al menu de calculos matematicos-----\n\n";
    cout << "1.Sistema de ecuaciones lineales.\n\n2.Calculo de raíces en ecuacion NO lineal\n\n3.Salir del programa";
    cout << "\n\nINGRESE UNA OPCION:\n";
    cin>>opcion;

    switch(opcion){
    case 1:
    
        Gauss();
        
        break;

    case 2:
        
        Biseccion();
        
        break;

    case 3:
        cout << "Saliendo...";
        
        break;
        
    default:
        cout << "Por favor ingrese una opcion valida del menu";
        
    }

} while (opcion!=3);

return 0;
}

//----------------------------------------------------------------------------------------------
//Funcion Gauss-Jordan
void Gauss(){
int opcion,repetir=1;   //inicializo variables
 float matriz2x3[2][3],matriz3x4[3][4],x,y,z;    //creo matrices de 2x3 y 3x4 
 do
 {
 cout<<"METODO DE GAUSS-JORDAN"<<endl;
 cout<<"Para resolver un sistema de 2 incognitas Presiona 1"<<endl;
 cout<<"Para resolver un sistema de 3 incognitas Presiona 2"<<endl;
 cout<<"Opcion: ";
 cin>>opcion;
 while(opcion<1||opcion>2)   //Si la opcion no es ni 1 ni 2
 {
  cout<<endl<<"Seleccione una opcion valida"<<endl;
  cout<<"Opcion: ";
  cin>>opcion;
 }
 system("cls");   //limpio consola
 switch(opcion)
 {
  case 1:
   cout<<"Primera Ecuacion"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";
   cin>>matriz2x3[0][0];    //Tomo valor para la posicion 0 0
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";
   cin>>matriz2x3[0][1];      //Tomo valor para la posicion 0 1
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";
   cin>>matriz2x3[0][2];      //Tomo valor para la posicion 0 2
   cout<<endl;
   cout<<"Segunda Ecuacion"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";    //Tomo valor para la posicion 1 0 
   cin>>matriz2x3[1][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";     //Tomo valor para la posicion 1 1 
   cin>>matriz2x3[1][1];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";       //Tomo valor para la posicion 1 2 
   cin>>matriz2x3[1][2];
   cout<<endl;
   //Resuelvo
  
  
   matriz2x3[0][1]=matriz2x3[0][1]/matriz2x3[0][0];
   matriz2x3[0][2]=matriz2x3[0][2]/matriz2x3[0][0];
   matriz2x3[0][0]=matriz2x3[0][0]/matriz2x3[0][0];// Se hace 1 
   //----------------------------------------------
   matriz2x3[1][1]=((-matriz2x3[1][0])*matriz2x3[0][1])+matriz2x3[1][1];
   matriz2x3[1][2]=((-matriz2x3[1][0])*matriz2x3[0][2])+matriz2x3[1][2];
   matriz2x3[1][0]=((-matriz2x3[1][0])*matriz2x3[0][0])+matriz2x3[1][0];// Se hace 0
   //-------------------------------------------------------------------
   matriz2x3[1][2]=matriz2x3[1][2]/matriz2x3[1][1];//Solucion variable y
   matriz2x3[1][1]=matriz2x3[1][1]/matriz2x3[1][1];
   //----------------------------------------------
   matriz2x3[0][2]=((-matriz2x3[0][1])*matriz2x3[1][2])+matriz2x3[0][2];//Solucion variable x
   matriz2x3[0][1]=((-matriz2x3[0][1])*matriz2x3[1][1])+matriz2x3[0][1];
   //-------------------------------------------------------------------
   x=matriz2x3[0][2];     //Traigo valor de posicion 0 2 
   y=matriz2x3[1][2];     //Traigo valor de posicion 1 2 
   cout<<"Solucion: "<<endl;
   cout<<"\tx="<<x<<endl;
   cout<<"\ty="<<y<<endl;
   break;
   //--------------------------------------------------------------
  case 2:
   cout<<"Primera Ecuacion"<<endl<<endl;  
   cout<<"Ingrese el coeficiente de x: ";    //Tomo valor para la posicion 0 0 
   cin>>matriz3x4[0][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";    //Tomo valor para la posicion 0 1 
   cin>>matriz3x4[0][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";      //Tomo valor para la posicion 0 2 
   cin>>matriz3x4[0][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";     //Tomo valor para la posicion 0 3 
   cin>>matriz3x4[0][3];
   cout<<endl;
   cout<<"Segunda Ecuacion"<<endl<<endl;     
   cout<<"Ingrese el coeficiente de x: ";      //Tomo valor para la posicion 1 0 
   cin>>matriz3x4[1][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";     //Tomo valor para la posicion 1 1 
   cin>>matriz3x4[1][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";       //Tomo valor para la posicion 1 2
   cin>>matriz3x4[1][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";       //Tomo valor para la posicion 1 3
   cin>>matriz3x4[1][3];
   cout<<endl;
   cout<<"Tercera Ecuacion"<<endl<<endl;
   cout<<"Ingrese el coeficiente de x: ";       //Tomo valor para la posicion 2 0 
   cin>>matriz3x4[2][0];
   cout<<endl;
   cout<<"Ingrese el coeficiente de y: ";     //Tomo valor para la posicion 2 1
   cin>>matriz3x4[2][1];
   cout<<endl;
   cout<<"Ingrese el coeficiente de z: ";      //Tomo valor para la posicion 2 2
   cin>>matriz3x4[2][2];
   cout<<endl;
   cout<<"Ingrese el valor del termino independiente: ";     //Tomo valor para la posicion 2 3 
   cin>>matriz3x4[2][3];
   cout<<endl;
   //Resuelvo
   matriz3x4[0][1]=matriz3x4[0][1]/matriz3x4[0][0];
   matriz3x4[0][2]=matriz3x4[0][2]/matriz3x4[0][0];
   matriz3x4[0][3]=matriz3x4[0][3]/matriz3x4[0][0];
   matriz3x4[0][0]=matriz3x4[0][0]/matriz3x4[0][0];// Se hace 1
   //----------------------------------------------
   matriz3x4[1][1]=((-matriz3x4[1][0])*matriz3x4[0][1])+matriz3x4[1][1];
   matriz3x4[1][2]=((-matriz3x4[1][0])*matriz3x4[0][2])+matriz3x4[1][2];
   matriz3x4[1][3]=((-matriz3x4[1][0])*matriz3x4[0][3])+matriz3x4[1][3];
   matriz3x4[1][0]=((-matriz3x4[1][0])*matriz3x4[0][0])+matriz3x4[1][0];// Se hace 0
   matriz3x4[2][1]=((-matriz3x4[2][0])*matriz3x4[0][1])+matriz3x4[2][1];
   matriz3x4[2][2]=((-matriz3x4[2][0])*matriz3x4[0][2])+matriz3x4[2][2];
   matriz3x4[2][3]=((-matriz3x4[2][0])*matriz3x4[0][3])+matriz3x4[2][3];
   matriz3x4[2][0]=((-matriz3x4[2][0])*matriz3x4[0][0])+matriz3x4[2][0];// Se hace 0
   //-------------------------------------------------------------------
   matriz3x4[1][2]=matriz3x4[1][2]/matriz3x4[1][1];
   matriz3x4[1][3]=matriz3x4[1][3]/matriz3x4[1][1];
   matriz3x4[1][1]=matriz3x4[1][1]/matriz3x4[1][1];// Se hace 1
   //----------------------------------------------
   matriz3x4[0][2]=((-matriz3x4[0][1])*matriz3x4[1][2])+matriz3x4[0][2];
   matriz3x4[0][3]=((-matriz3x4[0][1])*matriz3x4[1][3])+matriz3x4[0][3];
   matriz3x4[0][1]=((-matriz3x4[0][1])*matriz3x4[1][1])+matriz3x4[0][1];// Se hace 0
   matriz3x4[2][2]=((-matriz3x4[2][1])*matriz3x4[1][2])+matriz3x4[2][2];
   matriz3x4[2][3]=((-matriz3x4[2][1])*matriz3x4[1][3])+matriz3x4[2][3];
   matriz3x4[2][1]=((-matriz3x4[2][1])*matriz3x4[1][1])+matriz3x4[2][1];// Se hace 0
   //-------------------------------------------------------------------
   matriz3x4[2][3]=matriz3x4[2][3]/matriz3x4[2][2];//Solucion variable z
   matriz3x4[2][2]=matriz3x4[2][2]/matriz3x4[2][2];
   //-------------------------------------------------------------------
   matriz3x4[0][3]=((-matriz3x4[0][2])*matriz3x4[2][3])+matriz3x4[0][3];//Solucion variable x
   matriz3x4[0][2]=((-matriz3x4[0][2])*matriz3x4[2][2])+matriz3x4[0][2];
   matriz3x4[1][3]=((-matriz3x4[1][2])*matriz3x4[2][3])+matriz3x4[1][3];//Solucion variable y
   matriz3x4[1][2]=((-matriz3x4[1][2])*matriz3x4[2][2])+matriz3x4[1][2];
   //-------------------------------------------------------------------
   x=matriz3x4[0][3];    //Traigo valor de posicion 0 3 
   y=matriz3x4[1][3];    //Traigo valor de posicion 1 3
   z=matriz3x4[2][3];     //Traigo valor de posicion 2 3
   cout<<"Solucion: "<<endl;
   cout<<"\tx="<<x<<endl;
   cout<<"\ty="<<y<<endl;     //Muestro por pantalla los valores
   cout<<"\tz="<<z<<endl;
   break;
 }
 cout<<"Para realizar otro calculo presione 1, para salir presione 0"<<endl;
 cout<<"Opcion: ";
 cin>>repetir;
 while (repetir<0||repetir>1)     //flag repetir estaba inicializada en 1
 {
  cout<<endl<<"Ingrese una opcion valida"<<endl;    //Si la op no es 1, error
  cout<<"Opcion: ";
  cin>>repetir;
 }
 system("cls");
 }while(repetir==1);            
}


//-------------------------------------------------------------------------------------------

int Biseccion(){
   cout << setprecision(PRECISION); // Establecemos precisión con el valor definido
   
   double a, b, tolerancia;    //declaro variables
   
   cout << "\nCALCULO DE RAICES MEDIANTE METODO DE BISECCION" << endl;
   cout << "\nIngrese el intervalo inicial [a, b]" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";                  
   cin >> b;
   
   imprimePuntos(a, b);    //llamo funcion
   
   cout << "\nIngrese un subintervalo" << endl;       //ingresar el segundo intervalo
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   // [a, b]
   
   float xr; // raiz de la función
   
   
   if (f(a) * f(b) > 0) {     //Validación para que sea con distinto signo (menor que 0)
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
      
   } else {
      cout << "Tolerancia = ";     //Establecemos limite de tolerancia
      cin >> tolerancia;
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;   //Mostramos valores
      do {
         xr = (a + b) / 2.0;      //raiz, (a+b)/2 
         cout << a << "\t" << b << "\t" << xr << "\t";    //Muestro raices
         cout << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;

         
         if (abs(f(xr)) <= tolerancia) { //Valor absoluto de la raiz de f() menor o igual a tolerancia      ABS=Valor absoluto
         
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << xr << endl;
         
            break;
        
         }
      } while (true);
   }
   
   
   return 0;
}


double f(double x) 
{
  return exp(-1 * x) - cos(3 * x) - 0.5;    //Probamos con una función ya escrita en consola 
  
  
}

#define INTERVALOS 10  //10 subintervalos
void imprimePuntos(double a, double b)    //Para mostrar el cuerpo 
{
   int puntos = INTERVALOS + 1;    
   
   double ancho = (b - a) / INTERVALOS;    //La diferencia entre los puntos extremos y los intervalos
                                             //Para que muestre todos los puntos posibles entre a y b
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {                  //Que muestre mientras i sea menor a cantidad de puntos
      cout << "\t" << a << "\t" << f(a) << endl;    //Empieza en a
      a = a + ancho;             //a aumenta su valor actual mas el ancho
   }
}




