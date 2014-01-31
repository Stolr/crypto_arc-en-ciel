#include "ArcEnCiel.h"
#include "Context.h"

void ArcEnCiel::creer(Context ctxt, int num, int M, int T )
{
    _numero = num;
    _M = M;
    _T = T;
    uint64_t idx;
    std::string clair="";
    unsigned char empreinte[255];

    for(int i=0;i<_M;i++){
       idx = ctxt.randIndex();
       _X[i].idx1 = idx;
        for(int j=0;j<_T;j++){
            ctxt.i2c(idx, clair);
            ctxt.h(clair, empreinte);
            idx = ctxt.h2i(j, empreinte);
        }
        _X[i].idxT = idx;
    }
}
      // Tri _X suivant idxT.
void ArcEnCiel::trier()
{
}
// Sauvegarde la table sur disque.
void ArcEnCiel::save( std::string name )
{
}
// Charge en mémoire la table à partir du disque.
void ArcEnCiel::load( std::string name )
{
}
// Recherche dichotomique dans la table
// ( p et q sont le premier/dernier trouvé )
bool ArcEnCiel::recherche( uint64_t idx, unsigned int & p, unsigned int & q )
{
}
