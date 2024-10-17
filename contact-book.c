#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMITE 100

typedef struct
{
    int userId;
    char userName[20];
    int userFone;
    char contactType[10];
} Contato;

void addContato(Contato *contatos, int *usersQuantity, int *indice)
{

    if (*usersQuantity < LIMITE)
    {
        contatos[*usersQuantity].userId = *usersQuantity + 1;
        printf("CADASTRAR NOVO CONTATO! \n");
        printf("\n-------------------------------------------\n");
        printf("\nDigite o nome do contato:\n");
        scanf("%s", &contatos[*usersQuantity].userName);

        printf("Digite o telefone do contato:\n");
        scanf("%d", &contatos[*usersQuantity].userFone);

        printf("Digite o tipo do contato (Pessoal ou Profissional):\n");
        scanf("%s", &contatos[*usersQuantity].contactType);

        *usersQuantity = *usersQuantity + 1;
    }
    else
    {
        printf("Numero maximo de contatos atingido\n");
    }
}

int localizarContato(Contato *contatos, int *usersQuantity)
{

    int indice = 0;
    int menuLocalizar = 0;
    int numId = 0;
    int numFone = 0;

    do
    {
        printf("\nPara localizar o contato o qual voce deseja realizar esta acao, e necessario saber o ID do contato: \n");
        printf("1 - Informar o numero de identificacao do contato\n");
        printf("2 - Exibir lista completa para saber o numero de identificacao de cada contato\n");
        scanf("%d", &menuLocalizar);

        if (menuLocalizar == 1)
        {
            do
            {
                printf("\nInforme o numero de identificacao do contato desejado: \n");
                scanf("%d", &numId);
            } while (numId > *usersQuantity);

            for (int c = 0; c < *usersQuantity; c++)
            {
                if (contatos[c].userId == numId)
                {
                    indice = contatos[c].userId - 1;
                }
            }
        }
        else if (menuLocalizar == 2)
        {
            if (*usersQuantity == 0)
            {
                printf("\nNao existe nenhum contato!\n");
            }
            else
            {
                system("cls");
                for (int j = 0; j < *usersQuantity; j++)
                {
                    printf("\nNome do contato: %s\n", contatos[j].userName);
                    printf("Numero de identificacao do contato: %d\n", contatos[j].userId);
                    printf("Numero de telefone do contato: %d\n", contatos[j].userFone);
                    printf("Tipo de contato: %s\n", contatos[j].contactType);
                    printf("\n-------------------------------------------\n");
                }
            }
        }
        else
        {
            printf("operacao inexistente!");
        }
    } while ((menuLocalizar != 1 && menuLocalizar != 2) || (menuLocalizar == 2));

    return indice;
}

void imprimirContato(int *indice, Contato *contatos)
{
    printf("\nID: %d\n", contatos[*indice].userId);
    printf("Nome: %s\n", contatos[*indice].userName);
    printf("Telefone: %d\n", contatos[*indice].userFone);
    printf("Tipo de contato %s\n", contatos[*indice].contactType);
}

void excluirContato(Contato *contatos, int *usersQuantity)
{

    int indice = 101;
    int menuExcluir = 0;
    int numId = 0;
    int numFone = 0;

    do
    {
        printf("Para localizar o contato o qual voce deseja excluir, informe um de seus dados: \n");
        printf("1 - Informar o numero de identificacao do contato\n");
        printf("2 - Exibir lista completa para saber o numero de identificacao de cada contato\n");
        scanf("%d", &menuExcluir);

        if (menuExcluir == 1)
        {
            do
            {
                printf("Informe o numero de identificacao do contato desejado: \n");
                scanf("%d", &numId);
            } while (numId > *usersQuantity);

            for (int c = 0; c < *usersQuantity; c++)
            {
                if (contatos[c].userId == numId)
                {
                    system("cls");
                    printf("CONTATO EXCLUIDO COM SUCESSO! \n");
                    indice = contatos[c].userId - 1;
                }
            }
        }
        else if (menuExcluir == 2)
        {
            if (*usersQuantity == 0)
            {
                printf("\nNao existe nenhum contato!\n");
            }
            else
            {
                system("cls");
                for (int j = 0; j < *usersQuantity; j++)
                {
                    printf("\nNome do contato: %s\n", contatos[j].userName);
                    printf("Numero de identificacao do contato: %d\n", contatos[j].userId);
                    printf("Numero de telefone do contato: %d\n", contatos[j].userFone);
                    printf("Tipo de contato: %s\n", contatos[j].contactType);
                    printf("\n-------------------------------------------\n");
                }
            }
        }
        else
        {
            printf("Operacao inexistente!\n");
        }
    } while ((menuExcluir != 1 && menuExcluir != 2) || (menuExcluir == 2));

    if (indice != 101)
    {
        for (int i = indice; i < *usersQuantity; i++)
        {
            strcpy(contatos[i].userName, contatos[i + 1].userName);
            strcpy(contatos[i].contactType, contatos[i + 1].contactType);
            contatos[i].userFone = contatos[i + 1].userFone;
            // contatos[i].userId = contatos[i+1].userName;
        }
        *usersQuantity = *usersQuantity - 1;
    }
}

void atualizarContato(int *indice, Contato *contatos)
{
    char nome[20];
    int fone;
    char tipo[10];
    char opcao;

    do
    {
        system("cls");
        printf("\nQual dado do contato voce deseja atualizar:\n");
        printf("1 - Nome\n");
        printf("2 - Telefone\n");
        printf("3 - Tipo de contato\n");
        scanf("%d", &opcao);
    } while (opcao < 1 && opcao > 3);

    switch (opcao)
    {

    case 1:
        printf("\nDigite o novo nome do contato:\n");
        scanf("%s", &contatos[*indice].userName);
        break;
    case 2:
        printf("\nDigite o novo telefone do contato:\n");
        scanf("%d", &contatos[*indice].userFone);
        break;

    case 3:
        printf("\nDigite o novo tipo do contato:\n");
        scanf("%s", &contatos[*indice].contactType);
        break;

    default:
        break;
    }
}

int main()
{

    int indice = 0;
    int operacao = 0;
    int usersQuantity = 0;
    Contato contatos[LIMITE];

    do
    {
        printf("\nEscolha a operacao que deseja realizar: \n");
        printf("1 - Incluir um novo contato \n");
        printf("2 - Excluir um contato existente \n");
        printf("3 - Alterar um contato existente \n");
        printf("4 - Listar todos os contatos cadastrados \n");
        printf("5 - Localizar um contato \n");
        printf("6 - Sair do programa ==> \n");
        scanf("%d", &operacao);

        switch (operacao)
        {
        case 1: // cadastrar contato
            system("cls");
            addContato(contatos, &usersQuantity, &indice);
            printf("\nQuantidade de contatos: %d\n", usersQuantity);
            system("cls");
            break;
        case 2: // excluir contato
            system("cls");
            if (usersQuantity == 0)
            {
                printf("Nao existe nenhum contato!\n");
            }
            else
            {
                excluirContato(contatos, &usersQuantity);
            }
            break;
        case 3: // alterar contato
            system("cls");
            if (usersQuantity == 0)
            {
                printf("Nao existe nenhum contato!\n");
            }
            else
            {
                indice = localizarContato(contatos, &usersQuantity);
                atualizarContato(&indice, contatos);
                system("cls");
                printf("\n-------------------------------------------\n");
                printf("\nInformacoes do contato alterado:\n");
                imprimirContato(&indice, contatos);
                printf("\n-------------------------------------------\n");
            }
            break;
        case 4: // listar todos os contatos
            system("cls");
            printf("\nQuantidade de contatos: %d\n", usersQuantity);
            printf("\n-------------------------------------------\n");
            printf("LISTA DE CONTATOS: \n");

            if (usersQuantity == 0)
            {
                printf("Nao existe nenhum contato!\n");
            }
            else
            {
                for (int j = 0; j < usersQuantity; j++)
                {
                    printf("\nNome do contato: %s\n", contatos[j].userName);
                    printf("Numero de identificacao do contato: %d\n", contatos[j].userId);
                    printf("Numero de telefone do contato: %d\n", contatos[j].userFone);
                    printf("Tipo de contato: %s\n", contatos[j].contactType);
                    printf("\n-------------------------------------------\n");
                }
            }
            break;
        case 5: // localizar contato
            system("cls");
            if (usersQuantity == 0)
            {
                printf("Nao existe nenhum contato!\n");
            }
            else
            {
                indice = localizarContato(contatos, &usersQuantity);
                system("cls");
                printf("\n-------------------------------------------\n");
                imprimirContato(&indice, contatos);
                printf("\n-------------------------------------------\n");
            }
            break;
        }
    } while (operacao != 6);

    system("cls");
}