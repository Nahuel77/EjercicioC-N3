#include <iostream>
using namespace std;

class Pitagoras {
private:
  int catetoA, catetoB;
  float hipotenusa;

  // metodo para calcular una raiz cualquiera sea, por aproximación iterada.
  // Cada iteración converge al resultado, si es que no es una raiz notable.
  // Si la raiz es notable, se obtiene el resultado al primer intento.
  // Serie de Newton-Raphson: https://es.wikipedia.org/wiki/M%C3%A9todo_de_Newton
  float calcularRaiz(int x) {
    float raizAprox = x / 2.0;
    float y;

    do {
      y = raizAprox;
      raizAprox = (raizAprox + (x / raizAprox)) / 2;
    } while ((y - raizAprox) > 0.0001);
    return raizAprox;
  }

public:
  // Consutructor (lee los datos de entrada);
  // En C++ la funcion con el mismo nombre de la clase se toma como constructor
  // automaticamente.
  Pitagoras(int _catetoA, int _catetoB) {
    catetoA = _catetoA; // la notación _catetoA es equivalente a this catetoA
    catetoB = _catetoB;
  }

  float calcularHipotenusa() {
    int x = ((catetoA * catetoA) + (catetoB * catetoB));
    hipotenusa = calcularRaiz(x);
    // cout << "La hipotenusa es: " << hipotenusa << endl;
    return hipotenusa;
  }
};

int main() {
  std::cout << "Hello World!\n";

  float hipo500;

  for (int i = 1; i < 500; i++) {
    for (int j = 1; j < 500; j++) {
      Pitagoras pitagoras = Pitagoras(i, j);
      hipo500 = pitagoras.calcularHipotenusa();
      if (hipo500 < 500) {
        cout << "La hipotenusa con cateto A: " << i << " y cateto B: " << j
             << " es: " << hipo500 << endl;
      }
    }
  }

  return 0;
}
