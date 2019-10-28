#include <iostream>
#include <time.h>

#include "headers/chain.h"
#include "headers/data.h"

using namespace std;

int main() {
    time_t now;
    
    Chain chain = Chain();
    chain.addBlock(
        chain.createBlockFromData(
            // Il Grimi diventa povero andando in ALL-IN 
            // sulla puntata del Johnny.
            // Haha tanto perderà, che sfigato :D
            Data("grimiKey", "johnnyKey", 1000, time(&now))
        )
    );

}