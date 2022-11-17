#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class empleado
{
private:
  int id;
  string cargo;
  float salario;
  float bono;

public:
  empleado(int _id = 0, string _cargo = "", float _salario = 0.0, float _bono = 0.0)
  {
    id = _id;
    cargo = _cargo;
    salario = _salario;
    bono = _bono;
  }
  void setEmpleado(int _id = 0, string _cargo = "", float _salario = 0.0, float _bono = 0.0)
  {
    id = _id;
    cargo = _cargo;
    salario = _salario;
    bono = _bono;
  }
  void setSalario(float _salario) { salario = _salario; }
  void setBono(float _bono) { bono = _bono; }
  void setAumento(float aumento) { setSalario(getSalario() + aumento); }
  int getId() { return id; }
  string getCargo() { return cargo; }
  float getSalario() { return salario; }
  float getQuincena() { return salario / 2; }
  float getBono() { return bono; }
  float getRAP() { return (getSalario() * 1.5) / 100; }
  float getIHSS() { return (getSalario() * 4) / 100; }
  float getISR() { return (getSalario() * 1.5) / 100; }
  float getCooperativa() { return (getSalario() * 10) / 100; }
  float getDeducciones() { return getRAP() + getIHSS() + getISR() + getCooperativa() + getIV(); }
  float getSalarioDeducido() { return getSalario() - getDeducciones(); }
  float getQuincenaDeducida() { return getSalarioDeducido() / 2; }
  float getIV()
  {
    if (getSalario() == 30000)
      return 30 * 3;
    if (getSalario() == 14000)
      return 14 * 3;
    if (getSalario() > 13000.0 && getSalario() < 13999.9)
      return 13 * 3;
    if (getSalario() > 11000.0 && getSalario() < 11999.9)
      return 11 * 3;
    if (getSalario() > 10000.0 && getSalario() < 10999.9)
      return 10 * 3;
  }
};

void menuPrincpipal();
void menuPlanilla();
void menuDeducciones();
void hacerAumentos();
void menuSalarios();
void hacerBono();
bool findEmp(int id);

int arr[2];
const int fila = 5, columna = 8;
empleado employees[fila][columna];

int main()
{
  const string rol[5] = {"Supervisor", "Operario", "Vendedor", "Mantenimiento", "aseo"};
  const float salary[5] = {14000, 13050.68, 11419.35, 10875.57, 10875.57};
  // GERETNES FILA 0
  for (int i = 0; i < columna - 4; i++)
    employees[0][i].setEmpleado(i + 1, "Gerente", 30000.00, 0.0);
  // SUPERVISORES FILA 0
  for (int i = 4; i < columna; i++)
    employees[0][i].setEmpleado(i + 1, rol[0], salary[0], 0.0);

  // INDEX 9 - 40 / FILA 1 - 4
  for (int i = 1; i < fila; i++)
  {
    for (int j = 0; j < columna; j++)
    {
      static int index = 9;
      employees[i][j].setEmpleado(index, rol[i], salary[i], 0.0);
      index++;
    }
  }

  menuDeducciones();
  // menuSalarios();

  // MOSTRAR
  // for (int i = 0; i < fila; i++)
  //   for (int j = 0; j < columna; j++)
  //     cout << employees[i][j].getId() << " " << employees[i][j].getCargo() << endl;
  return 0;
}

// void menuPrincpipal()
// {
//   bool state = true;
//   int opcion;
//   do
//   {
//     cout << "MENU PRINCIPAL\n";
//     cout << "1. ver planilla / 2. ver deducciones  / 3. realizar aumento / 4. ver salario sin deducciones / 5. bonos aleatorios / 6. limpiar pantalla / 7. salir\n";
//     cout << "Ingrese el numero de la opcion: ";
//     cin >> opcion;

//     switch (opcion)
//     {
//     case 1:
//       menuPlanilla();
//       break;
//     case 2:
//       menuDeducciones();
//       break;
//     case 3:
//       hacerAumentos();
//       break;
//     case 4:
//       menuSalarios();
//       break;
//     case 5:
//       hacerBono();
//       break;
//     case 6:
//       system("cls");
//       break;
//     case 7:
//       state = false;
//       break;
//     default:
//       cout << "Ingres una opcion valida\n";
//     }
//   } while (state);
// }

// void menuPlanilla()
// {
//   bool state = true;
//   int opcion;
//   do
//   {
//     cout << "MENU DE PLANILLAS\n";
//     cout << "1. mostrar planilla individual / 2. mostrar planilla general / 3. limpiar pantalla / 4. regresar al menu principal\n";
//     cin >> opcion;
//     switch (opcion)
//     {
//     case 1:
//       int id;
//       cout << "ingrese el id del empleado: ";
//       cin >> id;

//       if (findEmp(id))
//       {
//         cout << setw(8) << left << "ID"
//              << setw(20) << left << "CARGO"
//              << setw(18) << left << "SALARIO"
//              << setw(16) << left << "QUINCENA"
//              << setw(18) << left << "DEDUCCIONES"
//              << setw(16) << left << "BONO"
//              << setw(16) << left << "TOTAL"
//              << endl;
//         cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
//         cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
//              << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
//              << setw(18) << left << employees[arr[0]][arr[1]].getSalario()
//              << setw(16) << left << employees[arr[0]][arr[1]].getQuincena()
//              << setw(28) << left << employees[arr[0]][arr[1]].getDeducciones()
//              << setw(26) << left << employees[arr[0]][arr[1]].getBono()
//              << setw(26) << left << employees[arr[0]][arr[1]].getQuincenaDeducida() + employees[arr[0]][arr[1]].getBono()
//              << endl;
//       }
//       else
//       {
//         cout << "empleado no encontrado\n";
//       }
//       break;
//     case 2:
//       cout << setw(8) << left << "ID"
//            << setw(20) << left << "CARGO"
//            << setw(18) << left << "SALARIO"
//            << setw(16) << left << "QUINCENA"
//            << setw(18) << left << "DEDUCCIONES"
//            << setw(16) << left << "BONO"
//            << setw(16) << left << "TOTAL"
//            << endl;
//       cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
//       for (int i = 0; i < fila; i++)
//       {
//         if (i < 2)
//         {
//           for (int j = 0; j < columna - 4; j++)
//           {
//             cout << setw(8) << left << employees[i][j].getId()
//                  << setw(20) << left << employees[i][j].getCargo()
//                  << setw(18) << left << employees[i][j].getSalario()
//                  << setw(16) << left << employees[i][j].getQuincena()
//                  << setw(28) << left << employees[i][j].getDeducciones()
//                  << setw(26) << left << employees[i][j].getBono()
//                  << setw(26) << left << employees[i][j].getQuincenaDeducida() + employees[i][j].getBono()
//                  << endl;
//           }
//         }
//         else
//         {
//           for (int j = 0; j < columna; j++)
//           {
//             cout << setw(8) << left << employees[i][j].getId()
//                  << setw(20) << left << employees[i][j].getCargo()
//                  << setw(18) << left << employees[i][j].getSalario()
//                  << setw(16) << left << employees[i][j].getQuincena()
//                  << setw(28) << left << employees[i][j].getDeducciones()
//                  << setw(26) << left << employees[i][j].getBono()
//                  << setw(26) << left << employees[i][j].getQuincenaDeducida() + employees[i][j].getBono()
//                  << endl;
//           }
//         }
//       }
//       break;
//     case 3:
//       system("cls");
//       break;
//     case 4:
//       state = false;
//       break;
//     default:
//       cout << "Ingres una opcion valida\n";
//     }
//   } while (state);
// }

void menuDeducciones()
{
  bool state = true;
  int opcion;
  do
  {
    cout << "1. mostrar deducciones individuales / 2. mostrar deducciones generales / 3. limpiar pantalla / 4. volver al menu principal\n";
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;

      if (findEmp(id))
      {
        cout << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << "ID"
             << setw(20) << left << "CARGO"
             << setw(18) << left << "SALARIO"
             << setw(16) << left << "RAP"
             << setw(16) << left << "IHSS"
             << setw(16) << left << "ISR"
             << setw(16) << left << "IV"
             << "COOPERATIVA"
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(18) << left << employees[arr[0]][arr[1]].getSalario()
             << setw(16) << left << employees[arr[0]][arr[1]].getRAP()
             << setw(16) << left << employees[arr[0]][arr[1]].getIHSS()
             << setw(16) << left << employees[arr[0]][arr[1]].getISR()
             << setw(16) << left << employees[arr[0]][arr[1]].getIV()
             << setw(16) << left << employees[arr[0]][arr[1]].getCooperativa()
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
      }
      else
      {
        cout << "empleado no encontrado\n";
      }
      break;
    case 2:
      cout << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << setw(8) << left << "ID"
           << setw(20) << left << "CARGO"
           << setw(18) << left << "SALARIO"
           << setw(16) << left << "RAP"
           << setw(16) << left << "IHSS"
           << setw(16) << left << "ISR"
           << setw(16) << left << "IV"
           << "COOPERATIVA"
           << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
      for (int i = 0; i < fila; i++)
      {
        for (int j = 0; j < columna; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(18) << left << employees[i][j].getSalario()
               << setw(16) << left << employees[i][j].getRAP()
               << setw(16) << left << employees[i][j].getIHSS()
               << setw(16) << left << employees[i][j].getISR()
               << setw(16) << left << employees[i][j].getIV()
               << setw(16) << left << employees[i][j].getCooperativa()
               << endl;
          cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
      cout << endl;
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
    do
    {
      cout << "ingrese la cantidad del aumento: ";
      cin >> aumento;
      if (aumento < 0)
        cout << "ingrese un valor valido\n";
    } while (aumento < 0);
    employees[arr[0]][arr[1]].setAumento(aumento);
    cout << "salario actualizado: " << employees[arr[0]][arr[1]].getSalario() << endl;
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
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;

      if (findEmp(id))
      {
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << setw(8) << left << "ID"
             << setw(20) << left << "CARGO"
             << setw(20) << left << "SALARIO"
             << "QUINCENA" << endl;
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(20) << left << employees[arr[0]][arr[1]].getSalario()
             << employees[arr[0]][arr[1]].getQuincena()
             << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
      }
      else
      {
        cout << "empleado no encontrado\n";
      }
      break;
    case 2:
      cout << endl;
      cout << "---------------------------------------------------------" << endl;
      cout << setw(8) << left << "ID"
           << setw(20) << left << "CARGO"
           << setw(20) << left << "SALARIO"
           << "QUINCENA"
           << endl;
      cout << "---------------------------------------------------------" << endl;

      for (int i = 0; i < 4; i++)
      {
        cout << setw(8) << left << employees[0][i].getId()
             << setw(20) << left << employees[0][i].getCargo()
             << setw(20) << left << employees[0][i].getSalario()
             << employees[0][i].getQuincena() << endl;
        cout << "---------------------------------------------------------" << endl;
      }

      for (int i = 4; i <= 8; i++)
      {
        cout << setw(8) << left << employees[0][i].getId()
             << setw(20) << left << employees[0][i].getCargo()
             << setw(20) << left << employees[0][i].getSalario()
             << employees[0][i].getQuincena() << endl;
        cout << "---------------------------------------------------------" << endl;
      }

      for (int i = 1; i < fila; i++)
        for (int j = 0; j < columna; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(20) << left << employees[i][j].getSalario()
               << employees[i][j].getQuincena() << endl;
          cout << "---------------------------------------------------------" << endl;
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
  do
  {
    cout << "Ingrese la cantidad del bono: ";
    cin >> bono;
    if (bono < 0)
      cout << "ingrese un valor valido\n";
  } while (bono < 0);
  rdm1 = (rand() % 4) + 1;
  rdm2 = rand() % 8;
  employees[rdm1][rdm2].setBono(bono);
  cout << "\nel empleado no. " << employees[rdm1][rdm2].getId() << " es el ganador del bono\n";
  cout << "Su quincena actual es de " << fixed << setprecision(2) << employees[rdm1][rdm2].getQuincena() + employees[rdm1][rdm2].getBono() << " Lempiras sin deducciones\n";
}

bool findEmp(int id)
{
  bool state = false;
  arr[0] = 0, arr[1] = 0;
  for (int i = 0; i < fila; i++)
    for (int j = 0; j < columna; j++)
      if (id == employees[i][j].getId())
      {
        arr[0] = i, arr[1] = j;
        state = true;
      }
  return state;
}