This project has been created as part of the 42 curriculum by msuter
Pipex
Description
Pipex reproduit le comportement du terminal. Le programme prend un infile contenant des données, applique une première commande, passe le résultat dans un pipe, applique une deuxième commande, et stocke le résultat final dans un outfile. Cela reproduit le comportement de < infile cmd1 | cmd2 > outfile.
Instructions
Compilation

make all : Compile le programme
make clean : Supprime les fichiers objets (.o)
make fclean : Supprime tout (exécutable inclus)
make re : Recompile si quelque chose a changé

Exécution
./pipex infile "cmd1 + arg" "cmd2 + arg" outfile
Exemple
bash./pipex infile "grep" "wc -l" outfile
# Compte le nombre de lignes dans infile
Resources
Documentation et références

CodeVault : Playlist UNIX processes — https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv
Man pages : man 2 dup2, man 2 execve, man 2 fork, man 2 pipe
GitBook 42

Utilisation de l'IA

Claude AI : Explication de concepts (ex: dup2) et debugging
Méthodologie : Utilisation strictement limitée à la compréhension des concepts et au debugging. Aucun code généré par l'IA. Toutes les implémentations ont été codées manuellement.