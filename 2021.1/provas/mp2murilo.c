//by mulittle <3

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int score;
    int attempts;
} Contender;

Contender *readContenders(Contender *contenders, int curr, int size) {
    int i;
    contenders = (Contender *)realloc(contenders, sizeof(Contender) * size);
    for (i = (size - curr); i < size; i++) {
        printf("Enter the name of contender %d: ", i + 1);
        scanf(" %29[^\n]", contenders[i].name);
        printf("Enter the max attempts for contender %d: ", i + 1);
        scanf("%d", &contenders[i].attempts);
    }
    return contenders;
}

int **reallocMatrix(int **matrix, int size) {
    int i, j;
    matrix = (int **)realloc(matrix, size * sizeof(int *));
    if (matrix == NULL) {
        printf("Failed to allocate memory for the matrix.\n");
        exit(1);
    }
    for (i = 0; i < size; i++) {
        matrix[i] = (int *)realloc(matrix[i], size * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Failed to allocate memory for matrix[%d].\n", i);
            exit(1);
        }
        for (j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int **placeTreasures(int **matrix, int size, int *treasures) {
    int i, j;
    *treasures = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (((4 * i * i + 3 * j) % 11) == 0) {
                matrix[i][j] = 1;
                (*treasures)++;
            }
        }
    }

    return matrix;
}

void freeMatrix(int **matrix, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void findWinner(Contender *contenders, int size) {
    int greatest = 0;
    for (int i = 0; i < size; i++) {
        if (contenders[i].score > contenders[greatest].score) {
            greatest = i;
        }
    }

    printf("That's it! The final winner is %s, with a score of %d!\n", contenders[greatest].name, contenders[greatest].score);
}

int main() {
    Contender *contenders = NULL;
    int **matrix = NULL, size = 1, numTreasures, x, y;
    int contenderCurr, contenderTotal = 0;

    printf("Enter the size of the matrix for the current round: ");
    scanf("%d", &size);
    while (size != 0) {
        // Reads info of current round and sets the matrix up
        printf("Enter the amount of contenders for the current round: ");
        scanf("%d", &contenderCurr);
        contenderTotal += contenderCurr;
        contenders = readContenders(contenders, contenderCurr, contenderTotal);
        matrix = reallocMatrix(matrix, size);
        matrix = placeTreasures(matrix, size, &numTreasures);

        // Attempts of contenders
        for (int i = (contenderTotal - contenderCurr); i < contenderTotal; i++) {
            int attemptCnt = 1;
            while ((contenders[i].attempts > 0) && (numTreasures > 0)) {
                printf("%s, enter attempt %d (out of %d): ", contenders[i].name, attemptCnt, contenders[i].attempts);
                scanf("%d %d", &x, &y);
                if (matrix[x][y] == 1) {
                    printf("Congrats! You found an egg there!\n");
                    contenders[i].score++;
                    numTreasures--;
                    matrix[x][y] = 0;
                } else {
                    printf("No egg there, better luck next time :(\n");
                }
                contenders[i].attempts--;
                attemptCnt++;
            }
        }

        printf("Enter the size of the matrix for the current round: ");
        scanf("%d", &size);
    }

    findWinner(contenders, contenderTotal);

    freeMatrix(matrix, size);
    free(contenders);
}