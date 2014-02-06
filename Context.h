#pragma once
#include <iostream>
#include <stdint.h>
#include <math.h>


using namespace std;

class Context
{

public:
  uint64_t _N;              // nombre de mots
  int _mot_taille_min;      // nombre de lettres min d'un mot
  int _mot_taille_max;      // nombre de lettres max d'un mot
  uint64_t _N_taille[];     // tableau, nombre de mots d'une taille donnée
  int _nb_lettres;          // nombre de lettres possibles pour un caractère
  string _lettres;          // tableau des lettres de taille _nb_lettres

  // fonction de hachage
  // In: Clair c ----> Out: Empreinte
  void h( string c, unsigned char* d );
  // In: position t, empreinte d ---> Retourne index
  uint64_t h2i( uint64_t t, unsigned char* d );
  // In: index idx ----> Out: Clair c
  void i2c( uint64_t idx, string & c );
  // In: index idx ----> retourne index (la composée des précédentes)
  uint64_t i2i(uint64_t idx, uint64_t t = 0 );
  // Retourne un indice aléatoire valide.
  uint64_t randIndex();


	Context(void);
	~Context(void);

private:
     void HashMD5(string pPlain, unsigned char* pHash);
     void HashSHA1(string pPlain, unsigned char* pHash);
     void convert(const string& s, unsigned char* pHash); // Fonction pour convertir un string en unsigned char
     unsigned long random();
};
