#include <string>

#include "../headers/block.h"
#include "../headers/data.h"

using namespace std;

Block::Block() {}

Block::Block(int index, Data data, size_t previousHash) {
    this->index = index;
    this->hash = this->toHash();
    this->previousHash = previousHash;
    this->data = data;
}

int Block::getIndex() {
    return this->index;
}

void Block::setIndex(int index) {
    this->index = index;
}

size_t Block::getHash() {
    return this->hash;
}

void Block::setHash(size_t hash) {
    this->hash = hash;
}

size_t Block::getPreviousHash() {
    return this->previousHash;
}

void Block::setPreviousHash(size_t previousHash) {
    this->previousHash = previousHash;
}

Data Block::getData() {
    return this->data;
}

void Block::setData(Data data) {
    this->data = data;
}

bool Block::isValid() {
    return this->toHash() == this->hash;
}

size_t Block::toHash() {
    std::hash<string> hashFuncData;
    std::hash<size_t> hashFuncPreviousHash, completeHash;

    // La stringa da hashare viene creata con tutte le informazioni
    // della transazione (nel caso di BTC) o da qualsiasi altra informazione
    // sensibile riguardante il contesto per il quale blockchain viene implementato.
    //
    // Se questo blocco viene modificato, il suo hash cambia e
    // non essendo più uguale all'hash del "previousHash" del
    // blocco successivo, s'incula hehehe >:D
    return completeHash(
        hashFuncData(
            this->data.getReceiverKey()
            + this->data.getSenderKey() 
            + to_string(this->data.getAmount()) 
            + to_string(this->data.getTimestamp())
        ) + hashFuncPreviousHash(previousHash)
    );
}