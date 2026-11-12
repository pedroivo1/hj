## Convenções (conforme o material da disciplina)

- **Treap** (*tree* + *heap*): cada nó tem uma **chave** e uma **prioridade**, escritas como `chave:prioridade` (ex.: `40:90`).
- **Pelas chaves, é uma árvore binária de busca:** chaves menores ficam à esquerda e chaves maiores ficam à direita (`esq.chave < nó.chave < dir.chave`).
- **Pelas prioridades, é um heap:**
  - **heap de máximo:** todo pai tem prioridade maior que a dos filhos (`prio(pai) > prio(filho)`); a raiz tem a maior prioridade;
  - **heap de mínimo:** todo pai tem prioridade menor que a dos filhos (`prio(pai) < prio(filho)`); a raiz tem a menor prioridade.
- **Rotação à direita** em um nó (`RotacionaDireita(nó)`): o filho esquerdo sobe e o nó desce para a direita dele. **Rotação à esquerda** (`RotacionaEsquerda(nó)`): o filho direito sobe e o nó desce para a esquerda dele. As rotações não estragam a ordem das chaves.
- **Inserir:**
  1. insere a chave como numa árvore binária de busca comum (o novo nó entra como folha);
  2. enquanto o novo nó tiver prioridade "melhor" que a do pai (maior no heap de máximo: `prio(pai(x)) < prio(x)`; menor no heap de mínimo: `prio(pai(x)) > prio(x)`), faz ele subir:
     - se ele é filho esquerdo, rotaciona o pai à direita (`RotacionaDireita(pai(x))`);
     - se ele é filho direito, rotaciona o pai à esquerda (`RotacionaEsquerda(pai(x))`).
- **Remover** um nó: empurra o nó para baixo com rotações até ele virar **folha** e então apaga a folha.
  - se só tem filho esquerdo, rotaciona à direita no nó (`RotacionaDireita(x)`);
  - se só tem filho direito, rotaciona à esquerda no nó (`RotacionaEsquerda(x)`);
  - se tem dois filhos, sobe o filho de prioridade "melhor" (maior no heap de máximo, menor no heap de mínimo): se for o esquerdo, rotaciona à direita; se for o direito, rotaciona à esquerda.
- Nos exercícios, **não há chaves repetidas nem prioridades repetidas**.

# Inserção

## Exercício 1

Comece com uma treap **vazia**, com heap de **máximo** nas prioridades, e insira, **nesta ordem**, um par `chave:prioridade` por vez:

**50:40, 30:60, 70:20, 20:10, 40:80, 60:50, 80:30, 35:90, 65:15**

## Exercício 2

Comece com uma treap **vazia**, com heap de **mínimo** nas prioridades, e insira, **nesta ordem**, um par `chave:prioridade` por vez:

**15:30, 8:50, 25:10, 4:40, 12:20, 30:60, 20:5, 10:45**

## Exercício 3

Considere a treap abaixo, com heap de **máximo** nas prioridades, e insira, **nesta ordem**, um par `chave:prioridade` por vez:

```
         _________50:90_________
        /                       \
   ___30:70___             ___70:60___
  /           \           /           \
20:40       40:50       60:30       80:20
```

**45:95, 35:55, 65:10, 25:65, 75:35**

# Remoção

## Exercício 4

Considere a treap abaixo, com heap de **máximo** nas prioridades. Remova a chave pedida em cada alínea (as alíneas são independentes):

```
         _______________40:90_______________
        /                                   \
   ___20:70_________             _________60:80___
  /                 \           /                 \
10:50          ___30:65       50:40___          70:75___
              /                       \                 \
            25:30                   55:20             80:35
```

- **(a)** remover **55**
- **(b)** remover **30**
- **(c)** remover **70**
- **(d)** remover **20**
- **(e)** remover **40**

## Exercício 5

Considere a treap abaixo, com heap de **mínimo** nas prioridades. Remova a chave pedida em cada alínea (as alíneas são independentes):

```
               _______________40:10_________
              /                             \
         ___20:30___                   ___60:20_________
        /           \                 /                 \
   ___10:50       30:35___          50:40          ___70:25
  /                       \                       /
5:70                    35:60                   65:45
```

- **(a)** remover **35**
- **(b)** remover **10**
- **(c)** remover **60**
- **(d)** remover **30**
- **(e)** remover **40**

## Exercício 6

Considere a treap abaixo, com heap de **máximo** nas prioridades, e remova, **nesta ordem**: **50, 30, 70**.

```
         _____________________50:95_________
        /                                   \
   ___30:80_________                   ___70:85_________
  /                 \                 /                 \
20:60          ___40:75___          60:70          ___80:40
              /           \                       /
            35:30       45:50                   75:20
```
