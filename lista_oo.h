#include <stdlib.h>
#include <iostream>
#include "no_dado.h"
using namespace std;

/*
struct lista {
	int info;
	struct lista* prox;
};
typedef struct lista no_dado;
*/
class lista_oo
{
	private:
		no_dado* cabeca;
		int qtd;

	public:
		lista_oo();
		~lista_oo();
		void insere_inicio(int x);
		void insere_fim(int x);
		void imprime();
		bool IsEmpty();
		int tamanho();
		bool busca(int v);
		bool retira_inicio();
		bool retira_fim();
		bool retira(int v);
		void libera();
		void libera_rec();
		void imprime_inicio();
		void imprime_fim();

	private:
		bool isempty(no_dado* l);
		void libera_recursividade(no_dado* l);


};