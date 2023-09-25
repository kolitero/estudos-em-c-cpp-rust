#include "output.hpp"

std::string printComplete(std::string content){
    int x;
    std::string result;
    x = content.size();
    result.append("|");
    for(int i = 1;i<50/2-x/2;i++){
        result.append(" ");
    }
    result.append(content);
    for(int i = 1;i<50/2-x/2-1;i++){
        result.append(" ");
    }
    result.append("|");
    return result;
}

std::string printLeft(std::string content){
    int x;
    std::string result;
    x = content.size();
    result.append("|");
    result.append(content);
    for(int i = 1;i<49-x;i++){
        result.append(" ");
    }
    result.append("|");
    return result;
}