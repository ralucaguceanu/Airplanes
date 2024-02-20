#include "./utils.h"

#define two 2
#define four 4
#define five 5
#define six 6
#define seven 7
#define eight 8
#define nine 9
#define thirteen 13
#define SIZE 50

typedef struct {
    unsigned short linie;
    unsigned short coloana;
    unsigned char directie;
    unsigned char tip;
    unsigned char firstLetter;
    unsigned char secondLetter;
    unsigned char thirdLetter;
    unsigned int viteza;
} quickStruct;

//  criteriile de comparatie folosite de qsort

int compare(const void *a, const void *b) {
    quickStruct *firstAirplane = (quickStruct *) a;
    quickStruct *secondAirplane = (quickStruct *) b;
    if (firstAirplane->tip < secondAirplane->tip) {
        return -1;
    } else {
        if (firstAirplane->tip > secondAirplane->tip) {
            return 1;
        } else {
            if (firstAirplane->firstLetter > secondAirplane->firstLetter) {
                return -1;
            } else {
                if (firstAirplane->firstLetter < secondAirplane->firstLetter) {
                    return 1;
                } else {
                    if (firstAirplane->secondLetter >
                    secondAirplane->secondLetter) {
                        return -1;
                    } else {
                        if (firstAirplane->secondLetter <
                        secondAirplane->secondLetter) {
                            return 1;
                        } else {
                            if (firstAirplane->thirdLetter >
                            secondAirplane->thirdLetter) {
                                return -1;
                            } else {
                                if (firstAirplane->thirdLetter <
                                secondAirplane->thirdLetter) {
                                    return 1;
                                } else {
                                    if (firstAirplane->viteza <
                                    secondAirplane->viteza) {
                                        return -1;
                                    } else {
                                        if (firstAirplane->viteza >
                                        secondAirplane->viteza) {
                                            return 1;
                                        } else {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void SolveTask3(void *info, int nr_avioane) {
    int count = 0;
    quickStruct airplanes[SIZE];  //  vector cu informatiile despre avioane
    for (int i = 0; i < nr_avioane; ++i) {
        airplanes[i].linie = *(unsigned short*)(info + count);
        airplanes[i].coloana = *(unsigned short*)(info + count + two);
        airplanes[i].directie = *(unsigned char*)(info + count + four);
        airplanes[i].tip = *(unsigned char*)(info + count + five);
        airplanes[i].firstLetter = *(unsigned char*)(info + count + six);
        airplanes[i].secondLetter = *(unsigned char*)(info + count + seven);
        airplanes[i].thirdLetter = *(unsigned char*)(info + count + eight);
        airplanes[i].viteza = *(unsigned int*)(info + count + nine);
        count = count + thirteen;
    }
    qsort(airplanes, nr_avioane, sizeof(quickStruct), compare);
    count = 0;
    for (int i = 0; i < nr_avioane; i++) {
        printf("(%hu, %hu)\n%c\n%c%c%c%c\n%u",
        airplanes[i].linie,
        airplanes[i].coloana,
        airplanes[i].directie,
        airplanes[i].tip,
        airplanes[i].firstLetter,
        airplanes[i].secondLetter,
        airplanes[i].thirdLetter,
        airplanes[i].viteza);
        count = count + thirteen;
        printf("\n\n");
    }
}
