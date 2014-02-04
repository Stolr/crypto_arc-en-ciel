#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Context.h"
#include "ArcEnCiel.h"
#include "Cracker.h"
#include "md5.h"
#include "sha1.h"

using namespace std;

int main()
{
    Context myContext;
    ArcEnCiel* myArc = new ArcEnCiel(0,100000,1000);
    unsigned char empreinte[255];
    Chaine* p = 0;
    Chaine* q = 0;
    string mdp = "ghost";
    unsigned char mdpCrypt[255];
    uint64_t index;
    uint64_t index2;
    string clair;
    Cracker* cracker = new Cracker();

    myContext.h(mdp, mdpCrypt);
    /*cout << "Hello world!" << endl;

    myContext.h(clair, empreinte);

    printf("Essai %s ", empreinte);
    cout << " crypte: "  << endl;

    index = myContext.h2i(1, empreinte);

    cout << " index: " << index << endl;*/

    //myContext.i2c(11680331, clair);

    //cout << " clair: " << clair << endl;
/*
/////////////////////////////////////////////////////::
    myContext.h(clair, empreinte);
    printf("Essai %s ", empreinte);
    cout << " crypte: "  << endl;

    index2 = myContext.h2i(1, empreinte);

    cout << " index: " << index2 << endl;

    cout << "--------------------------" << endl;

    cout << "second index: " << myContext.i2i(index, 1);

    cout << "--------------------------" << endl;

    cout << "rand index: " << myContext.randIndex();*/
    //myArc->creer(myContext);
    //myArc->trier();
    //myArc->save("PremierTest.txt");
    myArc->load("PremierTest.txt");
    /*for(int i=0;i<myArc->_M;i++){
        cout << "Trie: " << myArc->_X[i].idxT <<endl;
    }*/
    cout << "mdp clair   =>" << mdp << endl;
    cout << "mdp encrypt =>" << mdpCrypt << endl;

    //myArc->recherche(myContext.h2i(1,mdpCrypt))

    cracker->cracker( mdpCrypt, *myArc, myContext, clair );

    cout << "mdp clair   =>" << clair << endl;

    delete cracker;

    return 0;
}
