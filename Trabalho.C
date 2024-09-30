// ALUNOS : BIANCA e EDUARDO G.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");
  system("cls");
  int ValAposta = 1;
  int Carteira = 0, DadoUm = 0, DadoDois = 0, RandomUm = 0, RandomDois = 0, SomaDadosP = 0, SomaDadosC = 0, ParidadeP = 0, ParidadeC = 0, VezesJogadas = 0, Ganho = 0, Saldo = 0, DadoMaisRepetido = 0, Derrotas = 0, Multiplicador = 0, Perda = 0, Verificador = 0, MaiorAposta = 0, MaiorValorGanho = 0;
  int Con;
  char Lance;

  printf("---------------------------------\n");
  printf("         JOGO DE DADOS\n");
  printf("  Alunos: Bianca S. & Eduardo G.\n");
  printf("---------------------------------\n");
  Sleep(2000);
  system("cls");

  while (Verificador == 0)
  {
    printf("----------------------------------------------\n");
    printf("           BEM VINDO AO NOSSO CASSINO         \n");
    printf("          ~(sua perda, nossa alegria)~        \n");
    printf("----------------------------------------------\n");
    printf(" * Digite '1' Para Inserir Saldo  *           \n");
    printf(" * Digite '2' Para Iniciar o Jogo *           \n");
    printf(" * Digite '3' Para Ler as Regras  *           \n");
    printf("----------------------------------------------\n");
    printf("R: ");
    scanf("%d", &Verificador);
    while (Verificador != 1 && Verificador != 2 && Verificador != 3)
    {
      printf("Opcao Invalida.\n");
      printf(" * Digite '1' Para Iniciar o Jogo • \n");
      printf(" * Digite '2' Para Ler as Regras  •\n");
      printf("R: ");
      scanf("%d", &Verificador);
    }
    if (Verificador == 2)
    {
      system("cls");
      for(Con=0; Con <=2; Con +=1){ 
        printf("Entendido! Iniciando o Jogo");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        system("cls");
      }

      break;
    }
    else if (Verificador == 3)
    {
      system("cls");
      printf("-----------------------------------------------------------------------------------------------------------------------------\n");
      printf("                                              ======= Regras do Jogo ========                                                \n");
      printf("                                                                                                                             \n");
      printf("                        1. O jogador deve acessar a carteira e adicionar todo o dinheiro que ira apostar conforme o jogo.    \n");
      printf("                        2. O jogador deve iniciar o jogo e escolher dois numeros de 1 a 6.                                   \n");
      printf("                        3. O croupier (Condutor da Jogatina) lanca dois dados tambem.                                        \n");
      printf("                        4. As Vitorias sao:                                                                                  \n");
      printf("                            * Acertar os dois numeros exatos. (Ganha 6 vezes o valor apostado)                               \n");
      printf("                            * Acertar a soma dos dois dados.  (Ganha 3 vezes o valor apostado)                               \n");
      printf("                            * Acertar apenas um dos numeros.  (Ganha o valor apostado de volta)                              \n");
      printf("                            * Acertar a paridade da soma do palpite e dados. (ganha metade da aposta)                        \n");
      printf("                        5. Caso nao ocorra nenhuma das anteriores, o jogador perde o valor apostado.                         \n");
      printf("                                                                                                                             \n");
      printf("                                                                                                                             \n");
      printf("                                        * Quando quiser voltar ao menu, digite '0'.                                          \n");
      printf("-----------------------------------------------------------------------------------------------------------------------------\n");
      printf("R: ");
      scanf("%d", &Verificador);
      system("cls");
    }
    else if(Verificador == 1){
      system("cls");
      printf("----------------------------------------------\n");
      printf("Digite o valor que deseja inserir na carteira\n");
      printf("----------------------------------------------\n");
      printf("R: ");
      scanf("%d", &Carteira);
      Saldo += Carteira;
      printf("----------------------------------------------\n");
      printf("Saldo Atual: R$%d,00 \n", Saldo);
      printf("Digite '0' para voltar ao menu: ");
      scanf("%d", &Verificador);
      system("cls");
    }
    else
    {
      printf("Erro de scanf! Verificar no codigo...");
    }
  }

  srand(time(NULL));

  while (ValAposta >= 1)
  { 
    VezesJogadas += 1;
    printf("\n-------------------------------------------------\n");
    printf("                    Jogo %d                      \n", VezesJogadas);
    printf("-------------------------------------------------\n");
    printf("\nDigite o Valor que Voce Gostaria de Apostar: ");
    scanf("%d", &ValAposta);
    while (ValAposta > Saldo)
    {
      printf("-------------------------------------------------\n");
      printf("Voce Nao Possui Saldo Suficiente Para Essa Aposta. Porfavor Insira Um Valor Menor Ou Igual ao Seu Dinheiro Atual: R$%d,00 \nR: ", Saldo);
      scanf("%d", &ValAposta);
    }
    if(MaiorAposta < ValAposta){
      MaiorAposta = ValAposta;
    }
    Saldo -= ValAposta;
    

    if (ValAposta >= 1)
    {
      printf("Escolha o Valor do Primeiro Dado (Lembrando que isso varia de 1 a 6): ");
      scanf("%d", &DadoUm);
      while (DadoUm <= 0 || DadoUm >= 7)
      {
        printf("Valor incorreto. Insira um numero de 1 a 6. R: ");
        scanf("%d", &DadoUm);
      }
      printf("Escolha o Valor do Segundo Dado: ");
      scanf("%d", &DadoDois);
      while (DadoDois <= 0 || DadoDois >= 7)
      {
        printf("Valor incorreto. Insira um numero de 1 a 6: ");
        scanf("%d", &DadoDois);
      }
      printf("Quando quiser, digite a letra 'C' para que o croupier lance os dados: ");
      scanf(" %c", &Lance);
      while (Lance != 'c' && Lance != 'C')
      {
        printf("Erro... Porfavor insira c ou C: ");
        scanf(" %c", &Lance);
      }

      RandomUm = rand() % 6 + 1;
      RandomDois = rand() % 6 + 1;

      printf("Os valores dos dados aleatorios foram: %d e %d \n", RandomUm, RandomDois);

      SomaDadosP = DadoUm + DadoDois;
      SomaDadosC = RandomUm + RandomDois;
      ParidadeC = SomaDadosC % 2;
      ParidadeP = SomaDadosP % 2;

      if (DadoUm == RandomUm && DadoDois == RandomDois)
      {
        Multiplicador = 6;
        Ganho = ValAposta * Multiplicador;
        if( Ganho > MaiorValorGanho){
        MaiorValorGanho = Ganho;
        }
        Saldo += Ganho;
        Sleep(1500);
        printf("Parabens! Voce Conseguiu o Premio Maximo Acertando Ambos os Dados!(6x).\n");
        Sleep(1500);
        printf("Voce Ganhou R$%d,00 \n", Ganho);
        Sleep(1500);
        printf("Seu Saldo Atual e de R$%d,00 \n", Saldo);
        Sleep(1500);
        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
      else if (DadoUm == RandomDois && DadoDois == RandomUm)
      {
        Multiplicador = 6;
        Ganho = ValAposta * Multiplicador;
        if( Ganho > MaiorValorGanho){
        MaiorValorGanho = Ganho;
        }
        Saldo += Ganho;
        Sleep(1500);
        printf("Parabens! Voce Conseguiu o Premio Maximo Acertando Ambos os Dados!(6x).\n");
        Sleep(1500);
        printf("Voce Ganhou R$%d,00 \n", Ganho);
        Sleep(1500);
        printf("Seu Saldo Atual e de R$%d,00 \n", Saldo);
        Sleep(1500);
        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
      else if (DadoUm == RandomUm || DadoDois == RandomDois || DadoUm == RandomDois || DadoDois == RandomUm)
      {
        Multiplicador = 1;
        Ganho = ValAposta * Multiplicador;
        if( Ganho > MaiorValorGanho){
        MaiorValorGanho = Ganho;
        }
        Saldo += Ganho;
        Sleep(1500);
        printf("Voce Acertou um dos Dados!(1x).\n");
        Sleep(1500);
        printf("Manteve o valor apostado R$%d,00 \n", Ganho);
        Sleep(1500);
        printf("Seu Saldo Atual Continua Em R$%d,00 \n", Saldo);
        Sleep(1500);
        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
      else if (SomaDadosC == SomaDadosP)
      {
        Multiplicador = 3;
        Ganho = ValAposta * Multiplicador;
        if( Ganho > MaiorValorGanho){
        MaiorValorGanho = Ganho;
        }
        Saldo += Ganho;
        Sleep(1500);
        printf("Voce Ganhou Acertando a Soma dos Dados!(3x).\n");
        Sleep(1500);
        printf("Ganhou R$%d,00 \n", Ganho);
        Sleep(1500);
        printf("Seu Saldo Atual e de R$%d,00 \n", Saldo);
        Sleep(1500);
        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
      else if (ParidadeC == ParidadeP)
      {
        Ganho = ValAposta/2;
        if( Ganho > MaiorValorGanho){
          MaiorValorGanho = Ganho;
        }
        Saldo += Ganho;
        Sleep(1500);
        printf("Voce Acertou a Paridade dos Dados!(0.5x).\n");
        Sleep(1500);
        printf("Ganhou Metade Do Valor Apostado: R$%d,00 \n", Ganho);
        Sleep(1500);
        printf("Seu Saldo Atual e de R$%d,00 \n", Saldo);
        Sleep(1500);
        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
      else
      {
        Multiplicador = 0;
        Perda = ValAposta;
        Derrotas ++;
        Sleep(1500);
        printf("Voce Nao Acertou Nada..\n");
        Sleep(1500);
        printf("Voce Perdeu Os R$%d,00 Apostados\n", Perda);
        Sleep(1500);
        printf("Seu Saldo Atual e de R$%d,00 \n", Saldo);
        Sleep(1500);
        if (ValAposta <= 0) 
         {
           printf("Valor invalido inserido! \n");
           printf("Encerrando...");
           break;
         }
        else if(Saldo == 0)
        {
           printf("Saldo = %d", Saldo);
           printf("Sinto Muito, Voce Perdeu Todo o Seu Dinheiro Conosco (MUAHAHAHAHA)");
           Sleep(1500);
           printf("YOU ARE A LOSER ");
           Sleep(6000);
           system("cls");
           break;
         }

        printf("\n *Caso Queira Encerrar a Jogatina Digite '0' no Proximo Valor de Aposta* \n");
        Sleep(2000);
      }
     
   }
    
    
    
  }
//  system("cls");
  printf("\n--------- O Resumo do seu Jogo Foi -----------\n");
  VezesJogadas -= 1;
  printf("\nO jogador jogou %d vez(es).", VezesJogadas);
  printf("\nO saldo final foi de %d reais.", Saldo);
  printf("\nO valor do dado que mais saiu foi %d.", DadoMaisRepetido);
  printf("\nO maior valor ganho em uma jogada foi R$%d", MaiorValorGanho);
  printf("\nA maior aposta do jogador foi R$%d,00", MaiorAposta);
  printf("\n----------------------------------------------\n");
  printf("\n------------- Obrigado Por Jogar ------------- ");
  Sleep(10000);

  return 0;
}