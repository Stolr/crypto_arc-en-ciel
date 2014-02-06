#include "ArcEnCiel.h"
#include "Context.h"
#include <stdlib.h>


/*
    Fonction qui nous permet de créer notre table arc en ciel
*/
void ArcEnCiel::creer(Context ctxt)
{

    std::string clair;
    unsigned char empreinte[255];
    for(int i=0; i<_M; i++)
    {

        _X[i].idx1 = ctxt.randIndex();
        _X[i].idxT = _X[i].idx1;

        for(int j=0; j<_T; j++)
        {
            _X[i].idxT = ctxt.i2i(_X[i].idxT, j);
        }
    }
}

/*
    Fonction permettant de trier la table arc en ciel par ordre décroissant des derniers indices
*/
void ArcEnCiel::trier()
{
    register int a, b, c;
    int temp;
    uint64_t t;

    for(a = 0; a < _M-1; ++a)
    {
        temp = 0;
        c = a;
        t = _X[ a ].idxT ;
        for(b = a + 1; b < _M; ++b)
        {
            if( _X[ b ].idxT < t)
            {
                c = b;
                t =  _X[ b ].idxT ;
                temp = 1;
            }
        }
        if(temp == 1)
        {
            _X[ c ].idxT  =  _X[ a ].idxT ;
            _X[ a ].idxT  = t;
        }
    }
}
// Sauvegarde la table sur disque.
void ArcEnCiel::save( std::string name )
{
    ofstream monFlux(name.c_str());

    if(monFlux)
    {
        for(int i = 0 ; i < _M ; i++)
        {
            monFlux << _X[i].idx1 << ";" << _X[i].idxT << endl;
        }
        monFlux.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}
// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( std::string name )
{
    ifstream fichier(name.c_str());
    uint64_t i = 0, j = 0;
    if(fichier)
    {
        string ligne;
        string idx="";
        while(getline(fichier, ligne))
        {
            j = 0;
            idx="";
            while( ligne[j] != ';')
            {
                idx += ligne[j];
                j++;
            }
            j++;
            _X[i].idx1 = atoi(idx.c_str());
            idx="";
            while( ligne[j] != '\0')
            {
                idx += ligne[j];
                j++;
            }
            _X[i].idxT = atoi(idx.c_str());
            i++;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

/*
    Fonction de rechercher par dichotomie
    Celle-ci retourne un encadrement de lignes qui correspondent : au premier indice de la première ligne contenant l'indice recherché jusqu'au dernier indice de la derniere ligne contenant l'indice à rechercher
*/
bool ArcEnCiel::recherche( uint64_t idx, Chaine* &p, Chaine* &q )
{
    bool trouve;  //vaut faux tant que la valeur "val" n'aura pas été trouvée
    int id;  //indice de début
    int ifin;  //indice de fin
    int im;  //indice de "milieu"

    /* initialisation de ces variables avant la boucle de recherche */
    trouve = false;  //la valeur n'a pas encore été trouvée
    id = 0;  //intervalle de recherche compris entre 0...
    ifin = _M;  //...et nbVal

    /* boucle de recherche */
    while(!trouve && ((ifin - id) > 1))
    {
        im = (id + ifin)/2;  //on détermine l'indice de milieu

        trouve = (_X[im].idxT == idx);  //on regarde si la valeur recherchée est à cet indice

        if(_X[im].idxT > idx) ifin = im;  //si la valeur qui est à la case "im" est supérieure à la valeur recherchée, l'indice de fin "ifin" << devient >> l'indice de milieu, ainsi l'intervalle de recherche est restreint lors du prochain tour de boucle
        else id = im;  //sinon l'indice de début << devient >> l'indice de milieu et l'intervalle est de la même façon restreint
    }

    if(_X[id].idxT == idx)
    {
        p=&_X[id];
        q=&_X[id];
        while ((p-1)->idxT == idx) p--;
        while ((q+1)->idxT == idx) q++;

        return true;
    }
    else return false;  //sinon on retourne -1
}


ArcEnCiel::ArcEnCiel(int num,unsigned int M, int T )
{
    _M = M;
    _T = T;
    _numero = num;
    _X = new Chaine[_M];
}

ArcEnCiel::~ArcEnCiel()
{
    delete[] _X;
}
