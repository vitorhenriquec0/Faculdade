# define Pai(i) ((i - 1) /2)
# define F_esq(i) (2 * i + 1)
# define F_dir(i) (2 * i + 2)

typedef struct {
    int chave;
} Tipo_elem;

typedef struct {
    Tipo_elem *A;
    int n;
    int tam;
} Fila_pri;

typedef Fila_pri *fp;

void permuta (Tipo_elem *a, Tipo_elem *b) {
    Tipo_elem aux = *a;
    *a = *b;
    *b = aux;
}

void Insere (fp filapri, Tipo_elem elem) {
    filapri->A[filapri->n] = elem;
    filapri->n++;
    Sobe_no_heap(filapri, filapri->n  - 1);
}

void Sobe_no_heap(fp filapri, int k) {
    if (k > 0 && filapri->A[Pai(k)].chave < filapri->A[k].chave) {
        permuta(&filapri->A[k], &filapri->A[Pai(k)]);
        Sobe_no_heap(filapri, Pai(k));
    }
}

Tipo_elem Remove_maior(fp filapri) {
    Tipo_elem aux = filapri->A[0];
    permuta(&(filapri->A[0]), &(filapri->A[filapri->n - 1]));
    filapri->n--;
    Desce_no_heap(filapri, 0);
    
    return aux;
}

void Desce_no_heap(fp filapri, int k) {
    int maior_filho;
    
    if (F_esq(k) < filapri->n) {

        maior_filho = F_esq(k);

        if (F_dir(k) < filapri->n && filapri->A[F_dir(k)].chave > filapri->A[F_esq(k)].chave) {
            maior_filho = F_dir(k);
        }

        if (filapri->A[k].chave < filapri->A[maior_filho].chave) {
            permuta(&filapri->A[k], &filapri->A[maior_filho]);
            Desce_no_heap(filapri, maior_filho);
        }
    }
}

void altera_prioridade (fp filapri, int k, int valor) {
    if (filapri->A[k].chave < valor) {
        filapri->A[k].chave = valor;
        Sobe_no_heap(filapri, k);
    } else {
        filapri->A[k].chave = valor;
        Desce_no_heap(filapri, k);
    }
}

void constroi_heap (fp filapri) {
    for (int i = (filapri->n - 1) / 2; i >= 0; i--) {
        Desce_no_heap(filapri, i);
    }
}

void HeapSort(fp filapri) {
    int i;

    for (i = (filapri->n - 1) / 2; i >= 0; i--)
        Desce_no_heap(filapri, i);

    i = filapri->n;

    while (filapri->n > 1) {
        permuta(&filapri->A[0], &filapri->A[filapri->n - 1]);
        filapri->n--;
        Desce_no_heap(filapri, 0);
    }

    filapri->n = i;

}