#include <iostream>
using namespace std ;

int quad(int a){
  return a*a;
}

int cubo(int a){
  return a*a*a;
}

int somma(int a, int b){
  return a+b;
} 

int sotrazione(int a, int b){
  return a-b;
} 

int divisione(int a, int b){
  return a/b;
} 

int moltiplicazione(int a, int b){
  return a*b;
} 
 
int differenza(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int sommas(int quant,int(*pfun)(int)){
int somma = 0;
for(int i = 1; i <= quant; i++){
  somma += pfun(i);
}
return somma;
}

int main()
{
  
  // Prima parte del puntatore a funzione
  // dove si tenta a capire profondamente i puntatori a funzione 
  // qua abbiamo utilizzato il puntatore in modo non ortodosso
  // dove abbiamo dichiarato il puntatore ovvero un array di puntatori di tipo int 
  // in riga 60 con due parametri di tipo int 
  // così possiamo associarlo con le funzioni precedentemente dichiarata
  //per inizializzare ogni puntatore basta dare ad ogni cella una funzione compatibile riga 61;

  int a, b;

cout<<"Enter two numbers" << endl; 
cin >> a >> b ;

  int (*puntaFun[4]) (int, int);
    puntaFun[0] = somma;
    puntaFun[1] = sotrazione;  
    puntaFun[2] = divisione;
    puntaFun[3] = moltiplicazione;

cout << "choose what you'd like to do \n"
          "0-Somma \n"
          "1-Sotrazione \n"
          "2-divisione \n"
          "3-moltiplicazione \n";
          int k ;
          cin >> k;

      cout << (*puntaFun[k]) (a,b) << endl;


      // seconda parte del puntatore a funzione 
      int quant;
      cout << "Quanti numeri vorresti sommarli a quadrati ? " ; 
      cin >> quant;

      /* chiamo una funzione al posto del puntatore dove si possa chiamare multi-funzioni 
      basta che siano compatibili con i parametri della funzione stessa
      Non dobbiamo mettere nessun parametri alla funzione chiamata aposto del puntatore,
      intanto abbiamo già chiamato il puntatore col parametro precedentemente
      nella funzione che prende il puntatore come parametro
      */
    cout <<   "la somma dei primi " << quant << " numeri quadrate " << sommas(quant,quad)<< endl;
     
    cout << "Quanti numeri vorresti sommarli a cubi ? " ;
      cin >> quant;
     
       cout <<   "la somma dei primi " << quant << " numeri cubica " <<  sommas(quant,cubo) << endl;

  return 0;

}
