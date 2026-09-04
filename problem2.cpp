#include <iostream>
#include <math.h>
using namespace std;

string baseConverter(string number, int baseOG, int baseNew) {
    

    
    //Convert any num to base 10
    int num = 0;
    if (baseOG == 2) {
        for (int i = 0; i < number.length(); i++) {
            if (number.at(i) == '1') {
                num += pow(2, number.length() - 1 - i);
            }
        }
    }

    if (baseOG == 8) {
        for (int i = 0; i < number.length(); i++){
            num += (number.at(i) - '0') * pow(8, number.length() - 1 - i);
        }
    }

    if (baseOG == 10) {
        num = stoi(number);
    }

    if (baseOG == 16) {
        for (int i = 0; i < number.length(); i++) {
            if (number.at(i) >= 0 && number.at(i) <= 9) {
                num += (number.at(i) - '0') * pow(16, number.length() - 1 - i);
            }if (number.at(i) >= 'A' && number.at(i) <= 'F') {
                num += (number.at(i) - 55) * pow(16, number.length() - 1 - i);
            }
        }
    }

    string newNum = "";

    if (baseNew == 2) {
        int bits = 1;
        for (int i = 1; num / i > 1; i *= 2) {
            bits++;
        }

        for (int i = pow(2, bits - 1); i != 0; i /= 2) {
            if (num / i >= 1) {
                newNum += '1';
                num -= i;
            } else {
                newNum += '0';
            }
        }


    }

    if (baseNew == 8) {
        int digits = 1;
        for (int i = 1; num / i > 7; i *= 8) {
            digits++;
        }
        for (int i = pow(8, digits - 1); i != 0; i /= 8) {
            if (num / i >= 1) {
                newNum += '0' + (num / i);
                num %= i;
            } else {
                newNum += '0';
            }
        }
    }



    if (baseNew == 10) {
        newNum = std::to_string(num);
    }

    if (baseNew == 16) {
        int digits = 1;
        for (int i = 1; num / i > 15; i *= 16) {
            digits++;
        }
        for (int i = pow(16, digits - 1); i != 0; i /= 16) {
            if (num / i >= 1) {
                newNum += '0' + (num / i);
                num %= i;
            } else {
                newNum += '0';
            }
        }
    }

    return newNum;

    


}




int main(){

    string number = "1000";

    cout << baseConverter(number, 10, 8) << endl;

    return 0;
}