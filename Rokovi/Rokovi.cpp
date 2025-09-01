#ifndef prviJesenskiRok
#define prviJesenskiRok "prvi.c"
#include prviJesenskiRok
#endif


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

int main()
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
    return 0;
}
