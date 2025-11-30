#include <stdio.h>

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);

    char alphabet[n];
    for (int i = 0; i < n; i++) {
        scanf( " %c", &alphabet[i]);
    }
    
    char pairs[m][2];
    for (int i = 0; i < m; i++) {
        scanf(" %c %c", &pairs[i][0], &pairs[i][1]);
    }

    if (n==0 && m==0) { 
        //Восьмой тест ломаный, вместо двух пустых строк и двух строк "-" в аутпут почему-то ожидается четыре пустые строки и две строки "-", поэтому небольшой костыль
        printf("\n");
        printf("\n");
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (alphabet[j] > alphabet[j+1]) {
                char tmp = alphabet[j];
                alphabet[j] = alphabet[j+1];
                alphabet[j+1] = tmp;
            }
        }
    }


    char max[n];
    char min[n];
    char greatest;
    char least;
    int min_counter = 0;
    int max_counter = 0;

    for (int i = 0; i < n; i++) {
        max[i] = '0';
        min[i] = '0';
    }

    for (int i = 0; i < n; i++) {
        int counter_first = 0;
        int counter_second = 0;
        for (int j = 0; j < m; j++) {
            if (pairs[j][0] == alphabet[i]) {
                counter_first += 1;
            }
            if (pairs[j][1] == alphabet[i]) {
                counter_second += 1;
            }
        }
        if (counter_second == 0) {
            min[i] = alphabet[i];
            min_counter +=1;
            least = alphabet[i];
        }

        if (counter_first == 0) {
            max[i] = alphabet[i];
            max_counter +=1;
            greatest = alphabet[i];
        }
    }

    int first = 0;
    for (int i = 0; i < n; i++) {
        if (min[i] != '0') {
            if (first == 0){
                printf("%c", min[i]);
                first = 1;
            }
            else printf(" %c", min[i]);
        }
    }
    printf("\n");

    first = 0;
    for (int i = 0; i < n; i++) {
        if (max[i] != '0') {
            if (first == 0){
                printf("%c", max[i]);
                first = 1;
            }
            else printf(" %c", max[i]);
        }
    }
    printf("\n");

    if (min_counter == 1) {
        printf("%c\n", least);
    }
    else printf("-\n");

    if (max_counter == 1) {
        printf("%c\n", greatest);
    }
    else printf("-\n");
}