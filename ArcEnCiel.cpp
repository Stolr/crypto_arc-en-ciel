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
            idx = ctxt.i2i(idx, j);
        }
        _X[i].idxT = idx;
    }
}
      // Tri _X suivant idxT.
void ArcEnCiel::trier()
{
  register int a, b, c;
  int temp;
  char t;

  for(a = 0; a < _M-1; ++a) {
    temp = 0;
    c = a;
    t = _X[ a ]->idxT ;
    for(b = a + 1; b < _M; ++b) {
      if( _X[ b ]->idxT < t) {
        c = b;
        t =  _X[ b ]->idxT ;
        temp = 1;
      }
    }
    if(temp) {
       _X[ c ]->idxT  =  _X[ a ]->idxT ;
       _X[ a ]->idxT  = t;
    }
  }
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
