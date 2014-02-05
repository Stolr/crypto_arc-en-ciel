#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Context.h"
#include "ArcEnCiel.h"
#include "Cracker.h"
#include "md5.h"
#include "sha1.h"


/* Fonctionne avec singe, caves, fruit*/
/* Fonctionne pas avec porte, juste*/
using namespace std;

int main()
{
    Context myContext;
    ArcEnCiel* myArc = new ArcEnCiel(0,100000,1000);
    unsigned char mdpCrypt[255];
    string clair;
    Cracker* cracker = new Cracker();
    //myArc->creer(myContext);
    //myArc->trier();
    //myArc->save("PremierTest.txt");

    myArc->load("PremierTest.txt");
   cout << " Saisissez le Sha1 a decrypter:\n>";
   cin.get((char*)mdpCrypt, 255 );

    cout << endl; // Tres important sinon marche pas

    cracker->cracker( mdpCrypt, *myArc, myContext, clair );

    cout << "mdp clair   =>" << clair << endl;

    delete cracker;

    return 0;
}
