-------------------------------------------------------------------
		Instruction TP Crypto 	AVET Anthony DURAZ Aurélien
-------------------------------------------------------------------

- Si vous voulez chargé un dictionnaire pré éxistant il vous suffit:
	- D'aller dans la partie 2 du main
	- de changer le nom du fichier en paramètre de la fonction load dans le main.cpp
	
- Pour creer un nouveau dictionnaire:
	- décommenté la partie 1 du main.cpp
	- changer le nom du fichier dans la fonction save
	- changer le nom du fichier dans la fonction load
	
- Pour utiliser le programme :
	- lancer le programme et  entré un SHA1 à decrypter
	

	Pour changer l'alphabet et le nombre de lettre dans un mot il faut se rendre Context.cpp
	
	-------------------------- AVANCEMENT --------------------------------
	
Nous avons déjà créé un menu basique pour effectuer les actions décrites ci-dessus via la console mais celui-ci n'est pas décommenté dans le main.cpp (Partie 0)

Au niveau du programme, toutes les fonctions sont implémentées, le programme tourne, mais il semble qu'il ne trouve pas beaucoup de mots et soit un peu lent. 
Nous n'arrivons pas à comprendre d'où proviennent ces problèmes car toutes nos fonctions renvoient des valeurs correctes.

Avec Test_100000_1000.txt mot alphabet de 26 lettre et mot de taille fixe 5 lettres nous arrivons a trouver les mots fruit, singe, ghost ... 

 
Avec Test_300000_3000.txt le programme est très lent me semble trouver tous les mots que nous lui demandons en 5 lettres taille fixe alphabet de 26 lettres.
