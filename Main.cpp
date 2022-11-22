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
  string nombre;
  string cargo;
  float salario;
  float bono;

public:
  empleado(int _id = 0, string _nombre = "", string _cargo = "", float _salario = 0.0, float _bono = 0.0)
  {
    id = _id;
    nombre = _nombre;
    cargo = _cargo;
    salario = _salario;
    bono = _bono;
  }
  void setEmpleado(int _id = 0, string _nombre = "", string _cargo = "", float _salario = 0.0, float _bono = 0.0)
  {
    id = _id;
    nombre = _nombre;
    cargo = _cargo;
    salario = _salario;
    bono = _bono;
  }
  void setSalario(float _salario) { salario = _salario; }
  void setBono(float _bono) { bono = _bono; }
  void setAumento(float aumento) { setSalario(getSalario() + aumento); }
  int getId() { return id; }
  string getNombre() { return nombre; }
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
    if (getSalario() >= 5000 && getSalario() < 10000)
      return (int(getSalario()) % 10000 / 1000) * 2;

    if (getSalario() >= 10000 && getSalario() <= 20000)
      return (int(getSalario()) % 100000 / 1000) * 2.5;

    if (getSalario() > 20000 && getSalario() <= 30000)
      return (int(getSalario()) % 100000 / 1000) * 3;

    if (getSalario() > 30000 && getSalario() <= 50000)
      return (int(getSalario()) % 100000 / 1000) * 3.5;

    if (getSalario() > 50000 && getSalario() <= 75000)
      return (int(getSalario()) % 100000 / 1000) * 4;
  }
};

void menuPrincpipal();
void menuPlanilla();
void menuDeducciones();
void hacerAumentos();
void menuSalarios();
void hacerBono();
bool findEmp(int id);
bool validId(int id);
int validOp(int opcion);

string names[40];
int arr[2];
const int fila = 5, columna = 8;
empleado employees[fila][columna];

int main()
{
  srand(time(NULL));
  int n = 0;
  const string rol[5] = {"Supervisor", "Operario", "Vendedor", "Mantenimiento", "aseo"};
  const float salary[5] = {14000, 13050.68, 11419.35, 10875.57, 10875.57};
  string names[40] = {
      "Hugo", "Martin", "Lucas", "Mateo", "Leo", "Daniel", "Alejandro", "Pablo", "Manuel", "Alvaro",
      "Adrian", "David", "Mario", "Enzo", "Diego", "Marcos", "Izan", "Javier", "Marco", "Alex",
      "Bruno", "Oliver", "Miguel", "Thiago", "Antonio", "Marc", "Carlos", "angel", "Juan", "Gonzalo",
      "Gael", "Sergio", "Nicolas", "Dylan", "Gabriel", "Jorge", "Jose", "Adam", "Liam", "Eric"};
  // GERENTES FILA 0
  for (int i = 0; i < columna - 4; i++)
  {
    employees[0][i].setEmpleado(i + 1, names[n], "Gerente", float((rand() % 50000) + 30000), 0.0);
    n++;
  }
  // SUPERVISORES FILA 0
  for (int i = 4; i < columna; i++)
  {
    employees[0][i].setEmpleado(i + 1, names[n], rol[0], float((rand() % 25000) + salary[0]), 0.0);
    n++;
  }

  // INDEX 9 - 40 / FILA 1 - 4
  for (int i = 1; i < fila; i++)
  {
    for (int j = 0; j < columna; j++)
    {
      static int index = 9;
      employees[i][j].setEmpleado(index, names[n], rol[i], salary[i], 0.0);
      index++;
      n++;
    }
  }

  menuPrincpipal();

  return 0;
}

void menuPrincpipal()
{
  bool state = true;
  int opcion;
  do
  {
    system("cls");
    cout << "MENU PRINCIPAL\n";
    cout << "1. ver planilla / 2. ver deducciones  / 3. realizar aumento / 4. ver salario sin deducciones / 5. bonos aleatorios / 6. salir\n";
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;

    switch (validOp(opcion))
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
      state = false;
      break;
    default:
      cout << "ERROR: valor invalido\n";
      system("pause>nul");
      break;
    }
  } while (state);
}

void menuPlanilla()
{
  bool state = true;
  int opcion;
  do
  {
    system("cls");
    cout << "MENU DE PLANILLAS\n";
    cout << "1. mostrar planilla individual / 2. mostrar planilla general / 3. regresar al menu principal\n";
    cout << "ingrese el numero de la opcion: ";
    cin >> opcion;
    switch (validOp(opcion))
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;
      if (findEmp(id) || validId(id)) // si el empleado existe y si el id es valido
      {                               // titulos
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << "ID"
             << setw(18) << left << "NOMBRE"
             << setw(20) << left << "CARGO"
             << setw(18) << left << "SALARIO"
             << setw(16) << left << "QUINCENA"
             << setw(18) << left << "DEDUCCIONES"
             << setw(16) << left << "BONO"
             << setw(16) << left << "TOTAL"
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        // valores de un empleado
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(18) << left << employees[arr[0]][arr[1]].getNombre()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(18) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getSalario()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getQuincena()
             << setw(18) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getDeducciones()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getBono()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getQuincenaDeducida() + employees[arr[0]][arr[1]].getBono()
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        system("pause>nul");
      }
      else
      {
        cout << "empleado no encontrado\n";
      }
      break;
    case 2: // titulos
      cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << setw(8) << left << "ID"
           << setw(18) << left << "NOMBRE"
           << setw(20) << left << "CARGO"
           << setw(18) << left << "SALARIO"
           << setw(16) << left << "QUINCENA"
           << setw(18) << left << "DEDUCCIONES"
           << setw(16) << left << "BONO"
           << setw(16) << left << "TOTAL"
           << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
      for (int i = 0; i < fila; i++) // valores de todos los empleados
      {
        for (int j = 0; j < columna; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(18) << left << employees[i][j].getNombre()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(18) << left << fixed << setprecision(2) << employees[i][j].getSalario()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getQuincena()
               << setw(18) << left << fixed << setprecision(2) << employees[i][j].getDeducciones()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getBono()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getQuincenaDeducida() + employees[i][j].getBono()
               << endl;
          cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        }
      }
      system("pause>nul");
      break;
    case 3:
      state = false;
      break;
    default:
      cout << "ERROR: valor invalido\n";
      system("pause>nul");
    }
  } while (state);
}

void menuDeducciones()
{
  bool state = true;
  int opcion;
  do
  {
    system("cls");
    cout << "MENU DEDUCCIONES\n";
    cout << "1. mostrar deducciones individuales / 2. mostrar deducciones generales / 3. volver al menu principal\n";
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;
    switch (validOp(opcion))
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;

      if (findEmp(id) || validId(id)) // si el empleado existe y si el id es valido
      {                               // titulos
        cout << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << "ID"
             << setw(18) << left << "NOMBRE"
             << setw(20) << left << "CARGO"
             << setw(18) << left << "SALARIO"
             << setw(16) << left << "RAP"
             << setw(16) << left << "IHSS"
             << setw(16) << left << "ISR"
             << setw(16) << left << "IV"
             << "COOPERATIVA"
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        // valores de un empleado
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(18) << left << employees[arr[0]][arr[1]].getNombre()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(18) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getSalario()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getRAP()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getIHSS()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getISR()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getIV()
             << setw(16) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getCooperativa()
             << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        system("pause>nul");
      }
      else
      {
        cout << "empleado no encontrado\n";
        system("pause>nul");
      }
      break;
    case 2:
      cout << endl; // titulos
      cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << setw(8) << left << "ID"
           << setw(18) << left << "NOMBRE"
           << setw(20) << left << "CARGO"
           << setw(18) << left << "SALARIO"
           << setw(16) << left << "RAP"
           << setw(16) << left << "IHSS"
           << setw(16) << left << "ISR"
           << setw(16) << left << "IV"
           << "COOPERATIVA"
           << endl;
      cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
      for (int i = 0; i < fila; i++) // valores de todos los empleados
      {
        for (int j = 0; j < columna; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(18) << left << employees[i][j].getNombre()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(18) << left << fixed << setprecision(2) << employees[i][j].getSalario()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getRAP()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getIHSS()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getISR()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getIV()
               << setw(16) << left << fixed << setprecision(2) << employees[i][j].getCooperativa()
               << endl;
          cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
      }
      system("pause>nul");
      break;
    case 3:
      state = false;
      break;
    default:
      cout << "ERROR: valor invalido\n";
      system("pause>nul");
    }
  } while (state);
}

void hacerAumentos()
{

  int id;
  float aumento;

  cout << "ingrese el id del empleado: ";
  cin >> id;

  if (findEmp(id) || validId(id))
  { // si el empleado existe y el id es valido
    cout << "ingrese la cantidad del aumento: ";
    cin >> aumento;
    while (cin.fail() || aumento < 0)
    { // valida un numero positivo

      cout << "\nIngrese un valor valido\n";
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Ingrese la cantidad del aumento: ";
      cin >> aumento;
    }

    employees[arr[0]][arr[1]].setAumento(aumento);
    cout << "\nel salario actual de " << employees[arr[0]][arr[1]].getNombre() << " es de: " << employees[arr[0]][arr[1]].getSalario() << endl;
    system("pause>nul");
  }
  else
  {
    cout << "empleado no encontrado\n";
    system("pause>nul");
  }
}

void menuSalarios()
{
  bool state = true;
  int opcion;
  do
  {
    system("cls");
    cout << "MENU SALARIOS\n";
    cout << "1. mostrar salario individual / 2. mostrar salarios de empleados / 3. volver al menu principal\n";
    cout << "Ingrese el numero de la opcion: ";
    cin >> opcion;
    switch (validOp(opcion))
    {
    case 1:
      int id;
      cout << "ingrese el id del empleado: ";
      cin >> id;
      if (findEmp(id) || validId(id)) // si el empleado existe y wl id es valido
      {
        cout << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << setw(8) << left << "ID"
             << setw(18) << left << "NOMBRE"
             << setw(20) << left << "CARGO"
             << setw(20) << left << "SALARIO"
             << "QUINCENA" << endl;
        cout << setw(8) << left << employees[arr[0]][arr[1]].getId()
             << setw(18) << left << employees[arr[0]][arr[1]].getNombre()
             << setw(20) << left << employees[arr[0]][arr[1]].getCargo()
             << setw(20) << left << fixed << setprecision(2) << employees[arr[0]][arr[1]].getSalario()
             << fixed << setprecision(2) << employees[arr[0]][arr[1]].getQuincena()
             << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << endl;
        system("pause>nul");
      }
      else // si el empleado no existe
      {
        cout << "empleado no encontrado\n";
        system("pause>nul");
      }
      break;
    case 2:
      // titulos:
      cout << endl;
      cout << "---------------------------------------------------------------------------" << endl;
      cout << setw(8) << left << "ID"
           << setw(18) << left << "NOMBRE"
           << setw(20) << left << "CARGO"
           << setw(20) << left << "SALARIO"
           << "QUINCENA"
           << endl;
      cout << "---------------------------------------------------------------------------" << endl;
      // imprime valores de gerentes
      for (int i = 0; i < 4; i++)
      {
        cout << setw(8) << left << employees[0][i].getId()
             << setw(18) << left << employees[0][i].getNombre()
             << setw(20) << left << employees[0][i].getCargo()
             << setw(20) << left << fixed << setprecision(2) << employees[0][i].getSalario()
             << fixed << setprecision(2) << employees[0][i].getQuincena() << endl;
        cout << "---------------------------------------------------------------------------" << endl;
      }
      // imprime valores de supervisores
      for (int i = 4; i <= 8; i++)
      {
        cout << setw(8) << left << employees[0][i].getId()
             << setw(18) << left << employees[0][i].getNombre()
             << setw(20) << left << employees[0][i].getCargo()
             << setw(20) << left << fixed << setprecision(2) << employees[0][i].getSalario()
             << fixed << setprecision(2) << employees[0][i].getQuincena() << endl;
        cout << "---------------------------------------------------------------------------" << endl;
      }
      // imprime los valores de los demas cargos
      for (int i = 1; i < fila; i++)
        for (int j = 0; j < columna; j++)
        {
          cout << setw(8) << left << employees[i][j].getId()
               << setw(18) << left << employees[i][j].getNombre()
               << setw(20) << left << employees[i][j].getCargo()
               << setw(20) << left << fixed << setprecision(2) << employees[i][j].getSalario()
               << fixed << setprecision(2) << employees[i][j].getQuincena() << endl;
          cout << "---------------------------------------------------------------------------" << endl;
        }
      system("pause>nul");
      break;
    case 3:
      state = false;
      break;
    default:
      cout << "ERROR: valor invalido\n";
      system("pause>nul");
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
  while (cin.fail() || bono < 0)
  { // valida si es entero o caracter
    cout << "\nIngrese un valor valido\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Ingrese la cantidad del bono: ";
    cin >> bono;
  }
  // se guarda la ubicacion aleatoria
  rdm1 = (rand() % 4) + 1;
  rdm2 = rand() % 8;
  employees[rdm1][rdm2].setBono(bono);
  cout << "\nel empleado no. " << employees[rdm1][rdm2].getId() << " " << employees[rdm1][rdm2].getNombre() << " es el ganador del bono\n";
  cout << "Su quincena actual es de " << fixed << setprecision(2) << employees[rdm1][rdm2].getQuincena() + employees[rdm1][rdm2].getBono() << " Lempiras sin deducciones\n";
  system("pause>nul");
}

bool findEmp(int id)
{ // busca si el empleado existe
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

bool validId(int id)
{ // valida si es entero o caracter
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    return false;
  }
  else
  {
    cin.clear();
    cin.ignore(256, '\n');
    return true;
  }
}

int validOp(int opcion)
{ // valida si es un entero o caracter
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
    return 0;
  }
  else
  {
    cin.clear();
    cin.ignore(256, '\n');
    return opcion;
  }
}