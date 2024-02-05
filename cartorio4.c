#include <stdio.h> // Biblioteca de comunicação com o usuário.
#include <stdlib.h> // biblioteca para alocação de espaço de memoria
#include <locale.h>// biblioteca para localizar região e por acentuação
#include <string.h>// biblioteca para armazenar as strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); // Responsavel por trafuzir a linguagem utilizada no sistema
	
	//Inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/strings
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s",cpf); 
	
	strcpy(arquivo,cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w");
	fprintf(file,cpf);// salva o valor da variável	
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		fclose(file);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
					
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf, "r");


	if(file == NULL)
	{
		printf("Cpf não localizado!\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0;// Definir a variável
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao; 
	
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) // obs: o inicio de uma funçao não tem ponto e virgulga, fica atento 
	{
		for(laco=1;laco=1;)
		{
			system("cls"); // reposavel por limpar a tela
		
        	setlocale(LC_ALL,"Portuguese");
	
 	    	printf("### Cartório da EBAC ### \n\n");
        	printf("Opção desejada do menu\n\n");
	    	printf("\t1 - Registrar nomes\n");
	    	printf("\t2 - Consultar nomes\n");
	    	printf("\t3 - Deletar nomes\n\n");
	    	printf("\t4 - Sair do sistema\n\n");
	    	printf("Opção: ");
	
	    	scanf("%d", &opcao);// Armazenando as opções do usuário
	 
		    system("cls");
	    
	    	switch(opcao)
			{
	        	
	    		case 1:
	    		registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();			
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;
						
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			}
		}
	}
	else
	   printf("Senha incorreta!");
	
}
