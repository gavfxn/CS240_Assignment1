#include <string>
#include <iostream>
#include <vector>


int ASCIItoDecimal(char c) {
    return (int)c;
}

std::vector<int> ASCIItoDecimal(std::string s) {

    std::vector<int> arr;

    for (int i = 0; i < s.length(); i++) {
        arr.push_back(ASCIItoDecimal(s[i]));
    }

    return arr;
}


int main(){
    
    std::cout << ASCIItoDecimal('A') << std::endl;

    std::cout << "ASCII to Decimal Conversion" << std::endl;
    

    std::string s = "Hello, World!";

    std::vector<int> result = ASCIItoDecimal(s);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result.at(i) << " ";
    }
}



