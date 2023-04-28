#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

#define MAX_LENGTH 10

typedef struct {
    char numeral;
    int value;
} numerals;

int romanToInt(char * s, size_t length) {

    numerals array[7];

    int total;

    numerals i = {'I', I};
    numerals v = {'V', V};
    numerals x = {'X', X};
    numerals l = {'L', L};
    numerals c = {'C', C};
    numerals d = {'D', D};
    numerals m = {'M', M};

    array[0] = i;
    array[1] = v;
    array[2] = x;
    array[3] = l;
    array[4] = c;
    array[5] = d;
    array[6] = m;

    int number[MAX_LENGTH];

    for (int j = 0; j < MAX_LENGTH; j++) {
        number[j] = 0;
    }

    printf("LENGTH: %lu", length);

    int prev;
    int curr;

    for (int j = 0; j < length; j++) {

        for (int k = 0; k < 7; k++) {

            switch (prev) {
                case 1:
                    if (curr == 5 || curr == 10) {
                        number[j] = curr - prev;
                    }

                    else {
                        number[j] = curr;
                    }

                    break;

                case 10:
                    if (curr == 50 || curr == 100) {
                        number[j] = curr - prev;
                    }

                    else {
                        number[j] = curr;
                    }

                    break;

                case 100:
                    if (curr == 500 || curr == 1000) {
                        number[j] = curr - prev;
                    }

                    else {
                        number[j] = curr;
                    }

                    break;

                default:
                    number[j] = curr;
                    break;

            }

            if (strcmp(&s[j], &(array[k].numeral)) == 0) {
                    curr = array[k].value;
            }
        }
        prev = curr;
    }

    for (int j = 0; j < MAX_LENGTH; j++) {
        printf("%d", number[j]);
    }

    /*printf("Output: %d\n", total);*/

    return total;
}

int main() {

    char *number = "III";

    romanToInt(number, 3);

    return 1;
}
