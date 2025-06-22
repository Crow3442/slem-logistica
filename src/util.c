#include <math.h>
#include <string.h>
#include "util.h"

float calcularDistancia(Local a, Local b) {
    return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

void limparNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}