#include<iostream>
using namespace std;

struct Lista {
	int num;
	Lista *prox, *ant;
};

int leiaIdade() {
	int idade;
	cout<<"\n Digite sua idade:"<<endl;
	cin>>idade;
		if (idade>65){
			cout<<"\n Atentimento com Prioridade"<<endl;
		}
	return idade;
}

string leiaCpf(){
	string cpf;
	cout<<"\n Digite seu cpf:"<<endl;
	cin>>cpf;
	return cpf;
}

int leiaSexo(){
	int sexo;
	cout<<"\n Digite seu sexo 1 para Feminino 2 para Masculino: "<<endl;
	cin>>sexo;
		if (sexo==1){
			cout<<"\n Esta gravida? 1-Sim ou 2-Nao"<<endl;
		}
	return sexo;
}
int main() {
		
	Lista *inicio = NULL, *fim=NULL, *aux = NULL;
	int op=0, numero=0, achou = 0;
	
	while(op != 5) { 
		cout<<"\n\t 1-Cadastrar Atendimento prioritario";
		cout<<"\n\t 2-Cadastrar Atendimento";
		cout<<"\n\t 3-Consultar a lista ";
		cout<<"\n\t 4-Excluir registro de atendimento";
		cout<<"\n\t 5-Sair";
		cout<<"\n\t Escolha Opcao:"<<endl;
		cin>>op;
		if (op==1) {
			Lista *novo = new Lista;
			novo->num = leiaIdade(),leiaCpf(),leiaSexo();
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;
				cout<< "\nProximo Atendimento\n"<<novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}else {
				novo->prox = inicio;
				cout<<"+1 prox"<<inicio;
				inicio->ant=novo;
				cout<<"+1 ant"<<inicio;
				novo->ant=NULL;
				inicio=novo;
			}
		}
		if (op==2) {		
			Lista *novo = new Lista;
			novo->num = leiaIdade(),leiaCpf(),leiaSexo();
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}else {
				fim->prox = novo;
				novo->ant=fim;
				novo->prox=NULL;
				fim=novo;
			}
		}
		
		if(op ==3 ) { 
			if (inicio == NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = inicio;
				while (aux != NULL){
					cout<<"\n\tIdade:"<< aux->num <<endl;
					cout<<"\n\tCPF:"<< aux->num <<endl;
					cout<<"\n\tSexo:"<< aux->num <<endl;
					aux=aux->prox;
				}
			}
		}
		
		if (op==4) {
			if (inicio == NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = fim;//*
				while (aux != NULL){
					cout<<"\n\tIdade:"<< aux->num <<endl;
					cout<<"\n\tCPF:"<< aux->num <<endl;
					cout<<"\n\tSexo:"<< aux->num <<endl;
					aux=aux->ant;//*
				}
			}
		}
	}
	
	return 1;
}

