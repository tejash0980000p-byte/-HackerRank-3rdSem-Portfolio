#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char* s) {

    char* result = (char*)malloc(9 * sizeof(char));

    int hh, mm, ss;
    char meridian[3];

    sscanf(s, "%d:%d:%d%2s", &hh, &mm, &ss, meridian);

    if (strcmp(meridian, "AM") == 0) {
        if (hh == 12) {
            hh = 0;
        }
    } else {
        if (hh != 12) {
            hh += 12;
        }
    }

    snprintf(result, 9, "%02d:%02d:%02d", hh, mm, ss);
    return result;
}

int main() {
    char s[11];
    if (scanf("%10s", s) != 1) return 0;

    char* result = timeConversion(s);
    printf("%s\n", result);

    free(result);
    return 0;
}
