//Proyecto Final Nicole Ribautt y Juan Jose Bermudez

#include <iostream>
#include <fstream>
#include<stdlib.h>

using namespace std;

struct fichas{        //Para que sea mas facil mover las fichas.

char blanca;
char negra;
int color;            //para identificar el tipo de ficha que hay en la posicion 1=negras, 2=blancas, 0=vacio, 4=reina blanca 5=reina negra

};
fichas tablero[8][8];

void alias (string& , string&);
void color(string&, string&);
void inicializar_tablero(fichas tablero[8][8]);
void imprimir_tablero(fichas tablero[8][8]);
void movimiento_ficha (fichas tablero[8][8]);                                 //ESTRUCTURA JUEGO
int cambiarletra (char letra);                                               //PARA DARLES UN VALOR A LAS LETRAS O SEA DARLE UN VALOR A LAS LETRAS DE ARRIBA
int cambiarnumero (int numero);
int ganador(fichas tablero [8][8]);
void reina(fichas tablero [8][8], int );                                     //SI LLEGAMOS AL FINAL SE CONVIERTE EN REINA
bool movimiento_reina(fichas tablero [8][8],int,int, int,int);               //ESTRUCTURA LOGICA REINA
void historial_partida (fichas tablero [8][8], int);

int main()
{
    cout<<"                                      Estimados caballeros , sean bienvenidos a damas chinas:"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                              El juego consta de 2 jugadores, uno tendra fichas blancas y el otro negras."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"             Podemos observar que nuestro tablero esta elaborado por filas que las representan los numeros y las columnas las letras."<<endl;
     cout<<endl;
      cout<<endl;
       cout<<endl;
        cout<<"Las reglas del juego son las siguientes:"<<endl;
        cout<<endl;
        cout<<"1: Las fichas solo se pueden mover hacia delante excepto si son reinas"<<endl;
        cout<<endl;
        cout<<"2: Las fichas solo se pueden mover a casillas adyacentes con la siguiente excepción:"<<endl;
        cout<<endl;
        cout<<"3: Si queremos realizar un movimiento a una casilla ocupada por otra ficha del rival lo puede realizar pero se come a la ficha,"<<endl;
        cout<<"y  queda  ubicada  en  la  siguiente  casilla  diagonal  libre.Si  en  esa  nueva  posicion puede matar a otra ficha se repite el proceso anterior."<<endl;
        cout<<endl;
        cout<<"4: Si hay varias piezas contrarias que pudieran ser eliminadas, se debe elegir obligatoriamente la secuencia de movimientos que maximice el numero de piezas eliminadas en total,"<<endl;
        cout<<"esto lo hace el  programa  y muestra  el  nuevo  tablero  a  los  usuarios.  Si  hay varios  movimientos  que generan la misma cantidad de fichas comidas se elegira el camino aleatoriamente."<<endl;
        cout<<endl;
        cout<<"5: SI una ficha blanca llega a la fila 10 o una ficha negra llega a la 1 se convierte en reina, lo que implica que pueda moverse diagonalmente cualquier cantidad de casillas en diagonal siempre"<<endl;
        cout<<"y cuando esten vacias las casillas de su recorrido.Sin embargo, la regla de comer fichas aplica igual."<<endl;
        cout<<endl;
        cout<<"6: el jugador que se quede sin fichas pierde"<<endl;
        cout<<endl;
        cout<<"7: No es obligatorio comer, lo que es obligatorio es que si en el movimiento se come una pieza y hay múltiples opciones decomer otras se debe hacer de acuerdo a lo explicado en el punto 4."<<endl;
        cout<<endl;
        cout<<"8: el jugador que inicia es el de las fichas blancas"<<endl;
        cout<<endl;
        cout<<"9: el programa se encargara de validar si los movimientos son correctos"<<endl;
        cout<<endl;
        cout<<"10: cada jugador tiene la oportunidad de ponerse un nombre o un apodo para decir al final quien fue el ganador"<<endl;
        cout<<endl;
         cout<<endl;
          cout<<endl;
           cout<<"A continuacion ingresaras los nombres de cada usuario"<<endl;
    string aliasj1;
    string aliasj2;
    int turno;

        alias(aliasj1,aliasj2);
        color(aliasj1,aliasj2);

        cout<<endl;
        cout<<"\n-----------------------COMIENZA EL JUEGO!-------------------------\n";

         inicializar_tablero(tablero);
         imprimir_tablero(tablero);

         //comienza el juego

         movimiento_ficha(tablero);
         historial_partida(tablero,turno);


return 0;

}
void alias (string& aliasj1, string& aliasj2){
	cout << " Alias del primer jugador:  "<<endl;
	cin >> aliasj1;

	cout << " Alias del segundo jugador:  "<<endl;
	cin >> aliasj2;
}

void color(string& aliasj1, string& aliasj2){
fichas color;
color.blanca=2;
color.negra=1;
    cout << aliasj1<<"  Usted es blancas"<<endl;
    cout << aliasj2<<"  Usted es negras"<<endl;

        cout<<endl;

	cout<<"EMPIEZAN LAS BLANCAS!...."<<color.blanca<<endl;

}

void inicializar_tablero(fichas tablero [8][8]){

    int i, j;

    for (j=0;j<8;j++) {
            if (j%2==0){
        tablero[0][j].negra = 1;                                //con estas variables numericos controlamos que simbolo se crea, no importa si es .negra o .blanco
        tablero[0][j].color = 1;
        tablero[1][j].color = 0;
        tablero[2][j].negra = 1;
        tablero[2][j].color = 1;
            }else{
                tablero[1][j].negra = 1;
                 tablero[1][j].color = 1;
                tablero[0][j].color = 0;
                tablero[2][j].color = 0;
              }
        for (i = 3; i < 5; ++i){
            tablero[i][j].color = 0;
       if (j%2==0){
        tablero[6][j].blanca =2;
        tablero[6][j].color = 2;
        tablero[7][j].color = 0;
        tablero[5][j].color = 0;
            }else{
                tablero[7][j].blanca = 2;
                tablero[7][j].color = 2;
                tablero[6][j].color = 0;
                tablero[5][j].blanca = 2;
                tablero[5][j].color = 2;
              }
        }
    }
}

void imprimir_tablero(fichas tablero [8][8]) {
    int i, j;
    char a [8] = {'A','B','C','D','E','F','G','H'};

    cout<<endl;

    for (int k=0;k<8;k++){
        cout<<"   "<<a[k]<<"    ";
    }

    cout<<endl;

     for (int l=0; l<8; l++){
         cout<<" -------";
  	  }

    cout<<endl;

       for (j=0; j<8; j++){

        for (i=0; i<8; i++){

           cout<<"   "<<tablero[j][i].blanca<<tablero[j][i].negra<<"  |";
        }

  	 cout<<" "<<8-j;
  	 cout<<endl;

  	  for (int m=0; m<8; m++){
         cout<<" -------";
  	  }
  	  cout<<endl;
	}
}

int cambiarletra (char letra){
    int letter=0;       //CAMBIAR DE LETRA A NUMERO PARA GUIARNOS SEGUN LOS SUBINDICES DE LA MATRIZ
switch (letra){
    case 'A':
    letter=0;              //LETRAS=COLUMNA
    return letter;
    break;
case 'a':
    letter=0;
    return letter;
break;                                          //

     case 'B':
    letter=1;
    return letter;
    break;
case 'b':
    letter=1;
    return letter;
break;

     case 'C':
    letter=2;
    return letter;
    break;
case 'c':
    letter=2;
    return letter;
    break;


     case 'D':
    letter=3;
    return letter;
    break;
case 'd':
    letter=3;
    return letter;
    break;


     case 'E':
    letter=4;
    return letter;
    break;
case 'e':
    letter=4;
    return letter;
    break;


     case 'F':
    letter=5;
    return letter;
    break;
case 'f':
    letter=5;
    return letter;
    break;

    case 'G':
    letter=6;
    return letter;
    break;
case 'g':
    letter=6;
    return letter;
    break;

     case 'H':
    letter=7;
    return letter;
    break;
case 'h':
    letter=7;
    return letter;
    break;

    default:
    cout<<"ERROR Logico"<<endl;
    return 0;

}
}

int cambiarnumero (int numero){
int number=0;
switch (numero){            //ES PARA NO CONFUNDIR EL CODIGO SABIENDO QUE LA MATRIZ EMPIEZA DE 0 EN ADELANTE PERO EN EL EJEMPLO ES DE 8 DE FORMA DECRECIENTE.
    case 1:
    number=7;
    return number;
    break;

     case 2:
    number=6;
    return  number;
    break;

     case 3:
     number=5;
    return  number;
    break;

     case 4:
     number=4;
    return  number;
 break;

  case 5:
     number=3;
    return  number;
 break;

  case 6:
     number=2;
    return  number;
 break;

  case 7:
     number=1;
    return  number;
 break;

  case 8:
     number=0;
    return  number;
 break;

 default:
    cout<<"ERROR Logico"<<endl;
    return 0;
}
}

void reina(fichas tablero [8][8], int jugador){


if (jugador==1){


for(int i =0;i<8;i++){
        if(tablero[0][i].color== 2 || tablero[0][i].blanca== 2){
    tablero[0][i].blanca= 4;                                            //CAMBIA DE FIGURA Y SE VUELVE REINA LA FICHA BLANCA
    tablero[0][i].color= 4;
        }
}

}

if(jugador==2){
    for(int i =0;i<8;i++){
            if(tablero[7][i].negra== 1 || tablero[7][i].color== 1){
    tablero[7][i].negra= 5;
    tablero[7][i].color= 5;
            }
}
}







}

bool movimiento_reina(fichas tablero [8][8],int afila_num,int defila_num, int acolumna_num,int decolumna_num){
    bool x=true;
    if ( (afila_num>defila_num) && (acolumna_num>decolumna_num))
    {
        for (int i=defila_num+1, j=decolumna_num+1; i<afila_num; i++, j=j+1 )
        {
            if (tablero [i][j].color!=0){
                x=false;                        //VER SI EL MOVIMIENTO DE LA REINA ES LEGAL, SABIENDO QUE LA REINA SE PUEDE MOVER MUCHAS CASILLAS.
                return x;}
        }
    }
        if ( (afila_num>defila_num) && (acolumna_num<decolumna_num))
    {
        for (int i=defila_num+1,  j=decolumna_num-1; i<afila_num; i++, j=j-1 )
        {
            if (tablero [i][j].color!=0){
                x=false;
                return x;}
        }
    }
        if ( (afila_num<defila_num) && (acolumna_num<decolumna_num))
    {
        for (int i=defila_num-1,  j=decolumna_num-1; i>afila_num; i--, j=j-1 )
        {
            if (tablero [i][j].color!=0){
                x=false;
                return x;}
        }
    }
        if ( (afila_num<defila_num) && (acolumna_num>decolumna_num))
    {
        for (int i=defila_num-1,  j=decolumna_num+1; i>afila_num; i--, j=j+1 )
        {
            if (tablero [i][j].color!=0){
                x=false;
                return x;}
        }
    }
    return x;
}

int ganador(fichas tablero [8][8]){

 string gana;
 int piezasUno=0;
 int piezasDos=0;
 int bandera=0;

  for(int i=0;i<8;i++)
  {

    for(int j=0;j<8;j++){
            if(tablero[i][j].color==2){
                piezasUno++;
            }
        }
      }


       for(int i=0;i<8;i++)
  {

      for(int j=0;j<8;j++){
            if(tablero[i][j].color==1){          //revisa cuantas piezas quedan del jugador 2
                piezasDos++;
            }
        }
      }


 if (piezasUno==0)        //revisa quien gano
        {
              cout<<"El ganador es el Jugador 2"<<endl;
              return 0;
        }
  if (piezasDos==0)
  {

     cout<<"El ganador es el Jugador 1"<<endl;
     return 0;
  }

bandera=1;
return bandera;



  }

void movimiento_ficha(fichas tablero [8][8])  {


    int turnos=0, jugador=0,tmp=0, puede=0;  //TURNO=CONTADOR TURNOS PARA SABER QUIENES VA, JUGADOR= CONTADOR PARA IDENTIFICAR QUE JUGADOR SON, TMP=PARA GUARDAR CUANDO COME Y SE MUEVE, PUEDE= PARA IDENTIFICAR SI PUEDE O NO.
    int defila,afila; //DEFILA=LA QUE SELECCIONAMOS Y AFILA=DONDE QUEREMOS LLEGAR
    int defila_num,afila_num,decolumna_num,acolumna_num; //DEFILANUM=GUARDAR VALOR DE LA FUNCION
    char decolumna, acolumna, tpm2; //TMP=GUARDAMOS SI ES BLANCA O NEGRA PARA MOVERLO
    int pruebas=0;
    int bandera=0;
    bool seleccion=false, comer1 = true, reinaD; //SELECCION=VERIFICA MOVIMIENTO Y ELECCION VALIDO, REINAD,FUNCION MVIMIENTO REINA , ACA GUARDAMOS SI EL MOVIMIENTO ES LEGAL

    do
    {
        if(turnos%2==0)
        {
         jugador=1;  //REPETIMOS MIENTRAS QUE NO HAYA UN GANADOR , RECORRIDO DEL JUEGO

        }else{
            jugador=2;
        }

    cout<<"turno jugador"<<jugador<<endl;

    do { //do while para asegurar que se mueva segun las restricciones
        seleccion=false;

        cout<<"¿Que ficha deseas mover y a donde? (recuerde que solo se puede mover diagonalmente y dependiendo de su color, o si selecciona una reina, hacia arriba o hacia abajo)"<<endl;
        cout<<"ej.((B 4 C 5 ) '\n'  B = fila en la que esta la ficha   '\n' 4= columna en la que esta la ficha  '\n'  C = fila a la que te quieres mover '\n' 5= columna a la que te quieres mover" << endl;
        cin>>decolumna; cin>>defila; cin>>acolumna; cin>>afila;


    decolumna_num= cambiarletra(decolumna);   //revisar si hay o no la ficha en ese espacio
    acolumna_num = cambiarletra (acolumna);

    defila_num=cambiarnumero(defila);
    afila_num =cambiarnumero (afila);

reina(tablero, jugador);

if ((tablero[defila_num][decolumna_num].color==4 && jugador==1)||(tablero[defila_num][decolumna_num].color==5 && jugador==2)){
if((tablero[afila_num][acolumna_num].color !=2 && jugador==1)||(tablero[afila_num][acolumna_num].color !=1 && jugador==2)){ //asegurar que no pueda ir a una de su mismo color
if ((afila_num != defila_num)&&(acolumna_num!=decolumna_num)){ //condicionales para asegurar que vaya en diagonal

    reinaD = movimiento_reina( tablero , afila_num, defila_num, acolumna_num, decolumna_num);//funcion para indicar si su treyecto si es legal
    if (reinaD==true){
        seleccion=true;
        if(tablero[afila_num][acolumna_num].color==0){ //el 0 representa que si hay o no hay una ficha  en ese espacio

            if (jugador==1){
            tmp= tablero[defila_num][decolumna_num].color;
            tpm2=tablero[defila_num][decolumna_num].blanca;
            tablero[defila_num][decolumna_num].color=0;
            tablero[defila_num][decolumna_num].blanca=' ';  //se vacia el espacio en el que estaba
            tablero[afila_num][acolumna_num].color =tmp;
            tablero[afila_num][acolumna_num].blanca =tpm2;
            }//actualizamos con el nuevo dato

            if (jugador==2){
            tmp= tablero[defila_num][decolumna_num].color;
            tpm2=tablero[defila_num][decolumna_num].negra;
            tablero[defila_num][decolumna_num].color=0;  //MOVER CASILLA VACIA.
            tablero[defila_num][decolumna_num].negra=' ';
            tablero[afila_num][acolumna_num].color =tmp;
            tablero[afila_num][acolumna_num].negra =tpm2;
            }
        }

//Para comer y mover la ficha si es blanca
if(jugador==1){
    if((tablero[afila_num][acolumna_num].color==1 || tablero[afila_num][acolumna_num].color==5) && ((tablero[afila_num-1][acolumna_num-1].color==0)||(tablero[afila_num-1][acolumna_num+1].color==0)||(tablero[afila_num+1][acolumna_num-1].color==0)||(tablero[afila_num+1][acolumna_num+1].color==0)))
    {// si hay una ficha en este espacio se la borra
    tmp = tablero[defila_num][decolumna_num].color;
    tpm2=tablero[defila_num][decolumna_num].blanca;

    if (decolumna_num+1==acolumna_num && defila_num-1 == afila_num)
        {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].blanca=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].negra =' ';
        tablero[afila_num-1][acolumna_num+1].color =tmp;
        tablero[afila_num-1][acolumna_num+1].blanca =tpm2;
        }//se come la ficha negra y se mueve a la siguiente vacia en diagonal

    if (decolumna_num-1==acolumna_num && defila_num-1 == afila_num)
      {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].blanca=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].negra =' ';
        tablero[afila_num-1][acolumna_num-1].color =tmp;
        tablero[afila_num-1][acolumna_num-1].blanca =tpm2;
        }

    if (decolumna_num+1==acolumna_num && defila_num+1==afila_num  )
        {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].blanca=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].negra =' ';
        tablero[afila_num+1][acolumna_num+1].color =tmp;
        tablero[afila_num+1][acolumna_num+1].blanca =tpm2;}

    if (decolumna_num-1==acolumna_num && defila_num+1==afila_num)
      {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].blanca=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].negra =' ';
        tablero[afila_num+1][acolumna_num-1].color =tmp;
        tablero[afila_num+1][acolumna_num-1].blanca =tpm2;
      }
    }
}

//Para comer y mover la ficha si es negra
if(jugador==2){
    if((tablero[afila_num][acolumna_num].color==2||tablero[afila_num][acolumna_num].color==4) && ((tablero[afila_num-1][acolumna_num-1].color==0)||(tablero[afila_num-1][acolumna_num+1].color==0)||(tablero[afila_num+1][acolumna_num-1].color==0)||(tablero[afila_num+1][acolumna_num+1].color==0)))
    {
    tmp= tablero[defila_num][decolumna_num].color;
    tpm2=tablero[defila_num][decolumna_num].blanca;

    if (decolumna_num+1==acolumna_num && defila_num-1 == afila_num)
        {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num-1][acolumna_num+1].color =tmp;
        tablero[afila_num-1][acolumna_num+1].negra =tpm2;
        }//se come la ficha blanca y se mueve a la siguiente vacia en diagonal

    if (decolumna_num-1==acolumna_num && defila_num-1 == afila_num)
      {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num-1][acolumna_num-1].color =tmp;
        tablero[afila_num-1][acolumna_num-1].negra =tpm2;}

    if (decolumna_num+1==acolumna_num && defila_num+1==afila_num)
        {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num+1][acolumna_num+1].color =tmp;
        tablero[afila_num+1][acolumna_num+1].negra =tpm2;
        }

    if (decolumna_num-1==acolumna_num && defila_num+1==afila_num)
      {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num+1][acolumna_num-1].color =tmp;
        tablero[afila_num+1][acolumna_num-1].negra =tpm2;
        }
    }
}

// FINALIZA EL CODIGO DE LA REINA.

imprimir_tablero(tablero);
} //IMPRESION TABLERO CON LA REINAS
    else{
    seleccion=false;}        //SI NO CUMPLE LOS REQUISITOS SE REPITE A DONDE QUIERE LLEGAR
} // cierra el tercer <<IF ((afila_num != defila_num)&&(acolumna_num!=decolumna_num))>>
} // cierra el segundo << IF ((tablero[afila_num][acolumna_num].color !=2 && jugador==1)||(tablero[afila_num][acolumna_num].color !=1 && jugador==2)) >>
    else{
        seleccion = false;
        cout<<"movimiento invalido"<<endl;
        }
} //Cierra el primer << IF if ((tablero[defila_num][decolumna_num].color==4 && jugador==1)||(tablero[defila_num][decolumna_num].color==5 && jugador==2))>>

//crear solo restricciones diagonales
//INICIA CONDICIONES FICHAS NORMAL

if((tablero[defila_num][decolumna_num].color != 4 && tablero[defila_num][decolumna_num].color != 5)&&(tablero[defila_num][decolumna_num].color==1 && jugador==2)||(tablero[defila_num][decolumna_num].color==2 && jugador==1))
{
if(((defila_num-1==afila_num)&&(decolumna_num-1==acolumna_num || decolumna_num+1==acolumna_num) && jugador==1)||((defila_num+1==afila_num)&&(decolumna_num-1==acolumna_num || decolumna_num+1==acolumna_num) && jugador==2))
{//condicional para asegurar que vaya en diagonal y arriba o hacia abajo dependiendo del color
if((tablero[afila_num][acolumna_num].color==0)||(tablero[afila_num][acolumna_num].color==1 && jugador==1)||(tablero[afila_num][acolumna_num].color==2 && jugador==2))
{
    seleccion=true;

if(tablero[afila_num][acolumna_num].color==0){ //el 0 representa que si hay o no hay una ficha  en ese espacio

    if (jugador==1){ //PRIMEROS 3 CONDICIONALES SON PARA EVALUAR SI SE PUEDE MOVER HACIA ARRIBA O BAJO DEPENDIENDO EL COLOR.
    tmp= tablero[defila_num][decolumna_num].color;
    tpm2=tablero[defila_num][decolumna_num].blanca;
    tablero[defila_num][decolumna_num].color=0;
    tablero[defila_num][decolumna_num].blanca=' ';                                        //se vacia el espacio en el que estaba
    tablero[afila_num][acolumna_num].color =tmp;
    tablero[afila_num][acolumna_num].blanca =tpm2;
    }   //actualizamos con el nuevo dato

    if (jugador==2){
    tmp= tablero[defila_num][decolumna_num].color;
    tpm2=tablero[defila_num][decolumna_num].negra;
    tablero[defila_num][decolumna_num].color=0;
    tablero[defila_num][decolumna_num].negra=' ';
    tablero[afila_num][acolumna_num].color =tmp;
    tablero[afila_num][acolumna_num].negra =tpm2;
    }
}
 //LOS DOS IF DE ARRIBA SON PARA MOVERSE

if(jugador==1){

    if((tablero[afila_num][acolumna_num].color==1||tablero[afila_num][acolumna_num].color==5) && ((tablero[afila_num-1][acolumna_num-1].color==0)||(tablero[afila_num-1][acolumna_num+1].color==0)))
    { // si hay una ficha en este espacio se la borra
      tmp= tablero[defila_num][decolumna_num].color;
      tpm2=tablero[defila_num][decolumna_num].blanca;

        if (decolumna_num+1==acolumna_num)
            {

            tablero[defila_num][decolumna_num].color=0;
            tablero[defila_num][decolumna_num].blanca=' ';
            tablero[afila_num][acolumna_num].color =0;
            tablero[afila_num][acolumna_num].negra =' ';
            tablero[afila_num-1][acolumna_num+1].color =tmp;
            tablero[afila_num-1][acolumna_num+1].blanca =tpm2;
            }//se come la ficha negra y se mueve a la siguiente vacia en diagonal

        if (decolumna_num-1==acolumna_num)
          {
            tablero[defila_num][decolumna_num].color=0;
            tablero[defila_num][decolumna_num].blanca=' ';
            tablero[afila_num][acolumna_num].color =0;
            tablero[afila_num][acolumna_num].negra =' ';
            tablero[afila_num-1][acolumna_num-1].color =tmp;
            tablero[afila_num-1][acolumna_num-1].blanca =tpm2;
          }
    }
}

if(jugador==2){

 if((tablero[afila_num][acolumna_num].color==2||tablero[afila_num][acolumna_num].color==4) && ((tablero[afila_num+1][acolumna_num-1].color==0)||(tablero[afila_num+1][acolumna_num+1].color==0)))
    {
    tmp= tablero[defila_num][decolumna_num].color;
    tpm2=tablero[defila_num][decolumna_num].negra;

    if (decolumna_num+1==acolumna_num)
        {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num+1][acolumna_num+1].color =tmp;
        tablero[afila_num+1][acolumna_num+1].negra =tpm2;}
    if (decolumna_num-1==acolumna_num)
      {
        tablero[defila_num][decolumna_num].color=0;
        tablero[defila_num][decolumna_num].negra=' ';
        tablero[afila_num][acolumna_num].color =0;
        tablero[afila_num][acolumna_num].blanca =' ';
        tablero[afila_num+1][acolumna_num-1].color =tmp;
        tablero[afila_num+1][acolumna_num-1].negra =tpm2;
      }
    }
}

 imprimir_tablero(tablero);
} // cierre del tercer if
} // cierre del segundo if

    else{
        cout<<"Movimiento invalido vuelva a intentar"<<endl;
        }

}// cierre del primer if

}while(seleccion==false); // cierre del segundo do while--SOLO PARA VER SI LA FICHA ELEGIDA Y DONDE SE QUIERE MOVER ES LEGAL
   bandera = ganador(tablero);
   turnos++;

 if ((turnos==1)&&(turnos%5==0)){ //para que se imprima en el archivo.
    historial_partida(tablero,turnos);
 }

 }while(bandera==1);//REPETIR JUEGO HASTA QUE HAYA UN GANADOR.
}

void historial_partida (fichas tablero [8][8], int turnos){

    ofstream historial;
    int i, j;
    char a [8] = {'A','B','C','D','E','F','G','H'};

    historial.open ("historial.txt",ios::out | ios::app); //abriendo el archivo

    if (!historial){

        cout<<"No se pudo abrir el historial del juego";
        exit (1);

    }else{

    for (int k=0;k<8;k++){
        historial<<"   "<<a[k]<<"    ";
    }

    historial<<endl;

     for (int l=0; l<8; l++){
         historial<<" -------";
  	  }

    historial<<endl;

       for (j=0; j<8; j++){

        for (i=0; i<8; i++){

           historial<<"   "<<tablero[j][i].blanca<<tablero[j][i].negra<<"  |";
        }

  	 historial<<" "<<8-j;
  	 historial<<endl;

  	  for (int m=0; m<8; m++){
         historial<<" -------";
  	  }
  	  historial<<endl;
       }
    }

    historial<<ganador (tablero);

    historial.close();//cerrar archivo
}
