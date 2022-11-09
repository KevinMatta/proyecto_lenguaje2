#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

class empleado
{
private:
  string name;
  string cargo;
  float salario;
  int horas_extras;

public:
  empleado(string _name, string _cargo, float _salario, int _horas_extras)
  {
    name = _name;
    cargo = _cargo;
    salario = _salario;
    horas_extras = _horas_extras;
  }
  // void setSalario(float _salario)
  // {
  //   salario = _salario;
  // }
  // void setAumento(string aumento)
  // {
  //   float nuevoSalario = getSalario();
  //   nuevoSalario = nuevoSalario + aumento;
  //   setSalario(nuevoSalario);
  // }
  string getName() { return name; }
  string getCargo() { return cargo; }
  float getSalario() { return salario; }
  int getHoras_extras() { return horas_extras; }
  float getQuincena() { return salario / 2; }
  float valorHoras_extras() { return ((horas_extras / 15) / 8) * horas_extras; }
  float totalBruto() { return getQuincena() + valorHoras_extras(); }
};

void menuPrincpipal();
void printPlanilla();
void printDeducciones();
void hacerAumentos();
void printSalarios();
void bono();

int main()
{
  // proyecto de lenguaje de programacion 2
  // asdasdasd

  return 0;
}

void menuPrincpipal()
{
  int opcion;
  cout << "Menu Principal\n";
  cout << "1. ver planilla / 2. ver deducciones por empleados / 3. realizar aumento / 4. ver salario sin deducciones / 5. bonos a empleados / 6. limpiar / 7. salir\n";
  cout << "Ingrese el numero de la opcion: ";
  cin >> opcion;

  switch (opcion)
  {
  case 1:
    printPlanilla();
    break;
  case 2:
    printDeducciones();
    break;
  case 3:
    hacerAumentos();
    break;
  case 4:
    printSalarios();
    break;
  case 5:
    bono();
    break;
  case 6:
    system("cls");
    break;
  case 7:
    break;
  default:
    menuPrincpipal();
  }
}

void printPlanilla()
{
  int opcion;
  cout << "1. mostrar planilla individual / 2. mostrar planilla general / 3. regresar al menu principal / 4. limpiar pantalla y salir\n";
  cin >> opcion;
  switch (opcion)
  {
  case 1: // busca al empleado y muestra planilla
    break;
  case 2: // mostrar planilla general
    break;
  case 3:
    menuPrincpipal();
    break;
  case 4:
    system("cls");
    break;
  default:
    printPlanilla();
  }
}

void printDeducciones()
{
  int opcion;
  cout << "1. mostrar deducciones individuales / 2. mostrar deducciones generales / 3. regresar al menu principal / 4. limpiar pantalla y salir\n";
  cin >> opcion;
  switch (opcion)
  {
  case 1: // busca al empleado y muestra deducciones
    break;
  case 2: // mostrar deducciones de todos los empleados
    break;
  case 3:
    menuPrincpipal();
    break;
  case 4:
    system("cls");
    break;
  default:
    printDeducciones();
  }
}

void hacerAumentos()
{
  // revisar logica!!
  string opcion;
  float aumento;
  int aux;
  bool state = false;
  cout << "ingrese el nombre del empleado o empleada: ";
  cin >> opcion;
  for (int i = 0; i < 40; i++)
  {
    if (opcion == obj[i].getName())
    { // Error: objeto y metodo no declarados
      state = true;
      aux = 1;
      i = 40;
    }
    else
    {
      state = false;
    }
    if (state)
    {
      cout << "ingrese la cantidad del aumento: ";
      cin >> aumento;
      obj[i].setAumento(aumento);
      cout << "aumento realizado\n";
      menuPrincpipal();
    }
    else
    {
      cout << "empleado no encontrado";
      menuPrincpipal();
    }
  }
}

void printSalarios()
{
  int opcion;
  cout << "1. mostrar salario individual / 2. mostrar salarios de empleados / 3. regresar al menu principal / 4. limpiar pantalla y salir\n";
  cin >> opcion;
  switch (opcion)
  {
  case 1: // busca al empleado y muestra el salario
    break;
  case 2: // mostrar salarios de los empleados
    break;
  case 3:
    menuPrincpipal();
    break;
  case 4:
    system("cls");
    break;
  default:
    printSalarios();
  }
}

void bono()
{
  srand(time(NULL));
  int aleatorio = rand() % 500 + 2000;
  // se suma el bono al la quincena
}