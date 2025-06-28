# 🚚 SLEM – Sistema de Logística de Entrega de Mercadorias

Trabalho prático da disciplina **Algoritmos e Estruturas de Dados I** – Engenharia de Software  
Pontifícia Universidade Católica de Minas Gerais  
Professor: Ivan Luiz Vieira de Araújo

---

## 📌 Descrição do Projeto

O SLEM é um sistema de gerenciamento de entregas, desenvolvido em **C++** com base em estruturas e algoritmos estudados na disciplina. O sistema simula operações de logística, incluindo cadastro de locais, veículos e pedidos, além de cálculo de rotas de entrega com distância euclidiana.

Este projeto enfatiza a modularização, manipulação de arquivos binários, abstração de dados com structs, e lógica de roteamento. Também foram incluídos scripts auxiliares para geração de dados de teste e um `Makefile` para automação da compilação e execução.

---

## 🎯 Funcionalidades

- **CRUD de Locais** (nome, coordenadas X e Y)
- **CRUD de Veículos** (placa, modelo, status, localização)
- **CRUD de Pedidos** (origem, destino, peso, status, veículo vinculado)
- **Entrega em duas etapas**: iniciar e finalizar entrega
- **Cálculo de rota** com busca do veículo mais próximo (distância euclidiana)
- **Atualização automática de status e posição**
- **Backup e restauração** com arquivos binários
- **Scripts para geração de dados de exemplo**
- **Menu interativo** em loop até a opção SAIR

---

## 📁 Estrutura de Diretórios

```
SLEM/
├── include/        # Arquivos .h (interfaces)
├── src/            # Arquivos .cpp (implementações)
├── tools/          # Scripts para gerar dados de exemplo
├── data/           # Arquivos de dados binários gerados (.dat)
├── main.cpp        # Função principal (menu)
├── Makefile        # Script de compilação e execução
└── README.md       # Este arquivo
```

---

## ⚙️ Compilação e Execução

### ✅ Usando Make (recomendado)

O `Makefile` oferece suporte aos seguintes comandos:

| Comando             | Ação                                                      |
|---------------------|-----------------------------------------------------------|
| `make`              | Compila o projeto principal e gera `slem.exe`             |
| `make run`          | Executa o programa principal                              |
| `make clean`        | Remove apenas `slem.exe`                                  |
| `make locais`       | Compila e executa o script de locais                      |
| `make veiculos`     | Compila e executa o script de veículos                    |
| `make pedidos`      | Compila e executa o script de pedidos                     |
| `make dados`        | Executa todos os três scripts de geração de dados         |
| `make clean-tools`  | Remove os executáveis dos scripts de dados                |
| `make clean-all`    | Remove todos os executáveis (principal + scripts)         |

---

## 🧰 Como Configurar e Rodar o Projeto

### ✅ Requisitos

| Tecnologia | Função                         | Link Oficial                                      |
|------------|--------------------------------|---------------------------------------------------|
| **GCC/G++**| Compilador C/C++               | https://gcc.gnu.org/                              |
| **Make**   | Automação de compilação        | https://www.gnu.org/software/make/               |
| **MinGW**  | GCC e Make para Windows        | https://www.mingw-w64.org/                        |
| **Git Bash** | Terminal compatível no Windows| https://git-scm.com/downloads                    |

---

### 🪟 Windows (recomendado)

1. **Instale o GCC/G++ com MinGW:**
   - https://www.mingw-w64.org/

2. **Instale o Chocolatey (se ainda não tiver):**
   - Abra o **PowerShell como Administrador**
   - Execute:

   ```powershell
   Set-ExecutionPolicy Bypass -Scope Process -Force; `
   [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; `
   iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
   ```

3. **Instale o Make com Chocolatey:**

   ```powershell
   choco install make
   ```

4. **Use o Git Bash ou PowerShell para rodar o projeto:**

   ```bash
   cd caminho/para/SLEM
   make run
   ```

---

### 🐧 Linux / WSL

```bash
sudo apt update
sudo apt install build-essential make
make run
```

---

## 📊 Análise de Complexidade

### 🔍 Busca do Veículo Mais Próximo
- Varre todos os veículos disponíveis
- Calcula a distância entre o local atual do veículo e o local de origem do pedido
- **Complexidade da operação: O(n)**, onde n = número de veículos

---

## 👥 Equipe

- João Eduardo Soares Moreira  
- Rafael Nagem Volpini

---

> O sistema foi testado, validado e cumpre todos os critérios definidos no enunciado do trabalho prático. A estrutura modular, a simulação de entregas e o uso de arquivos binários foram aplicados com sucesso.