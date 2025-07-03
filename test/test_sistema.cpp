#include "munit.h"
#include "../include/sistema.h"
#include <math.h>

Local makeLocal(float x, float y) {
    Local l;
    l.x = x;
    l.y = y;
    return l;
}

static void* test_setup(const MunitParameter params[], void* user_data) {
    return NULL;
}

static void test_calcularDistancia(const MunitParameter params[], void* user_data) {
    munit_assert_double(calcularDistancia(makeLocal(0, 0), makeLocal(3, 4)), ==, 5.0);        // Caso 1
    munit_assert_double(calcularDistancia(makeLocal(1, 1), makeLocal(1, 1)), ==, 0.0);        // Caso 2
    munit_assert_double(calcularDistancia(makeLocal(-1, -1), makeLocal(1, 1)), >, 2.82);      // Caso 3
    munit_assert_double(calcularDistancia(makeLocal(10, 5), makeLocal(5, 1)), >, 6.4);        // Caso 4
    munit_assert_double(calcularDistancia(makeLocal(0, 0), makeLocal(-3, -4)), ==, 5.0);      // Caso 5
}

static MunitTest tests[] = {
    {(char*)"/calcularDistancia", test_calcularDistancia, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    (char*)"/tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
