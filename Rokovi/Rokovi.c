#define _CRT_SECURE_NO_WARNINGS
#ifndef prviJesenskiRok
#define prviJesenskiRok
#define PrviZadatak "prvi.c"
//#define DrugiZadatak "drugi.c"
#include PrviZadatak
//#include DrugiZadatak
#endif

#define NMAX 100


void PrintLinkedList(oe* list) {
    oe* temp = (oe*)malloc(sizeof(oe));
    temp = list;
    while (temp != NULL)
    {
        printf("%d ", temp->x);
        temp = temp->sljedeci;
    }
    printf("\n");
}

void TestPrvi()
{
    oe* lista = (oe*)malloc(sizeof(oe));
    lista = NULL;
    lista = InsertAtEnd(lista, 5);
    lista = InsertAtEnd(lista, 3);
    lista = InsertAtEnd(lista, 2);

    PrintLinkedList(lista);

    lista = DeleteFront(lista);

    PrintLinkedList(lista);

    oe* lista2 = (oe*)malloc(sizeof(oe));
    lista2 = NULL;

    lista2 = InsertAtEnd(lista2, 1);
    lista2 = InsertAtEnd(lista2, 2);
    lista2 = InsertAtEnd(lista2, 3);
    lista2 = InsertAtEnd(lista2, 4);
    lista2 = InsertAtEnd(lista2, 5);

    lista = ConcatLists(lista, lista2);

    PrintLinkedList(lista);
}
int tree[NMAX][3];

void TestDrugi()
{
    int N, i;
    char red[100];
    float ar_sredina = 0;
    fgets(red, 100, stdin);
    sscanf(red, "%d", &N);
    for (i = 0; i < N; i++)
    {
        fgets(red, 100, stdin);
        sscanf(red, "%d %d %d", &tree[i][0], &tree[i][1], &tree[i][2]);
        tree[i][1]--;
        tree[i][2]--;
    }

    /*KOD*/
    
    int suma = 0, broj = 0;

    for (i = 0; i < N; i++)
    {
        if (tree[i][1] != -1) {
            suma += tree[tree[i][1]][0];
            broj++;
        }

    }
    if (broj == 0)
    {
        printf("nema %d", tree[0][0]);
    }
    else
    {
        ar_sredina = (float) suma / broj;
        //ispis

        printf("%0.2f", ar_sredina);
    }
    return;
}

int main()
{
    //TestPrvi();
    TestDrugi();
    return 0;
}
