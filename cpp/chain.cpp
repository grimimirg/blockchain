#include <iostream>
#include <time.h>

#include "headers/block.h"
#include "headers/chain.h"

using namespace std;

Chain::Chain() {
    // Ogni volta che la Chain viene inizializzata, deve
    // per forza avere almeno un blocco (il primo in assoluto).
    chain.push_back(
        this->createGenesisBlock()
    );
}

Block Chain::createGenesisBlock() {
    // Per il primo blocco in assoluto, non sono
    // necessarie particolari informazioni.
    //
    // Previous hash (ultimo parametro) impostato come l'hash
    // di 0 in quanto non esiste nessun blocco precedente a questo.
    //
    // Assegnato nel momento della creazione, appunto :V
    time_t now;
    hash<int> hashFunc;
    return Block(0, Data("genesis", "genesis", 0, time(&now)), hashFunc(0));
}

vector<Block> Chain::getChain() {
    return this->chain;
}

void Chain::setChain(vector<Block> chain) {
    this->chain = chain;
}

Block Chain::createBlockFromData(Data data) {
    return Block(
        ((int) chain.size()) - 1, 
        data, 
        this->getLatestBlock()->getHash()
    );
}

void Chain::addBlock(Block block) {
    chain.push_back(block);
}

Block *Chain::getLatestBlock() {
    return &chain.back();
}

bool Chain::isValid() {
    vector<Block>::iterator iterator;

    for(iterator = chain.begin(); iterator != chain.end(); ++iterator) {
        Block currentBlock = *iterator;

        // Scrivere meglio ste due condizioni perchè fannommerdah :D
        if (!currentBlock.isValid()) {
            // La chain non è più valida
            return false;
        }

        if ((int) chain.size() > 1) {
            Block previousBlock = *(iterator - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getHash()) {
                // Il blocco corrente è stato modificato
                // La chain non è più valida
                return false;
            }
        }
    }

    return true;
}