#ifndef block_h
#define block_h

#include "data.h"

using namespace std;

class Block {

    private:
        int index;
        size_t hash;
        size_t previousHash;
        Data data;

        size_t toHash();

    public:
        Block();
        Block(int index, Data data, size_t previousHash);

        int getIndex();
        void setIndex(int index);

        size_t getHash();
        void setHash(size_t hash);

        size_t getPreviousHash();
        void setPreviousHash(size_t previousHash);

        Data getData();
        void setData(Data data);

        bool isValid();

};
#endif