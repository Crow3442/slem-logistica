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

## 📁 Estrutura de Diretórios

```
SLEM/
├── include/      # Arquivos .h (interfaces)
├── src/          # Arquivos .cpp (implementações)
├── data/         # Arquivos de dados binários
├── main.cpp      # Função principal (menu)
├── Makefile      # Script de compilação (automatizado)
└── README.md     # Este arquivo
```

---

## ⚙️ Compilação e Execução

### ✅ Usando Make (recomendado)

Este projeto possui um `Makefile` com suporte a:

| Comando         | O que faz                                            |
|-----------------|------------------------------------------------------|
| `make`          | Compila o projeto e gera o executável `slem.exe`     |
| `make run`      | Compila (se necessário) e executa o programa         |
| `make clean`    | Remove o executável                                  |
| `make rebuild`  | Limpa e recompila tudo do zero                       |

> 💡 Use **Git Bash**, **MinGW** ou **PowerShell com Make instalado** no Windows.

### 🔧 Compilação manual (alternativa)

Se preferir compilar diretamente, use:

```bash
g++ -Wall -Iinclude -o slem main.cpp src/locais.cpp
```

E para executar:

```bash
./slem
```

---

## 👥 Equipe

- João Eduardo Soares Moreira  
- Rafael Nagem Volpini

---

## 🧰 Como configurar e rodar o projeto

### ✅ Requisitos

Para compilar e executar este projeto, você precisa ter:

- [GCC/G++ (compilador C++)](https://jmeubank.github.io/pt-br/GCC-Installer/)
- [Make](https://chocolatey.org/packages/make) (opcional, mas recomendado)
- Um terminal compatível (Git Bash, PowerShell, CMD ou Windows Terminal)

---

### ⚙️ Passos para configurar no Windows

1. **Instale o compilador C++:**
   - Baixe e instale o GCC/G++ pelo link:
     https://jmeubank.github.io/pt-br/GCC-Installer/

2. **Instale o Make com Chocolatey:**
   - Se ainda não tiver o Chocolatey, abra o PowerShell como administrador e execute:
     ```powershell
     Set-ExecutionPolicy Bypass -Scope Process -Force; `
     [System.Net.ServicePointManager]::SecurityProtocol = `
     [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; `
     iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
     ```

   - Depois, instale o make:
     ```powershell
     choco install make
     ```

3. **Abra o terminal, vá até a pasta do projeto:**
   ```bash
   cd caminho/para/SLEM
   ```

4. **Compile e execute:**
   ```bash
   make run
   ```

---

> ⚠️ Certifique-se de que todos os arquivos estão salvos em UTF-8 (sem BOM), especialmente se usar acentos nos textos.