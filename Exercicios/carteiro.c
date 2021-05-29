#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define cmpexch(A, B) { if(less(B, A)) exch(A, B) }

void intercala(Item *v, int l, int m, int r) {
    Item *c = malloc(sizeof(Item) * (r - l + 1));
    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r) {
        if(lesseq(v[i], v[j]))
            c[k++] = v[i++];
        else
            c[k++] = v[j++];
    }

    while(i <= m)
        c[k++] = v[i++];

    while(j <= r)
        c[k++] = v[j++];

    k = 0;
    for(i = l; i <= r; i++)
        v[i] = c[k++];

    free(c);
}

void merge_sort(Item *v, int l, int r) {
    if (l >= r) return;

    int meio = (l + r) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio + 1, r);

    intercala(v, l, meio, r);
}

int main() {

    int numero_casas, numero_encomendas, tempo = 0, casa_que_esta = 0;
    int ordem_casas[1000000], ordem_encomendas[100000];

    scanf("%d %d", &numero_casas, &numero_encomendas);

    for(int i = 0; i < numero_casas; i++)
        scanf("%d", &ordem_casas[i]);

    for(int i = 0; i < numero_encomendas; i++)
        scanf("%d", &ordem_encomendas[i]);

    for(int i = 0, j = 0; i < numero_encomendas; j++) {
        if(j == numero_casas) {
            j = -1;
            continue;
        }

        if(ordem_encomendas[i] == ordem_casas[j]) {
            if(casa_que_esta > j) tempo += (casa_que_esta - j);
            else tempo += (j - casa_que_esta);
            
            casa_que_esta = j;
            i++;
            continue;
        }
        
    }

    printf("%d\n", tempo);

    return 0;
}