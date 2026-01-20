This project has been created as part of the 42 curriculum by msuter

Fract'ol

Description
Une fractale est une forme géométrique qui crée des patterns à l'infini lorsqu'on zoom à l'intérieur. Mon programme a 3 types de fractales différentes, dans lesquelles il est possible de se déplacer, de zoomer et de changer les couleurs en fonction des préférences.
Implémentation de Mandelbrot, fractale emblématique, sa forme se retrouve partout en zoomant. Julia, fractale dynamique, qui permet de changer ses valeurs en temps réel. Phoenix, est une version modifiée de Julia, avec un calcul légèrement différent ce qui crée d'autres patterns.
Instructions
Compilation
Prérequis : S'assurer d'avoir la bibliothèque MiniLibX installée.

make : Compile le programme
make clean : Supprime les fichiers objets
make fclean : Supprime le programme exécutable
make re : Recompile entièrement le projet

Exécution
Lancer le programme avec un argument pour choisir la fractale :
./fractol M    # Mandelbrot
./fractol J    # Julia
./fractol F    # Phoenix
En cas d'argument invalide, un message d'erreur s'affiche avec la liste des arguments disponibles.
Contrôles

Flèches directionnelles : Se déplacer dans la fractale
Molette de la souris : Zoomer / Dézoomer
Touches 1-4 : Changer la palette de couleurs
Touche J (Julia et Phoenix uniquement) : Fixer/débloquer les paramètres pour modification en temps réel avec la souris
ESC ou croix : Fermer le programme

Resources
Documentation et références

GitBook : Compréhension des concepts de fractales et nombres complexes
Documentation MiniLibX : Utilisation de la bibliothèque graphique et gestion des événements

Utilisation de l'IA

Claude AI : Explications des concepts mathématiques (nombres complexes, algorithmes de fractales) et du multithreading
Méthodologie : Utilisation stricte pour la compréhension des concepts uniquement, aucun code copié-collé. Toutes les implémentations ont été codées manuellement après compréhension des principes.