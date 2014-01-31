#pragma once
#include <iostream>
#include <stdint.h>
#include <math.h>


using namespace std;

class Context
{

public:
  uint64_t _N;            // nombre de mots
  int _mot_taille_min;  // nombre de lettres min d'un mot
  int _mot_taille_max;  // nombre de lettres max d'un mot
  uint64_t _N_taille[];   // tableau, nombre de mots d'une taille donn�e
  int _nb_lettres;      // nombre de lettres possibles pour un caract�re
  char _lettres[];      // tableau des lettres de taille _nb_lettres

  // fonction de hachage
  // In: Clair c ----> Out: Empreinte
  void h( string c, unsigned char* d );
  // In: position t, empreinte d ---> Retourne index
  uint64_t h2i( uint64_t t, unsigned char* d );
  // In: index idx ----> Out: Clair c
  void i2c( uint64_t idx, string & c );
  // In: index idx ----> retourne index (la compos�e des pr�c�dentes)
  uint64_t i2i(uint64_t idx);
  // Retourne un indice al�atoire valide.
  uint64_t randIndex();


	Context(void);
	~Context(void);

private:
     void HashMD5(string pPlain, unsigned char* pHash);
     void HashSHA1(string pPlain, unsigned char* pHash);
     void convert(const string& s, unsigned char* pHash);
     unsigned long random();
};
/*
mot en claire => chiffrement => indice => mot en clair ...

combien d'indices al�atoires ?
al�atoire 26^4

principe :
g�n�ration al�atoire

i2c = a partir de l'indice retrouver le mot en clair -> indice % 26 ensuite on divise par 26 et rebelote jusqu'a nombre <=26

mdp crypt�
h2i() = crypt� vers indice voir tanou -> principe de prendre une partie de la chaine convertir le pointeur en int, ajout� le num�ro de colonne et modulo N

i2i a partir d'un indice h2i( k, h( i2c( idx ) ) )


pour N indice aleatoire
    MFin = M = indice al�atoire
   while( pas fait T tour)
    MFin <- i2i(MFin)
  fin while
  stocker(M, MFin)
fin Pour




Programme on donne un crypt�
compteur de tour = 0
    Jusqua qu'on trouve un indice valide
        h2i
        on regarde dans la base
            il y est on sort ..
        il y est pas on augmente compteur de tour de 1, on convertit i2c, puis h, et on reboucle
    Fin Jusqua
    recup�rer depuis la base le point de d�part de l'indice valide ..
    i2c(depuis le point de d�part on boucle sur T- compteur de tour) pour r�cup�rer le bon indice puis i2c pour le mot en clair*/
