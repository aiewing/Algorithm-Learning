//
//  AiArray.hpp
//  InterviewQuestion_CArray
//
//  Created by 舒毅文 on 2019/3/19.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#ifndef AiArray_hpp
#define AiArray_hpp

#include <stdio.h>

typedef int TYPE;

struct NodeList {
    TYPE val;
    NodeList *prev;
    NodeList *next;
    NodeList(int x) : val(x) {}
};

class AiArray {
private:
    NodeList *_headNode;
    NodeList *_tailNode;
    int _size;
    
public:
    AiArray();
    ~AiArray();
    
    bool addData(TYPE data);
    bool deleteDataWithIndex(int index);
    int searchDataWithIndex(int index);
    bool updataDataWithIndex(int index, TYPE data);
    bool insertDataWithIndex(int index, TYPE data);
    int count() {
        return _size;
    }
};

#endif /* AiArray_hpp */
