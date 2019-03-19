//
//  main.cpp
//  InterviewQuestion_CArray
//
//  Created by 舒毅文 on 2019/3/19.
//  Copyright © 2019 舒毅文. All rights reserved.
//

#include <iostream>
#include "AiArray.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    AiArray * aaa = new AiArray();
    aaa->addData(0);
    aaa->addData(1);
    aaa->addData(2);
    aaa->addData(3);
    aaa->addData(4);
    int aa = aaa->searchDataWithIndex(3);
    std::cout << aa << std::endl;
    aaa->deleteDataWithIndex(3);
    aa = aaa->searchDataWithIndex(3);
    std::cout << aa << std::endl;
    aaa->updataDataWithIndex(3, 100);
    aa = aaa->searchDataWithIndex(3);
    std::cout << aa << std::endl;
    aaa->insertDataWithIndex(2, 999);
    aa = aaa->searchDataWithIndex(3);
    std::cout << aa << std::endl;
    std::cout << "Hello, World!\n";
    return 0;
}
