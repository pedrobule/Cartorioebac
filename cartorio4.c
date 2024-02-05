#include <stdio.h> // Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // biblioteca para aloca��o de espa�o de memoria
#include <locale.h>// biblioteca para localizar regi�o e por acentua��o
#include <string.h>// biblioteca para armazenar as strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); // Responsavel por trafuzir a linguagem utilizada no sistema
	
	//Inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/strings
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s",cpf); 
	
	strcpy(arquivo,cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w");
	fprintf(file,cpf);// salva o valor da vari�vel	
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
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
		printf("Cpf n�o localizado!\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0;// Definir a vari�vel
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao; 
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) // obs: o inicio de uma fun�ao n�o tem ponto e virgulga, fica atento 
	{
		for(laco=1;laco=1;)
		{
			system("cls"); // reposavel por limpar a tela
		
        	setlocale(LC_ALL,"Portuguese");
	
 	    	printf("### Cart�rio da EBAC ### \n\n");
        	printf("Op��o desejada do menu\n\n");
	    	printf("\t1 - Registrar nomes\n");
	    	printf("\t2 - Consultar nomes\n");
	    	printf("\t3 - Deletar nomes\n\n");
	    	printf("\t4 - Sair do sistema\n\n");
	    	printf("Op��o: ");
	
	    	scanf("%d", &opcao);// Armazenando as op��es do usu�rio
	 
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}
		}
	}
	else
	   printf("Senha incorreta!");
	
}
