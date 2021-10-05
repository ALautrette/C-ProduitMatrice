#include <stdio.h>

void produitMatrice(int *, int, int, int *, int, int);
void afficheMatrice(int *, int, int);

int main(int argc, char *argv[])
{
    int tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tab2[6] = {1, 2, 3, 4, 5,6};
    int tab3[4] = {1, 0, 0, 1};
    // produitMatrice(tab, 3, 3, tab, 3, 3);
    // afficheMatrice(tab, 3, 3);
    produitMatrice(tab2, 3, 2, tab3, 2, 2); 
    // Test d'erreur
    // produitMatrice(tab2, 3, 2, tab3, 1, 2); 
    return 0;
}

void produitMatrice(int *m1, int l1, int c1, int *m2, int l2, int c2)
{
    afficheMatrice(m1, l1, c1);
    printf("\n*\n");
    afficheMatrice(m2, l2, c2);
    printf("\n=\n");
    if (c1 != l2)
    {
        printf("Multiplication impossible");
    }
    else
    {
        int *m;
        m = malloc(l1 * c2 * sizeof(int));
        int somme;
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                somme = 0;
                for (int k = 0; k < c1; k++)
                {
                    somme += m1[k + (c1 * i)] * m2[k * c2 + j];
                }
                m[i * c2 + j] = somme;
            }
        }
        afficheMatrice(m, l1, c2);
    }
}

void afficheMatrice(int *m, int l, int c)
{
    for (int i = 0; i < l * c; i++)
    {
        if ((i) % c == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%d ", m[i]);
    }
}