// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente
// entre dois valores mínimo e máximo e retorna esse valor

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

//EXERCÍCIO 1'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''{
float percentage(float esc, float max, float min) {
  float result = 0;
  float sub1 = esc - min;
  float sub2 = max - min;

  result = 100 * (sub1 / sub2);
  return result;
}


//2 - Faça uma função que recebe um número inteiro e retorna este valor inserido em formato de return
int value(int num) {
  return num;
}

//3 - Faça uma função que que insere novos valores em um vetor cujos argumentos serão: valor a ser inserido, capacidade de armazenamento de valores (número de posições), qual foi a última posição preenchida e o nome do vetor criado. A função funcionará como um "append" do Python controlado
int append(int num, int cap, int last, int *vet) {
  if (last < cap) {
    vet[last] = num;
    last++;
  }
  return last;
}
//4 - Faça uma função que recebe um vetor com 4 valores numéricos que representam "distâncias": Direita, esquerda, frente e trás e retorna qual destes valores (direita, etc) é o maior.
//i.e: 3,5,1,6: saída: trás
//Faça outra função que retorne este maior valor do vetor
//i.e.: 3,5,1,6: saída: 6
int maior(int *vet) {
  int maior = vet[0];
  for (int i = 0; i < 4; i++) {
    if (vet[i] > maior) {
      maior = vet[i];
    }
  }
  return maior;
}

//5 - Faça uma função que lê os valores 0 e 1, ficando em loop até que o valor 0 seja lido
int loop() {
  int num = 1;
  while (num != 0) {
    printf("Digite um número: ");
    scanf("%d", &num);
  }
  return 0;
}

//6 - Interpretação subjetiva. Robô lê um vetor semelhante ao item 4 que define a ordem de execução de movimentos de um robô. Armazene a posição e a distância para qual o robô andou em um vetor (ou dicionário, ou struct, etc).
string movimentos(int *vet) {
  string mov = "";
  for (int i = 0; i < 4; i++) {
    if (vet[i] == 0) {
      mov += "Frente ";
    } else if (vet[i] == 1) {
      mov += "Trás ";
    } else if (vet[i] == 2) {
      mov += "Direita ";
    } else if (vet[i] == 3) {
      mov += "Esquerda ";
    }
  }
  return mov;
}
//i.e.: 4,3,21
//Direita
//Esquerda
//Frente
//Trás
//Armazenamento: {Direita:4; Esquerda:3, Frente:2, Trás:1}


// TESTE DE VALIDAÇÃO DOS EXERCÍCIOS
int main(){
// EXERCÍCIO 1:

    float teste = percentage(80, 100, 60);
    cout << teste << endl;
//EXERCÍCIO 2:
        int teste2 = value(10);
        cout << teste2 << endl;
        
//EXERCÍCIO 3:
        int test3 = append(10, 10, 0, &teste2);
        cout << test3 << endl;

//EXERCÍCIO 4:
        int vet[4] = {3, 5, 1, 6};
        int teste4 = maior(vet);
        cout << teste4 << endl;
//EXERCÍCIO 5:
        int teste5 = loop();
        cout << teste5 << endl;
//

return 0;
}
