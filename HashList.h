//
//
//  Created by SOFLY on 11/17/18.
//  Copyright © 2018 SOFLY. All rights reserved.
//
#include "StudentList.h"
#include "Student.h"

#ifndef HashList_h
#define HashList_h


using namespace std;

class HashList{
    const static int MAX_SIZE= 100000;

private:
    int size;
    StudentList* hashTable;
    int numberOfCollision;
    int count;

    int _getGoodKeyNumber(string key);
    int _getBadKeyNumber(string key);

public:
    HashList(int s){size = s;
        numberOfCollision = 0;
        count = 0;
        hashTable = new StudentList[s];
    }
    int getSize(){return size;}
    double getLoadFactor(){return ((double)(count)/size)*100;}
    bool badHashing(string key, Student* value);
    bool goodHashing(string key, Student* value);
    bool getValueByGoodHashing(string key, Student& returned);
    bool getValueByBadHashing(string key, Student& returned);
    void debugPrinting(){
        for(int i = 0; i < size; i++)
            cout << "array position:" << i << " has(" << hashTable[i].getCount() << ")students." << endl;
        cout << "Collision total: " << numberOfCollision << endl;
        cout << "Load Factor: " << getLoadFactor() << endl;
    }
};



//////////////////Public Function Definitions////////////////
bool HashList::badHashing(string key, Student* value){
    int keyNum = _getBadKeyNumber(key);
    int address = keyNum % size;
    if(hashTable[address].getCount() == 0){
        count++;
        hashTable[address].insertNode(value);
        return true;
    }
    else{
        numberOfCollision++;
        hashTable[address].insertNode(value);
        return true;
    }
    return false;
}

bool HashList::goodHashing(string key, Student* value){
    int keyNum = _getGoodKeyNumber(key);
    int address = keyNum% size;
    if(hashTable[address].getCount() == 0){
        count++;
        hashTable[address].insertNode(value);
        return true;
    }
    else{
        numberOfCollision++;
        hashTable[address].insertNode(value);
        return true;
    }
    return false;
}

bool HashList::getValueByGoodHashing(string key, Student& returned){
    int keyNum = _getGoodKeyNumber(key);
    int address = keyNum % size;
    StudentList target = hashTable[address];
    if(target.searchListByID(key, returned)==true)
        return true;
    return false;

}

bool HashList::getValueByBadHashing(string key, Student& returned){
    int keyNum = _getBadKeyNumber(key);
    int address = keyNum % size;
    StudentList target = hashTable[address];
    if(target.searchListByID(key, returned)==true)
        return true;
    return false;

}

//////////////////Private Function Definitions////////////////
int HashList::_getBadKeyNumber(string key){
    int result = atoi((key.substr(0, 1)).c_str());
    return result;
}

int HashList::_getGoodKeyNumber(string key){
    int result = 1;
    result *= atoi((key.substr(0, 3)).c_str());
    result = result * result;
    result *= atoi((key.substr(3, 3)).c_str());
    result -= atoi((key.substr(1, 4)).c_str());
    return result;
}




#endif /* Header_h */
