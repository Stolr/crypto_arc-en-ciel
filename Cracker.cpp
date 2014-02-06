#include "Cracker.h"

Cracker::Cracker()
{
    //ctor
}

Cracker::~Cracker()
{
    //dtor
}


/*
Fonction permettant de cracker l'empreinte donnée en paramètre à l'aide des différentes fonctions créées
*/
bool Cracker::cracker( unsigned char *y, ArcEnCiel& aec, Context & ctxt, string & clair )
{
    Chaine* p=0;
    Chaine* q=0;
    uint64_t idx;
    int nb_fausses_alertes = 0;

    for ( int t = aec._T - 1; t > 0; --t ) {
       // fabrication du bon indice
       ctxt.h2i( t, y );
       for ( int k = t+1; k <= aec._T-1 ; ++k ) {
         idx = ctxt.i2i(idx, k);
       }

       // Recherche dans la table.
       if ( aec.recherche( idx, p, q ) ) {
         // On vérifie chacune des alertes
         //&aec._X [0] &aec._X[aec._M]
         for ( Chaine* m = p; m <= q; m++ ) {
            //cout << " m= "<< m->idx1 << " ; " << m->idxT << endl;
           if ( verifierAlerte( y, ctxt, t, m, clair ))
           {
             return true;
            }
           nb_fausses_alertes++;
         }
       }
    }
    cout << "Non trouve, fausses alertes = " << nb_fausses_alertes << endl;

    return false;
}

/*
   Fonction permettant de vérifier si une ligne trouvée contient l'empreinte et donc le clair
*/
bool Cracker::verifierAlerte( unsigned char *y, Context  & ctxt, int t,Chaine* m, std::string& clair )
{
    unsigned char empreinte[255];
    uint64_t idx = m->idx1;

    for(int i=0; i<t; i++)
    {
        ctxt.i2c(idx, clair);
        ctxt.h(clair, empreinte);

        // opti :
        idx = ctxt.h2i(i, empreinte);
        //idx = ctxt.i2i(idx, i);

        // verification du l'empreinte
        int j = 0;

        while (empreinte[j] == y[j])
        {
            j++;
            if(y[j] == '\0') return true;
        }
    }
    clair =" Aucune correspondance";
    return false;
}
