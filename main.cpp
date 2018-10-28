/*
* Author: kelj0
* Github: https://github.com/kelj0/Brainfuck-interpreter
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
    char *ptr = (char*) malloc(2048);
    ptr = ptr+512;
    std::ifstream in("bf.txt");
    if(!in){
        std::cout << "Error opening file, check filename\n";
        return 1;
    }
    std::string arr;
    std::getline(in,arr);
    in.close();
    char ins;
    std::stack<int> s;
    std::cout << "=======\nOutput: ";
    for(int i = 0; i < arr.length();++i){
        ins = arr[i];
        switch(ins){
            case '>':++ptr;break;
            case '<':--ptr;break;
            case '+':++*ptr;break;
            case '-':--*ptr;break;
            case '.':std::cout << static_cast<char*>(ptr);break;
            case ',':
                std::cout<<"\nEnter char: ";
                *ptr = getchar();
                break;
            case '[':
                if(!i){
                    std::cout << "Thats a fishy while loop on start im aborting";
                    return 1;
                }
                if(*ptr){
                    s.push(i-1);
                }else{
                    while(arr[i]!=']')
                        ++i;
                }
                break;
            case ']':
                if(!i){
                    std::cout << "See first character you wrote. Hm.";
                    return 1;
                }
                i = s.top();
                s.pop();
                break;
            default:
                std::cout << "====Syntax error====\n";
                return 1;
        }
    }
    std::cout << std::endl;
    return 0;
}
