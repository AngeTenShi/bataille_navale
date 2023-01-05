FAVIER NOLWEN
GONZALEZ ANGE

stdprof supprimé pour plus de clareté les prototypes sont dans le fichier batlle.h

differente regle du Makefile :
- all : compile projet
- clean : supprime le dossier contenant les fichiers objets
- fclean : clean et supprime le binaire compilé
- re : fclean + all

Regles :
- Au plus 4 bateaux chacun pour les deux joueurs sinon erreur.
- Chaque joueur a un board de minimum 5x5 question d'esthetisme tout autre taille en dessous sera refuse.
- La seule commande qui fait sortir du programme est "Jouer" si la configuration n'est pat celle demande alors on sort du mode interactif
- 3 modes d'execution :
	- cat fichier | ./bataille_navalle permet de visualiser où en est une partie si elle est valide. Ne permets pas de restaurer la partie en mode intéractif
	- ./bataille_navale -f fichier permet de charger une configuration ou d'en restaurer une
	- ./bataille_navale -i
- Dans le mode interactif il n'y a pas de règles spéciales c'est roue libre tant que les prérequis pour lancer la partie sont respectés.
- Il y'a deux boards différents c'est une approche différente mais plus réaliste chaque jur a son propre board.
- La commande Afficher affiche les deux boards dans tous les cas.

Certaines parties ont ete moins approfondies pour favoriser une gestion d'erreur tres stricte pour gerer un maximum de format sans segfault ainsi que l'utilisation de structure de donnees plus avancees comme une liste chainees de bateaux pour gerer les bateaux.

Avant de lancer une partie de nombreux tests sont realises par exemple les bateaux de memes noms doivent etre de meme taille aucun probleme si les bateaux n'ont pas de noms ainsi que de nombreuses verifications logiques lors du placement et des tirs.

Les 4 formats sur les 3 demandes ont ete geres. (Format supplémentaire mix entre nom et sans nom)

8 des 9 fonctionnalites demandees ont ete implementees

Dont une IA intelligente (mode interactif only) qui réfléchit à chaque coup et capable de gagner un adversaire solide. Un systeme de restauration et de sauvegarde avancee, une tres bonne gestion d'erreur et la gestion desbateaux avec leurs noms(les noms ne doivent pas contenir d'espace) le tout implemente avec une liste chainee de bateaux qui s'actualise a chaque input.

Seul le deplacement des bateaux n'a pas ete realise par manque de temps.

Des fichiers de test ont ete places dans le dossier test/ et dans save/ les formats donnes par le professeur inclus.
