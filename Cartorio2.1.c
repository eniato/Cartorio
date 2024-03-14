#include <stdio.h> //biblioteca de comunicação do usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro()//responsavel por cadastrar o usuario
{
	//criação das strings
        char arquivo[40];
		char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];
    //final das strings
	    
        printf("digite o cpf a ser cadastrado:");//coletar a informação do usuário
        scanf("%s",cpf);//%s refere-se a string
        
        strcpy(arquivo, cpf); //responsavel por copiar os valores das string
        
        FILE *file; //cria o arquivo
        file = fopen(arquivo, "w");//"w" refere-se a escrever
        fprintf(file,cpf); // salvo o valor da variavel
        fclose(file); //fecha o arquivo
        
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
       
	   
        printf("digite o nome a ser cadastrado:");//coletar a informação do usuário
        scanf("%s", nome);
        
        file = fopen(arquivo,"a");
        fprintf(file,nome);// salvo o valor da variavel
        fclose(file);
        
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
    
        printf("digite o sobrenome a ser cadastrado:");
        scanf("%s", sobrenome);
        
        file = fopen(arquivo,"a");
        fprintf(file,sobrenome);
        fclose(file);
        
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
        
        printf("digite o seu cargo a ser cadastrado:");
        scanf("%s", cargo);
        
        file = fopen(arquivo, "a");
        fprintf(file,cargo);
        fclose(file);
    
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
        
        system("pause");                      
        
}



int consulta() 
{
    setlocale(LC_ALL, "portuguese");

    char cpf[40];
    char conteudo[200];
    char *token;

    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) //Caso a informação não existir traz a seguinte informação
    {
        printf("\nNão foi possivel abrir, cpf não localizado!\n\n");
    } 
	
	else 
	{
        while (fgets(conteudo, 200, file) != NULL) //Enquanto tiver informação, armazene a informação em conteudo se for diferente de NULL
        {
            printf("\nInformações do usuário: \n"); //Informação a aparecer antes dos dados

            token = strtok(conteudo, ","); //Dividir string em linhas
            printf("CPF: %s\n", token);//Informação a aparecer antes dos dados do CPF

            token = strtok(NULL, ","); //Dividir string em linhas
            printf("Nome: %s\n", token);//Informação a aparecer antes dos dados do nome

            token = strtok(NULL, ","); //Dividir string em linhas
            printf("Sobrenome: %s\n", token);//Informação a aparecer antes dos dados do Sobrenome

            token = strtok(NULL, ","); //Dividir string em linhas
            printf("Cargo: %s\n", token);//Informação a aparecer antes dos dados do cargo
        }

       
    }

    printf("\n"); //Pular uma linha no final

    system("pause");
  
}


int deletar()
{
	    char cpf[40], conteudo[40];
	    printf("Digite do usuário cpf a ser deletado: ");
	    scanf("%s", cpf);
	    
	       
	    FILE *file;
	    file = fopen(cpf,"r");
	    fclose(file);
	   
	    
	    if(file == NULL)	    
	    {
		printf("\nNão foi possivel encontrar o usuário! \n\n");
	    system("pause");
	    }
	    
	    else
	    {
	    if(remove(cpf) == 0)	
	    {
	    printf("\nUsuário deletado com sucesso!\n\n");
	    system("pause");
	    
		}
	    remove(cpf);	
		}
		

}


int main()
{
	int opcao=0; //definindo as variaveis
	int x=0;
	
	for(x=1;x=1;)
	{
	
	  system("cls");//responsavel por limpar a tela
	
	
	 setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	
	 printf("\t ###Cartório###  \n\n\tSeja bem-vindo \n"); //Inicio do menu 
	 printf("   Selecione as opções desejadas : \n\n");
	 printf("\t1 - Registrar nomes \n");
	 printf("\t2 - Consultar nomes \n");
	 printf("\t3 - Deletar nomes \n\n"); //Fim do menu
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Insira sua opção: ");
	
	 scanf("%d", &opcao); //Armazanamento da escolha do usuario
	
	 system("cls"); //Limpar menu
	
	 switch(opcao)
	{
		case 1:
		registro();//chamada de funções
		break;
		
		case 2:	
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		
		default:
		printf("Opção inválida, tente novamente\n");
		system("pause");
		break;
	}
	
     }
}
