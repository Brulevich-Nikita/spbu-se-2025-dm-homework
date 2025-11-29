#include <stdio.h>

char reflective(int n, int m, char pairs[][2]) {
    int reflect_counter = 0;
    for (int i = 0; i < m; i++){
        if (pairs[i][0] == pairs[i][1]) {
            reflect_counter += 1;
        }
    }
    if (reflect_counter == n) return 'R';
    else return '*';
}

char symmetric(int m, char pairs[][2]) {
    int first;
    int second;
    int symmetric_counter = 0;
    for (int i = 0; i < m; i++){
        first = pairs[i][1];
        second = pairs[i][0];
        for (int j = 0; j < m; j++){
            if ((pairs[j][0] == first) && (pairs[j][1] == second)) {
                symmetric_counter += 1;
            }
        }
    }
    if (symmetric_counter == m) return 'S';
    else return '*';
}

char transitive(int m, char pairs[][2]) {
    int transitive_flag;
    for (int i = 0; i < m; i++) {
        int first = pairs[i][0];
        int trans_number = pairs[i][1];
        for (int j = 0; j < m; j++) {
            if (pairs[j][0] == trans_number) {
                int second = pairs[j][1];
                transitive_flag = 0;
                for (int k = 0; k < m; k++) {
                    if ((pairs[k][0] == first) && (pairs[k][1] == second)) {
                        transitive_flag += 1;      
                    }
                }
                if (transitive_flag == 0) return '*';
            }
        }
    }
    return 'T';
}

char antisymmetric(int m, char pairs[][2]) {
    for (int i = 0; i < m; i++) {
        int first = pairs[i][0];
        int second = pairs[i][1];
        for (int j = 0; j < m; j++) {
            if ((pairs[j][0] == second) && (pairs[j][1] == first) && (first != second)) {
                return '*';
            }
        }
    }
    return 'A';
}


int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    char alphabet[n];
    for (int i = 0; i < n; i++) {
        scanf( " %c", &alphabet[i]);
    }
    
    char pairs[m][2];
    for (int i = 0; i < m; i++){
        scanf(" %c %c", &pairs[i][0], &pairs[i][1]);
    }

    char output[5];
    output[0] = reflective(n, m, pairs);
    output[1] = symmetric (m, pairs);
    output[2] = transitive(m, pairs);
    output[3] = antisymmetric(m, pairs);
    output[4] = '\0';
    printf("%s\n", output);
}