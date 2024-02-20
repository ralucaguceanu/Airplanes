#include "./utils.h"

#define two 2
#define four 4
#define five 5
#define thirteen 13

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    int i = 0, j = 0, passed = 1, nr = 0, coord1 = 0, coord2 = 0;
    unsigned char directie = 0, tip = 0;
    int count = 0;
    for (i = 0; i < nr_avioane; ++i) {
        coord1 = *(unsigned short*)(info + count);
        coord2 = *(unsigned short*)(info + count + two);
        directie = *(unsigned char*)(info + count + four);
        tip = *(unsigned char*)(info + count + five);

        /*  pentru fiecare tip de avion, in functie de directie, se verifica
        daca exista vreun obstacol inaintea aripilor sau pe acestea, respectiv
        daca exista vreun obstacol pe portiunea dintre aripi si coada
        avionului  */
        if (tip == '1') {
            if (directie == 'N') {
                for (j = 0; j < nr_obstacole; ++j) {
                    if ((x[j] <= coord1 + 1
                    && coord2 - 2 <= y[j] && coord2 + 2 >= y[j]) ||
                    (x[j] > coord1 + 1 && x[j] <= coord1 + 3 &&
                    coord2 - 1 <= y[j] && coord2 + 1 >= y[j])) {
                        passed = 0;
                    }
                }
            } else {
                if (directie == 'E') {
                    for (j = 0; j < nr_obstacole; ++j) {
                        if ((y[j] >= coord2 - 1 &&
                        coord1 - 2 <= x[j] && coord1 + 2 >= x[j]) ||
                        (y[j] >= coord2 - 3 && y[j] < coord2 - 1 &&
                        coord1 - 1 <= x[j] && coord1 + 1 >= x[j])) {
                            passed = 0;
                        }
                    }
                } else {
                    if (directie == 'S') {
                        for (j = 0; j < nr_obstacole; ++j) {
                            if ((x[j] >= coord1 - 1 && coord2 - 2 <= y[j]
                            && coord2 + 2 >= y[j]) ||
                            (x[j] >= coord1 - 3 && x[j] < coord1 - 1 &&
                            coord2 - 1 <= y[j] && coord2 + 1 >= y[j])) {
                                passed = 0;
                            }
                        }
                    } else {
                        for (j = 0; j < nr_obstacole; ++j) {
                            if ((y[j] <= coord2 + 1 && coord1 - 2 <= x[j]
                            && coord1 + 2 >= x[j]) ||
                            (y[j] <= coord2 + 3 && y[j] > coord2 + 1 &&
                            coord1 - 1 <= x[j] && coord1 + 1 >= x[j])) {
                                passed = 0;
                            }
                        }
                    }
                }
            }
        } else {
            if (directie == 'N') {
                for (j = 0; j < nr_obstacole; ++j) {
                    if ((x[j] <= coord1 + 2 && coord2 - 3 <= y[j]
                    && coord2 + 3 >= y[j]) ||
                    (x[j] > coord1 + 2 && x[j] <= coord1 + 4 &&
                    coord2 - 2 <= y[j] && coord2 + 2 >= y[j])) {
                        passed = 0;
                    }
                }
            } else {
                if (directie == 'E') {
                    for (j = 0; j < nr_obstacole; ++j) {
                        if ((y[j] >= coord2 - 2 && coord1 - 3 <= x[j] &&
                        coord1 + 3 >= x[j]) ||
                        (y[j] >= coord2 - 4 && y[j] < coord2 - 2
                        && coord1 - 2 <= x[j] && coord1 + 2 >= x[j])) {
                            passed = 0;
                        }
                    }
                } else {
                    if (directie == 'S') {
                        for (j = 0; j < nr_obstacole; ++j) {
                            if ((x[j] >= coord1 - 2 && coord2 - 3 <= y[j]
                            && coord2 + 3 >= y[j]) ||
                            (x[j] >= coord1 - 4 && x[j] < coord1 - 2 &&
                            coord2 - 2 <= y[j] && coord2 + 2 >= y[j])) {
                                passed = 0;
                            }
                        }
                    } else {
                        for (j = 0; j < nr_obstacole; ++j) {
                            if ((y[j] <= coord2 + 2 && coord1 - 3 <= x[j] &&
                            coord1 + 3 >= x[j]) ||
                            (y[j] <= coord2 + 4 && y[j] > coord2 + 2
                            &&coord1 - 2 <= x[j] && coord1 + 2 >= x[j])) {
                                passed = 0;
                            }
                        }
                    }
                }
            }
        }
        if (passed == 1) {
            ++nr;
        }
        passed = 1;
        count += thirteen;
    }
    printf("%d", nr);
}
