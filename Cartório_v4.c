#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca respons�vel por cuidar das strings

int registro() //fun��o para criar um novo registro no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s = armazena os dados dentro de uma string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //chamando uma fun��o pronta do sistema para receber o comando file
	file = fopen(arquivo, "w"); //o comando file cria um arquivo novo - w = write
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //a = atualizar um arquivo existente
	fprintf(file,","); //incluindo uma ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //armazendando informa��o coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informa��o coletada
	fprintf(file, nome); //salvando o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo existente
	fprintf(file,","); //incluindo uma ","
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //armazendando informa��o coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informa��o coletada
	fprintf(file, sobrenome); //salvando o valor da vari�vel
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo existente
	fprintf(file,",");//incluindo uma ","
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); //armazendando informa��o coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informa��o coletada
	fprintf(file, cargo); //salvando o valor da vari�vel
	fclose(file);
	
	system("pause"); //pausa na tela para o usu�rio ler a mensagem

}

int consulta() //fun��o para consultar um novo registro no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria��o de vari�vel/string
	char conteudo[200]; //cria��o de vari�vel/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //armazendando informa��o coletada
	
	FILE *file; //chamando uma fun��o pronta do sistema para receber o comando file
	file = fopen(cpf,"r"); //abrindo o arquivo encontrado para fazer a leitura dos dados / r = read
	
	if(file == NULL) //se o arquivo n�o for encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) //operador de repeti��o - iremos ler dentro do arquivo (file) at� 200 caracteres e salvaremos dentro da vari�vel "conte�do" - enquanto o caracter n�o for nulo/vazio
	{
		printf("\nEssas s�o as informa��es do CPF consultado: ");
		printf("\n%s", conteudo); //retorna para o usu�rio as informa��es coletadas de dentro do arquivo (file)
		printf("\n\n");
	}
		system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria��o de vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //armazendando informa��o coletada
	
	FILE *file; //chamando uma fun��o pronta do sistema para receber o comando file
	file = fopen(cpf, "r"); //abrindo o arquivo encontrado para fazer a leitura dos dados / r = read
	
	if(file == NULL) //se o cpf n�o for encontrado
	{
		printf("CPF n�o localizado no sistema.\n");
		system("pause");
	}
	else //quando o cpf for encontrado
	{
		remove(cpf); //deleta o registro/arquivo encontrado
		printf("O usu�rio foi deletado!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{ //in�cio do la�o
	
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		//in�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpa a tela
		
		switch(opcao)
		{ //in�cio da sele��o
			case 1:
			registro(); //chamada da fun��o registro
			break;
			
			case 2:
			consulta(); //chamada da fun��o consulta
			break;
			
			case 3:
			deletar(); //chamada da fun��o deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //retonra valor 0, ou seja, quebra la�os e fun��es e sai do sistema
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		} //fim da sele��o
			
	} //fim do la�o
}
