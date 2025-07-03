#include "munit.h"
#include "../include/veiculos.h"

Veiculo makeVeiculo(const char* placa) {
    Veiculo v;
    strcpy(v.placa, placa);
    return v;
}

static void* test_setup(const MunitParameter params[], void* user_data) {
    return NULL;
}

static void test_encontrarVeiculoPorPlaca(const MunitParameter params[], void* user_data) {
    Veiculo veiculos[3];
    veiculos[0] = makeVeiculo("ABC1234");
    veiculos[1] = makeVeiculo("DEF5678");
    veiculos[2] = makeVeiculo("GHI9012");

    munit_assert_int(encontrarVeiculoPorPlaca(veiculos, 3, "ABC1234"), ==, 0); // Caso 1
    munit_assert_int(encontrarVeiculoPorPlaca(veiculos, 3, "ZZZ9999"), ==, -1); // Caso 2
    munit_assert_int(encontrarVeiculoPorPlaca(veiculos, 3, NULL), ==, -1); // Caso 3
    munit_assert_int(encontrarVeiculoPorPlaca(veiculos, 0, "ABC1234"), ==, -1); // Caso 4
    munit_assert_int(encontrarVeiculoPorPlaca(veiculos, 3, "abc1234"), ==, -1); // Caso 5
}

static MunitTest tests[] = {
    {(char*)"/encontrarVeiculoPorPlaca", test_encontrarVeiculoPorPlaca, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    (char*)"/tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
