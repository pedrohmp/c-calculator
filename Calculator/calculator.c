/*
 * calculator.c
 *
 *  Created on: 8 de mai de 2017
 *      Author: PedroPorta
 */

#include <stdio.h>
#include <stdlib.h> //diretiva para usar o atof
#include <string.h> //permite uso das funções na string como gets e puts
#include <ctype.h> //diretiva para usar a função isdigt
#define N 50 //o grupo estabeleceu que a expressão matemática suportará até 50 caracteres

int main() {
	int topo = 0, tam, i; //varáveis pra posição do topo, tamanho da expressão e controlador do laço de repetição
	char expressao[N], aux[2]; //String para a expressão matemática e outra auxiliar
	float pilha[3]; //vetor para a pilha
	float num, dado1, dado2, res;

//lendo a expressão
	printf("Digite a expressão matematica a ser calculada: \n");
	fflush(stdin);
	gets(expressao);
//pegando o número de caracteres da expressão
	tam = strlen(expressao);
	printf("Tamanho da expressao: %d caracteres\n", tam);

//criando laço para percorrer toda a expressão matemática
	for (i = 0; i < tam; i++) {
//verificando se o caractere é um digito ou símbolo matemático
		if (isdigit(expressao[i])) {
//convertendo a expressão para número real
			aux[0] = expressao[i];
			aux[1] = '\0';
			num = atof(aux);
//empilhando o numero
			pilha[topo] = num;
			topo++;
		} else {
//atribuindo os valores da pilha para dado1 e dado2
			topo--;
			dado1 = pilha[topo];
			pilha[topo] = 0;
			topo--;
			dado2 = pilha[topo];
			pilha[topo] = 0;

//comparando para depois calcular os valores de dado1 e dado2
			if (expressao[i] == '+') {
				res = dado2 + dado1;
			} else if (expressao[i] == '-') {
				res = dado2 - dado1;
			} else if (expressao[i] == '*') {
				res = dado2 * dado1;
			} else {
				res = dado2 / dado1;
			}
//pondo o resultado de volta na pilha
			pilha[topo] = res;
			topo++;
		}œ
	}
//atribuindo o valor restante a variável de resultado
	topo--;
	res = pilha[topo];
	printf("\nO resultado e: %.2f \n", res);
	system("pause");
}
