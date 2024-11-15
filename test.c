#include <stdio.h>
#include <math.h>

int main() {
    long int cardNum = 4003600000000014;
    int length = 0;
    for (long int x = 1; x < cardNum; x *= 10) {
        length += 1;
    }
    int times = 1;
    int p = length - 1;
    int total = 0;
    int total2 = 0;
    int total3 = 0;
    for (long int y = pow(10, p); y > 0; y /= 10){
        int digit = cardNum / y;
        cardNum -= digit * y;
        if (times <= 2){
          total2 += digit;
          if (times == 1) {
            total3 += digit;
          }
        }
        int result = 0;
        if (times % 2 == 1) {
            result += digit * 2;
            for (int z = 10; z > 0; z /= 10) {
                int digit2 = result / z;
                result -= digit2 * z;
                total += digit2;
            }
        }
        else {
            total += digit;
        }
        times += 1;
    }
    if (total % 10 == 0) {
    printf("Valid\n");
    if (length == 15 && (total2 == 7 || total2 == 10)){
        printf("American Express\n");
    }
    else {
        if (length == 16 && (total2 == 6 || total2 == 7 || total2 == 8 || total2 == 9 || total2 == 10)) {
            printf("MasterCard\n");
        }
        else {
            if ((length == 13 || length == 16) && total3 == 4) {
                printf("VISA\n");
            }
            }
        }
    }
}
