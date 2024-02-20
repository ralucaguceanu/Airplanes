#include "./utils.h"

#define two 2
#define four 4
#define five 5
#define six 6
#define seven 7
#define eight 8
#define nine 9
#define thirteen 13

void SolveTask1(void *info, int nr_avioane) {
    int count = 0, i = 0;
    for (i = 0; i < nr_avioane; ++i) {
        printf("(%hu, %hu)\n%c\n%c%c%c%c\n%u",
        *(unsigned short*)(info + count),
        *(unsigned short*)(info + count + two),
        *(unsigned char*)(info + count + four),
        *(unsigned char*)(info + count + five),
        *(unsigned char*)(info + count + six),
        *(unsigned char*)(info + count + seven),
        *(unsigned char*)(info + count + eight),
        *(unsigned int*)(info + count + nine));
        count += thirteen;
        printf("\n\n");
    }
}
