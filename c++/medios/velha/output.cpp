#include "output.hpp"

using namespace std;

string printComplete(string content){
    int x;
    string result;
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

string printLeft(string content){
    int x;
    string result;
    x = content.size();
    result.append("|");
    result.append(content);
    for(int i = 1;i<49-x;i++){
        result.append(" ");
    }
    result.append("|");
    return result;
}