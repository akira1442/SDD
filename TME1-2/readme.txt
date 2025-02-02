Q1.1 Quand on éxécute la commande on obtient l'erreur "input file tme1 is the same as output"

Q1.2 La variable i est assigné à une valeur 'aléatoire' après le 9ème tour ou i est égale a 0.

En plus on essaye d'accéder a une case du tableau qui n'éxiste pas, d'où le segmentation fault.
 
Comme i est un unsigned int il ne peut pas être négatif donc le programme boucle à l'infini.

Q1.3 En remplacant la condition de boucle par (i>=0 && i<len)

Q1.4 Il crée une variable maison de type adresse et l'affiche. En l'éxécutant on a une erreur de segmentation.

Q1.5 En voulant afficher new->rue on a 0x0
Le problème viens de la ligne 16, il faut remplacer strcpy() par strdup()

Q1.6 Le code ajoute 5 valeur dans un tableau puis affiche le tableau. En le compilant et l'éxécutant on n'obtient aucune erreur

Q1.7 Il alloue 100 case mémoire pour le tableau mais en utilise que 5.

Q1.8 Il y a une fuite mémoire, il manque un free.

Q1.9 En ajoutant une fontion LibererTab pour libérer le tableau de la structure puis de la structure elle même le problème sera résolu.



