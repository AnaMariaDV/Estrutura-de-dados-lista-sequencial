# 📋⚙️📈 Lista Sequencial Dinâmica em C 

Desenvolvido no contexto do curso de Estruturas de Dados (IF63C Lab1) sob orientação do Prof. Mauro Fonseca (UTFPR), este projeto oferece um ambiente robusto para análise comparativa entre abordagens sequenciais e encadeadas.

## 📖📂🔗 Descrição 

Apresenta-se aqui uma implementação em **C** de uma lista sequencial dinâmica de registros de clientes (campos `nome` e `RG`). O mecanismo de realocação incremental adapta dinamicamente a capacidade da lista ao volume de dados, permitindo investigações precisas de desempenho em termos de custo computacional e uso de memória.

## Funcionalidades

1. **Inserção de elementos**
   - No início, no final ou em posição arbitrária
2. **Remoção de elementos**
   - Do início, do final ou de posição específica
3. **Busca sequencial por RG**
   - Localização de registros via iteração linear
4. **Persistência em disco**
   - Salvamento e recarga em formato CSV (`nome,RG`)
5. **Medição de métricas de desempenho**
   - **C(n)**: quantidade de comparações de chaves
   - **M(n)**: número de movimentações (cópias de registros)
   - **Tempo de execução**: duração em segundos de cada operação

## 🏗️📂🔌 Arquitetura dos Módulos 

- **lib.h**: definições de tipos (`Item`, `Lista`) e assinaturas de funções
- **list.c**: lógica principal de manipulação (inserir, remover, buscar, exibir)
- **io.c**: operações de E/S (salvar e carregar CSV)
- **menu.c**: interface de usuário (menu interativo)
- **main.c**: inicialização e liberação de recursos

## 💻⚙️🖥️ Compilação 

No diretório do projeto, execute:

```bash
gcc -Wall -Wextra -std=c99 list.c io.c menu.c main.c -o programa.exe
```

## ▶️📂📦 Execução 

Inicie o programa e siga as instruções exibidas no menu:

```bash
./programa.exe
```

## 🔍📐✅ Observações 

- A capacidade ajusta-se automaticamente, eliminando a necessidade de topos estáticos.
- Métricas detalhadas viabilizam análises comparativas rigorosas.
- Código modular e comentado, alinhado a boas práticas de engenharia de software.

---

🎓🏛️📖 *UTFPR — DAINF — IF63C Lab1*

