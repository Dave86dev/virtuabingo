//PRACTICA DE VERANO - 1 P.L.E - CURSO 2006/2007 -DAVID OCHANDO BLASCO-

#include <stdio.h>                    
#include <stdlib.h>                   
#include <string.h>      
#include <time.h>                

//!Declaracion de la Constante Tam
/*!Tam hace referencia al numero de cartones que se desea generar, en este caso 10.
*/
#define tam 10    

//!Declaracion de la Constante Tam2
/*!Tam2 hace referencia a la cantidad de numeros que compone un carton de Bingo, en este caso 15.
*/               
#define tam2 15       

//!Declaracion de la Constante Tam3
/*!Tam3 hace referencia a la cantidad de bolas que se van a extraer en la partida de Bingo, en este caso 90.
*/                    
#define tam3 90
//!Estructura carton
/*!La estructura carton almacenara los datos de los distintos cartones.*/
typedef struct carton{  
    //!Declaracion de la variable de estructura numeros[tam2] 
    /*!En el vector de tipo entero numeros[tam2] sirve para almacenar los numeros que se asignen a los cartones.
*/                 
    int numeros[tam2];                  

}carton;
//!Declaracion del vector de la estructura carton vecarton[tam]
/*!El vector de la estructura carton vecarton[tam] se encuentra declarado en la funcion main
      para poder modificar el vector de estructura vecarton[tam] en cualquier momento y poder pasarlo a las funciones
      que lo utilizen o lo modifiquen de alguna manera. 
      */
carton vecarton[tam];

//!Declaracion de la funcion menu.                      
int menu();             
//!Declaracion de la funcion de submenu destinada al diseno del interfaz del sub-menu.                                  
int submenu(carton vecarton[tam],int almacbolas2[tam3],int *empez, int *numbolsac);
//!Declaracion de la funcion de salida resexit.                  
int resexit();         
//!Declaracion de la funcion muestracar "muestra cartones".                                   
void muestracar(carton vecarton[tam],int opcionel2,int *empez,int *numbolsac);
//!Declaracion de la funcion casobingo.
void casobingo(carton vecarton[tam],int *empez);
//!Declaracion de la funcion inicializarcar "inicializar cartones".                              
void inicializarcar(carton vecarton[tam],int *empez,int *numbolsac); 
//!Declaracion de la funcion extraerbola.         
void extraerbola(carton vecarton[tam],int almacbolas2[tam3],int opcionel2,int *empez,int *numbolsac);
//!Declaracion de la funcion ganar.
void ganar(carton vecarton[tam],int almacbolas2[tam3],int opcionel2, int *empez,int *numbolsac);
//!Declaracion de la funcion guanyador.     
void guanyador(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac);
//!Declaracion de la funcion restaurar.
void restaurar(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac);
//!Declaracion de la primera funcion destinada al diseno del interfaz disseny.
void disseny();
//!Declaracion de la segunda funcion destinada al diseno del interfaz disseny2.
void disseny2();
//!Declaracion de la funcion guardarpartida.
void guardarpartida(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac);
//!Declaracion de la funcion cargarpartida.
void cargarpartida(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac);

//!Declaracion de la funcion main.
int main(){  
    /*! Funcion main "principal" en la cual se procede a la declaracion de distintos tipos de variables 
        y ejecucion de funciones*/
    
      int opcionel,bolanue,exit,exit2,comenz,bolestretes,*empez,*numbolsac; //Declaracion de variables tipo entero y punteros
                                                                            //tambien de tipo entero
      
      carton vecarton[tam];
      
      int almacbolas2[tam3];                                                                     
      
      empez=&comenz;                                                       
      *empez=0;                                                    
      
      numbolsac=&bolestretes;
      *numbolsac=0;
      
      do{ opcionel=menu();   //se invoca a la funcion menu y se guarda el contenido que devuelve en la variable "opcionel"
        switch(opcionel){    //se analiza el contenido de la variable "opcionel" ...
              
              case 1:        //en el caso de que el valor sea 1....
                do{ 
                exit2=submenu(vecarton,almacbolas2,empez,numbolsac); //se ejecuta la funcion submenu y devuelve contenido a exit2
                }while(exit2!=6);                                    //en el momento en que ese contenido sea 6 saldra de submenu
              break;                                                 //para volver a menu 
              
              case 2:       //en el caso de que el valor sea 2.....
                cargarpartida(vecarton,almacbolas2,empez,numbolsac); //se ejecuta la funcion cargarpartida para cargar el fichero
              break;                                                 //partida.txt...
              
              case 3:       //en el caso de que el valor sea 3.....
                exit=resexit();                                      //se ejecuta la funcion de salida resexit, la cual si
              break;                                                 //devuelve el valor 3 a la variable exit, hara que 
        }                                                            //se pueda salir del do while y de esa manera de la funcion
      }while(exit!=3);                                               //principal main y asi del programa
      
      system("PAUSE");
      return 1;
}            
      
int menu(){
    
    /*!Funcion menu encargada de representar el interfaz de menu de usuario del que he dispuesto a Bingo Virtual, aqui es
    donde se brinda la opcion de jugar al Bingo Virtual, Cargar una Partida o salir del programa.
    */

      int opcionel;  //Declaracion de la funcion que corresponde a la opcion elegida por el usuario en referencia a la accion
                     //que desea realizar, la funcion opcionel tambien se utiliza en la funcion princpipal main de la misma manera.
      do{
          
        system ("color 0E");
        disseny();   //funcion disseny encargada de mostrar la cabecera
        printf("      1.Jugar al Bingo Virtual            2.Cargar tu partida\n\n\n      3.Salir de Bingo Virtual\n\n\n");
        printf("      -Que accion deseas realizar? : ");
          
        scanf("%d", &opcionel);   //scanf encargado de recoger la opcion elegida por el usuario y guardarlo en "opcionel"
          
        system("cls");  //limpieza de pantalla.
          
      }while  ((opcionel<1) || (opcionel>3));   //volvera a mostar el menu mientras el usuario responda con una cifra menor a 1
                                                //o mayor a 3.
          
      return (opcionel);                        //la funcion devolvera el contenido de la variable "opcionel"
}

int submenu(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac){
    
      /*!Es la funcion encargada de representar el interfaz de submenu de usuario, desde el submenu se accede a las funciones
      sobre las que se desarrolla el juego, tales como repartir cartones, extraer una bola, mostrar los cartones, guardar
      la partida o comprobar cuanto le falta a un carton en concreto para realizar bingo.
    */
    
      int opcionel2,exit2=0;   //declaracion de las variables de tipo entero "opcionel2" y "exit2".
      
      do{
     
        disseny(); //funcion disseny encargada de mostrar la cabecera
        printf("      1.Reparte cartones                  2.Extrae una bola  \n\n\n      3.Muestra cartones de partida ");
        printf("      4.Bingo? Compruebalo aqui          \n\n\n      5.Guardar la partida\n\n\n");
        printf("      -Elige una opcion o pulsa 6 para volver al menu principal : ");
          
        scanf("%d", &opcionel2); //scanf encargado de recoger la opcion elegida por el usuario y guardarlo en "opcionel2"
          
        system("cls"); //limpieza de pantalla.
     
        switch(opcionel2){ //se analiza el contenido de la variable "opcionel2" ...
              
              case 1:
                inicializarcar(vecarton,empez,numbolsac);  //ejecucion de la funcion encargada de inicializar los cartones...
              break;
              
              case 2:
                extraerbola(vecarton,almacbolas2,opcionel2,empez,numbolsac); //ejecuta la funcion encargada de extraer una bola..
              break;
              
              case 3:
                muestracar(vecarton,opcionel2,empez,numbolsac); //ejecuta la funcion que muestra el estado de los cartones...
              break;
              
              case 4:
                casobingo(vecarton,empez); //ejecuta la funcion que comprueba cuanto le falta a un carton para realizar bingo..
              break;
              
              case 5:
                guardarpartida(vecarton,almacbolas2,empez,numbolsac); //ejecuta la funcion encargada de guardar la partida actual.
              break;
              
              case 6:
                exit2=6;  //iguala la variable exit2 a 6 para poder salir del submenu e ir de vuelta al menu principal.
                system("cls");
              break;
        }
      }while  ((opcionel2<1) || (opcionel2>6)); //volvera a mostar el menu mientras el usuario responda con una cifra menor a 1
                                                //o mayor que 6.
          
      return(exit2); //la funcion devolvera el contenido de la variable exit2, el cual si es igual a 6 hara que se salga 
}                    //de la funcion y se vuelva al menu principal

void inicializarcar(carton vecarton[tam],int *empez,int *numbolsac){
     
      /*!La funcion inicializarcar se ocupa de inicializar los cartones de Bingo Virtual, el usuario procedera
      a utilizar esta funcion eligiendo la opcion 1 en el submenu, en ese caso se generaran 10 cartones de partida
      con 15 numeros cada uno, siendo aleatorios estos y sin repetirse en un mismo carton, de esa manera se podra
      acceder posteriormente a realizar otras acciones en el juego.
    */
     
      int x,i,j,norepetir,almacbolas[tam2]; //declaracion de las variables de tipo entero x,i,j, y el vector almacbolas2[tam]
                                            //(almacen de bolas 2)...
                                            
      disseny(); //muestra la cabecera de bingo virtual
      printf("     -Estos son los nuevos cartones-\n\n"); //mensaje que anuncia que nuevos cartones han sido generados
      srand(time(NULL)); 
     
      for(i=0; i<tam; i++){                          //empiezo con 2 bucles for que van a recorrer la estructura de datos 
        printf("     -Carton %d: ",i+1);            //vecarton[i].numeros[x]
          for(x=0; x<tam2; x++){
            do{
                 
            norepetir=0;                           //igualo la variable entera "norepetir" a 0
            vecarton[i].numeros[x]=rand()%91;      //genero un numero aleatorio y lo almaceno en vecarton[i].numeros[x]
            almacbolas[x]=vecarton[i].numeros[x];  //guardo en almacbolas[x] el numero generado anteriormente que habia guardado en
                                                   //vecarton[i].numeros[x].
                                                   
            if(x>=1){                              //en el caso de que la variable x sea mayor que 1, es decir, que por lo menos se haya
              for(j=0; j<x; j++){                  //introducido un numero..se inicia un bucle for....
                if(almacbolas[j]==vecarton[i].numeros[x]){ //se compara el contenido de vecarton[i].numeros[x] con el de almacbolas[j]..recorriendo
                  norepetir=1;                     //el vector almacbolas... y si la ultima cifra generada para la estructura coincide con alguna ya generada
                }                                  //la variable norepetir se iguala a 1, haciendo que el bucle do while se repita, y se vuelva a generar otro numero
              }                                    //de esa manera evito que se generen numeros iguales a los generados anteriormente en el mismo carton!!!
            }
              
            }while ((vecarton[i].numeros[x]<1) || (vecarton[i].numeros[x]>90) || (norepetir==1)); //este while delimita que los
                                                                               //numeros generaods no sean menores a 1, mayores a 90 ni se repitan!
            printf("%d ",vecarton[i].numeros[x]);  //imprimo el numero genreado y guardado en vecarton[i].numeros[x] que no estara repetido en el mismo carton!
          }
        printf("\n"); //cambio de renglon para cambiar de carton...
      }
      
      printf("\n\n      "); //aseo...
     
      *empez=1,*numbolsac=0; //asigno el valor 1 al puntero *empez para que indique que los cartones han sido inicializados.
                             //y 0 al puntero *numbolsac porque al inicializarse cartones empieza una nueva partida y las bolas se sacan de nuevo desde 0.
      system("PAUSE");
      system("cls");
     
      return;
}

void extraerbola(carton vecarton[tam],int almacbolas2[tam3],int opcionel2, int *empez,int *numbolsac){
     
      /*!En este caso la funcion extraerbola nos va a permitir ficticiamente extraer una bola del bombo, 
      cuando se procede a ejecutar la funcion extraerbola se genera un numero aleatorio, y se muestra un
      mensaje por pantalla indicando el numero de la bola extraida, ademas se contabiliza el numero de bolas extraidas,
      no permitiendo a este en ningun caso ser superior a 90, y no permitiendo que se repita el numero de las bolas
      al extraerse, oscilando ese numero entre las cifras 1 y 90.
    */
      
      int i,x,bolas,aux2;     //declaracion de las variables de tipo entero i,x,bolas y aux2..
      
      if(*empez<=0){ //compruebo el contenido de la variable puntero *empez, si es menor o igual a 0 es porque no se
        disseny();   //han inicializado cartones, por lo tanto no se puede extraer una bola, y se advierte al usuario con un mensaje. 
        disseny2();
      }
    
      if(*empez>0){  //en el caso de que el contenido de la variable puntero *empez sea mayor a 0, es porque ya se 
                     //han iniciado los cartones, por lo tanto si se puede extraer una bola.
                              
      srand(time(NULL));
    
          do{                 
    
          aux2=0;                   //damos el valor 0 a la variable aux2
          bolas=rand()%91;          //la variable bolas adquiere la cifra generada aleatoriamente...
          almacbolas2[*numbolsac]=bolas; //guardamos el contenido de bolas, que es la cifra generada anteriormente en el 
                                  //vector almacbolas2 en la posicion pongo *numbolsac para guardar la cifra en la posicion
                                  //correspondiente al numero de bola sacada, es decir, si es la sexta bola, se guardara en la sexta posicion.
                                  
          for(i=0; i<*numbolsac; i++){    //con un bucle for voy a recorrer el vector almacbolas2[]...
            if(bolas==almacbolas2[i]){    //comparo el contenido de bolas con el de almacbolas2[i] posicion a posicion...y si son iguales..
              aux2=1;                     //a la variable aux2 le voy a dar el valor 1, lo que hara que no salga del bucle do while,por lo tanto
            }                             //es una manera de evitar que se repitan las bolas extraidas durante la partida, ya que cada bola que se saque ha de ser solo una vez.
          }
    
          }while  ((bolas<1) || (bolas>90) || (aux2==1)); //las bolas extraidas no pueden ser menores a 1, ni superiores a 90, ni repetidas..
    
          disseny(); //muestra la cabecera de bingo virtual..
          printf("     Extraccion de bolas del bombo\n\n\n");    //en este mensaje se le muestra al usuario la la cifra de la bola extraida
          printf("     La bola extraida numero %d corresponde a la cifra : %d",*numbolsac+1,bolas); //y el numero de bola que se extrae.
          printf("\n\n\n");
    
          for(i=0; i<tam; i++){                                //en esta accion se procede a recorrer la estructura de datos
            for(x=0; x<tam2; x++){                        //vecarton[i].numeros para comprobar que numeros coinciden con el numero
               if(bolas==vecarton[i].numeros[x]){         //de bola extraida.... si una bola extraida coincide con un numero de la estructura,
                  vecarton[i].numeros[x]=777;            //este numero sera substituido por la cifra 777, mas adelante, cuando haya que mostrar los cartones, 
               }                                        //cada cifra 777 sera mostrada como una X indicando que ese numero se ha tachado.
            }
          }
     
          *numbolsac=*numbolsac+1;                        //despues de extraer la bola, incrementamos el numero de bolas extraidas en 1.
          
          muestracar(vecarton,opcionel2,empez,numbolsac); //ejecucion de la funcion muestracar.. para mostrar los cartones justo debajo de la bola extraida.
          
          ganar(vecarton,almacbolas2,opcionel2,empez,numbolsac); //ejecutamos la funcion ganar para comprobar si al extraer una bola un carton logra realizar bingo.
                                                                 //siendo ese el caso, en la funcion ganar se procede a ejecutar otra funciones como guanyador
        }                                                         //encargadas de mostrar los interfaces del programa oportunos al usuario.
      
      return;
}

void muestracar(carton vecarton[tam],int opcionel2,int *empez,int *numbolsac){
     
     /*!Funcion que realiza el cometido de mostrar los 10 cartones de menor a mayor con sus respectivos 15 numeros
     ordenados de izquierda a derecha, si algun numero ha sido marcado lo muestra como una X por pantalla.
    */
    
      int x,i; //declaracion de las variables de tipo entero i e x que se utilizaran en los bucles for...
      
      if(*empez<=0){ //compruebo el contenido de la variable puntero *empez, si es menor o igual a 0 es porque no se
        disseny();   //han inicializado cartones, por lo tanto no se pueden mostrar, y se advierte al usuario con un mensaje. 
        disseny2();
      }
    
      if(*empez>0){  //en el caso de que el contenido de la variable puntero *empez sea mayor a 0, es porque ya se 
                     //han iniciado los cartones, por lo tanto si se pueden mostrar.
        if(opcionel2==3){  //compruebo si la opcion elegida era mostrar los cartones, en ese caso mostrare la cabecera antes 
          disseny();       //de mostrar los cartones, no como en el caso contrario.
        }
    
        for(i=0; i<tam; i++){                //recorro con un bucle for las posicicones "i" del vector de estructura vecarton[tam].numeros
           printf("     -Carton %d: ",i+1);  //imprimo en pantalla -Carton seguido del numero de carton correspondiente, a 
             for(x=0; x<tam2; x++){          //continuacion recorro con otro for las posiciones de "x" del vector de estructura, concretamente
               if(*numbolsac>1){             //de la variable int numeros[tam2], en el caso de que el numero de bolas extraidas sea
                 if(vecarton[i].numeros[x]==777){ //superior a 1, comprobado con el puntero *numbolsac, si en la estructura de datos
                   printf("X ");                  //existe en alguna posicion la cifra "777" significa que en esa posicion se ha tachado
                  }                               //un numero, por lo tanto cada 777 sera representado por una X "tachando" el carton.
               }
                 if(vecarton[i].numeros[x]!=777){ //Dado el caso que la cifra sea distinta a 777, es decir, que no vaya a ser tachada,
                   printf("%d ",vecarton[i].numeros[x]); //se mostrara la cifra de un modo normal.
                 }
             }
           printf("\n");    //con este "\n" consigo cambiar de linea despues de imprimir los 15 numeros de cada carton..
        }
     
        printf("\n\n      "); //printf por cuestiones de aseo..
        
       
        system("PAUSE");
        system("cls");
       
      }
    
      return;
}

void casobingo(carton vecarton[tam],int *empez){
     
      /*!La funcion casobingo tiene como principal utilidad ofrecer la posibilidad al
      usuario de saber cuantos numeros le faltan por tachar a un carton concretado por el usuario,
      se procede preguntandole que numero de carton quiere comprobar y posteriormente se le muestra
      en pantalla el numero de bolas que le faltan por tachar a dicho carton para realizar bingo.
    */
     
      int i,x,bcart,restantes=0,todascifras=0; //declaracion de variables de tipo entero.. 
     
      if(*empez<=0){ //compruebo el contenido de la variable puntero *empez, si es menor o igual a 0 es porque no se
        disseny();   //han inicializado cartones, por lo tanto no se puede consultar y se advierte al usuario con un mensaje.
        disseny2();
      }
     
      if(*empez>0){  //en el caso de que el contenido de la variable puntero *empez sea mayor a 0, es porque ya se 
                     //han iniciado los cartones, por lo tanto si se puede consultar.
     
        do{
                             
        disseny(); //funcion que muestra la cabecera de bingo virtual
        printf("     Indica el numero de carton que desees comprobar :  ");
        scanf("%d", &bcart); //recogemos el valor numerico introducido por el usuario en la variable bcart.
        printf("\n\n");
     
        }while  ((bcart<1) || (bcart>10)); //el numero introducido por el usuario no ha de ser menor a 1 ni mayor a 10
     
        for(x=0; x<tam2; x++){                        //comprobamos recorriendo el carton seleccionado por el usuario cuyo
            if(vecarton[bcart-1].numeros[x]==777){   //valor ha sido guardado en la variable bcart (-1 porque en la estructura empieza de 0..)
            todascifras=todascifras+1;               // recorriendo con un for
                                                    //las 15 posiciones (tam2) del carton .. si equivalen a 777 (X en pantalla)
            }                                      //la variable todascifras suma un numero, asi cuenta el numero de X existentes.
        }
     
        restantes=tam2-todascifras;             //para saber el numero de cifras que quedan por tachar, restamos 15 a todascifras
        printf("     ");                      //posteriormente imprimiremos un mensaje mostrando el numero de cifras por tachar.
        printf("Al carton numero %d aun le faltan tachar %d numeros para realizar bingo\n\n\n", bcart, restantes);
        printf("     ");
     
        system("PAUSE");
        system("cls");
     
      }
     
      return;
}

void guardarpartida(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac){
     
     /*!La funcion guardarpartida es la que realiza la accion de guardar los datos mas importantes que genera
     el funcionamiento y transcurso de la partida en un fichero de texto, para su posterior carga y uso.
    */

      int x,i;           //declaracion de variables x e i que necesitaremos para recorrer bucles for...
      char opcguard;     //declaracion de variable de tipo caracter opcguard donde guardaremos la opcion que introduzca
                         //el usuario.
                              
      if(*empez<=0){     //compruebo el contenido de la variable puntero *empez, si es menor o igual a 0 es porque no se
        disseny();       //han inicializado cartones, por lo tanto no se puede guardar y se advierte al usuario con un mensaje.
        disseny2();
      }
    
      if(*empez>0){      //en el caso de que el contenido de la variable puntero *empez sea mayor a 0, es porque ya se 
                         //han iniciado los cartones, por lo tanto si se puede guardar la partida.

        do{
    
          system("cls");
    
          disseny();     //muestra cabecera de bingo virtual..
          printf("\n     Deseas guardar la partida actual?? (s/n) : "); //pregunta al usuario si desea guardar la partida..
          scanf("%c", &opcguard);                                       //guardamos en la variable de caracteres opcguard
                                                                        //la opcion elegida por el usuario
        }while ((opcguard!='s') && (opcguard!='n')); //se preguntara al usuario mientras responda disinto de 's' (si) o 'n' (no)
    
        if(opcguard=='n'){      //en caso de que el usuario elija 'n' (no) como opcion no se guardara la partida y se saldra  
          system("cls");        //de la funcion.
        }
     
        if(opcguard=='s'){     //en caso de que el usuario elija 's' (si)....
                      
          FILE *fichero;       //declaracion de *fichero..
    
          fichero=fopen("partida.txt", "w");    //abrimos el fichero en modo escritura desde el principio, se va a crear
                                                //el fichero partida.txt y vamos a escribir en el.
                                                
          if(fichero==NULL){                    //en caso de que el fichero sea NULO o ocurra algun error se mostrara un mensaje
            fprintf(stderr, "No se pudo guardar la partida\n"); //que indicara que no se ha podido guardar la partida
          }else{  //en caso contrario..
            
          for(i=0; i<tam; i++){                            //recorremos la estructura con 2 bucles for y con la funcion fprintf                            
            for(x=0; x<tam2; x++){                         //escribiremos en el fichero numero a numero
             fprintf(fichero,"%d",vecarton[i].numeros[x]); //escribiremos un espacio despues de cada numero para facilitar su
             fprintf(fichero,"\n");                     //posterior carga.
             }
          }
       
          fprintf(fichero,"%d\n",*numbolsac);      //escribimos en el fichero el numero de bolas sacadas contenido en la variable
                                                   //puntero *numbolsac y hacemos \n para cambiar de linea
                                                   
          for(i=0; i<tam3; i++){                   //a continuacion escribimos en el fichero el almacén de bolas correspondiente a
            fprintf(fichero,"%d\n",almacbolas2[i]); //las bolas que ya hemos extraido o no, seran 90 cifras, una en cada linea..
          }
     
          fclose(fichero);             //cierre del fichero, asi protegeremos la info que tiene.
          system("cls");
                    
          }
        }
    
      }
     
      return;
}

void cargarpartida(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac){
     
     /*!La funcion cargarpartida es la que realiza la accion de cargar los datos que contiene el fichero 
     "partida" generado al guardar previamente una partida.
    */
    
      int x,i=0,j=0,almacargar[242]; //declaracion de variables tipo entero ademas de un vector de tipo entero donde almacenar
      char opccarg;                  //los datos que se vayan extrayendo del fichero,tambien se declara una variable de tipo 
                                     //caracter donde guardar la opcion del usuario sobre si va a cargar la partida o no. 
      do{
     
        system("cls");
        disseny(); //funcion que muestra la cabecera de bingo virtual..
        printf("\n     Deseas cargar la partida?? (s/n) : "); //preguntamos al usuario si desea cargar la partida
        scanf("%c", &opccarg);                                //guardamos en la variable de tipo caracter opccarg su respuesta.. 
    
      }while ((opccarg!='s') && (opccarg!='n'));  //..la cual no ha de ser distinta de 's' (si) o de 'n' (no) ...
                                                  
      if(opccarg=='n'){     //en caso de que el usuario elija 'n' (no) como opcion no se cargara la partida y se saldra
        system("cls");      //de la funcion
      }
    
      if(opccarg=='s'){     //en el caso de que el usuario elija 's' (si) se procedera a cargar la partida...
                       
        int todosdatos;      //declaracion de la variable de tipo entero "todosdatos" que ira recogiendo las cifras del fichero
                     
        FILE *fichero;      //declaracion de *fichero..
    
        fichero=fopen("partida.txt", "r");    //abrimos el fichero en modo lectura,, el archivo que se va a intentar abrir es
                                              //partida.txt
        
        if(fichero==NULL){   //en caso de que el fichero no existiera se mostrara este mensaje de error..
          fprintf(stderr, "\n\n     Lo sentimos pero no se pudo cargar la partida\n\n\n     ");
          system("PAUSE");   //y se procederia a salir de la funcion cargarpartida..
          system("cls");
                    //sale de la funcion....
        }else{
        
        if(fichero!=NULL){   //en caso de que el fichero si exista se empezara a leer datos de el...
          while (fscanf(fichero,"%d",&todosdatos)!=EOF){     //hacemos un bucle while con la funcion fscanf para enteros,
                                                             //y vamos guardando en la variable todosdatos el numero que lea del fichero..
          almacargar[i]=todosdatos;                          //almacenamos en la posicion i (que empieza por 0) del vector             
          i++;                                               //almacargar[i] (almacen cargar) el contenido de todosdatos, posteriormente
          }                                                  //incrementamos la variable i en 1, para asi ir incrementando las posiciones del vector donde iremos
                                                             //guardando las cifras que vayamos leyendo hasta que esten todas guardadas.
          fclose(fichero);          //cerramos el fichero para proteger la informacion que contiene.                         
        }
        
        *empez=1;    //igualamos el puntero *empez a 1 para asi al cargar la partida con los cartones, despues poder realizar
                                                  //cualquier accion del juego que necesite tener los cartones inicializados.
                                                  
        for(i=0; i<tam; i++){                    //recorremos con 2 bucles for la estructura vecarton[i].numeros[x] dandole valores
           for(x=0; x<tam2; x++){             //continuamente en funcion de i e x ademas de en funcion de j, que da valor a la posicion
                    vecarton[i].numeros[x]=almacargar[j]; //en el vector almacargar[j], incrementando cada vez j, de ese modo guardamos
                    j++;                                 //en el vector  de estructura vecarton[i].numeros[x] los numeros correspondientes
           }                                             //almacenados previamente en el vector almacargar[j].
        }
        
        *numbolsac=almacargar[j];    //guardamos en el puntero *numbolsac el contenido de almacargar[j], que en la posicion actual
        j++;                        //despues de los 2 bucles anteriores nos dara el numero de bolas sacadas en la partida guardado en la funcion guardarpartida,
                                    //posteriormente incrementamos en 1 el valor de j.
                                    
        for(i=0; i<tam3; i++){               //a continuacion recorremos con un bucle for 90 posiciones (tam3) para guardar en el vector
          almacbolas2[i]=almacargar[j];  //almacbolas2[i] el contenido de almacargar[j], lo cual nos llevara a cargar las cifras que han sido extraidas durante la partida
          j++;                 //guardada anteriormente, ..para ello incrementaremos j cada vez tambien.
        }
        
      }
      
      }
      
      system("cls");
    
      return;
}

void ganar(carton vecarton[tam],int almacbolas2[tam3],int opcionel2, int *empez,int *numbolsac){
     
     /*!La funcino ganar comprueba si alguno de los cartones consigue realizar bingo, la funcion
     ganar se ejecuta dentro de la funcion extraerbola,por lo tant cada vez que se extrae una bola
     se realiza una comprobacion para verificar si algun carton ha logrado realizar bingo, en caso de
     ser asi muestra por pantalla un mensaje indicando que se ha producido bingo y el numero de carton
     ganador.
    */
     
      int i,x,todascifras2=0;  //declaracion de las variables de tipo entero i, x y todascifras2...
     
      for(i=0; i<tam; i++){                        //realizamos 2 bucles for para recorrer la estructura de datos que contiene
         for(x=0; x<tam2; x++){                 //la informacion numerica de los cartones.
            if(vecarton[i].numeros[x]==777){       //en caso de que se encuentre una cifra con el valor 777 (tachada en el juego)
               todascifras2=todascifras2+1;      //se incrementara el valor de la varible todascifras2 en 1.
               if(todascifras2==tam2){            //si la variable todascifras2 equivale a la variable tam2(15..),...
                 disseny();                    //se muestra la cabecera de bingo virtual
                 printf("     El/los carton/es numero %d han conseguido realizar bingo!!!\n\n\n", i+1); //se muestra el mensaje
                                                                             //de carton ganador y su numero correspondiente 
                 muestracar(vecarton,opcionel2,empez,numbolsac);   //ejecucion de la funcion muestracar para mostrar los cartones                                                  
                 system("cls");   //limpieza de pantalla..
                 guanyador(vecarton,almacbolas2,empez,numbolsac);  //ejecucion de la funcion guanyador que nos llevara al interfaz
               }                                              //propio cuando un carton ha logrado bingo.. 
            }
            if(vecarton[i].numeros[x]!=777){    //en el caso de que se encontraran cifras distintas a 777 (tachado) 
               todascifras2=0;                  //se iguala la funcion todascifras2 a 0 para empezar de nuevo el recuento en el
               x=tam2;                          //siguiente carton, y se iguala x a tam2 para que x siga contando desde una posicion
                                                 //correspondiente al siguiente carton..si un carton tiene cifras distintas a 777 (X)
            }                                   //no lograra realizar bingo..
         }
      }
     
      printf("   ");
     
      return;
}

void guanyador(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac){
    
    /*!Funcion guanyador encargada de mostrar el interfaz correspondiente al usuario despues de 
     que uno de los cartones haya realizado bingo, en dicho interfaz se opta por inicializar el 
     programa, mediante la funcion restaurar que sera ejecutada en ese caso, o guardar la partida, 
     la funcion guanyador es ejecutada dentro de la funcion ganar en el caso de que alguno de los
     cartones logre realizar bingo.
    */
    
      int opcionel3,tornar=0; //declaracion de las variables de tipo entero "opcionel3" y "tornar".
      
      do{
     
        disseny();    //funcion disseny encargada de mostrar la cabecera
        printf("      1.Inicializar Bingo Virtual y volver al menu de juego  \n\n\n");        
        printf("      2.Guardar la partida  \n\n\n");
        printf("      -Elige una opcion : ");
          
        scanf("%d", &opcionel3); //scanf encargado de recoger la opcion elegida por el usuario y guardarlo en "opcionel3"
          
        system("cls");
     
        switch(opcionel3){  //se analiza el contenido de la variable "opcionel3" ...
              
              case 1:
                restaurar(vecarton,almacbolas2,empez,numbolsac); //ejecucion de la funcion restaurar...
                tornar=1;    //se le da el valor numerico 1 a la variable tornar para poder salir del do while y asi de la funcion
              break;
              
              case 2:
                guardarpartida(vecarton,almacbolas2,empez,numbolsac); //ejecucion de la funcion guardarpartida ..
                system("cls");
              break;
              
        }
          
      }while  ((opcionel3<1) || (opcionel3>2) || (tornar!=1));   //volvera a mostar las opciones mientras el numero introducido
                                                                //por el usuario sea menor que 1,mayor que 2, o la variable tornar
                                                                //sea igual a 1.
      return;
}

void restaurar(carton vecarton[tam],int almacbolas2[tam3],int *empez,int *numbolsac){ 
     
      /*!Funcion restaurar encargada de restaurar los valores de las variables numbolsac "numero de bolas sacadas" y
      empez "empezada" , ademas de iniciar a 0 todos los cartones para iniciar una nueva partida*/
      
      int i,x;   //declaracion de las variables de tipo entero i e x que se utilizaran en los bucles for...                    
     
      *numbolsac=0,*empez=0;  //Igualando los punteros a variable de tipo entero *numbolsac y *empez a 0.
     
      for(i=0; i<tam; i++){           //Utilizamos 2 bucles for para asignar el valor 0 a la estructura que contiene el valor
        for(x=0; x<tam2; x++){        //de los cartones de juego.
           vecarton[i].numeros[x]=0; //asignandolo asi de este modo conseguiremos igualar a 0 todos los valores de los cartones
        }
      }
      
      for(i=0; i<tam3; i++){        //con este bucle igualamos a 0 el valor de todo el vector almacbolas2 que sirve de 
        almacbolas2[i]=0;           //almacen de todas las bolas sacadas en la partida, cuando acabe el bucle las 90 posiciones
      }                             //del vector tendran como valor 0.
     
      disseny();   //Cabecera de diseño
      printf("     A continuacion volveras al menu de juego de Bingo Virtual\n\n\n     ");   //Imprimir mensaje que indica 
      system("PAUSE");                                                                       //la vuelta al menu de juego.
      system("cls");
     
      return;
}
     
void disseny(){  
     
     /*!
     La funcion disseny se encarga de represenar la cabecera de Bingo Virtual
         en el interfaz del programa. 
     */
     
      printf("\n     ===================================================================\n");
      printf("     =====Bingo Virtual 1.0=============================================\n");
      printf("     ===================================================================\n\n\n");
      
      return;
}

void disseny2(){  
     
     /*!
     La funcion disseny2 se encarga de recordar al usuario mediante un mensaje
     que para realizar cualquier accion en el bingo primero ha de iniciar unos cartones nuevos.
     */
     
      printf("     Para realizar cualquier accion debes inicializar cartones previamente\n\n\n     ");
    
      system("PAUSE");
      system("cls");
      
      return;
}
      
int resexit(){  

     /*!
     La funcion resexit se encarga de preguntar al usuario si realmente quiere salir de la aplicacion.
     Si su respuesta es si 's' la funcion devolvera una variable con un contenido que facilitara la salida del programa
     en la funcion principal main.
     */
    
      char opcsal;        //Declaramos una variable de tipo caracter "opcsal" donde almacenaremos la respuesta del usuario
      int eixir=0;        //Igualamos "eixir" a 0.
    
      do{                 //Con este do while preguntaremos al usuario si desea salir de la aplicacion.
    
        system("cls");  //limpieza de pantalla.
        disseny();     //funcion disseny encargada de mostrar la cabecera.
        printf("\n     Deseas salir del Bingo Virtual?? (s/n) : ");
        scanf("%c", &opcsal);           //Guardaremos la respuesta del usuario en la variable de tipo caracter "opcsal"
    
      }while ((opcsal!='s') && (opcsal!='n'));          //Si la respuesta es diferente a 's' o a 'n' volveremos a preguntarle
    
      if(opcsal=='s'){   //Al ser 's' (si) la respuesta, igualaremos "eixir" a 3, y posteriormente devolveremos el valor
        eixir=3;         //en el return de la funcion... por lo tanto se abandonara la aplicacion, se muestra la cabecera 
        system("cls");   //de salida de Bingo Virtual
        printf("\n   =====================================================================\n   ");
        printf("==Has decidido salir de Bingo Virtual.===============================\n   ");
        printf("=====================================================================\n\n\n   ");
      }
    
      if(opcsal=='n'){  //En el caso de que la respuesta sea 'n' (no).
        system("cls");
      }
    
      return(eixir);
}

//FIN DEL CÓDIGO
