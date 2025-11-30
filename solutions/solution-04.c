#include <stdio.h>

char alphabet[8];
char current[8];
int used[8];
int n;

void permutations(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++)
            printf("%c ", current[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            used[i] = 1;
            current[pos] = alphabet[i];
            permutations(pos + 1);
            used[i] = 0;
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %c", &alphabet[i]);
    //for (int i = 0; i < n - 1; i++)
    //    for (int j = 0; j < n - 1 - i; j++)
     //       if (alphabet[j] > alphabet[j + 1]) {
     //           char t = alphabet[j];
       //         alphabet[j] = alphabet[j + 1];
      //          alphabet[j + 1] = t;
       //     }

    permutations(0);
    printf("\n");
}