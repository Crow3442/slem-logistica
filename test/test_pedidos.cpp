#include "munit.h"
#include "../include/pedidos.h"

Pedido makePedido(int ativo, int veiculo, StatusPedido status) {
    Pedido p;
    p.ativo = ativo;
    p.idVeiculo = veiculo;
    p.status = status;
    return p;
}

static void* test_setup(const MunitParameter params[], void* user_data) {
    return NULL;
}

static void test_veiculoEmUso(const MunitParameter params[], void* user_data) {
    Pedido pedidos[3];
    pedidos[0] = makePedido(1, 2, EM_ENTREGA);
    pedidos[1] = makePedido(1, 2, PENDENTE);
    pedidos[2] = makePedido(1, 1, EM_ENTREGA);

    munit_assert_int(veiculoEmUso(2, pedidos, 3, -1), ==, 1);
    munit_assert_int(veiculoEmUso(2, pedidos + 1, 1, -1), ==, 0);
    munit_assert_int(veiculoEmUso(1, pedidos, 3, 2), ==, 0);
    munit_assert_int(veiculoEmUso(-1, pedidos, 3, -1), ==, 0);
    munit_assert_int(veiculoEmUso(2, pedidos, 0, -1), ==, 0);
}

static MunitTest tests[] = {
    {(char*)"/veiculoEmUso", test_veiculoEmUso, test_setup, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    (char*)"/tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}