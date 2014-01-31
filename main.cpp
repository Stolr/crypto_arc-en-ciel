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
    uint64_t index2;

    cout << "Hello world!" << endl;

    myContext.h(clair, empreinte);

    printf("Essai %s ", empreinte);
    cout << " crypte: "  << endl;

    index = myContext.h2i(1, empreinte);

    cout << " index: " << index << endl;

    myContext.i2c(index, clair);

    cout << " clair: " << clair << endl;

/////////////////////////////////////////////////////::
    myContext.h(clair, empreinte);
    printf("Essai %s ", empreinte);
    cout << " crypte: "  << endl;

    index2 = myContext.h2i(1, empreinte);

    cout << " index: " << index2 << endl;

    cout << "--------------------------" << endl;

    cout << "second index: " << myContext.i2i(index, 1);

    cout << "--------------------------" << endl;

    myArc.creer(myContext,0,100,100);


    return 0;
}
