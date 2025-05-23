## 📄 README.md

# BM-Bank: Sistema de Gestão de Usuários

Este projeto implementa um sistema de gestão de usuários para o BM-Bank, utilizando a linguagem C++. O sistema permite operações como inserção, busca, transferência, remoção e persistência de dados de usuários.

### 🎯 Objetivo

Desenvolver um sistema que gerencie usuários com as seguintes funcionalidades:

1. Inserção de um novo usuário.
2. Inserção de múltiplos usuários.
3. Busca de usuário por ID.
4. Transferência entre usuários.
5. Remoção de usuários por ID.
6. Carregamento de usuários a partir de um arquivo externo.([cplusplus.com][1], [Medium][2])

### 🛠️ Tecnologias Utilizadas

* Linguagem: C++
* Compilador: g++
* Bibliotecas: iostream, fstream, cstring, iomanip([Great Learning][3], [W3Schools][4])

### 📋 Requisitos

* Utilização exclusiva da linguagem C++.
* Proibição do uso de containers da STL (vector, list, etc.).
* Alocação dinâmica de memória para todos os vetores/matrizes.
* Interface de linha de comando para interação com o usuário.
* Identificadores únicos para cada usuário.
* Proibição de saldos negativos para usuários.
* Formato de arquivo de saída conforme especificado.([unstop.com][5])

### 📂 Estrutura do Projeto

* `main.cpp`: Código-fonte principal contendo toda a lógica do programa.
* `usuarios.txt`: Arquivo gerado contendo os dados persistidos dos usuários.

### 🚀 Como Executar

1. Compile o código-fonte:

   ```bash
   g++ -o bmbank main.cpp
   ```


2\. Execute o programa:([cplusplus.com][1])

```bash
./bmbank
```


3\. Siga as instruções exibidas na interface de linha de comando para interagir com o sistema.

### 📌 Observações

* Certifique-se de que o arquivo `usuarios.txt` esteja no mesmo diretório do executável para o correto carregamento e salvamento dos dados.
* O programa foi desenvolvido seguindo rigorosamente as especificações fornecidas, garantindo unicidade e conformidade com os requisitos.

---

## 💻 Código-Fonte

O código-fonte completo está disponível no arquivo `main.cpp`. Ele foi desenvolvido de forma modular, utilizando alocação dinâmica de memória e evitando o uso de containers da STL, conforme as restrições estabelecidas.

Para acessar o código-fonte, consulte o arquivo [main.cpp](./main.cpp).

---
