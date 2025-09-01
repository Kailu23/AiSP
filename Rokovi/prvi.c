#include <stdio.h>
#include <stdlib.h>

struct oe {
    int x;
    struct oe* sljedeci;
};

typedef struct oe oe;

oe* InsertAtEnd(oe* L, int X) {
    oe* novi = (oe*)malloc(sizeof(oe));
    if (!novi) return L;
    novi->x = X;
    novi->sljedeci = NULL;

    if (L == NULL) {
        return novi;
    }

    oe* temp = L;
    while (temp->sljedeci != NULL) {
        temp = temp->sljedeci;
    }
    temp->sljedeci = novi;

    return L;
}

oe* ConcatLists(oe* L1, oe* L2) {
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    oe* temp = L1;
    while (temp->sljedeci != NULL)
        temp = temp->sljedeci;

    temp->sljedeci = L2;
    return L1;
}

oe* DeleteFront(oe* L) {
    if (L == NULL) return NULL;

    oe* noviPocetak = L->sljedeci;
    free(L);
    return noviPocetak;
}