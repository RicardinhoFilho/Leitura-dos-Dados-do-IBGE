#include <stdio.h>
#include <stdlib.h>

int ComparaEstados(char *estado1, char *estado2)
{

    int teste;
    for (int i = 0; i < 17; i++)
    {
        if (estado1[i] == estado2[i])
        {
            teste = 0;
        }
        else
        {
            teste = 1;
            break;
        }
    }

    return teste;
}

void igualaVetores(char *estado1, char *estado2)
{

    for (int i = 0; i < 17; i++)
    {
        estado1[i] = estado2[i];
    }
}

int main(void)
{

    int uf;
    char nomeUf[136];
    char estado[18];
    char estadoCompara[18];
    int cont = 1;

    FILE *file;

    file = fopen("./arquivos.txt/ibge_municipios_coluna_fixa_sem_cab.txt", "r");
    if (file == NULL)
    {
        printf("Arquivo não encontrado");
        return 0;
    }

    while (fgets(nomeUf, 136, file) != NULL)
    {

        for (int i = 0; i < 17; i++)
        {
            estado[i] = nomeUf[2 + i];
        }
        if (estado[0] > '9')
        {

            if (ComparaEstados(estadoCompara, estado) == 0)
            {
                cont++;
            }
            else
            {
                if (cont > 1)
                {
                    printf("Estado: %s", estadoCompara);
                    printf("  Quantidade: %i\n", cont);
                }

                cont = 1;
                igualaVetores(estadoCompara, estado);
            }
        }
    }

    fclose(file);

    return 0;
}