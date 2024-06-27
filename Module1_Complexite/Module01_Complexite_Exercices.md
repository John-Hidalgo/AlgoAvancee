<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script> 

# Module 01 - Complexité

## Préalables pour la suite

Installez le support de C++ pour Visual Studio :

1. Ouvrez Visual Studio
2. Allez dans le menu `Tools` > `Get Tools and Features`
3. Sélectionnez `Desktop development with C++`
4. Cliquez sur `Modify`
5. Pendant les opérations d'installation, vous pouvez faire les exercices

## Exercice 1 - Recherche

1. Calculer la complexité de la recherche d'une valeur dans une liste

Si la liste a longeur $n$, on a

$$T(n) = T(1) + T(n-1)$$

$$T(n) = T(1) + T(1) + T(n-2)$$
$$T(n) = T(1) + ... +T(1) = nT(1) = O(n)$$

2. Essayer de recalculer la complexité de la recherche dichotomique

Encore on a une liste avec $n$ elements, puis

$$T(n) = T(1) + T(\frac{n}{2})$$

$$T(n) = T(1) + T(1) + T(\frac{n}{2^2})$$

$$T(n) = T(1) + ... + T(\frac{n}{2^x})$$

dont 


$$ \frac{n}{2^x} = 1 \implies n = 2^x \implies x = \log_2(n)$$


donc
$$T(n) = \sum_{1}^{\log_2n}T(1) = O(\log_2(n))$$


## Exercice 2 - Une idée sur l'impact de la complexité sur le temps d'exécution

Créez un projet **C#** (Vous n'avez pas encore vu C++) dans Visual Studio et implémentez un programme qui permet d'afficher le temps d'exécution d'une fonction en fonction de la taille de l'entrée et de sa complexité.

Les complexités à tester sont :

- O(1)
- O(n)
- O(n²)
- O(n³)
- O(2^n)
- O(n!)
- O(n log n)

Les hypothèses sont :

- 1 000 000 d'opérations par seconde
- Tests avec des entrées de dimensions 10, 100, 1000, 10 000, 100 000, 1 000 000

## Exercice 3 - Tris

1. Calculez la complexité du tri à bulles

$T(n) = c_1n + T(n-1)$
$T(n) = c_1(n-1) + c_2(n-2) + T(n-2)$

$j=n,...,1$

$T(n) = c_1(n-1) + ... + c_{n-j}(n-j) < n(n-1) = O(n^2) $

2. Calculez la complexité du tri rapide dans le meilleur des cas : division en deux du tableau à chaque itération

$T(n) = 2c_1(\frac{n-1}{2}) + T(\frac{n}{2^1})$
$T(n) = c_1(n-1) + c_2(n-2^1) + T(\frac{n}{2^4})$

$j= \log_2(n), ... , 1$

$T(n) = c_1(n-1) + ... +c_{\log_2(n)}(n - j) < c_1(n-1) + ... +c_{\log_2(n)}(n-1) <  (n-1)\log_2(n) = O(n\log_2(n))$


3. Calculez la complexité du tri rapide dans le pire : tableau trié en ordre croissant ou décroissant et donc partitionnement qui ne partitionne pas vraiment
