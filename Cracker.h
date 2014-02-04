#ifndef CRACKER_H
#define CRACKER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Context.h"
#include "ArcEnCiel.h"

class Cracker
{
    public:
        Cracker();
        virtual ~Cracker();
        bool cracker( unsigned char *y, ArcEnCiel aec, Context& ctxt, string & clair );
        bool verifierAlerte( unsigned char *y, Context& ctxt, int t,Chaine* m, std::string& clair );
    protected:
    private:
};

#endif // CRACKER_H
