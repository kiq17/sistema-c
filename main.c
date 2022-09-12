/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int receitas[12];
int despesas[12]; 

int add(int n, int mes, int* array);

int listagem(int* array);

int inserirDados();
int calcularSaldo();
int menu();
int encerrar();


int receitaInput;
int despesaInput;
int mesInput;

int main()
{
    
    menu();
    
    
}


int add(int n, int mes, int* array){
    int i;
    
    if(array[mes - 1] == 0){
        array[mes - 1] = n;
    } else{
        printf("Já foi adicionado um valor nesse mês \n");
        menu();
    }
}

int listagem(int* array){
    int i;
    
    for(i=0; i < 12; i++){
        if(array[i] !=0){
           printf("%d \n", array[i]);    
        }
        
    }
}

int inserirDados(){
    
    printf("Digite a receita: \n");

    scanf("%d", &receitaInput);
    
    printf("Digite a despesa: \n");

    scanf("%d", &despesaInput);
    
    printf("Digite o numero correspondete ao mês: \n");
    
    scanf("%d", &mesInput);
    
    add(receitaInput, mesInput, receitas);
    add(despesaInput, mesInput, despesas);
    
    printf("Vetor das despesas \n");
    listagem(despesas);
    
    printf("Vetor das receitas \n");
    listagem(receitas);
    
    encerrar();
    
}

int calcularSaldo(){
    int tempo;
    int resultado;
    
    if(receitas[mesInput - 1] == 0 || despesas[mesInput - 1] == 0){
        printf("Você precisa adicionar valores  \n");
        menu();
    }
    
    printf("Digite: \n");
    printf("1 - Para visualizar o saldo por mês; \n");
    printf("2 - Para visualizar o saldo por trimestre; \n");
    printf("3 - Para visualizar o saldo do ano. \n");
    scanf("%d", &tempo);
    
    if(tempo == 1){
        resultado = receitas[mesInput] - despesas[mesInput];
        printf("Resultado: %d \n", resultado);    
        encerrar();
    } else if(tempo == 2){
        resultado = (receitas[0] + receitas[1] + receitas[2]) - (despesas[0] + despesas[1] + despesas[2]);
        printf("Resultado: %d \n", resultado);
        encerrar();
    }
    
}

int menu(){
    int opcao;
    
    printf("Digite 1 para inserir valor da receite e despesas \n");

    printf("Digite 2 para calcularSaldo \n");

    scanf("%d", &opcao);
    
    if(opcao == 1){
        inserirDados();
    } else if(opcao == 2){
        calcularSaldo();
    }
}


int encerrar(){
    int confirmacao;
    
    printf("Deseja encerar digte 1 para continuar ou 2 para encerar \n");
    scanf("%d", &confirmacao);
    
    if(confirmacao == 2){
        printf("Sitema encerrado.");
    } else if(confirmacao == 1){
        menu();
    }
}