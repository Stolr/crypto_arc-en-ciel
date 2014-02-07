-------------------------------------------------------------------
		Instruction TP Crypto 	AVET Anthony DURAZ Aurélien
-------------------------------------------------------------------

- Si vous voulez charger un dictionnaire éxistant il vous suffit:
	- D'aller dans la partie "1" du main.cpp
	- Changer le nom du fichier en paramètre de la fonction load
	
- Pour creer un nouveau dictionnaire:
	- Décommenter la partie "0" du main.cpp
	- Changer le nom du fichier dans la fonction save
	- Changer le nom du fichier dans la fonction load
	
- Pour utiliser le programme :
	- lancer le programme et  entrez un SHA1 à decrypter
	

	Pour changer l'alphabet et le nombre de lettre dans un mot il faut se rendre dans Context.cpp
	
	-------------------------- AVANCEMENT --------------------------------
	
Nous avons déjà créé un menu basique pour effectuer les actions décrites ci-dessus via la console mais celui-ci n'est pas décommenté dans le main.cpp (Partie 0)

Au niveau du programme, toutes les fonctions sont implémentées, le programme tourne, mais il semble qu'il ne trouve pas beaucoup de mots et soit un peu lent. 
Nous n'arrivons pas à comprendre d'où proviennent ces problèmes car toutes nos fonctions renvoient des valeurs correctes.

Avec Test_100000_1000.txt pour un alphabet de 26 lettre et mot de taille fixe de 5 lettres nous arrivons a trouver les mots "fruit", "singe", "ghost" ... 

 
Avec Test_300000_3000.txt le programme est très lent me semble trouver tous les mots que nous lui demandons en 5 lettres taille fixe alphabet de 26 lettres.
