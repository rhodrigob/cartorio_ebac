#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsável por cuidar das strings

int registro() //função para criar um novo registro no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s = armazena os dados dentro de uma string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //chamando uma função pronta do sistema para receber o comando file
	file = fopen(arquivo, "w"); //o comando file cria um arquivo novo - w = write
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //a = atualizar um arquivo existente
	fprintf(file,","); //incluindo uma ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //armazendando informação coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informação coletada
	fprintf(file, nome); //salvando o valor da variável
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo existente
	fprintf(file,","); //incluindo uma ","
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); //armazendando informação coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informação coletada
	fprintf(file, sobrenome); //salvando o valor da variável
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo existente
	fprintf(file,",");//incluindo uma ","
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo); //armazendando informação coletada
	
	file = fopen(arquivo, "a"); //abrindo o arquivo criado anteriormente e alterando com a nova informação coletada
	fprintf(file, cargo); //salvando o valor da variável
	fclose(file);
	
	system("pause"); //pausa na tela para o usuário ler a mensagem

}

int consulta() //função para consultar um novo registro no sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //criação de variável/string
	char conteudo[200]; //criação de variável/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s", cpf); //armazendando informação coletada
	
	FILE *file; //chamando uma função pronta do sistema para receber o comando file
	file = fopen(cpf,"r"); //abrindo o arquivo encontrado para fazer a leitura dos dados / r = read
	
	if(file == NULL) //se o arquivo não for encontrado
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL) //operador de repetição - iremos ler dentro do arquivo (file) até 200 caracteres e salvaremos dentro da variável "conteúdo" - enquanto o caracter não for nulo/vazio
	{
		printf("\nEssas são as informações do CPF consultado: ");
		printf("\n%s", conteudo); //retorna para o usuário as informações coletadas de dentro do arquivo (file)
		printf("\n\n");
	}
		system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //criação de variável/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s", cpf); //armazendando informação coletada
	
	FILE *file; //chamando uma função pronta do sistema para receber o comando file
	file = fopen(cpf, "r"); //abrindo o arquivo encontrado para fazer a leitura dos dados / r = read
	
	if(file == NULL) //se o cpf não for encontrado
	{
		printf("CPF não localizado no sistema.\n");
		system("pause");
	}
	else //quando o cpf for encontrado
	{
		remove(cpf); //deleta o registro/arquivo encontrado
		printf("O usuário foi deletado!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{ //início do laço
	
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		//início do menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
		//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpa a tela
		
		switch(opcao)
		{ //início da seleção
			case 1:
			registro(); //chamada da função registro
			break;
			
			case 2:
			consulta(); //chamada da função consulta
			break;
			
			case 3:
			deletar(); //chamada da função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //retonra valor 0, ou seja, quebra laços e funções e sai do sistema
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		} //fim da seleção
			
	} //fim do laço
}
