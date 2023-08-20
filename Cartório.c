#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //bbiblioteca responsável por cuidar das string

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
    
    //Declara as vari�veis/strings
    char cpf[50];
    char nomeArquivo[50];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    strcpy(nomeArquivo, cpf); //Copia o CPF para a vari�vel 'nomeArquivo'
    
    FILE *file; //Cria o arquivo
    file = fopen(nomeArquivo, "r"); //O "r" significa que ele vai ser o arquivo
    
    if (file == NULL) //Se o arquivo n�o exite ou n�o foi criado 
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o encontrado!\n");
    }
    else //Caso o arquivo seja localizado ,mostra as informa��es dentro dele
    {
        fgets(conteudo, 200, file); // L� o CPF
        printf("CPF: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // L� o nome
        printf("Nome: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // L� o sobrenome
        printf("Sobrenome: %s\n", conteudo);
        
        fgets(conteudo, 200, file); // L� o cargo
        printf("Cargo: %s\n", conteudo);
        
        fclose(file); //Fim do arquivo
        
        
    }
    
    system("pause");
}

int deletar()
{
	//Declara��o das vari�veis/Strings

	char cpf[50]; //Armazena o CPF a ser deletado
    char nomeArquivo[50];  //Armazena o nome do arquivo a ser deletado
    char confirmacao[5]; //Armazena a confirma��o de exclus�o
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    strcpy(nomeArquivo, cpf); //Copia o CPF para a vari�vel 'nomeArquivo'
    
    printf("Tem certeza que deseja deletar o arquivo %s? (Sim/N�o): ", nomeArquivo);
    scanf("%s", confirmacao);
    
    if (strcmp(confirmacao, "Sim") == 0 || strcmp(confirmacao, "sim") == 0)  //Verifica se a confirma��o � "Sim" ou "sim"
    
        
    {
        if (remove(nomeArquivo) == 0) {  //Tenta remover o arquivo usando o nome armazenado na vari�vel 'nomeArquivo'
            printf("Arquivo deletado com sucesso.\n");
        } else { //Se n�o encontrar o CPF do usu�rio
            printf("O usu�rio n�o se encontra no sistema.\n"); 
        }
    }
    else //Se o cliente escolher a op��o 'N�o'
    {
        printf("Exclus�o cancelada.\n");
    }
    
    system("pause");

}


int main() 
    {
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;) //Inicio do la�o
	{
	
	
    	system("cls");
	
    	setlocale(LC_ALL, "Portuguese"); //Defindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");//Incio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Op��o: ");//Fim do menu
	
    	 scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Limpar a pagina para n�o ter polui��o visual quando o cliente for inicar a sele��o
    
    switch(opcao) //Incio da sele��o
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
			printf("Est� op��o n�o esta disponivel!\n");
    	system("pause");
    	break;		
	} //Fim da sele��o
	
    } //Fim do la�o
    

}

