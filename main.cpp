#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Context.h"
#include "ArcEnCiel.h"
#include "md5.h"
#include "sha1.h"

using namespace std;

int main()
{
    Context myContext;
    ArcEnCiel myArc;
    unsigned char empreinte[255];
    string clair = "grape";
    uint64_t index;

    cout << "Hello world!" << endl;

    myContext.h(clair, empreinte);

    printf("Essai %s ", empreinte);
    cout << " crypte: "  << endl;

    index = myContext.h2i(1, empreinte);

    cout << " index: " << index << endl;

    myContext.i2c(index, clair);

    cout << " clair: " << clair << endl;

    cout << "index aleatoire: " << myContext.randIndex();

    myArc.creer(myContext,0,100,100);


    return 0;
}
