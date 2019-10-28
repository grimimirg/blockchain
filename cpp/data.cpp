#include <string>
#include "headers/data.h"

Data::Data() {}

Data::Data(string senderKey, string receiverKey, double amount, time_t timestamp) {
    this->senderKey = senderKey;
    this->receiverKey = receiverKey;
    this->amount = amount;
    this->timestamp = timestamp;
}

string Data::getSenderKey() {
    return this->senderKey;
}

void Data::setSenderKey(string senderKey) {
    this->senderKey = senderKey;
}

string Data::getReceiverKey() {
    return this->receiverKey;
}

void Data::setReceiverKey(string receiverKey) {
    this->receiverKey = receiverKey;
}

double Data::getAmount() {
    return this->amount;
}

void Data::setAmount(double amount) {
    this->amount = amount;
}

time_t Data::getTimestamp() {
    return this->timestamp;
}

void Data::setTimestamp(time_t timestamp) {
    this->timestamp = timestamp;
}
