// Pascal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// SIN TERMINAR!!!

#include <iostream>
#include <string>

int powTen(int num) {
    int result = 1;
    if (num == 0) { result = 1; }
    if (num > 1) {
        for (int k = 1; k < num; k++) {
            result = result * 10;
        }
    }
    return result;
}

int main()
{
    std::cout << "Piramide de Pascal generada automaticamente!\n";
    // se espera obtener:
    // 1 - 1 1 - 1 2 1 - 1 3 3 1 - 1 4 6 4 1 - 1 5 10 10 5 1 - 1 6 15 20 15 6 1
    int pascal[7];

    //normalizo el array a 0
    for (int i = 0; i < 6; i++) {
        pascal[i] = 0;
    }

    pascal[0] = 1;

    for (int i = 1; i < 7; i++) {//2
        int pow = powTen(i+1);        //100
        //std::cout << "i: "<< i << std::endl;
        //std::cout << "pow: " << pow << std::endl;

        int row = pascal[i - 1];    //11
        int tempFour = 0;
        //std::cout << "pascal " << i << ": " << pascal[i - 1] << std::endl;
        for (int j = 0; j < i ; j++) {


            int tempOne = row % 10;                         // 1
            //std::cout << "tempOne: " << tempOne << std::endl;
            row = row / 10;                                 // 1
            //std::cout << "row: " << row << std::endl;
            int tempTwo = row % 10;                         // 1
            //std::cout << "tempTwo: " << tempTwo << std::endl;

            //////////////aqui corregir el accarreo cuando tempOne + tempTwo es mayor a un digito////////
            int tempThree = (tempOne + tempTwo)*powTen(i-j);//2*10 = 20 
            tempFour = tempFour + tempThree; //1+1
            //std::cout << "tempFour: " << tempFour << std::endl;

            pascal[i] = pow + tempFour;
        }
    }

    for (int i = 0; i < 7; i++) {
        std::cout << pascal[i] << std::endl;
    }

}
