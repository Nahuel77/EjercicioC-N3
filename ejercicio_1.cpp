#include <iostream>

int main() {
    const int filas = 7;
    int pascal[filas]={};
    pascal[0]=1;

    std::cout << "Pirámide de Pascal generada automáticamente:\n";

    for (int i = 0; i < filas; i++) {               //0 1   2   3
        for (int j = i; j > 0; j--) {               //  1   2-1 3-2
            pascal[j] = pascal[j] + pascal[j - 1];  //  1   1-1 1-2-1..
        }
    
        for (int j = 0; j <= i; j++) {
            std::cout << pascal[j] << " ";          //1 1   1-1
        }
        std::cout << std::endl;
    }

    return 0;
}
