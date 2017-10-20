#include <iostream>
using namespace std;


class Matriz{
  public:
  int filas, columnas;
  int **m;
  public:
    void set_tam(int f, int c){
      filas = f;
      columnas = c;
      m = new int* [filas];
      for(int i = 0; i < filas; i++){
        m[i] =  new int [columnas];
      }
    }
    void asignar(){
      for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
          cin >> *(*(m + i) + j);
        }
      }
    }
    void print_mat(){
      for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
          cout << *(*(m + i) + j) << " ";
        }
        cout << endl;
      }
    }
};

class Calc{
  public:
  Matriz a,b,c;
  public:
    void sum_mat(){
      for(int i = 0; i < a.filas; i++){
        for(int j = 0; j < a.columnas; j++){
          c.m[i][j] = a.m[i][j] + b.m[i][j];
        }
      }
      c.print_mat();
    }
    void sus_mat(){
      for(int i = 0; i < a.filas; i++){
        for(int j = 0; j < b.columnas; j++){
          c.m[i][j] = a.m[i][j] - b.m[i][j];
        }
      }
      c.print_mat();
    }
    void max_mat(){
      for(int i = 0; i < a.filas; i++){
        for(int j = 0; j < a.columnas; j++){
          if(a.m[i][j] > b.m[i][j]){//si comp me devuelve true agrego a ya que es el mayor
              c.m[i][j] = a.m[i][j];
          }
          else{
            c.m[i][j] = b.m[i][j];
          }
        }
      }
      c.print_mat();
    }
    int min_mat(int i = 0, int j = 0){
      if(i == a.filas){
        c.print_mat();
        return 0;
      }
      if(j == a.columnas){
        return min_mat(++i,0);
      }
      if(a.m[i][j] < b.m[i][j]){//si comp me develve true le agrego B ya que es el menor
        c.m[i][j] = a.m[i][j];
      }
      else{//sino agrego m ya que es el menor
        c.m[i][j] = b.m[i][j];
      }
      return min_mat(i,++j);
    }

    void promedio(){
      for(int i = 0; i < a.filas; i++){
          for(int j = 0; j < a.columnas; j++){
            c.m[i][j] = (a.m[i][j] + b.m[i][j])/2;
          }
      }
      c.print_mat();
    }
    void mult(){
       for(int i = 0; i < a.filas; i++){
         for(int j = 0; j < b.columnas; j++){
           for(int k = 0; k < a.columnas; k++){
             c.m[i][j] += a.m[i][k] * b.m[k][j];
          }
        }
      }
      c.print_mat();
    }
};



int main(){
  Matriz a;
  Matriz b;
  Matriz result;
  a.set_tam(2,2);
  a.asignar();
  b.set_tam(2,2);
  b.asignar();
  result.set_tam(2,2);
  Calc calcu;
  calcu.a = a;
  calcu.b = b;
  calcu.c = result;
  cout << "suma: \n";
  calcu.sum_mat();
  cout << "resta: \n";
  calcu.sus_mat();
  cout << "promedio: \n";
  calcu.promedio();
  cout << "minimo: \n";
  calcu.min_mat();
  cout << "maximo: \n";
  calcu.max_mat();
  cout << "Ingresa matriz a y b para multiplicarlos: \n";
  a.set_tam(3,2);
  a.asignar();
  b.set_tam(2,3);
  b.asignar();
  result.set_tam(3,3);
  cout << "multiplicacion: \n";
  calcu.a = a;
  calcu.b = b;
  calcu.c = result;
  calcu.mult();

  return 0;
}
