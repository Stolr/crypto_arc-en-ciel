#include "Context.h"
#include "md5.h"
#include "sha1.h"
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#define AES_BLOCK_SIZE 16


/*
    Fonction permettant d'obtenir une empreinte à partir d'un clair
*/
void Context::h(string c, unsigned char * d)
{
    //HashMD5(c, &d);
    HashSHA1(c, d);
}

/*
    Fonction permettant d'obtenir un indice à partir d'une empreinte
*/
uint64_t Context::h2i( uint64_t t, unsigned char* d )
{
    return (*((uint64_t*) d) + t) % _N;
}


/*
    Fonction permettant de passer un tour de t en allant d'un indice à son suivant
*/
uint64_t Context::i2i( uint64_t idx, uint64_t t){
    string clair;
    unsigned char empreinte[255];

    i2c(idx, clair);
    h(clair, empreinte);

    return h2i(t, empreinte);
}



Context::Context(void)
{
  _mot_taille_min = 5; // nombre de lettres min d'un mot
  _mot_taille_max = 5; // nombre de lettres max d'un mot
  _nb_lettres = 26;     // nombre de lettres possibles pour un caractère
  _N = pow(_nb_lettres, _mot_taille_max);          // nombre de mots
    srand (time(NULL));
  _lettres = "azertyuiopqsdfghjklmwxcvbn";
}


/*
    Fonction permettant d'obtenir un clair à partir d'un indice
*/
void Context::i2c( uint64_t idx, string & c )
{
    c = "";
    int i=0;
    while (i<_mot_taille_min)
    {
        c += _lettres[idx%_nb_lettres];

        idx /= _nb_lettres;
        i++;
    }
}

Context::~Context(void)
{
}

void Context::HashMD5(string pPlain, unsigned char* pHash)
{
    convert(md5(pPlain), pHash);
}

void Context::HashSHA1(string pPlain, unsigned char* pHash)
{
     convert(sha1(pPlain), pHash);
}


/*
    Convertir String en unsigned char
*/
void Context::convert(const string& s, unsigned char* conv){

    for(int i = 0; i < s.length(); i++)
    {
      conv[i]=s[i];
    }
    conv[s.length()]='\0';
    //get rid of the rubbish
}

/*
    Permet de générer un index aléatoire
*/
uint64_t Context::randIndex(){

    unsigned long n1 = random();
    unsigned long n2 = random();
    uint64_t n = ( (uint64_t) n2 ) + ( ( (uint64_t) n1 ) << 32 );
    return n%_N;
}


unsigned long Context::random(){
  /* generate secret number between 1 and 10: */
 return  (unsigned long) rand();
}
