#include "lista_oo.h"

lista_oo::lista_oo()
{
	cabeca = 0; // mesmo NULL
	qtd=0;
}
lista_oo::~lista_oo()
{
	libera();
}
void lista_oo::insere_inicio(int x)
{
	//no_dado* novo=(no_dado*)malloc(sizeof(no_dado));
	//novo->info =x;
	//novo->prox = cabeca;
	no_dado* novo= new no_dado(x,cabeca);
	cabeca=novo;
	qtd++;

}

void lista_oo::insere_fim(int x)
{
	no_dado* novo = new no_dado(x, nullptr);

	// Se a lista estiver vazia, o novo nó se torna a cabeça da lista
	if (cabeca == nullptr) {
		cabeca = novo;
	} else {
		// Caso contrário, percorre até o final da lista
		no_dado* p = cabeca;
		while (p->prox != nullptr) {
			p = p->prox;
		}
		// Define o próximo do último nó como o novo nó
		p->prox = novo;
	}
	
	qtd++;
}
void lista_oo::imprime()
{
	if(isempty(cabeca)) {
		cout<<"\nLista vazia!!!";
	} else {
		cout<<"\nInicio da Lista: ";
		for (no_dado* p = cabeca; p!= NULL; p=p->prox) {
			cout<<p->info;
			if(p->prox!=NULL) cout<<" - ";
		}

	}
}
bool lista_oo::IsEmpty()
{
	return isempty(cabeca);
}
int lista_oo::tamanho()
{
	return qtd;
}

bool lista_oo::busca(int v)
{
	no_dado* p=cabeca;
	for(; p !=NULL; p= p->prox) {
		if(p->info==v) {
			return true;
		}
	}
	return false;
}
bool lista_oo::retira_inicio()
{
	if(IsEmpty()) {
		return false;
	}
	no_dado* p = cabeca;
	cabeca=cabeca->prox;
	free(p);
	qtd--;
	return true;
}
bool lista_oo::retira_fim(){
	if(IsEmpty()) {
		return false;
	}
	if (cabeca->prox == nullptr) {
        delete cabeca;
        cabeca = nullptr;
    } else {
        // Percorre até o penúltimo nó
        no_dado* p = cabeca;
        while (p->prox->prox != nullptr) {
            p = p->prox;
        }
        // Remove o último nó
        delete p->prox;
        p->prox = nullptr;
    }
    qtd--;
	return true;	
}

bool lista_oo::retira(int v)
{
	if(IsEmpty()) {
		return false;
	}

	no_dado* ant = NULL; /* ponteiro para elemento anterior */
	no_dado* p = cabeca; /* ponteiro para percorrer a lista*/

	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}

	/*caso não achou: retorna lista original */
	if (p == NULL) {
		return false;
	}


	/*senão, achou... retira elemento */
	if (ant == NULL)  /* retira elemento do inicio */
		return retira_inicio();
	ant->prox = p->prox;
	cout<<"\nElemento v: "<<v<<"Removido com sucesso\n";
	free(p); //desaloca no-dado
	qtd--; //decrementa o contador de nós-dado da lista
	return true;

}
void lista_oo::libera()
{
	no_dado* p = cabeca;
	while (p != NULL) {
		no_dado* t = p->prox; /* guarda referência para o próximo elemento*/
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
	cabeca=0;
	qtd=0;

}
void lista_oo::libera_rec()
{
	libera_recursividade(cabeca);
	cabeca=0;
	qtd=0;

}

void lista_oo::imprime_inicio()
{
	cout<<cabeca->info<<endl;
}

void lista_oo::imprime_fim()
{
	no_dado* p = cabeca;
	for(; p->prox!=NULL; p=p->prox) {
	}
	cout<<p->info<<endl;
}

bool lista_oo::isempty(no_dado* l)
{
	if(l == NULL) {
		return true;
	}
	return false;

}

void lista_oo::libera_recursividade(no_dado* l)
{
	if (!isempty(l)) {
		libera_recursividade(l->prox);
		free(l);
	}
}