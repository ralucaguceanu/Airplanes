#include "./utils.h"

#define two 2
#define four 4
#define five 5
#define thirteen 13

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    unsigned char directie = 0, tip = 0;
    int i = 0, j = 0, k = 0, count = 0;
    for (k = 0; k < nr_avioane; ++k) {
        directie = *(unsigned char*)(info + count + four);
        tip = *(unsigned char*)(info + count + five);
        i = *(unsigned short*)(info + count);
        j = *(unsigned short*)(info + count + two);
        mat[i][j] = '*';
        if (tip == '1') {
            if (directie == 'N') {
                mat[i + 1][j - 2] = mat[i + 1][j - 1] = mat[i + 1][j] =
                mat[i + 1][j + 1] = mat[i + 1][j + 2]= mat[i + 2][j] =
                mat[i + 3][j -1] = mat[i + 3][j] = mat[i + 3][j + 1] = '*';
            } else {
                if (directie == 'E') {
                    mat[i - 2][j - 1] = mat[i - 1][j - 1] = mat[i][j - 1] =
                    mat[i + 1][j - 1] = mat[i + 2][j - 1] = mat[i][j - 2] =
                    mat[i - 1][j - 3] = mat[i][j - 3] =
                    mat[i + 1][j - 3] = '*';
                } else {
                    if (directie == 'S') {
                        mat[i - 1][j - 2] = mat[i - 1][j - 1] = mat[i - 1][j] =
                        mat[i - 1][j + 1] = mat[i - 1][j + 2]= mat[i - 2][j] =
                        mat[i - 3][j -1] = mat[i - 3][j] =
                        mat[i - 3][j + 1] = '*';
                    } else {
                        mat[i - 2][j + 1] = mat[i - 1][j + 1] = mat[i][j + 1] =
                        mat[i + 1][j + 1] = mat[i + 2][j + 1] = mat[i][j + 2] =
                        mat[i - 1][j + 3] = mat[i][j + 3] =
                        mat[i + 1][j + 3] = '*';
                    }
                }
            }
        } else {
            if (directie == 'N') {
                mat[i + 1][j - 1] = mat[i + 1][j] = mat[i + 1][j + 1] =
                mat[i + 2][j - 3] = mat[i + 2][j - 2] = mat[i + 2][j - 1] =
                mat[i + 2][j] = mat[i + 2][j + 1] = mat[i + 2][j + 2] =
                mat[i + 2][j + 3] = mat[i + 3][j] = mat[i + 4][j - 2] =
                mat[i + 4][j - 1] = mat[i + 4][j] = mat[i + 4][j + 1] =
                mat[i + 4][j + 2] = '*';
            } else {
                if (directie == 'E') {
                    mat[i - 1][j - 1] = mat[i][j - 1] = mat[i + 1][j - 1] =
                    mat[i - 3][j - 2] = mat[i - 2][j - 2] = mat[i - 1][j - 2] =
                    mat[i][j - 2] = mat[i + 1][j - 2] = mat[i + 2][j - 2] =
                    mat[i + 3][j - 2] = mat[i][j - 3] = mat[i - 2][j - 4] =
                    mat[i - 1][j - 4] = mat[i][j - 4] = mat[i + 1][j - 4] =
                    mat[i + 2][j - 4] = '*';
                } else {
                    if (directie == 'S') {
                        mat[i - 1][j - 1] = mat[i - 1][j] = mat[i - 1][j + 1] =
                        mat[i - 2][j - 3] = mat[i - 2][j - 2] =
                        mat[i - 2][j - 1] = mat[i - 2][j] = mat[i - 2][j + 1] =
                        mat[i - 2][j + 2] = mat[i - 2][j + 3] = mat[i - 3][j] =
                        mat[i - 4][j - 2] = mat[i - 4][j - 1] = mat[i - 4][j] =
                        mat[i - 4][j + 1] = mat[i - 4][j + 2] = '*';
                    } else {
                        mat[i - 1][j + 1] = mat[i][j + 1] = mat[i + 1][j + 1] =
                        mat[i - 3][j + 2] = mat[i - 2][j + 2] =
                        mat[i - 1][j + 2] = mat[i][j + 2] = mat[i + 1][j + 2] =
                        mat[i + 2][j + 2] = mat[i + 3][j + 2] = mat[i][j + 3] =
                        mat[i - 2][j + 4] = mat[i - 1][j + 4] = mat[i][j + 4] =
                        mat[i + 1][j + 4] = mat[i + 2][j + 4] = '*';
                    }
                }
            }
        }
        count += thirteen;
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}
