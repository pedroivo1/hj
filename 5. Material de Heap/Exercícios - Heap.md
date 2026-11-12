## Convenções (conforme o material da disciplina)

- **Heap mínimo:** a raiz guarda o menor valor, e todo pai é menor ou igual aos seus filhos (`H[Pai(i)] ≤ H[i]`, para todo `i > 1`).
- **Vetor:** o heap fica num vetor que começa na posição 1 (`H[1..n]`). Para um nó na posição `i`:
  - o pai está na metade de `i`, arredondada para baixo (`Pai(i) = i div 2`);
  - o filho esquerdo está no dobro de `i` (`Esq(i) = 2·i`);
  - o filho direito está no dobro de `i` mais um (`Dir(i) = 2·i + 1`).
- **Subir** (`Subir(i, n, H)`): enquanto o nó não for a raiz (`i > 1`) e o pai for maior que ele (`H[Pai(i)] > H[i]`), troca o nó com o pai e continua a partir da posição do pai.
- **Descer** (`Descer(i, n, H)`): escolhe o menor dos filhos que existem; se os dois forem iguais, escolhe o esquerdo. Se esse filho for menor que o nó (`H[filho] < H[i]`), troca os dois e continua a partir da posição do filho. Para quando o nó não tem filhos (`filho > n`) ou quando o filho não é menor.
- **Inserir** (`Inserir(x, n, H)`): aumenta o tamanho em 1 (`n ← n + 1`), coloca o novo valor na última posição (`H[n] ← x`) e faz ele subir (`Subir(n, n, H)`).
- **Remover o mínimo** (`RemoverMínimo(n, H)`): o mínimo é a raiz. Copia o último elemento para a raiz (`H[1] ← H[n]`), diminui o tamanho em 1 (`n ← n − 1`) e, se ainda sobrou algum elemento (`n ≥ 1`), faz a raiz descer (`Descer(1, n, H)`).
- **Valores iguais não trocam de lugar:** só há troca quando um valor é estritamente menor que o outro (`<` ou `>`, nunca `≤`).

# Inserção

## Exercício 1

Comece com um heap mínimo **vazio** (`n = 0`) e insira, **nesta ordem**, um valor por vez com `Inserir`:

**40, 20, 50, 10, 30, 15, 60, 5, 35**

## Exercício 2

Comece com um heap mínimo **vazio** (`n = 0`) e insira, **nesta ordem**, um valor por vez com `Inserir`:

**18, 25, 9, 30, 9, 4, 12, 27, 2, 30**

## Exercício 3

Considere o heap mínimo `H = [6, 14, 9, 20, 17, 11, 25, 30, 22]` e insira, **nesta ordem**, um valor por vez com `Inserir`:

**3, 19, 10, 9, 7**

# Remoção

## Exercício 4

Aplique **uma** vez `RemoverMínimo` em cada heap (as alíneas são independentes):

- **(a)** `H = [42]`
- **(b)** `H = [10, 25]`
- **(c)** `H = [5, 10, 8, 15, 12, 9, 40, 20, 18, 14, 13]`
- **(d)** `H = [2, 3, 6, 10, 5, 7, 8, 20, 30, 5]`
- **(e)** `H = [1, 5, 2, 15, 6, 4, 5]`
- **(f)** `H = [1, 3, 3, 7, 8, 5, 6, 20, 30, 12]`

## Exercício 5

Aplique **uma** vez `RemoverMínimo` em cada heap (as alíneas são independentes):

- **(a)** `H = [7]`
- **(b)** `H = [5, 9]`
- **(c)** `H = [2, 4, 3, 10, 6, 5, 7, 25, 30, 20, 22]`
- **(d)** `H = [1, 2, 5, 9, 3, 6, 7, 15, 20, 3]`
- **(e)** `H = [1, 3, 2, 12, 4, 8, 3]`
- **(f)** `H = [4, 4, 4, 10, 11, 8, 9, 30, 35, 20]`

## Exercício 6

Considere o heap mínimo `H = [4, 12, 8, 20, 25, 15, 9, 30, 40, 28, 32]` e aplique `RemoverMínimo` **três vezes**, em sequência.
