
#include <iostream>
#include <math.h>

using namespace std;

void inverteVetor( int *a, int tamanho){
    //Trocando os valores dos vetores
    int aux = 0;
    int x=tamanho/2; //ele troca ATÉ A METADE, EX: se tiver 21 de tamanho: troca 0 com 20 até  o 09, pois o 10 se trocaria consigo
    int lim = tamanho-1 ; //limite para que no primeiro se for 5 poisições, a primeira vá em 4-0, não em 5-0
    for (int j = 0; j < x; j++) {//x menos 1, pois se x deu 2, ele vai trocar o 0 e o 1, pq o vetor começa em 0
        aux = a[j];
        a[j] = a[lim-j];
        a[lim-j] = aux;
    }
}

int decimalBinario(int x){
    
   
    int dividendo = x;
    int i=1;
    while(dividendo >= 2){
         /*agora, o novo dividendo, será o anterior, menos o resto por 2, ex: 17/2=8, mas sobra 1, aí seria: (17-1)/2 =8*/
         dividendo = (dividendo - dividendo%2) / 2;
         
         i++;
        
    }
    
    int bin[i]; //onde vãqo ficar os binários
    
    i=0;
    
    dividendo = x;
    while(dividendo >= 2 || dividendo == 1){
        if(dividendo==1){
            bin[i]=1;
            dividendo =0;
            
        }else{
            bin[i] = dividendo%2;
            dividendo = (dividendo - dividendo%2) / 2;
            
        }
        i++;
         
    }

    int *p;//ponteiro 
    p=bin;//aponta pro vetor
    inverteVetor(p,i);//fala qual o vetor e quantos índices têm

    for (int j = 0; j < i; j++) {
        cout<<bin[j];
    }
    if(x<0){
        cout<<"Não trabalhamos com decimais negativos.";
    }
    return 0;
    
}

int binarioDecimal(int x){
    int i =x;
    int qtd=0;
    if(x%10!=0 && x%10!=1){
        cout<<"Binário é diferente de decimal.";
        return 0;
    }
    while(i!=0){
        
        if(i%2==1){
            i=(i-1)/10;
        }else{
            i/=10;
        }
        
        qtd++;
    }
    int arr[qtd];
    int vezes=0;
    i =x;
     
    while(i!=0){
        if(i%2==1){
            //assim o vetor já inverte pois começa de TRÁS PARA FRENTE
            arr[vezes] =1;
            i=(i-1)/10;
        }else{
            arr[vezes] =0;
            i/=10;
        }
        
        
        vezes++;
    }
    //JÁ TEMOS O VETOR A0 CONTRARIO, AGORA MULTIPLICAREMOS COMO FAZEMOS EM BINÁRTIO PARA DECIMAL
    int soma =0;
    for (int i = 0; i < qtd; i++) {
        soma+=arr[i]*(pow(2,i));
    }
        
    
    if(x<0){
        cout<<"NÃO EXISTE ISSO.";
        return 0;
    }
    std::cout << soma << std::endl;

    return 0;
}
    

int main()
{
    
    cout<<"Digite:"<<endl;
    cout<<"1 -> Binário para Decimal"<<endl;
    cout<<"2 -> Decimal para Binário"<<endl;
    int n,x;
    cin>>n;
    
    if(n==1){
        cout<<"Digite seu binário:";
        cin>>x;
        binarioDecimal(x);
    }else if(n==2){
        cout<<"Digite seu decimal:";
        cin>>x;
        decimalBinario(x);
    }
    
    

    return 0;
}