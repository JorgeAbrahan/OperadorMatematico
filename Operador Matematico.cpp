#include "iostream"
#include "conio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
void ver_el_procedimiento();
void ingresar_matrices();
void mostrar_matrices();
void ingresar_matriz();
void pedir_numero();
void minijuego_numero_random();
int observar_procedimiento = 0, cantidad_de_filas1, cantidad_de_filas2, cantidad_de_columnas1, cantidad_de_columnas2;
int matriz1[100][100], matriz2[100][100], matriz_correcta, numero_ingresado; 
/*Variables para los numeros aleatorios*/
int numero_aleatorio, hasta;

int main() {
	char nombre_del_usuario[30];
	int opcion_escogida, iterador = 0, strngLngth = 0;
	string hxdcml[100];
	/*Se pide el nombre del usuario y se le saluda*/
	cout<<"\tEscribe tu nombre: ";
	cin.getline(nombre_del_usuario,30,'\n');
	cout<<"\tHola "<<nombre_del_usuario<<endl;
	
	/*Se le da la bienvenida y se le muestran las instrucciones*/
	cout<<"\tBIENVENIDO A TU OPERADOR MATEMATICO"<<endl;
	cout<<"\tA continuacion se te presentaran todas las posibles operaciones que este programa"<<endl;
	cout<<"\tte permite desarrollar. Para ejecutar alguna de ellas solo sigue las instrucciones"<<endl;
	cout<<"\tque se te muestran."<<endl;
	
	do {
		int cantidad_de_numeros = 0, totales = 0, numeros_a_mostrar[100], total_multiplicacion = 1, matriz_resultante[100][100]; 
		float raiz_cuadrada = 0;
		/*Operaciones que el programa puede realizar*/
		cout<<endl;
		cout<<"\t\t\tOPERACIONES BASICAS: "<<endl;
		cout<<"\t1  -\tSumar n cantidad de numeros."<<endl;
		cout<<"\t2  -\tSumar hasta n numero."<<endl;
		cout<<"\t3  -\tRestar n numeros."<<endl;
		cout<<"\t4  -\tMultiplicar n numeros."<<endl;
		cout<<"\t5  -\tDescomponer un numero en sus factores primos"<<endl;
		cout<<"\t6  -\tElevar un numero a una potencia."<<endl;
		cout<<"\t7  -\tConocer la paridad de un numero."<<endl;
		cout<<"\t8  -\tConocer la tabla de multiplicar de n numero."<<endl;
		cout<<"\t9  -\tConocer si en un conjunto numerico alguno es la suma de los demas."<<endl;
		cout<<"\t10 -\tConocer el factorial de n numero."<<endl;
		
		cout<<"\t\t\tOPERACIONES INTERMEDIAS: "<<endl;
		cout<<"\t11 -\tResolver una ecuacion cuadratica."<<endl;
		cout<<"\t12 -\tAplicar el teorema de pitagoras."<<endl;
		cout<<"\t13 -\tCalcular la longitud de un vector."<<endl;
		
		cout<<"\t\t\tMATRICES: "<<endl;
		cout<<"\t14 -\tSumar matrices."<<endl;
		cout<<"\t15 -\tRestar matrices."<<endl;
		cout<<"\t16 -\tMultiplicar matrices."<<endl;
		cout<<"\t17 -\tConocer la diagonal principal de una matriz."<<endl;
		cout<<"\t18 -\tConocer la transpuesta de una matriz."<<endl;
		
		cout<<"\t\t\tCONVERSIONES: "<<endl;
		cout<<"\t19 -\tDe sistema decimal a romano."<<endl;
		cout<<"\t20 -\tDe sistema decimal a binario."<<endl;
		cout<<"\t21 -\tDe sistema decimal a hexadecimal."<<endl;
		
		cout<<"\t\t\tMINIJUEGO: "<<endl;
		cout<<"\t22 -\tAdivinar un numero aleatorio."<<endl;
		
		cout<<"\t23 -\tSALIR."<<endl;
		
		/*Se muestran las instrucciones y se le pide al usuario escoger una opcion*/
		cout<<endl;
		cout<<"\t\t\tINSTRUCCIONES: "<<endl;
		cout<<"\tBusque en la lista anteriormente mostrada la operacion que desee realizar y"<<endl;
		cout<<"\tdigite el numero relacionado a esa opcion escogida."<<endl;
		cout<<"\t\tNOTA: "<<endl;
		cout<<"\tPodra salir en cualquier momento digitando el numero relacionado a la opcion de salir"<<endl;
		cout<<endl;
		cout<<"\tDigite la opcion escogida: ";
		cin>>opcion_escogida;
		
		/*En base a la opcion escogida determinar el caso a realizar*/
		if((opcion_escogida > 22) || (opcion_escogida < 1)) {
			cout<<"\tLa opcion escogida no esta dentro del menu de opciones."<<endl;
		}
		else {
			switch(opcion_escogida) {
				//APARTADO OPERACIONES BASICAS
				case 1:
					int numero_a_sumar;
					/*Opcion sumar n cantidad de numeros*/
					cout<<"\tDigite la cantidad de numeros que desea sumar: ";
					cin>>cantidad_de_numeros; 
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*Bucle para sumar la cantidad de numeros ingresada*/
					for(int i = 0; i < cantidad_de_numeros; i++) {
						cout<<"\tDigite el "<<i+1<<" numero a sumar: ";
						cin>>numero_a_sumar;
						totales += numero_a_sumar;
						/*En caso de que el usuario desee observar el procedimiento*/
						if(observar_procedimiento == 1) {
							numeros_a_mostrar[i] = numero_a_sumar;
						}
					}
					/*En caso de desear ver el procedimiento*/
					if(observar_procedimiento == 1) {
						cout<<"\tPROCEDIMIENTO: "<<endl<<"\t";
						/*Bucle para mostrar el procedimiento*/
						for(int i = 0; i < cantidad_de_numeros; i++) {
							cout<<numeros_a_mostrar[i];
							/*Si aun no se ha llegado al ultimo numero*/
							if(i < cantidad_de_numeros - 1) {
								cout<<" + ";
							}
						}
						cout<<endl;/*Estetica*/
					}
					/*Se muestra el total*/
					cout<<"\tTOTAL: "<<totales<<endl;
				break;
				
				case 2: 
					/*Opcion sumar hasta n numero*/
					cout<<"\tDigite el numero hasta el cual desea sumar: ";
					cin>>cantidad_de_numeros;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*En caso de que el usuario desee observar el procedimiento*/
					if(observar_procedimiento == 1 && cantidad_de_numeros < 500) {
						cout<<"\tPROCEDIMIENTO: "<<endl<<"\t";
					}
					/*Bucle para sumar hasta el numero ingresado*/
					for(int i = 1; i <= cantidad_de_numeros; i++) {
						totales += i;
						/*En caso de que el usuario desee observar el procedimiento*/
						if(observar_procedimiento == 1 && cantidad_de_numeros < 500) {
							cout<<i;
							if(i < cantidad_de_numeros) {
								cout<<" + ";
							}
						} 
					}
					/*En caso de que desee ver el procedimiento pero el numero hasta el cual se sumara es mayor sea 500*/
					if((observar_procedimiento == 1) && (cantidad_de_numeros > 500)){
						cout<<"\tSu numero es demasiado grande como para mostrar el procedimiento"<<endl;
					}
					/*Un salto de linea solo en caso de que se cumpla la condicion establecida*/
					if((observar_procedimiento == 1) && (cantidad_de_numeros < 500)) {
						cout<<endl;/*Estetica*/
					}
					/*Se muestra el total*/
					cout<<"\tTOTAL: "<<totales<<endl;
					
				break;
				case 3: 
					int numero_a_restar;
					/*Opcion restar n numeros*/
					cout<<"\tDigite la cantidad de numeros que desea restar: ";
					cin>>cantidad_de_numeros;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*Se le muestra una aclaracion al usuario*/
					cout<<"\tLos numeros seran restados en el orden que los ingrese"<<endl;
					/*Se piden almacenan y restan los numeros que el usuario desee*/
					for(int i = 0; i < cantidad_de_numeros; i++) {
						cout<<"\tDigite el "<<i+1<<" numero a restar: ";
						cin>>numero_a_restar;
						totales -= numero_a_restar;
						/*Se pasa el primer valor a positivo*/
						if(i == 0) {
							totales *= -1;
						}
						/*Se almacenan los numeros a mostrar en un arreglo*/
						if(observar_procedimiento == 1) {
							numeros_a_mostrar[i] = numero_a_restar;
						}
					}
					if(observar_procedimiento == 1) {
						/*Se muestra el procedimiento*/
						cout<<"\tPROCEDIMIENTO"<<endl<<"\t";
						for(int i = 0; i < cantidad_de_numeros; i++) {
							cout<<numeros_a_mostrar[i];
							if(i < cantidad_de_numeros - 1) {
								cout<<" - ";
							}
						}
					}
					/*Se muestra el total*/
					cout<<endl;
					cout<<"\tTOTAL: "<<totales<<endl;
					
				break;
				case 4: 
					int numero_a_multiplicar;
					/*Opcion multiplicar n numeros*/
					cout<<"\tDigite la cantidad de numeros que desea multiplicar: ";
					cin>>cantidad_de_numeros;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					for(int i = 0; i < cantidad_de_numeros; i++) {
						cout<<"\tDigite el "<<i+1<<" numero a multiplicar: ";
						cin>>numero_a_multiplicar;
						total_multiplicacion *= numero_a_multiplicar;
						if(observar_procedimiento == 1) {
							/*Se almacenan los numeros a mostrar en un arreglo*/
							numeros_a_mostrar[i] = numero_a_multiplicar;
						}
					}
					if(observar_procedimiento == 1) {
						/*Se muestra el procedimiento*/
						cout<<"\tPROCEDIMIENTO"<<endl<<"\t";
						for(int i = 0; i < cantidad_de_numeros; i++) {
							cout<<numeros_a_mostrar[i];
							if(i < cantidad_de_numeros - 1) {
								cout<<" x ";
							}
						}
					}
					/*Se muestra el total*/
					cout<<endl;
					cout<<"\tTOTAL: "<<total_multiplicacion<<endl;
					
				break;
				case 5: 
					/*Opcion descomponer un numero en sus factores primos*/
					cout<<"\tIngrese el numero que desea descomponer: ";
					cin>>numero_ingresado;
					/*Se descompone el numero en sus factores primos*/
		    		cout<<"\t"<<numero_ingresado;
					do{
			    		if(numero_ingresado%(2) == 0){
				    		cout<<"\t|2\n";
				    		numero_ingresado /= 2;
			    		}
			    		else if(numero_ingresado%(3) == 0){
				    		cout<<"\t|3\n";
				    		numero_ingresado /= 3;
			    		}
			    		else if(numero_ingresado%(5) == 0){
				    		cout<<"\t|5\n";
				    		numero_ingresado /= 5;
			    		}
			    		else if(numero_ingresado%(7) == 0){
				    		cout<<"\t|7\n";
				    		numero_ingresado /= 7;
			    		}
			    		else if(numero_ingresado%(11) == 0){
				    		cout<<"\t|11\n";
				    		numero_ingresado /= 11;
			    		}
			    		else if(numero_ingresado%(13) == 0){
				    		cout<<"\t|13\n";
				    		numero_ingresado /= 13;
			    		}
			    		else if(numero_ingresado%(17) == 0){
				    		cout<<"\t|17\n";
				    		numero_ingresado /= 17;
			    		}
			    		else if(numero_ingresado%(19) == 0){
				    		cout<<"\t|19\n";
				    		numero_ingresado /= 19;
			    		}
			    		else if(numero_ingresado%(23) == 0){
				    		cout<<"\t|23\n";
				    		numero_ingresado /= 23;
		    			}
		    			else if(numero_ingresado%(29) == 0){
				    		cout<<"\t|29\n";
				    		numero_ingresado /= 29;
		    			}
		    			else if(numero_ingresado%(31) == 0){
				    		cout<<"\t|31\n";
				    		numero_ingresado /= 31;
		    			}
		    			else if(numero_ingresado%(37) == 0){
				    		cout<<"\t|37\n";
				    		numero_ingresado /= 37;
		    			}
		    			else if(numero_ingresado%(41)==0){
				    		cout<<"\t|41\n";
				    		numero_ingresado/=41;
		    			}
		    			else if(numero_ingresado%(43) == 0){
				    		cout<<"\t|43\n";
				    		numero_ingresado /= 43;
		    			}
		    			else if(numero_ingresado%(47) == 0){
				    		cout<<"\t|47\n";
				    		numero_ingresado /= 47;
		    			}
		    			else if(numero_ingresado%(53) == 0){
				    		cout<<"\t|53\n";
				    		numero_ingresado /= 53;
		    				}
		    			else if(numero_ingresado%(59) == 0){
			    			cout<<"\t|59\n";
			 			   	numero_ingresado /= 59;
		    			}
		    			else if(numero_ingresado%(61) == 0){
				    		cout<<"\t|61\n";
				    		numero_ingresado /= 61;
		    			}
		    			else if(numero_ingresado%(67) == 0){
				    		cout<<"\t|67\n";
				    		numero_ingresado /= 67;
		    			}
		    			else if(numero_ingresado%(71) == 0){
				    		cout<<"\t|71\n";
						    numero_ingresado /= 71;
		    			}
		    			else if(numero_ingresado%(73) == 0){
				    		cout<<"\t|73\n";
				    		numero_ingresado /= 73;
		    			}
		    			else if(numero_ingresado%(79) == 0){
				    		cout<<"\t|79\n";
				    		numero_ingresado /= 79;
		    			}
		    			else if(numero_ingresado%(83) == 0){
				    		cout<<"\t|83\n";
				    		numero_ingresado /= 83;
		    			}
		    			else if(numero_ingresado%(89) == 0){
				    		cout<<"\t|89\n";
				    		numero_ingresado /= 89;
		    			}
		    			else if(numero_ingresado%(97) == 0){
				    		cout<<"\t|97\n";
				    		numero_ingresado /= 97;
		    			}
		    			else{
		    				cout<<"\t|"<<numero_ingresado;
							numero_ingresado/=numero_ingresado;
						}
						cout<<"\t"<<numero_ingresado;
	    			}while(numero_ingresado!=1);
	    			cout<<endl;
						
				break;
				case 6:
					int base, exponente; 
					/*Opcion elevar un numero a una potencia*/
					/*Se le pide al usuario ingresar la base que sera elevada y luego el exponente*/
					cout<<"\tDigite la base: ";
					cin>>base;
					cout<<"\tDigite el exponente: ";
					cin>>exponente;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					if(observar_procedimiento == 1) {
						cout<<"\tPROCEDIMIENTO: "<<endl<<"\t";
					}
					/*Se multiplica la base tantas veces el exponente*/
					for(int i = 0; i < exponente; i++) {
						total_multiplicacion *= base;
						/*En caso de que se desee ver el procedimiento*/
						if(observar_procedimiento == 1) {
							cout<<base;
							if(i < exponente - 1) {
								cout<<" x ";
							}
						}
					}
					cout<<endl;
					cout<<"\tTOTAL: "<<total_multiplicacion<<endl;
					
				break;
				case 7: 
					/*Opcion conocer la paridad de un numero*/
					cout<<"\tDigite el numero para conocer su paridad: ";
					cin>>numero_ingresado;
					/*Se evalua si el numero es par o impar*/
					if(numero_ingresado%(2) == 0) {
						cout<<"\tEl numero es par";
					}
					else if(numero_ingresado%(2) == 1){
						cout<<"\tEl numero es impar";
					}
					/*Se evalua si el numeroes o no positivo*/
					if(numero_ingresado > 0) {
							cout<<", y es positivo"<<endl;
					}
					else if(numero_ingresado < 0){
							cout<<", y es negativo"<<endl;
					}
					
				break;
				case 8: 
					/*Opcion conocer la tabla de multiplicar de n numero entre 1 y 20*/
					cout<<"\tDigite el numero del que desea conocer su tabla de multiplicar: ";
					cin>>numero_ingresado;
					cout<<endl;
					for(int i = 1; i <= 20; i++) {
						/*Se realiza y muestra la multiplicacion*/
						cout<<"\t"<<numero_ingresado<<" x "<<i<<" = "<<numero_ingresado * i<<endl;
					}
					
				break;
				case 9: 
					/*Se declara un arreglo que almacene a todos los numeros del conjunto que seran sumados*/
					int numeros_conjunto[100];
					/*Opcion conocer si en un conjunto numerico es la suma de los demas*/
					cout<<"\tDigite la cantidad de numeros del conjunto: ";
					cin>>cantidad_de_numeros;
					/*Se declara un bucle para almacenar todos los numeros del conjunto*/
					for(int i = 0; i < cantidad_de_numeros; i++) {
						cout<<"\tDigite el numero "<<i+1<<" del conjunto: ";
						cin>>numeros_conjunto[i];
					}
					cout<<"\tArreglo Ingresado: "<<endl;
					/*Se declara un bucle para sumar todos los numeros del conjunto y obtener el total*/
					for(int i = 0; i < cantidad_de_numeros; i++) {
						totales += numeros_conjunto[i];
						/*Se muestra cada elemento del arreglo junto a su posicion en el mismo*/
						cout<<"\tNumero: "<<numeros_conjunto[i]<<"\tPosicion en el conjunto: "<<i+1<<endl;
					}
					/*Se evalua si algun numero del conjunto es igual a la suma de los demas*/
					for(int i = 0; i < cantidad_de_numeros; i++) {
						if(totales - numeros_conjunto[i] == numeros_conjunto[i]) {
							cout<<"\tEl numero del conjunto igual a la suma de los demas es: ";
							cout<<numeros_conjunto[i]<<endl;
							cout<<"\tCuya posicion en el conjunto es: "<<i+1<<endl;
						}
						/*Si el ultimo numero del conjunto no es igual a la suma de los demas entonces se muestra este mensaje*/
						else if((totales - numeros_conjunto[i] != numeros_conjunto[i]) && (i == cantidad_de_numeros - 1)) {
							cout<<"\tNo existe ningun numero en el conjunto que sea la suma de los demas"<<endl;
						}
					}
					
				break;
				case 10: 
					/*Opcion conocer el factorial de n numero*/
					cout<<"\tDigite el numero del que desea calcular el factorial: ";
					cin>>numero_ingresado;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*En caso de que se desee observar el procedimiento*/
					if(observar_procedimiento == 1) {
						cout<<"\tPROCEDIMIENTO: "<<endl<<"\t";
					}
					/*Bucle para calcular el valor o factorial del numero*/
					for(int i = 1; i <= numero_ingresado;i++) {
						total_multiplicacion *= i;
						if(observar_procedimiento == 1) {
							cout<<i;
							if(i < numero_ingresado) {
								cout<<" x ";
							}
						}
					}
					cout<<endl;
					cout<<"\tTOTAL: "<<numero_ingresado<<"! = "<<total_multiplicacion<<endl;
					
				break;
				
				//APARTADO OPERACIONES INTERMEDIAS
				case 11: 
					int a, b, c; /*Sirve para almacenar los valores a, b y c de la ecuacion cuadratica*/
					/*Sirven para almacenar los valores de x*/
					float primer_valor_x, segundo_valor_x;
					/*Opcion resolver una ecuacion cuadratica*/
					cout<<"\tIngrese los valores que a continuacion se le piden: "<<endl;
					cout<<"\tValor de a: ";
					cin>>a;
					cout<<"\tValor de b: ";
					cin>>b;
					cout<<"\tValor de c: ";
					cin>>c;
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*Se calcula el valor de la raiz cuadrada*/
					raiz_cuadrada = sqrt(pow(b,2) - (4 * a * c));
					/*Se calculan los dos valores para x*/
					primer_valor_x = (-b + raiz_cuadrada) / (2 * a);
					segundo_valor_x = (-b - raiz_cuadrada) / (2 * a);
					/*En caso de que la raiz sea exacta*/
					if(raiz_cuadrada >= 0) {
						if(observar_procedimiento == 1) {
							cout<<"\tPROCEDIMIENTO: "<<endl;
							cout<<"\tx1 = -"<<b<<" + RaizCuadrada("<<b<<"^2 - 4("<<a<<")("<<c<<"))"<<endl<<"\t\t2("<<a<<")"<<endl;
							cout<<"\tx1 = -"<<b<<" + RaizCuadrada("<<pow(b,2)<<" - "<<4 * a * c<<")"<<endl<<"\t\t"<<2 * a<<endl;
							cout<<"\tx1 = -"<<b<<" + "<<raiz_cuadrada<<endl<<"\t\t"<<2 * a<<endl;
							cout<<"\tx1 = "<<-b + raiz_cuadrada<<endl<<"\t      "<<2 * a<<endl;
						}
						/*Resultado*/
						cout<<"\tTOTAL: "<<endl;
						cout<<"\tx1 = "<<primer_valor_x<<endl;
						cout<<endl;
						if(observar_procedimiento == 1) {
							cout<<"\tPROCEDIMIENTO: "<<endl;
							cout<<"\tx1 = -"<<b<<" - RaizCuadrada("<<b<<"^2 - 4("<<a<<")("<<c<<"))"<<endl<<"\t\t2("<<a<<")"<<endl;
							cout<<"\tx1 = -"<<b<<" - RaizCuadrada("<<pow(b,2)<<" - "<<4 * a * c<<")"<<endl<<"\t\t"<<2 * a<<endl;
							cout<<"\tx2 = -"<<b<<" - "<<raiz_cuadrada<<endl<<"\t\t"<<2 * a<<endl;
							cout<<"\tx2 = "<<-b - raiz_cuadrada<<endl<<"\t      "<<2 * a<<endl;
						}
						/*Resultado*/
						cout<<"\tTOTAL: "<<endl;
						cout<<"\tx2 = "<<segundo_valor_x<<endl;
					}
					else {
						cout<<"\tLA RAIZ DA COMO RESULTADO UN NUMERO IMAGINARIO"<<endl;
						cout<<"\tRESULTADO: "<<endl;
						cout<<"\tx1 = -"<<b<<" + RaizCuadrada("<<pow(b,2)<<" - "<<4 * a * c<<endl<<"\t\t"<<2*a<<endl;
					}
					
				break;
				case 12: 
					int operacion_escogida;
					int primer_cateto, segundo_cateto, hipotenusa;
					/*Opcion aplicar el teorema de pitagoras*/
					/*Se pregunta si desea calcular la hipotenusa o algun cateto*/
					do {
						cout<<"\tSolo puede ingresar un numero dentro de los parametros"<<endl;
						cout<<"\t1 -\tHipotenusa"<<endl;
						cout<<"\t2 -\tCateto ('a' o 'b')"<<endl;
						cout<<"\tIngrese el numero correspondiente a lo que desea calcular: ";
						cin>>operacion_escogida;
					} while(operacion_escogida < 1 || operacion_escogida > 2);
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*Se evalua si escogio calcular la hipotenusa o los catetos*/
					switch(operacion_escogida) {
						case 1: 
							int suma_catetos;
							/*Desea calcular la hipotenusa*/
							cout<<"\tDigite el valor del primer cateto: ";
							cin>>primer_cateto;
							cout<<"\tDigite el valor del segundo cateto: ";
							cin>>segundo_cateto;
							suma_catetos = pow(primer_cateto,2) + pow(segundo_cateto,2);
							/*Se muestra la formula el procedimiento y el total*/
							cout<<"\tFORMULA: "<<endl;
							cout<<"\thyp = RaizCuadrada(cat^2 + cat^2)"<<endl;
							if(observar_procedimiento == 1) {
								cout<<"\tPROCEDIMIENTO: "<<endl;
								cout<<"\thyp = RaizCuadrada("<<primer_cateto<<"^2 + "<<segundo_cateto<<"^2)"<<endl;
								cout<<"\thyp = RaizCuadrada("<<pow(primer_cateto,2)<<" + "<<pow(segundo_cateto,2)<<")"<<endl;
								cout<<"\thyp = RaizCuadrada("<<suma_catetos<<")"<<endl;
							}
							cout<<"\tTOTAL: "<<endl;
							raiz_cuadrada = sqrt(suma_catetos);
							if(raiz_cuadrada >= 0) {
								cout<<"\thyp = "<<raiz_cuadrada<<endl;
							}
							else {
								cout<<"\tLa raiz da como resultado un numero imaginario: "<<endl;
								cout<<"\thyp = RaizCuadrada("<<suma_catetos<<")"<<endl;
							}
							
						break;
						case 2: 
							int resta_lados;
							/*Desea calcular uno de los catetos*/
							cout<<"\tDigite el valor de la hipotenusa: ";
							cin>>hipotenusa;
							cout<<"\tDigite el valor del cateto: ";
							cin>>primer_cateto;
							resta_lados = pow(hipotenusa,2) - pow(primer_cateto,2);
							/*Se muestra la formual el procedimiento y el total*/
							cout<<"\tFORMULA: "<<endl;
							cout<<"\tcat = RaizCuadrada(hyp^2 - cat^2)"<<endl;
							if(observar_procedimiento == 1) {
								cout<<"\tPROCEDIMIENTO: "<<endl;
								cout<<"\tcat = RaizCuadrada("<<hipotenusa<<"^2 - "<<primer_cateto<<"^2)"<<endl;
								cout<<"\tcat = RaizCuadrada("<<pow(hipotenusa,2)<<" - "<<pow(primer_cateto,2)<<")"<<endl;
								cout<<"\tcat = RaizCuadrada("<<resta_lados<<")"<<endl;
							}
							cout<<"\tTOTAL: "<<endl;
							raiz_cuadrada = sqrt(resta_lados);
							if(raiz_cuadrada >= 0) {
								cout<<"\tcat = "<<raiz_cuadrada<<endl;
							}
							else {
								cout<<"\tLa raiz da como resultado un numero imaginario: "<<endl;
								cout<<"\tcat = RaizCuadrada("<<resta_lados<<")"<<endl;
							}
							
						break;
					}
					
				break;
				case 13:
					int coordenada1, coordenada2, suma_coordenadas; 
					/*Se pide al usuario ingresar las coordenadas del vector y se suman sus cuadrados*/
					cout<<"\tIngrese las coordenadas del vector separadas por un espacio: ";
					cin>>coordenada1>>coordenada2;
					suma_coordenadas = pow(coordenada1,2) + pow(coordenada2,2);
					/*Se llama a la funcion para ver el procedimiento*/
					ver_el_procedimiento();
					/*Se muestra el procedimiento en el caso de que haya decidido verlo*/
					if(observar_procedimiento == 1) {
						cout<<"\tSe nombro al vector como 'a'"<<endl;
						cout<<"\t|a| = RaizCuadrada("<<coordenada1<<"^2 + "<<coordenada2<<"^2)"<<endl;
						cout<<"\t|a| = RaizCuadrada("<<pow(coordenada1,2)<<" + "<<pow(coordenada2,2)<<")"<<endl;
						cout<<"\t|a| = RaizCuadrada("<<suma_coordenadas<<")"<<endl;
					}
					cout<<"\tTOTAL: "<<endl;
					raiz_cuadrada = sqrt(suma_coordenadas);
					/*Se evalua si la raiz da o no como resultado un numero complejo*/
					if(raiz_cuadrada >= 0) {
						cout<<"\t|a| = "<<raiz_cuadrada<<endl;
					}
					else {
						cout<<"\tLa raiz da como resultado un numero imaginario: "<<endl;
						cout<<"\t|a| = RaizCuadrada("<<suma_coordenadas<<")"<<endl;
					}
					
				break;
				
				//APARTADO MATRICES
				case 14: 
					/*Opcion sumar matrices*/
					do {
						/*Se llama la funcion para pedir y almacenar las dos matrices*/
						ingresar_matrices();
						/*Se llama la funcion para mostrar las dos matrices ingresadas*/
						mostrar_matrices();
					} while (matriz_correcta != 1);
					/*Se evalua si la matriz es conformable para la suma*/
					if((cantidad_de_filas1 == cantidad_de_filas2) && (cantidad_de_columnas1 == cantidad_de_columnas2)) {
						cout<<"\tMATRIZ RESULTANTE: "<<endl;
						for(int i = 0; i < cantidad_de_filas1; i++) {
							for(int j = 0; j < cantidad_de_columnas1; j++) {
								cout<<"\t"<<matriz1[i][j] + matriz2[i][j];
							}
							cout<<endl;
						}
					}
					else {
						cout<<"\tLas matrices no son conformables para la operacion que desea realizar"<<endl;
						cout<<"\tEl numero de filas de la primera matriz debe ser igual al de la segunda"<<endl;
						cout<<"\tal igual que con las columnas de ambas matrices."<<endl;
					}
					
				break;
				case 15: 
					/*Opcion restar matrices*/
					do {
						/*Se llama la funcion para pedir y almacenar las dos matrices*/
						ingresar_matrices();
						/*Se llama la funcion para mostrar las dos matrices ingresadas*/
						mostrar_matrices();
					} while (matriz_correcta != 1);
					if((cantidad_de_filas1 == cantidad_de_filas2) && (cantidad_de_columnas1 == cantidad_de_columnas2)) {
						cout<<"\tMATRIZ RESULTANTE: "<<endl;
						for(int i = 0; i < cantidad_de_filas1; i++) {
							for(int j = 0; j < cantidad_de_columnas1; j++) {
								cout<<"\t"<<matriz1[i][j] - matriz2[i][j];
							}
							cout<<endl;
						}
					}
					else {
						cout<<"\tLas matrices no son conformables para la operacion que desea realizar."<<endl;
						cout<<"\tEl numero de filas de la primera matriz debe ser igual al de la segunda"<<endl;
						cout<<"\tigual que con las columnas de ambas matrices."<<endl;
					}
					
				break;
				case 16: 
					int elementos[100][100];
					/*Opcion multiplicar matrices*/
					do {
						/*Se llama la funcion para pedir y almacenar las dos matrices*/
						ingresar_matrices();
						/*Se llama la funcion para mostrar las dos matrices ingresadas*/
						mostrar_matrices();
					} while (matriz_correcta != 1);
					/*Se evalua si las matrices son conformables para la multiplicacion*/
					if(cantidad_de_columnas1 == cantidad_de_filas2) {
						/*Se realiza la multiplicacion de las matrices*/
						for(int i = 0; i < cantidad_de_filas1; i++)//Bucle que recorra las filas de la primera matriz
						{
							for(int j = 0; j < cantidad_de_columnas2; j++)//Bucle que recorra las columnas de la segunda matriz
							{
								int k = 0;//Se inicializa en 0 el iterador de las filas de la segunda matriz
								for(int l = 0; l < cantidad_de_columnas1; l++)//Bucle que recorra las filas de la primera matriz
								{
									if((i == 0) && (j == 0)) //Se calcula y almacena el elemento [0] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 0) && (j == 1)) //Se calcula y almacena el elemento [0] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 0) && (j == 2)) //Se calcula y almacena el elemento [0] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 0) && (j == 3)) //Se calcula y almacena el elemento [0] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 0) && (j == 4)) //Se calcula y almacena el elemento [0] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 0) && (j == 5)) //Se calcula y almacena el elemento [0] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 0)) //Se calcula y almacena el elemento [1] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 1)) //Se calcula y almacena el elemento [1] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 2)) //Se calcula y almacena el elemento [1] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 3)) //Se calcula y almacena el elemento [1] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 4)) //Se calcula y almacena el elemento [1] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 1) && (j == 5)) //Se calcula y almacena el elemento [1] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 0)) //Se calcula y almacena el elemento [2] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 1)) //Se calcula y almacena el elemento [2] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 2)) //Se calcula y almacena el elemento [2] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 3)) //Se calcula y almacena el elemento [2] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 4)) //Se calcula y almacena el elemento [2] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 2) && (j == 5)) //Se calcula y almacena el elemento [2] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 0)) //Se calcula y almacena el elemento [3] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 1)) //Se calcula y almacena el elemento [3] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 2)) //Se calcula y almacena el elemento [3] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 3)) //Se calcula y almacena el elemento [3] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 4)) //Se calcula y almacena el elemento [3] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 3) && (j == 5)) //Se calcula y almacena el elemento [3] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 0)) //Se calcula y almacena el elemento [4] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 1)) //Se calcula y almacena el elemento [4] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 2)) //Se calcula y almacena el elemento [4] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 3)) //Se calcula y almacena el elemento [4] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 4)) //Se calcula y almacena el elemento [4] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 4) && (j == 5)) //Se calcula y almacena el elemento [4] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 0)) //Se calcula y almacena el elemento [5] [0] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 1)) //Se calcula y almacena el elemento [5] [1] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 2)) //Se calcula y almacena el elemento [5] [2] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 3)) //Se calcula y almacena el elemento [5] [3] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 4)) //Se calcula y almacena el elemento [5] [4] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									if((i == 5) && (j == 5)) //Se calcula y almacena el elemento [5] [5] de la matriz
									{
										elementos[i][j] += matriz1[i][l] * matriz2[k][j];	
									}
									k++;//Itera las filas en la segunda matriz
								}
							}	
						}//Bucle capaz de calcular matrices resultantes con una dimension maxima de 6x6
						cout<<endl;
						cout<<"\tMATRIZ RESULTANTE: "<<endl;
						for(int i = 0; i < cantidad_de_filas1; i++) {
							for(int j = 0; j < cantidad_de_columnas2; j++) {
								cout<<"\t"<<elementos[i][j];
							}
							cout<<endl;
						}
					}
					else {
						cout<<"\tLas matrices no son conformables para la multiplicacion."<<endl;
						cout<<"\tPara serlo, la cantidad de columnas de la primera matriz"<<endl;
						cout<<"\tdeberian ser iguales a la cantidad de filas de la segunda."<<endl;
					}
				break;
				case 17: 
					/*Opcion conocer la diagonal principal de una matriz*/
					do {
						ingresar_matriz();
					} while(matriz_correcta != 1);
					/*Se determina si la matriz tiene diagonal principal*/
					if(cantidad_de_columnas1 == cantidad_de_filas1) {
						cout<<"\tMATRIZ RESULTANTE: "<<endl;
						/*Localizar los elementos de la diagonal principal y mostrarlos*/
						for(int i = 0; i < cantidad_de_filas1; i++) {
							cout<<"\t"<<matriz1[i][i]<<endl;
							cout<<"\t";
							if(iterador > 0) {
								cout<<"\t";
							}
							if(iterador > 1){
								cout<<"\t";
							}
							if(iterador > 2){
								cout<<"\t";
							}
							if(iterador > 3){
								cout<<"\t";
							}
							if(iterador > 4){
								cout<<"\t";
							}
							if(iterador > 5){
								cout<<"\t";
							}
							iterador++;
						}
						cout<<endl;
					}
					else {
						cout<<"\tLa matriz no tiene diagonal principal"<<endl;
						cout<<"\tPara tener debe ser cuadrada, osea que su cantidad de filas"<<endl;
						cout<<"\tdebe ser igual a su cantidad de columnas."<<endl;
					}
					
				break;
				case 18: 
					/*Opcion conocer la transpuesta de una matriz*/
					do {
						ingresar_matriz();
					} while(matriz_correcta != 1);
					cout<<"\tMATRIZ RESULTANTE:"<<endl;
					for(int i = 0; i < cantidad_de_columnas1; i++) {
						for(int j = 0; j < cantidad_de_filas1; j++) {
							cout<<"\t"<<matriz1[j][i];
						}
						cout<<endl;
					}
					
				break;
				
				//APARTADO CONVERSIONES
				case 19: 
					int unidades, decenas, centenas, unidades_millar;
					/*Opcion de sistema decimal a romano*/
					do {
						pedir_numero();
					} while(matriz_correcta != 1);
					if(numero_ingresado < 10000) {
						cout<<"\tEl numero "<<numero_ingresado<<" en sistema romano es: "<<endl;
						/*Se descompone el numero en sus unidades, decenas, centenas y unidades de millar*/
						unidades = numero_ingresado % 10;
						numero_ingresado /= 10;
						decenas = numero_ingresado % 10;
						numero_ingresado /= 10;
						centenas = numero_ingresado % 10;
						numero_ingresado /= 10;
						unidades_millar = numero_ingresado % 10; 
						cout<<"\t";
						/*Hasta el numero 9999*/
						switch(unidades_millar){
							case 1:cout<<"M";break;
							case 2:cout<<"MM";break;
							case 3:cout<<"MMM";break;
							case 4:
								cout<<"__"<<endl;
								cout<<"\tIM";
							break;
							case 5:
								cout<<"_"<<endl;
								cout<<"\tV";
								break;
							case 6:
								cout<<"__"<<endl;
								cout<<"\tVI";
							break;
							case 7:
								cout<<"___"<<endl;
								cout<<"\tVII";
							break;
							case 8:
								cout<<"____"<<endl;
								cout<<"\tVIII";
							break;
							case 9:
								cout<<"__"<<endl;
								cout<<"\tIX";
							break;
						}
						switch(centenas){
							case 1:cout<<"C";break;
							case 2:cout<<"CC";break;
							case 3:cout<<"CCC";break;
							case 4:cout<<"CD";break;
							case 5:cout<<"D";break;
							case 6:
								if(decenas == 0) {
									cout<<"DC";
								}
								else {
									cout<<"DI";
								}
							break;
							case 7:
								if(decenas == 0) {
									cout<<"DCC";
								}
								else {
									cout<<"DII";
								}
							break;
							case 8:
								if(decenas == 0) {
									cout<<"DCCC";
								}
								else {
									cout<<"DIII";
								}
							break;
							case 9:cout<<"CM";break;
						}
						switch(decenas){
							case 1:cout<<"X";break;
							case 2:cout<<"XX";break;
							case 3:cout<<"XXX";break;
							case 4:cout<<"XL";break;
							case 5:cout<<"L";break;
							case 6:cout<<"LX";break;
							case 7:cout<<"LXX";break;
							case 8:cout<<"LXXX";break;
							case 9:cout<<"XC";break;
						}					
						switch(unidades){
							case 1:cout<<"I";break;
							case 2:cout<<"II";break;
							case 3:cout<<"III";break;
							case 4:cout<<"IV";break;
							case 5:cout<<"V";break;
							case 6:cout<<"VI";break;
							case 7:cout<<"VII";break;
							case 8:cout<<"VIII";break;
							case 9:cout<<"IX";break;
						}
						cout<<endl;
					}
					/*En caso de que el numero sea 10000*/
					else if(numero_ingresado == 10000) {
						cout<<"\tEl numero "<<numero_ingresado<<" en el sistema romano es: "<<endl;
						cout<<"\t_"<<endl;
						cout<<"\tX"<<endl;
					}
					/*En caso de que el numero sobrepase los limites de conversion*/
					else {
						cout<<"\tEl programa no puede aplicar factores de conversion a numeros"<<endl;
						cout<<"\tmayores a 10000."<<endl;
					}
					
				break;
				case 20: 
					int arreglo_binario[100];
					
					/*Funcion para pedir que ingresen el numero*/
					do {
						pedir_numero();
					} while(matriz_correcta != 1);
					cout<<"\tEl numero "<<numero_ingresado<<" en el sistema binario es: "<<endl;
					
					/*Se divide modularmente para obtener el numero en binario*/
					for(iterador = 0; numero_ingresado != 0; iterador++) { 
						arreglo_binario[iterador] = numero_ingresado %(2);
						numero_ingresado /= 2;
					}
					cout<<"\t";
					/*Se muestra el arreglo que contiene el numero en binario*/
					for(int i = iterador - 1; i != -1; i--) {
						cout<<"  "<<arreglo_binario[i];
					}
					cout<<endl;
					
				break;
				case 21: 
					int nmroDcml, modulo;
			
					//Se pide y almacena el numero a convertir
					cout<<"\tIngresa el numero: ";
					cin>>nmroDcml;
					//En caso de que el numero sea 15 o menor
					if(nmroDcml < 16) {
						
						//Se imprime su equivalente
						switch(nmroDcml) {
							case 10: cout<<"\tA";break;
							case 11: cout<<"\tB";break;
							case 12: cout<<"\tC";break;
							case 13: cout<<"\tD";break;
							case 14: cout<<"\tE";break;
							case 15: cout<<"\tF";break;
							default: cout<<"\t"<<nmroDcml;break;
						}
					}
					//En caso de que el numero sea 16 o mayor
					else {
						//Bucle para convertir a hexadecimal
						for(int i = 0; nmroDcml != 0; i++) {
							//Se almacena el modulo de el numero decimal entre 16
							modulo = nmroDcml%(16);//65536%16=0; 4096%16=0; 256%16=0; 16%16=0
							//Se divide el numero decimal entre 16
							nmroDcml /= 16;//65536/16=4096; 4096/16=256; 256/16=16; 16/16=1
							//Se almacena el equivalente del modulo en hexadecimal en una cadena
							switch(modulo) {
								fflush(stdin);
								case 1: hxdcml[i] = "1";break;
								case 2: hxdcml[i] = "2";break;
								case 3: hxdcml[i] = "3";break;
								case 4: hxdcml[i] = "4";break;
								case 5: hxdcml[i] = "5";break;
								case 6: hxdcml[i] = "6";break;
								case 7: hxdcml[i] = "7";break;
								case 8: hxdcml[i] = "8";break;
								case 9: hxdcml[i] = "9";break;
								case 10: hxdcml[i] = "A";break;
								case 11: hxdcml[i] = "B";break;
								case 12: hxdcml[i] = "C";break;
								case 13: hxdcml[i] = "D";break;
								case 14: hxdcml[i] = "E";break;
								case 15: hxdcml[i] = "F";break;
								default: hxdcml[i] = "0";break;
							}//0-0-0-0
							//Si el numero llega a ser 1 se almacena en el arreglo
							if(nmroDcml == 1) {
								i++;
								hxdcml[i] = "1";
								nmroDcml--;
								if(strngLngth >= 3) {
									strngLngth++;
								}
							}
							//Variable que mide la longitud de la cadena
							strngLngth++; //65535
						}
						cout<<"\n"<<strngLngth<<"\n\t";
						//Se muestra la cadena a la inversa
						for(strngLngth; strngLngth > -1; strngLngth--) {
							cout<<hxdcml[strngLngth];
						}
					}
					cout<<endl;
				break;
				
				//APARTADO MINIJUEGO
				case 22:
					int dificultad;
					/*Opcion adivinar un numero aleatorio*/
					cout<<"\tBienvenido al minijuego de adivinar un numero aleatorio"<<endl;
					do {
						cout<<"\tA continuacion seleccione el numero correspondiente a la"<<endl;
						cout<<"\tdificultad que lo desee: "<<endl;
						cout<<"\t1 -\tFacil: Rango (1 - 100)"<<endl;
						cout<<"\t2 -\tMedio: Rango (1 - 1,000)"<<endl;
						cout<<"\t3 -\tDificil: Rango (1 - 10,000)"<<endl;
						cout<<"\tDificultad: ";
						cin>>dificultad;
					} while(dificultad < 1  ||  dificultad > 3);
					/*Se evaluan los casos dependiendo de la dificultad a la que lo haya escogido*/
					switch(dificultad) {
						case 1:
							cout<<"\tSelecciono la dificultad FACIL"<<endl;
							hasta = 100;
							srand(time(NULL));
							numero_aleatorio = 1 + rand() % (100);
							minijuego_numero_random();
							
						break;
						case 2:
							cout<<"\tSelecciono la dificultad MEDIA"<<endl;
							hasta = 1000;
							srand(time(NULL));
							numero_aleatorio = 1 + rand() % (1000);
							minijuego_numero_random();
							
						break;
						case 3:
							cout<<"\tSelecciono la dificultad DIFICIL"<<endl;
							hasta = 10000;
							srand(time(NULL));
							numero_aleatorio = 1 + rand() % (10000);
							minijuego_numero_random();
							
						break;
					}
					
					
				break;
				case 23: 
					/*Opcion salir*/
					
				break;
			}
		}
		cout<<"\t";
		system("pause");
	} while(opcion_escogida != 22);
	
	return 0;
}

void ver_el_procedimiento() {
	do {
		cout<<"\tSolo puede ingresar un numero dentro de los parametros"<<endl;
		cout<<"\tSi desea observar el procedimiento digite 1, si no 0: ";
		cin>>observar_procedimiento;
		/*El bucle se repite en caso de que el numero no este entre el rango establecido*/
	} while(observar_procedimiento > 1 || observar_procedimiento < 0);
}

void ingresar_matrices() {
	cout<<"\tIngrese la cantidad de filas y columnas de la primera matriz separadas por un espacio: ";
	cin>>cantidad_de_filas1>>cantidad_de_columnas1;
	cout<<"\tIngrese la cantidad de filas y columnas de la segunda matriz separadas por un espacio: ";
	cin>>cantidad_de_filas2>>cantidad_de_columnas2;
	cout<<"\tIngrese los elementos como se le piden a continuacion "<<endl;
	/*Se piden y almacenan los elementos de la primera matriz*/
	cout<<"\tPRIMERA MATRIZ: "<<endl;
	for(int i = 0; i < cantidad_de_filas1; i++) {
		for(int j = 0; j < cantidad_de_columnas1; j++) {
			cout<<"\tElemento ["<<i+1<<"] ["<<j+1<<"]: ";
			cin>>matriz1[i][j];
		}
	}
	/*Se piden y almacenan los elementos de la segunda matriz*/
	cout<<"\tSEGUNDA MATRIZ: "<<endl;
	for(int i = 0; i < cantidad_de_filas2; i++) {
		for(int j = 0; j < cantidad_de_columnas2; j++) {
			cout<<"\tElemento ["<<i+1<<"] ["<<j+1<<"]: ";
			cin>>matriz2[i][j];
		}
	}
}

void mostrar_matrices() {
	cout<<"\tA continuacion se le mostraran las matrices ingresadas"<<endl;
	cout<<"\tPRIMERA MATRIZ: "<<endl;
	for(int i = 0; i < cantidad_de_filas1; i++) {
		for(int j = 0; j < cantidad_de_columnas1; j++) {
			cout<<"\t"<<matriz1[i][j];
		}
		cout<<endl;
	}
	cout<<"\tSEGUNDA MATRIZ:"<<endl;
	for(int i = 0; i < cantidad_de_filas2; i++) {
		for(int j = 0; j < cantidad_de_columnas2; j++) {
			cout<<"\t"<<matriz2[i][j];
		}
		cout<<endl;
	}
	do{
		cout<<"\tSi las matrices ingresadas son correctas digite 1, si no digite 0: ";
		cin>>matriz_correcta;
	} while(matriz_correcta < 0 || matriz_correcta > 1);
}

void ingresar_matriz() {
	cout<<"\tIngrese la cantidad de filas de la matriz: ";
	cin>>cantidad_de_filas1;
	cout<<"\tIngrese la cantidad de columnas de la matriz: ";
	cin>>cantidad_de_columnas1;
	cout<<"\tIngrese los elementos de la matriz como se le piden a continuacion "<<endl;
	/*Se pide y almacena la matriz*/
	for(int i = 0; i < cantidad_de_filas1; i++) {
		for(int j = 0; j < cantidad_de_columnas1; j++) {
			cout<<"\tElemento ["<<i+1<<"] ["<<j+1<<"]: ";
			cin>>matriz1[i][j];
		}
	}
	/*Se muestra la matriz*/
	for(int i = 0; i < cantidad_de_filas1; i++) {
		for(int j = 0; j < cantidad_de_columnas1; j++) {
			cout<<"\t"<<matriz1[i][j];
		}
		cout<<endl;
	}
	do{
		cout<<"\tSi la matriz ingresada es correcta digite 1, si no digite 0: ";
		cin>>matriz_correcta;
	} while(matriz_correcta < 0 || matriz_correcta > 1);
}

void pedir_numero() {
	cout<<"\tDigite un numero en sistema decimal para convertirlo: ";
	cin>>numero_ingresado;
	do{
		cout<<"\tSi escribio bien el numero digite 1, si no digite 0: ";
		cin>>matriz_correcta;
	} while(matriz_correcta < 0 || matriz_correcta > 1);
}

void minijuego_numero_random(){
	int intentos = 0;
	cout<<"\tRANGO ESCOGIDO: 1 - "<<hasta<<endl;
	do {
		cout<<"\tAdivina el numero: ";
		cin>>numero_ingresado;
		if(numero_ingresado < numero_aleatorio) {
			cout<<"\tEl numero aleatorio es MAYOR"<<endl;
		}						
		else if(numero_ingresado > numero_aleatorio) {
			cout<<"\tEl numero aleatorio es MENOR"<<endl;
		}
		else if(numero_ingresado < 1 || numero_ingresado > hasta) {
			cout<<"\tEl numero ingresado no esta dentro del rango"<<endl;
			cout<<"\tEl rango escogido fue: 1 - "<<hasta<<endl;
		}
		intentos++;
		cout<<endl;
	} while(numero_ingresado != numero_aleatorio);
	cout<<"\tFELICIDADES ADIVINASTE EL NUMERO"<<endl;
	cout<<"\tCantidad de intentos: "<<intentos<<endl;
	cout<<"\tNumero aleatorio generado por la maquina: "<<numero_aleatorio<<endl;
	
}


