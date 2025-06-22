# SLEM - Sistema de Logística de Entrega de Mercadorias

Este é um sistema desenvolvido como Trabalho Prático da disciplina **Algoritmos e Estruturas de Dados I** (PUC Minas - 1º semestre de 2025).

O sistema simula o gerenciamento de pedidos, veículos e locais de entrega, utilizando estruturas de dados e conceitos fundamentais da programação em C.

---

## 📦 Funcionalidades

- Cadastro, listagem, atualização e remoção de:
  - Locais
  - Veículos
  - Pedidos
- Cálculo da rota de entrega com distância euclidiana
- Simulação de entrega:
  - Seleção automática do veículo mais próximo disponível
  - Atualização de status e local do veículo
- Backup e restauração dos dados usando arquivos binários

---

## 📁 Estrutura do Projeto

```
SLEM/
├── main.c
├── includes/
│   ├── defines.h
│   ├── locais.h
│   ├── veiculos.h
│   ├── pedidos.h
│   └── util.h
├── src/
│   ├── locais.c
│   ├── veiculos.c
│   ├── pedidos.c
│   └── util.c
├── data/              # Arquivos binários gerados automaticamente
├── Makefile
├── DOCUMENTACAO.pdf   # Documento explicativo do sistema
└── README.md
```

---

## 🛠️ Compilação e Execução

### Pré-requisitos

- GCC instalado
- Terminal de comando (Linux/macOS/WSL ou MinGW no Windows)

### Compilar:

```bash
make
```

### Executar:

```bash
./slem
```

### Limpar arquivos compilados:

```bash
make clean
```

### Limpar também os backups:

```bash
make clean-all
```

---

## 💡 Observações Técnicas

- Linguagem: **C**
- Estilo modular, com arquivos `.c` e `.h` organizados
- Manipulação de arquivos binários para persistência
- Não usa o tipo `string` (restrição da disciplina)

---

## 👨‍🏫 Professor

Ivan Luiz Vieira de Araújo

---

## 🧑‍💻 Desenvolvedor

João Eduardo Soares Moreira

PUC Minas – Engenharia de Computação