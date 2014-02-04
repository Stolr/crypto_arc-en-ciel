#include "Cracker.h"

Cracker::Cracker()
{
    //ctor
}

Cracker::~Cracker()
{
    //dtor
}

bool Cracker::cracker( unsigned char *y, ArcEnCiel aec, Context & ctxt, string & clair )
{
    Chaine* p=0;
    Chaine* q=0;
    uint64_t idx;
    int nb_fausses_alertes = 0;
    for ( int t = aec._T - 1; t > 0; --t ) {
       // fabrication du bon indice
       idx = ctxt.h2i( t, y );
       if(t == 477){
        cout << "je viens de generer le suivant de ghost reconnu" <<endl;
        cout << "empreinnnnnte: " << y << endl;
        cout << "indice generer: " << idx << endl;
        }
       for ( int k = t + 1; k <= aec._T - 1; ++k ) {
         idx = ctxt.i2i( k, idx );
       }
       // Recherche dans la table.
       if ( aec.recherche( idx, p, q ) ) {
       cout << "j'ai trouvé" << endl;

         // On vérifie chacune des alertes
         for ( Chaine* m = p; m <= q; m++ ) {
            cout << " m= "<< m->idx1 << " ; " << m->idxT << endl;
           if ( verifierAlerte( y, ctxt, t, m, clair ) )
             return true;
           nb_fausses_alertes++;
         }
       }
    }
    cout << "Non trouve, fausses alertes = " << nb_fausses_alertes << endl;

    return false;
}
bool Cracker::verifierAlerte( unsigned char *y, Context  & ctxt, int t,Chaine* m, std::string& clair )
{
    unsigned char empreinte[255];
    uint64_t idx = m->idx1;
    for(int i=1; i<=500/*t*/; i++)
    {
        if(idx == 2027052)
            cout << "indice correspondant a ghost trouve: "<< endl;
        ctxt.i2c(idx, clair);
        ctxt.h(clair, empreinte);
        idx = ctxt.h2i(i, empreinte);
        if(i == 477)
            cout << "indice verifie generer: "<< idx << endl;
        /*cout << "----------------" << endl;
        cout << empreinte << endl;
        cout << y << endl;*/
        if(clair.compare("ghost") == 0)
            cout << "trouve: "<< clair << endl;

        int j = 0;
        while (empreinte[j] == y[j])
        {
            //cout << empreinte[j] << y[j] << endl;
            j++;
            if(y[j] == '\0')
            {

            /*cout << "----------------" << endl;
            cout << empreinte << endl;
            cout << y << endl;*/

                return true;
            }
        }
    }
    //cout << "----------------" << endl;
    return false;
}
