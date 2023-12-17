#include <iostream>
#include <string.h>
using namespace std;

const char tens[6][50] = {{"двадцять"}, {"тридцять"}, {"сорок"}, {"п'ятдеят"}, {"шістдесят"}, {"сімдесят"}};
const char ones[9][50] = {{"один"}, {"два"}, {"три"}, {"чотири"}, {"п'ять"}, {"шість"}, {"сім"}, {"вісім"}, {"дев'ять"}};
const char lessThanTwenty[6][50] = {{"чотирнадцять"}, {"п'ятнадцять"}, {"шістнадцять"}, {"сімнадцять"}, {"віміснадцять"}, {"дев'ятнадцять"}};

void numAgeToString(int age, char result[]){
    if(age < 14 || age > 75){
        cout << "Не задовольняє умові";
        return;
    }

    if(age < 20){
        strncat(result, lessThanTwenty[age-14], 32);
        strncat(result, " років", 32);
        return;
    }
    strncat(result, " ", 1);

    strncat(result, tens[(age/10)-2], 32);
    if(age%10 != 0){
        strncat(result, " ", 1);
        strncat(result, ones[(age%10) - 1], 32);

        if(age%10 == 1){
            strncat(result, " рік", 32);
        }else if(age%10 > 1 and age%10 <5){
            strncat(result, " роки", 32);
        }else{
            strncat(result, " років", 32);
        }
    } else{
        strncat(result, " років", 32);
    }

}


int main() {
    system("chcp 65001");
    char result[255];
    numAgeToString(74, result);
    cout << result;
    return 0;
}
