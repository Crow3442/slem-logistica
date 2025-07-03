#include "munit.h"
#include "../include/locais.h"

static void* test_setup(const MunitParameter params[], void* user_data) {
    return NULL;
}

static void test_nomeInvalido(const MunitParameter params[], void* user_data) {
    munit_assert_int(nomeInvalido("   "), ==, 1);      // Caso 1: só espaços
    munit_assert_int(nomeInvalido(""), ==, 1);         // Caso 2: string vazia
    munit_assert_int(nomeInvalido("BH"), ==, 0);       // Caso 3: nome válido
    munit_assert_int(nomeInvalido("   SP"), ==, 0);    // Caso 4: nome com espaços mas válido
}

static MunitTest tests[] = {
    {(char*)"/nomeInvalido", test_nomeInvalido, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    (char*)"/tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
