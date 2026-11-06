# Primeira questão

- Uma estrutura de dados com 10 posições fixas. Cada posição deve ser uma
referência para outra estrutura (um vetor) de posições variadas.

- Assumir que se trata de uma estrutura para armazenar inteiros.

## O programa deve possuir as opções:

### 1:
- Inserir elemento (1 por vez) na posição desejada.
    - Se ainda não houver a sub-estrutura criada, o usuário deve
    informar qual o tamanho total dessa sub-estrutura.
    - O programa deve informar caso não haja mais espaço livre para
    inserir novos númeors

### 2:

- Listar os números de todas as estruturas. Ele deve mostrar pelo ponto de vista
Da estrutura principal, indicando o tamanho de cada sub-estrutura e seus elemen-
tos.
    * Ex: [ Vector x: {.size = y}, {Elements: a, b, c} ],


### 3:

- Listar os números ordenados para cada sub-estrutura
    - Cria buffer com tamanho da sub-estrutura.
    - Copiar dados para o buffer.
    - Ordenar o buffer.
    - Listar.
    - Liberar memória.

### 4:

- Listar os números ordenados.
    - Criar buffer com tamanho = tamanho total da estrutura.
    - Copiar dados das sub-estruturas.
    - Ordenar buffer.
    - Listar.
    - Liberar memória.

### 5:

- Excluir a primeira ocorrência de um elemento em determinada sub-estrutura
dita pelo usuário.

### 6:

- Aumentar o tamanho de uma estrutura auxiliar. O usuário deve escolher
uma estrutura que já exista e informar qual o tamanho extra dessa estrutura.
    - Receber tamanho extra a ser aumentado, não tamanho total
        - Ex: remagroscebeu 2 -> tam += 2

### 7:

- Sair


# Planejamento de código:

A estrutura terá um vetor de 10 posições para ponteiros de estruturas (node),
onde cada node irá possuir ponteiro para inteiros (keys) e seu tamanho.
A estrutura principal também possuirá um contador de tamanho máximo.

- Criar função construtora que inicializa tudo com 0 e NULL.
- Criar função add que adiciona um elemento a determinada posição do vetor.
    - Se a estrutura for NULL, deve inicializar elas. 
        - Função auxiliar para criar estruturas.
            - Existem testes para ser feitos e valores de retorno padrão
            (macros) já definidas.
            - Verificar se a posição é válida.
            - Verificar se já existe.
            - Verificar se o tamanho for muito grande
            - Verificar se o tamanho for menor que 1
            - Dar sucesso se passar em tudo.

- Criar função add() para inserir números nas sub-estruturas
