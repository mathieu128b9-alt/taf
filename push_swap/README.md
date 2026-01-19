# Push_swap

*Ce projet a été réalisé dans le cadre du cursus 42 par msuter.*

## Description

Push_swap est un projet d'algorithme de tri qui consiste à trier une pile d'entiers en utilisant un ensemble limité d'opérations, avec pour objectif de minimiser le nombre de coups nécessaires.

Le projet implémente un algorithme utilisant deux piles (a et b) et des opérations spécifiques (swap, push, rotate, reverse rotate). L'objectif principal est de trier la pile `a` par ordre croissant en utilisant le moins d'opérations possible.

L'algorithme implémenté utilise la stratégie de la **Plus Longue Sous-Séquence Croissante (LIS)** :
1. Normalisation des nombres en indices
2. Calcul de la LIS
3. Conservation de la LIS dans la pile `a`, transfert du reste dans la pile `b`
4. Réinsertion optimisée des éléments de `b` vers `a` (choix de l'élément au coût minimal)
5. Rotation finale pour positionner le plus petit élément en haut

## Instructions

### Compilation

```bash
make
```

### Utilisation

```bash
./push_swap [liste d'entiers]
```

**Exemples :**

```bash
# Trier 5 nombres
./push_swap 5 2 8 1 9

# Compter les opérations pour 100 nombres aléatoires
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Gestion des erreurs

Le programme affiche "Error" dans les cas suivants :
- Arguments non-entiers
- Nombres dépassant INT_MIN ou INT_MAX
- Doublons

### Nettoyage

```bash
make clean     # Supprime les fichiers objets
make fclean    # Supprime les fichiers objets et l'exécutable
make re        # Recompile tout
```

## Resources

### Références classiques

- [GeeksforGeeks - Longest Increasing Subsequence](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/)
- [42 Gitbook - Push_swap](https://42-cursus.gitbook.io/guide/rank-02/push_swap)
- [Big O Notation](https://www.bigocheatsheet.com/)

### Utilisation de l'IA

**ChatGPT** a été utilisé comme assistant d'apprentissage pour :

✅ **Ce qui a été utilisé :**
- Explications de concepts (LIS, calcul de coûts, complexité algorithmique)
- Clarifications sur les stratégies d'optimisation
- Méthodologie de débogage

❌ **Ce qui n'a PAS été utilisé :**
- Génération de code
- Solutions directes ou implémentations copiées-collées

**Processus d'apprentissage :**
1. Demande d'explication d'un concept à ChatGPT
2. Compréhension via questions de suivi
3. Implémentation du concept dans mon code
4. Tests et débogage de manière autonome

Les parties les plus difficiles du projet ont été la compréhension de l'algorithme LIS et le calcul des coûts optimaux pour la réinsertion.
