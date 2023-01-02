FAVIER NOLWEN
GONZALEZ ANGE

stdprof supprimé pour plus de clareté les prototypes sont dans le fichier batlle.h

differente regle du Makefile : all : compile projet , clean : supprime le dossier contenant les fichiers objets, fclean : clean et supprime le binaire compile , re : fclean + all 

Regles :
- Au plus 4 bateaux chacun pour les deux joueurs sinon erreur.
- Chaque joueur a un board de minimum 5x5 question d'esthetisme tout autre taille en dessous sera refuse.
- La seule commande qui fait sortir du programme est "Jouer" si la configuration n'est pat celle demande alors on sort du mode interactif
- 3 modes d'execution :
	- cat fichier | ./bataille_navalle permet de visualiser où en est une partie si elle est valide. Ne permets pas de restaurer la partie en mode intéractif
	- ./bataille_navale -f fichier permet de charger une configuration ou d'en restaurer une
	- ./bataille_navale -i
- Dans le mode interactif il n'y a pas de règles spéciales c'est roue libre tant que les prérequis pour lancer la partie sont respectés.
- Il y'a deux boards différents c'est une approche différente mais plus réaliste chaque joueur à son board
- La commande Afficher affiche les deux boards dans tous les cas.
