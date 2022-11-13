#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int fila = 6, columna = 8;
empleado employees[fila][columna];
int arr[2];

class empleado
{
private:
  int id;
  string cargo;
  float salario;
  float bono;

public:
  empleado(int _id, string _cargo, float _salario, int _bono)
  {
    id = _id;
    cargo = _cargo;
    salario = _salario;
    bono = _bono;
  }
  void setSalario(float _salario)
  {
    salario = _salario;
  }
  void setAumento(float aumento)
  {
    float nuevoSalario = getSalario();
    nuevoSalario = nuevoSalario + aumento;
    setSalario(nuevoSalario);
  }
  void setBono(float _bono)
  {
    bono = _bono;
  }
  int getId() { return id; }
  string getCargo() { return cargo; }
  float getSalario() { return salario; }
  float getQuincena() { return salario / 2; }
  float getBono() { return bono; }
  float getRAP() { return (getSalario() * 1.5) / 100; }
  float getIHSS() { return (getSalario() * 4) / 100; }
  float getISR() { return (getSalario() * 1.32) / 100; }
  float getIV()
  {
    if (getSalario() == 30000)
      return 30 * 3;
    if (getSalario() == 14000)
      return 14 * 3;
    if (getSalario() == 13050.68)
      return 13 * 3;
    if (getSalario() == 11419.35)
      return 11 * 3;
    if (getSalario() == 10875.57)
    {
      return 10 * 3;
    }
  }
  float getCooperativa() { return getSalario(); }
};

void menuPrincpipal();
void menuPlanilla();
void menuDeducciones();
void hacerAumentos();
void menuSalarios();
void hacerBono();
bool findEmp(int id);

int main()
{

  return 0;
}

void menuPrincpipal()
{
  bool state = true;
  int opcion;
  do
  {
    cout << "MENU PRINCIPAL\n";
    cout << "1. ver planilla / 2. ver deducciones  / 3. realizar aumento / 4. ver salario sin deducciones / 5. bonos aleatorios / 6. limpiar pantalla / 7. salir\n";
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      menuPlanilla();
      break;
    case 2:
      menuDeducciones();
      break;
    case 3:
      hacerAumentos();
      break;
    case 4:
      menuSalarios();
      break;
    case 5:
      hacerBono();
      break;
    case 6:
      system("cls");
      break;
    case 7:
      state = false;
      break;
    default:
      cout << "Ingres una opcion valida\n";
    }
  } while (state);
}

void menuPlanilla()
{
  bool state = true;
  int opcion;
  do
  {
    cout << "MENU DE PLANILLAS\n";
    cout << "1. mostrar planilla individual / 2. mostrar planilla general / 3. limpiar pantalla / 4. regresar al menu principal\n";
    cin >> opcion;
    switch (opcion)
    {
    case 1: // busca al empleado y muestra planilla
      break;
    case 2: // mostrar planilla general
      break;
    case 3:
      system("cls");
      break;
    case 4:
      state = false;
      break;
    default:
      cout << "Ingres una opcion valida\n";
    }
  } while (state);
}

void menuDeducciones()
{
  bool state = true;
  int opcion;
  do
  {
    cout << "1. mostrar deducciones individuales / 2. mostrar deducciones generales / 3. limpiar pantalla / 4. volver al menu principal\n";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;

      if (findEmp(id))
      {
        cout << setw(8) << left << "ID"
             << setw(20) << left << "CARGO"
             << setw(18) << left << "SALARIO"
             << setw(16) << left << "RAP"
             << setw(16) << left << "IHSS"
             << setw(16) << left << "ISR"
             << setw(16) << left << "IMP VECINAL"
             << "COOPERATIVA"
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(20) << left << employees[arr[0]][arr[1]].getSalario()
             << setw(20) << left << employees[arr[0]][arr[1]].getRAP()
             << setw(20) << left << employees[arr[0]][arr[1]].getIHSS()
             << setw(20) << left << employees[arr[0]][arr[1]].getISR()
             << setw(20) << left << employees[arr[0]][arr[1]].getIV()
             << setw(20) << left << employees[arr[0]][arr[1]].getCooperativa()
             << endl;
      }
      else
      {
        cout << "empleado no encontrado\n";
      }
      break;
    case 2:
      cout << setw(8) << left << "ID"
           << setw(20) << left << "CARGO"
           << setw(18) << left << "SALARIO"
           << setw(16) << left << "RAP"
           << setw(16) << left << "IHSS"
           << setw(16) << left << "ISR"
           << setw(16) << left << "IMP VECINAL"
           << "COOPERATIVA"
           << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
      for (int i = 0; i < fila; i++)
      {
        for (int j = 0; j < 1; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(20) << left << employees[i][j].getSalario()
               << setw(20) << left << employees[i][j].getRAP()
               << setw(20) << left << employees[i][j].getIHSS()
               << setw(20) << left << employees[i][j].getISR()
               << setw(20) << left << employees[i][j].getIV()
               << setw(20) << left << employees[i][j].getCooperativa()
               << endl;
        }
      }
      break;
    case 3:
      system("cls");
      break;
    case 4:
      state = false;
      break;
    default:
      cout << "Ingres una opcion valida\n";
    }
  } while (state);
}

void hacerAumentos()
{
  int id;
  float aumento;

  cout << "ingrese el id del empleado: ";
  cin >> id;

  if (findEmp(id))
  {
    cout << "ingrese la cantidad del aumento: ";
    cin >> aumento;
    employees[arr[0]][arr[1]].setAumento(aumento);
    cout << "aumento realizado\n";
  }
  else
  {
    cout << "empleado no encontrado\n";
  }
}

void menuSalarios()
{
  bool state = true;
  int opcion;
  do
  {
    cout << "MENU SALARIOS\n";
    cout << "1. mostrar salario individual / 2. mostrar salarios de empleados / 3. limpiar pantalla / 4. volver al menu principal\n";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;

      if (findEmp(id))
      {
        cout << setw(8) << left << "ID"
             << setw(20) << left << "CARGO"
             << setw(20) << left << "SALARIO"
             << "QUINCENA" << endl;
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(20) << left << employees[arr[0]][arr[1]].getSalario()
             << employees[arr[0]][arr[1]].getQuincena()
             << endl;
      }
      else
      {
        cout << "empleado no encontrado\n";
      }
      break;
    case 2:
      cout << setw(8) << left << "ID"
           << setw(20) << left << "CARGO"
           << setw(20) << left << "SALARIO"
           << "QUINCENA"
           << endl;
      for (int i = 0; i < fila; i++)
      {
        if (i < 2)
        {
          for (int j = 0; j < columna - 4; j++)
          {
            cout << setw(8) << left << employees[i][j].getId()
                 << setw(20) << left << employees[i][j].getCargo()
                 << setw(20) << left << employees[i][j].getSalario()
                 << employees[i][j].getQuincena() << endl;
          }
        }
        else
        {
          for (int j = 0; j < columna; j++)
          {
            cout << setw(8) << left << employees[i][j].getId()
                 << setw(20) << left << employees[i][j].getCargo()
                 << setw(20) << left << employees[i][j].getSalario()
                 << employees[i][j].getQuincena() << endl;
          }
        }
      }

      break;
    case 3:
      system("cls");
      break;
    case 4:
      state = false;
      break;
    default:
      cout << "ingrese una opcion valida\n";
    }
  } while (state);
}

void hacerBono()
{
  srand(time(NULL));
  float bono;
  int rdm1, rdm2;
  cout << "Ingrese la cantidad del bono: ";
  cin >> bono;
  rdm1 = (rand() % 4) + 2;
  rdm2 = rand() % 8;
  employees[rdm1][rdm2].setBono(bono);
  cout << "\nel empleado no. " << employees[rdm1][rdm2].getId() << " es el ganador del bono\n";
  cout << "Su quincena actual es de " << employees[rdm1][rdm2].getQuincena() + employees[rdm1][rdm2].getBono() << " Lempiras\n";
}

bool findEmp(int id)
{
  bool state = false;
  arr[0] = 0, arr[1] = 0;
  for (int i = 0; i < fila; i++)
  {
    for (int j = 0; j < columna; j++)
      if (id == employees[i][j].getId)
      {
        arr[0] = i, arr[1] = j;
        state = true;
      }
  }
  return state;
}