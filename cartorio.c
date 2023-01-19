#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca presponsavel por cuidar das strings

int registrar(){
	
	char arquivo[40]; 
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo[40];
	
	//------ cpf
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf); //%s guardar string
	
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //criar espa�amento
	
	//------- nome
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s guardar string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //criar espa�amento
	
	//---------- sobrenome
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //%s guardar string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //criar espa�amento
	
	//--------- cargo
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo); //%s guardar string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); //criar espa�amento
}

int consultar(){
	
	setlocale(LC_ALL, "portuguese"); //acentua��o-linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");


	if(file==NULL){
		printf("O CPF n�o foi encontrado! \n");
	}
	
	while(fgets(conteudo,200,file) != NULL){
		
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	
	fclose(file);
	system("pause");
	
}

int deletar(){
	
	setlocale(LC_ALL, "portuguese"); //acentua��o-linguagem
	
	char cpf [40];
	
	printf("Digite o CPF  a ser deletado: ");
	scanf("%s",cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" ler arquivo
	
	if(file == NULL){
		
		printf("Usu�rio n�o se encontra cadastrado!\n");
		system("pause");
		
	}	
	
}

//----------------------------


int main (){
	
	int opcao=0; // definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao=strcmp(senhadigitada,"adm");
	
	if(comparacao==0){  //==comparando, = igualando
	
		for (laco=1;laco=1;)
	  
		{
	
			system("cls");
		
			setlocale(LC_ALL, "portuguese"); //acentua��o-linguagem
	
			printf("### Cart�rio da EBAC ###\n\n");
			printf("Escolha a op��o do menu desejada:\n\n"); // \n\n espa�amento
			printf("\t1 - Registrar nomes\n"); // \t afastamento 
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			
			printf("\n Op��o: ");
	
			scanf("%d" , &opcao);
	
			system("cls"); //limpa textos
		
			switch(opcao)
			{
				case 1:
				registrar();
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
			
				
			
				default:
				printf("Esta op��o n�o esta disponivel ! \n");
				system("pause");
				break;
			
			}
		}
	}
	else 
	printf("Senha incorreta!");

}

// int assinantes = 0 ;
// for (assinantes =0; assinantes < 10; assinantes++){instru�oes}
