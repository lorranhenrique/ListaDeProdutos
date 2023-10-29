#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int codigo;
    char *produto;
    int quant;
    float valor;

    struct No *prox;
} No;

No *InseriInicio(No *atual,No dados);
No *InseriFinal(No *atual,No dados);
No *Remove(No *atual,int cod);
void imprimi(No *atual);
float Media(No *atual);
No *Buscar(No *atual,int cod);

int main()
{
    No *lista=NULL;
    No dados;
    No *selecionado;
    int op,c=0,cod;
    float media;

    do
    {
        printf("\n\n[1]Inserir no inicio\n[2]Inserir no final\n[3]Remover\n[4]Imprimir\n[5]Media\n[6]Buscar\n[0]Sair\n");
        scanf("%d",&op);


        switch(op)
        {
        case 0:
            return 0;
            break;
        case 1:
            dados.produto=(char*)malloc(sizeof(char)*50);
            printf("Informe o Nome do produto ");
            scanf("%s",dados.produto);
            printf("Informe a quantidade adicionada ao estoque");
            scanf("%d",&dados.quant);
            printf("Informe o valor desse produto ");
            scanf("%f",&dados.valor);
            dados.codigo=2023+c;
            c++;
            lista=InseriInicio(lista,dados);
            break;
        case 2:
            dados.produto=(char*)malloc(sizeof(char)*50);
            printf("Informe o Nome do produto ");
            scanf("%s",dados.produto);
            printf("Informe a quantidade adicionada ao estoque");
            scanf("%d",&dados.quant);
            printf("Informe o valor desse produto ");
            scanf("%f",&dados.valor);
            dados.codigo=2023+c;
            c++;
            lista=InseriFinal(lista,dados);
            break;
        case 3:
            printf("Informe o Codigo do produto que deseja remover");
            scanf("%d",&cod);
            lista = Remove(lista,cod);
            break;
        case 4:
            imprimi(lista);
            break;
        case 5:
            media=Media(lista);
            printf("Media De Precos: %.2f",media);
            break;
        case 6:
            printf("Informe o Codigo do produto que deseja Buscar");
            scanf("%d",&cod);
            if(Buscar(lista,cod)==NULL)
            {
                printf("lista vazia ou item nao encontrado");
            }
            else
            {
                selecionado=Buscar(lista,cod);
                printf("     Produto: %s",selecionado->produto);
                printf("     Valor: %.2f",selecionado->valor);
                printf("     Codigo: %d",selecionado->codigo);
                printf("     Quantidade: %d\n\n",selecionado->quant);
            }
            break;
        default:
            printf("Valor inválido insira um valor de [0-6]");
            scanf("%d",&op);
        }
    }
    while(op!=0);

}

No *InseriInicio(No *atual,No dados)
{

    No *novo=(No*)malloc(sizeof(No));
    novo->codigo=dados.codigo;
    novo->produto=dados.produto;
    novo->quant=dados.quant;
    novo->valor=dados.valor;

    novo->prox=atual;
    atual=novo;

    return atual;
}

No *InseriFinal(No *atual,No dados)
{

    No *novo=(No*)malloc(sizeof(No));
    novo->codigo=dados.codigo;
    novo->produto=dados.produto;
    novo->quant=dados.quant;
    novo->valor=dados.valor;

    No *no=atual;

    while(no->prox!=NULL)
    {
        no=no->prox;
    }
    no->prox=novo;

    return atual;
}

void imprimi(No *atual)
{
    if(atual==NULL)
    {
        printf("Lista vazia");
    }
    else
    {
        while(atual!=NULL)
        {
            printf("     Produto: %s",atual->produto);
            printf("     Valor: %.2f",atual->valor);
            printf("     Quantidade: %d\n\n",atual->quant);
            printf("     Codigo: %d",atual->codigo);
            atual=atual->prox;
        }
    }
}

float Media(No *atual)
{
    float soma=0,media;
    int cont=0;

    if(atual==NULL)
    {
        printf("Lista vazia");
    }
    else
    {
        while(atual!=NULL)
        {
            soma=soma+atual->valor;
            cont++;
            atual=atual->prox;
        }
    }
    media=soma/cont;
    return media;
}

No *Remove(No *atual,int cod)
{
    No *ant = NULL;

    No *inicio= atual;
    while(atual != NULL && atual->codigo != cod)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return inicio;

    No *exclui = atual;

    if(ant == NULL)
    {
        atual = atual->prox;
        inicio = atual;
    }
    else
    {
        ant->prox = atual->prox;
    }
    free(exclui);
    return inicio;
}

No *Buscar(No *atual, int cod)
{
    No *buscador = atual;

    if (atual == NULL)
    {
        return NULL;
    }
    else
    {
        while (buscador != NULL)
        {
            if (buscador->codigo == cod)
            {
                return buscador;
            }
            buscador = buscador->prox;
        }
        return NULL;
    }
}

