#include "lista_oo.h"

int menu()
{
	int op;
	cout<<"\n---- MENU ----- \n";
	cout<<"\nDigite 1- Insere inicio";
	cout<<"\nDigite 2- Insere fim";
	cout<<"\nDigite 3- Imprime";
	cout<<"\nDigite 4- IsEmpty";
	cout<<"\nDigite 5- Tamanho ";
	cout<<"\nDigite 6- Busca ";
	cout<<"\nDigite 7- Retira inicio";
	cout<<"\nDigite 8- Retira fim";
	cout<<"\nDigite 9- Retira";
	cout<<"\nDigite 10- Liberar ";
	cout<<"\nDigite 11- Liberar recursivo";
	cout<<"\nDigite 12- imprime inicio";
	cout<<"\nDigite 13- imprime fim";
	cout<<"\nDigite 14- Sair\n";
	cout<<"Digite a opcao: ";
	cin>>op;
	return op;
}

int main(int argc, char** argv)
{
	lista_oo l;
	int op, x;

	do {
		op=menu();
		switch(op) {

			case 1:
				cout<<"\nDigite o valor: ";
				cin>>x;
				l.insere_inicio(x);
				break;
			case 2:
				cout<<"\nDigite o valor: ";
				cin>>x;
				l.insere_fim(x);
				break;
			case 3:
				l.imprime();
				break;
			case 4:
				if(l.IsEmpty()) {
					cout<<"\nLista vazia!";

				} else {
					cout<<"\nLista possui dados!";
				}
				break;
			case 5:
				cout<<"\nO tamanho da lista e: "<<l.tamanho();
				break;
			case 6:
				if(l.IsEmpty())	{
					cout<<"\nLista vazia!";
					break;
				}
				cout<<"\nDigite o valor procurado: ";
				cin>>x;
				if(l.busca(x)) {
					cout<<"\nValor ENCONTRADO na lista !";

				} else {
					cout<<"\nValor NAO encontrado na Lista !";
				}
				break;
			case 7:
				if(l.retira_inicio()) {
					cout<<"\nExclusao efetuada com sucesso!!";
				} else {
					cout<<"\nLista vazia!";
				}
				break;
			case 8:
				if(l.retira_fim()) {
					cout<<"\nExclusao efetuada com sucesso!!";
				} else {
					cout<<"\nLista vazia!";
				}
				break;
			case 9:
				cout<<"\nDigite o valor a ser retirado: ";
				cin>>x;
				if (l.retira(x)) {
					cout<<"\nValor retirado com sucesso!!";
				} else {
					cout<<"\nValor nao encontrado..";
				}
				break;
			case 10:
				l.libera();
				cout<<"\nLista vazia!";
				break;
			case 11:
				l.libera_rec();
				cout<<"\nLista vazia!";
				break;

			case 12:
				if(l.IsEmpty())	{
					cout<<"\nLista vazia!";
					break;
				}
				cout<<"\nInicio da lista: ";
				l.imprime_inicio();
				break;
			case 13:
				if(l.IsEmpty())	{
					cout<<"\nLista vazia!";
					break;
				}
				cout<<"\nFim da lista: ";
				l.imprime_fim();
				break;
			case 14:
				cout<<"\nVoce esta saindo.....";
				break;

			default:
				cout<<"\nOpcao invalida!\n";
				break;
		}


	} while(op!=14);

	return 0;
}