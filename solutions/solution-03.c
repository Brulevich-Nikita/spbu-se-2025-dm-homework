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


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (alphabet[j] > alphabet[j+1]) {
                char tmp = alphabet[j];
                alphabet[j] = alphabet[j+1];
                alphabet[j+1] = tmp;
            }
        }
    }

    char sorted[n];
    char max[n];
    int sorted_counter = 0;
    int max_counter = 0;

    for (int i = 0; i < n; i++) {
        sorted[i] = '0';
        max[i] = '0';
    }


    //Выявление максимальных элементов заранее
    for (int i = 0; i < n; i++) {
        int counter_first = 0;
        int counter_second = 0;
        for (int j = 0; j < m; j++) {
            if (pairs[j][0] == alphabet[i]) {
                counter_first++;
            }
            if (pairs[j][1] == alphabet[i]) {
                counter_second++;
            }
        }
        if ((counter_second > 0) && (counter_first == 0)) {
            max[i] = alphabet[i];
            max_counter += 1;
        }
    }

    //Выявление элементов без рёбер
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < m; j++) {
            if (pairs[j][0] == alphabet[i] || pairs[j][1] == alphabet[i]) {
                counter+=1;
            }
        }
        if (counter == 0) {
            sorted[sorted_counter] = alphabet[i];
            sorted_counter += 1;
        }
    }

    //Сортировка всех немаксимальных элементов, имеющих рёбра
    while (sorted_counter < (n - max_counter)) {
        for (int i = 0; i < n; i++) {
            int counter_first = 0;
            int counter_second = 0;
            for (int j = 0; j < m; j++) {
                if ((pairs[j][0] == alphabet[i]) && (alphabet[i] != '0') && (pairs[j][1] != '0')) {
                    counter_first++;
                }
                if ((pairs[j][1] == alphabet[i]) && (alphabet[i] != '0') && (pairs[j][0] != '0')) {
                    counter_second++;
                }
            }
            if (counter_second == 0 && counter_first > 0) {
                sorted[sorted_counter] = alphabet[i];
                sorted_counter++;
                for (int k = 0; k < m; k++) {
                    if (pairs[k][0] == alphabet[i]) {
                        pairs[k][0] = '0';
                    }
                    if (pairs[k][1] == alphabet[i]) {
                        pairs[k][1] = '0';
                    }
                }
                alphabet[i] = '0';
            }
        }
    }
    for (int i = 0; i < sorted_counter; i++) {
        printf("%c %d\n", sorted[i], i+1);
    }

    for (int i = 0; i < n; i++) {
        if (max[i] != '0') {
            printf("%c %d\n", max[i], sorted_counter + 1);
            sorted_counter += 1;
        }
    }
}