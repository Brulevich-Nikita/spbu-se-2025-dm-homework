#include <stdio.h>

char alphabet[8];
char current[8];
int n;
int k;

void combinations(int pos, int start) {
    if (pos == k) {
        for (int i = 0; i < k; i++)
            printf("%c ", current[i]);
        printf("\n");
        return;
    }
    for (int i = start; i < n; i++) {
        current[pos] = alphabet[i];
        combinations(pos + 1, i + 1);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf(" %c", &alphabet[i]);

    combinations(0, 0);
    printf("\n");
}