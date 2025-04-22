# Análise e Implementação de Lista Sequencial Estática em C 🚀✨📊

## Visão Geral 📖📚🔍
Este repositório apresenta uma implementação em C de uma **lista sequencial estática** (vetor de tamanho fixo), acompanhada de um módulo interativo (menu) para realizar operações de inserção, remoção e busca pelo campo RG. Além disso, o sistema oferece persistência em arquivo CSV (`nome,RG`), permitindo salvar e recarregar a estrutura conforme necessário.

## Métricas de Desempenho ⚙️📈🔬
Todas as operações são acompanhadas por métricas empíricas que incluem:

- **C(n)**: número de comparações lógicas executadas  
- **M(n)**: quantidade de movimentações de dados (atribuições)  
- **Tempo de execução**: medido via `clock()` da biblioteca padrão  
- **Posição**: índice (1‑based) onde ocorre a operação  

    Essas métricas possibilitam uma análise comparativa de desempenho, fundamental para estudos acadêmicos e otimização de algoritmos de listas.

    ## Estrutura do Repositório 📂🗂️🔧

    - `lib.h`               – Definições de `Item`, `Lista` e protótipos de função
    - `copiaString.c`       – Cópia de cadeias de caracteres sem `<string.h>`
    - `inicializarLista.c`  – Inicialização da lista (tamanho = 0)
    - `inserirInicio.c`     – Inserção no início com métricas
    - `inserirFim.c`        – Inserção no fim com métricas
    - `inserirPosicao.c`    – Inserção em posição arbitrária com métricas
    - `removerInicio.c`     – Remoção do início com métricas
    - `removerFim.c`        – Remoção do fim com métricas
    - `removerPosicao.c`    – Remoção em posição arbitrária com métricas
    - `buscaPorRg.c`        – Busca sequencial por RG com métricas
    - `imprimirLista.c`     – Exibição do conteúdo da lista
    - `salvarLista.c`       – Persistência em arquivo CSV
    - `lerLista.c`          – Carregamento a partir de CSV
    - `sairDoSistema.c`     – Finalização graciosa da aplicação
    - `menuSequencial.c`    – Interface de usuário via switch‑case
    - `main.c`              – Ponto de entrada que invoca o menu

    ## Compilação e Execução 💻🔧🎉

    Para compilar todos os módulos e gerar o executável, utilize o GCC:

    ```bash
    gcc *.c -o programa.exe
    ```

    Em seguida, execute o programa:

    ```bash
    ./programa.exe
    ```

