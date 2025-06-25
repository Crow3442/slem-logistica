```markdown
# 🚚 SLEM – Sistema de Logística de Entrega de Mercadorias

Trabalho prático da disciplina **Algoritmos e Estruturas de Dados I** – Engenharia de Software  
Pontifícia Universidade Católica de Minas Gerais  
Professor: Ivan Luiz Vieira de Araújo

## 📌 Descrição do Projeto

O SLEM é um sistema de gerenciamento de entregas, desenvolvido em **C++** com base em estruturas e algoritmos estudados na disciplina. O sistema simula operações de logística, incluindo cadastro de locais, veículos e pedidos, além de cálculo de rotas de entrega.

Este projeto enfatiza a modularização, manipulação de arquivos binários/texto, abstração de dados com structs/classes, e lógica de roteamento com distância euclidiana.

---

## 🎯 Funcionalidades

- **CRUD de Locais** (nome, coordenadas X e Y)
- **CRUD de Veículos** (placa, modelo, status, localização)
- **CRUD de Pedidos** (ID, local de origem, destino, peso)
- **Cálculo de rota de entrega** com busca do veículo mais próximo
- **Simulação de entrega** com atualização de status e posição
- **Backup e restauração de dados** com arquivos binários
- **Menu interativo** em loop até opção SAIR

---

## 🗂 Estrutura de Diretórios

```
SLEM/
├── include/         # Arquivos .h (interfaces)
├── src/             # Arquivos .cpp (implementações)
├── data/            # Arquivos de dados binários
├── main.cpp         # Função principal (menu)
├── Makefile         # Script de compilação (opcional)
└── README.md        # Este arquivo
```

---

## ⚙️ Compilação e Execução

### 🔧 Compilação
```bash
g++ -o slem main.cpp src/*.cpp
```

### ▶️ Execução
```bash
./slem
```

---

## 🛠 Tecnologias e Restrições

- Linguagem: **C++ (sem uso de `std::string`)**
- Manipulação de arquivos: **stdio.h / C-style**
- Orientação a Objetos: **Recomendada**, mas não obrigatória
- Persistência: **Arquivos binários separados por entidade**

---

## 👥 Equipe

- João Eduardo Soares Moreira
- Rafael Nagem Volpini
```