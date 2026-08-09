#include<iostream>
#include<string>
using namespace std;

class Node{
    
public:
    string key;
    int val;
    Node* next;
    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }

};

class HashTable{
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;
        for(int i=0;i<key.length();i++){
            idx = idx + (key[i]*key[i])%totSize;
        }
        return idx%totSize;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totSize;
        totSize = 2*totSize;
        currSize = 0; 

        table = new Node*[totSize];
        for(int i=0;i<totSize;i++){
            table[i] = NULL;
        }

        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

public :
    HashTable(int totSize){
        this->totSize = totSize;
        currSize = 0;

        table = new Node*[totSize];
        for(int i=0;i<totSize;i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){
        int idx = hashFunction(key);
        Node* newNode = new Node(key,val);

        newNode->next = table[idx];
        table[idx] = newNode;
        currSize++;

        double lambda = currSize/(1.0*totSize);
        if(lambda > 0.7){
            rehash();
        }
    }

    void remove(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while(temp != NULL){
            if(temp->key == key){
                if(prev == NULL){
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                delete temp;
                currSize--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool exists(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while(temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
    
        while(temp != NULL){
            if(temp->key == key){
                return temp->val;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }
    
    
};

