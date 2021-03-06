#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filavetor.h"

/*
Sistema para gerenciar uma Fila de Pessoas
 - Pessoa (Nome, Idade)
 - Enfileirar, Desenfileirar, Exibir, Tamanho
*/



int menu(){
  int opcao = 0;
  printf("\n =====> Fila de Vacinação  <=====\n");
  printf(" Escolha uma opcao\n");
  printf(" 1 - Cadastrar uma pessoa na fila \n");
  printf(" 2 - Retirar uma pessoa da fila\n");
  printf(" 3 - Exibir a fila geral\n");
  printf(" 4 - Exibir a fila da fase 1\n");
  printf(" 5 - Exibir a fila da fase 2\n");
  printf(" 6 - Exibir a fila da fase 3\n");
  printf(" 7 - Exibir a fila da fase 4\n");
  printf(" 8 - Exibir a fila da fase 5\n");
  printf(" 0 - Sair\n");
  printf(" Digite a opcao desejada:\n ");
  scanf("%d", &opcao);
  return opcao;
}

void perguntas(Pessoa *p){
  p->prioridade=5;
  int resposta=0;
  printf(" Qual seu nome:\n");
  scanf("%s", p->nome);
  printf(" Qual sua idade: \n");
  scanf("%i", &p->idade);
  while(resposta!=1 && resposta!=2){
    printf(" Você é trabalhador da Saúde ou vive em instituição de longa permanência? \n Digite: \n 1 - Sim \n 2 - Não \n");
    scanf("%i", &resposta);
  }
  if(resposta==1 || p->idade>=75){
    p->prioridade=1;
  }
  else if(p->idade>60 && p->idade<75){
    p->prioridade=2;
  }
  else{
    resposta=0;
    while(resposta!=1 && resposta!=2){
      printf(" Você possui comorbidades? \n Digite: \n 1 - Sim \n 2 - Não \n");
      scanf("%i", &resposta);
    }
    if(resposta==1){
      p->prioridade=3;
    }
    else{
      resposta=0;
      while(resposta!=1 && resposta!=2){
        printf(" Você é morador de rua, quilombola, possui deficiência, pessoa privada de liberdade ou trabalha em algum serviço considerado essencial? \nServiços Essenciais:\n- Professores\n- Forças de segurança\n- Funcionários  do Sistema prisional  \n Digite: \n 1 - Sim \n 2 - Não \n");
        scanf("%i", &resposta);
      }
      if(resposta==1){
        p->prioridade=4;
      }
      else{
        p->prioridade=5;
      }
    }
  }
}



int main(void) {

  Fila fila1;

  new_fila(&fila1);


  int op = 0;

  do{

    op = menu();

    switch(op){

      case 1:
      {
        Pessoa p;
        perguntas(&p);
        enqueue(&fila1, p);
      }
      break;

      case 2:
      {
          Pessoa p = dequeue(&fila1);
          if(p.idade==-1){
            printf("\n Fila vazia ");
          } 
          printf("\nPessoa removida: ");
          print_pessoa(p);
      }
              
      break;

      case 3:
        print_fila(&fila1);
      break;

      case 4: 
        print_fila_especifica(&fila1, 1);
      break;
      
      case 5: 
        print_fila_especifica(&fila1, 2);
      break;

      case 6: 
          print_fila_especifica(&fila1, 3);
      break;

      case 7: 
        print_fila_especifica(&fila1, 4);
      break;

      case 8: 
        print_fila_especifica(&fila1, 5);
      break;

    }

  }while(op != 0);

  return 0;
}