#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bbiblioteca responsÃ¡vel por cuidar das string

int registro()
{
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Cria o arquivo de escrito
	fprintf(file,"%s\n",cpf); //Salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	
	file = fopen(arquivo, "a");
	scanf("%s",nome);
	fprintf(file,"%s\n",nome);
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"%s\n",sobrenome);
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"%s\n",cargo);
	fclose(file);
	
   system("pause");
}
	
	
	
	
int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    
    //Declara as variáveis/strings
    char cpf[50];
    char nomeArquivo[50];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    strcpy(nomeArquivo, cpf); //Copia o CPF para a variável 'nomeArquivo'
    
    FILE *file; //Cria o arquivo
    file = fopen(nomeArquivo, "r"); //O "r" significa que ele vai ser o arquivo
    
    if (file == NULL) //Se o arquivo não exite ou não foi criado 
    {
        printf("Não foi possível abrir o arquivo, não encontrado!\n");
    }
    else //Caso o arquivo seja localizado ,mostra as informações dentro dele
    {
        fgets(conteudo, 200, file); // Lê o CPF
        printf("CPF: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // Lê o nome
        printf("Nome: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // Lê o sobrenome
        printf("Sobrenome: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // Lê o cargo
        printf("Cargo: %s\n", conteudo);
        
        fclose(file); //Fim do arquivo
        
        
    }
    
    system("pause");
}

int deletar()
{
	//Declaração das variáveis/Strings

	char cpf[50]; //Armazena o CPF a ser deletado
    char nomeArquivo[50];  //Armazena o nome do arquivo a ser deletado
    char confirmacao[5]; //Armazena a confirmação de exclusão
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    strcpy(nomeArquivo, cpf); //Copia o CPF para a variável 'nomeArquivo'
    
    printf("Tem certeza que deseja deletar o arquivo %s? (Sim/Não): ", nomeArquivo);
    scanf("%s", confirmacao);
    
    if (strcmp(confirmacao, "Sim") == 0 || strcmp(confirmacao, "sim") == 0)  //Verifica se a confirmação é "Sim" ou "sim"
    
        
    {
        if (remove(nomeArquivo) == 0) {  //Tenta remover o arquivo usando o nome armazenado na variável 'nomeArquivo'
            printf("Arquivo deletado com sucesso.\n");
        } else { //Se não encontrar o CPF do usuário
            printf("O usuário não se encontra no sistema.\n"); 
        }
    }
    else //Se o cliente escolher a opção 'Não'
    {
        printf("Exclusão cancelada.\n");
    }
    
    system("pause");

}


int main() 
    {
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;) //Inicio do laço
	{
	
	
    	system("cls");
	
    	setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n");//Incio do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opção: ");//Fim do menu
	
    	 scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); //Limpar a pagina para não ter poluição visual quando o cliente for inicar a seleção
    
    switch(opcao) //Incio da seleção
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
		
		default:
			printf("Está opção não esta disponivel!\n");
    	system("pause");
    	break;		
	} //Fim da seleção
	
    } //Fim do laço
    

}

