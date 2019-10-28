#ifndef chain_h
#define chain_h

#include <vector>
#include "block.h"

using namespace std;

class Chain {

    private:
        vector<Block> chain;
        Block createGenesisBlock();

    public:
        Chain();

        vector<Block> getChain();
        void setChain(vector<Block> chain);

        Block createBlockFromData(Data data);
        void addBlock(Block block);
        Block *getLatestBlock();
        bool isValid();

};
#endif