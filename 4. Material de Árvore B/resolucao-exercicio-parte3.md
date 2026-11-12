# Exercício — Árvores-B (Parte IIIa)

Remover, nesta ordem, as chaves **A, B, Q, R e M** da árvore-B de ordem 5, usando o algoritmo da aula.

## Parâmetros (como no quadro da aula)

| | |
|---|---|
| ordem | m = 5 |
| máximo de chaves por página | m − 1 = 4 |
| mínimo de descendentes (exceto a raiz) | ⌈m/2⌉ = 3 |
| mínimo de chaves (exceto a raiz) | ⌈m/2⌉ − 1 = 2 |

A raiz pode ficar com uma única chave. A altura só diminui quando a última chave da raiz é retirada (concatenação dos filhos).

Algoritmo usado em cada remoção:

1. Se a chave não está numa folha, troca-se com a sucessora imediata (primeira chave da página mais à esquerda da filha à direita).
2. Elimina-se a chave da folha.
3. Se a página continua com pelo menos 2 chaves, a remoção termina.
4. Se a página ficou com 1 chave, olha-se a irmã da esquerda e depois a da direita.
   - Se alguma tiver mais de 2 chaves, redistribui-se: juntam-se as chaves das duas páginas com a separadora do pai e a chave do meio sobe para o pai.
   - Senão, concatena-se com a irmã da esquerda (ou com a da direita, se não houver irmã à esquerda) e com a chave separadora do pai.
5. Se houve concatenação, repetem-se os passos 3 a 6 na página pai.
6. Se a raiz ficar sem chaves, a página concatenada vira a nova raiz e a altura diminui.

## Árvore inicial

```
                    [ M ]
                   /     \
            [ D | H ]     [ Q | U ]
           /    |    \    /    |    \
     [ A B C ] [ E F G ] [ I J K L ] [ N O ] [ R S T ] [ V W ]
```

Ordem das chaves: A B C D E F G H I J K L M N O Q R S T U V W

---

## 1. Remover A — Caso 1

A está na folha `[ A B C ]`. Depois da retirada a página fica `[ B C ]`, ainda com 2 chaves (o mínimo). Nada mais muda.

```
                    [ M ]
                   /     \
            [ D | H ]     [ Q | U ]
           /    |    \    /    |    \
       [ B C ] [ E F G ] [ I J K L ] [ N O ] [ R S T ] [ V W ]
```

---

## 2. Remover B — Caso 3 (redistribuição)

B está na folha `[ B C ]`. A página fica `[ C ]`, com 1 chave: underflow.

A única irmã é a da direita, `[ E F G ]`, com 3 chaves (mais que o mínimo). Redistribui-se com a separadora D do pai `[ D | H ]`.

Chaves reunidas, em ordem:

```
C  D  E  F  G
      ↑
      E sobe para o pai
```

A folha da esquerda fica `[ C D ]`, a da direita fica `[ F G ]`, e D no pai é substituído por E. O pai passa a `[ E | H ]`.

```
                    [ M ]
                   /     \
            [ E | H ]     [ Q | U ]
           /    |    \    /    |    \
       [ C D ] [ F G ] [ I J K L ] [ N O ] [ R S T ] [ V W ]
```

---

## 3. Remover Q — Caso 2 e, na folha, Caso 1

Q está na página interna `[ Q | U ]`, não numa folha. A sucessora imediata é a primeira chave da filha à direita: R, da folha `[ R S T ]`.

Troca: a página interna fica `[ R | U ]` e a folha fica `[ Q S T ]`. Em seguida Q sai da folha, que fica `[ S T ]` — 2 chaves, o mínimo. A remoção termina.

```
                    [ M ]
                   /     \
            [ E | H ]     [ R | U ]
           /    |    \    /    |    \
       [ C D ] [ F G ] [ I J K L ] [ N O ] [ S T ] [ V W ]
```

---

## 4. Remover R — Casos 2, 4, 5 e 6

R está na página interna `[ R | U ]`. A sucessora imediata é S, primeira chave da folha `[ S T ]`.

Troca: a página interna fica `[ S | U ]` e a folha fica `[ R T ]`. R sai da folha, que fica `[ T ]` — 1 chave, underflow.

Irmãs de `[ T ]`:

- esquerda `[ N O ]`: 2 chaves, exatamente o mínimo
- direita `[ V W ]`: 2 chaves, exatamente o mínimo

Nenhuma pode ceder chave. Concatena-se com a irmã da esquerda e com a separadora S do pai `[ S | U ]`.

```
[ N O ]  +  S  +  [ T ]   =   [ N O S T ]
```

A folha da direita é liberada. O pai perde S e fica só com `[ U ]` — 1 chave, underflow que sobe (Caso 5).

A irmã à esquerda de `[ U ]` é `[ E | H ]`, com 2 chaves (o mínimo). Concatena-se as duas páginas internas com a separadora M da raiz.

```
[ E | H ]  +  M  +  [ U ]   =   [ E | H | M | U ]
```

Descendentes, na ordem: `[ C D ]`, `[ F G ]`, `[ I J K L ]`, `[ N O S T ]`, `[ V W ]`. São 4 chaves e 5 filhos, o máximo da ordem 5, então cabe numa página só.

A raiz ficou sem a única chave. A página concatenada passa a ser a nova raiz e a altura da árvore diminui (Caso 6).

```
              [ E | H | M | U ]
             /    |    |    |    \
       [ C D ] [ F G ] [ I J K L ] [ N O S T ] [ V W ]
```

---

## 5. Remover M — Caso 2 e, na folha, Caso 1

M está na raiz, que não é folha. A sucessora imediata é N, primeira chave da filha à direita `[ N O S T ]`.

Troca: a raiz fica `[ E | H | N | U ]` e a folha fica `[ M O S T ]`. M sai da folha, que fica `[ O S T ]` — 3 chaves, acima do mínimo. A remoção termina.

## Árvore final

```
              [ E | H | N | U ]
             /    |    |    |    \
       [ C D ] [ F G ] [ I J K L ] [ O S T ] [ V W ]
```

Ordem das chaves: C D E F G H I J K L N O S T U V W

Saíram A, B, Q, R e M. Toda página que não é raiz tem entre 2 e 4 chaves, as folhas estão no mesmo nível e a raiz tem 4 chaves e 5 filhos.

---

# Inserção das mesmas letras

Partindo da árvore final da remoção, inserir **A, B, Q, R e M**, nesta ordem. A inserção da aula desce até a folha. Se a página já tem 4 chaves, as 5 chaves (as antigas mais a nova) vão para uma página temporária, a do meio sobe e as outras duas ficam com a página da esquerda e as duas últimas com uma página nova, à direita da chave promovida. Se a promoção parte a raiz, cria-se uma raiz nova só com a chave promovida.

## Ponto de partida

```
              [ E | H | N | U ]
             /    |    |    |    \
       [ C D ] [ F G ] [ I J K L ] [ O S T ] [ V W ]
```

## 1. Inserir A

A cabe na folha `[ C D ]`, que ainda tem espaço. A folha fica `[ A C D ]`. Nenhuma promoção.

```
              [ E | H | N | U ]
             /    |    |    |    \
     [ A C D ] [ F G ] [ I J K L ] [ O S T ] [ V W ]
```

## 2. Inserir B

B entra na mesma folha. `[ A C D ]` passa a `[ A B C D ]`. Quatro chaves é o máximo, então a página fica cheia e não se divide.

```
              [ E | H | N | U ]
             /    |    |    |    \
    [ A B C D ] [ F G ] [ I J K L ] [ O S T ] [ V W ]
```

## 3. Inserir Q

Q cai na folha `[ O S T ]`, entre N e U. Ainda há uma vaga. A folha fica `[ O Q S T ]`, cheia.

```
              [ E | H | N | U ]
             /    |    |    |    \
    [ A B C D ] [ F G ] [ I J K L ] [ O Q S T ] [ V W ]
```

## 4. Inserir R — split da folha e split da raiz

R também cairia em `[ O Q S T ]`, que já está cheia. As cinco chaves da página temporária:

```
O  Q  R  S  T
      ↑
      R é a chave do meio e sobe
```

A folha antiga fica `[ O Q ]`. A página nova, filha direita de R, fica `[ S T ]`.

R precisa entrar na raiz `[ E | H | N | U ]`, que também está cheia. Página temporária da raiz, já com os filhos:

```
E        H        N        R        U
↑        ↑        ↑        ↑        ↑
[A B C D] [F G]  [I J K L] [O Q]  [S T]  [V W]
```

A chave do meio é N. Ela sobe para uma raiz nova. A página da esquerda fica `[ E | H ]` e a da direita, `[ R | U ]`.

```
                      [ N ]
                     /     \
              [ E | H ]     [ R | U ]
             /    |    \    /    |    \
      [ A B C D ] [ F G ] [ I J K L ] [ O Q ] [ S T ] [ V W ]
```

A altura volta a 2.

## 5. Inserir M — split só da folha

M cai em `[ I J K L ]`, entre H e N. A folha está cheia. Página temporária:

```
I  J  K  L  M
      ↑
      K sobe
```

A folha antiga fica `[ I J ]`. A página nova fica `[ L M ]`.

K entra no pai `[ E | H ]`, que tem duas chaves e ainda aceita mais uma. O pai fica `[ E | H | K ]` e não promove nada.

## Árvore depois das cinco inserções

```
                         [ N ]
                        /     \
              [ E | H | K ]        [ R | U ]
             /    |    |    \      /    |    \
      [ A B C D ] [ F G ] [ I J ] [ L M ] [ O Q ] [ S T ] [ V W ]
```

Ordem das chaves: A B C D E F G H I J K L M N O Q R S T U V W

As cinco letras voltaram. O split guarda a chave do meio no pai, então a forma da árvore fica diferente da árvore desenhada no início do exercício de remoção.
