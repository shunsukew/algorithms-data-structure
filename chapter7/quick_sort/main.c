#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

int partition(struct Card A[], int n, int p, int r) {
    int i, j;
    struct Card t, x;
    x = A[r];
    i = p-1;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }

    t = A[i + 1]; A[i + 1] = A[r], A[r] = t;
    return i + 1;
}

int quickSort(struct Card A[], int n, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q -1);
        quickSort(A, n, q+1, r);
    }
}

int main() {
    int n, i, v;
    struct Card A[MAX];
    char S[10];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %d", S, &v);
        A[i].suit = S[0];
        A[i].value = v;
    }

    quickSort(A, n, 0, n-1);

    for (i = 0; i < n; i++) {
        printf("%c %d\n", A[i].suit, A[i].value);
    }

    return 0;
}