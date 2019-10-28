#ifndef data_h
#define data_h

#include <string>

using namespace std;

class Data {

    private:
        string senderKey;
        string receiverKey;
        double amount;
        time_t timestamp;

    public:
        Data();
        Data(string senderKey, string receiverKey, double amount, time_t timestamp);

        string getSenderKey();
        void setSenderKey(string senderKey);

        string getReceiverKey();
        void setReceiverKey(string receiverKey);

        double getAmount();
        void setAmount(double amount);

        time_t getTimestamp();
        void setTimestamp(time_t timestamp);

};
#endif