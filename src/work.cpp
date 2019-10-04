#include "funcs.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int entrada() {
  int esc = 0;

  cout << "******************************************" << endl;
  cout << "                 BEM VINDO                " << endl;
  cout << "******************************************" << endl;
  cout << endl;

  cout << "CADASTRAR USUARIO (press 1)" << endl;
  cout << "CADASTRAR EXERCICIOS (press 2)" << endl;
  cout << "PRATICAR (press 3)" << endl;
  cout << endl;

  cout << "Informe a ação desejada: ";
  cin >> esc;
  cout << endl;

  return esc;
}
// ************************* CADASTRO DE NOVOS USUARIOS***************
void CadastraUsuario(usuario *novo) {
  ofstream conta;
  conta.open("usuario.txt", ios::out|ios::app);
  conta << novo->nome << endl;
  conta << novo->senha << endl;
  conta.close();
}
//******************FUNÇÃO PARA RECEBER EXERCICIOS FACEIS**********
void cadastraExe_1(int cont) {
  string titulo;
  string categ;
  string exe;

  ofstream lista1;
  lista1.open("exercicio_1.txt", ios::out|ios::app);
  lista1 << cont << endl;
  cout << "Informe o titulo do exercicio: ";
  cin.ignore();
  getline(cin, titulo);
  lista1 << "Titulo: " << titulo << endl;
  cout << "Informe a categoria: ";
  getline(cin, categ);
  lista1 << "Categoria: " << categ << endl;
  cout << "Descreva o exercicio" << endl;
  cin.ignore();
  getline(cin, exe);
  lista1 << exe << endl;
  lista1 << "end" << endl;
  lista1.close();
}
//******************FUNÇÃO PARA RECEBER EXERCICIOS DIFICEIS***********
void cadastraExe_2(int cont_2) {
  string titulo;
  string categ;
  string exe;

  ofstream lista1;
  lista1.open("exercicio_2.txt", ios::out|ios::app);
  lista1 << cont_2 << endl;
  cout << "Informe o titulo do exercicio: ";
  cin.ignore();
  getline(cin, titulo);
  lista1 << "Titulo: " << titulo << endl;
  cout << "Informe a categoria: ";
  getline(cin, categ);
  lista1 << "Categoria: " << categ << endl;
  cout << "Descreva o exercicio" << endl;
  cin.ignore();
  getline(cin, exe);
  lista1 << exe << endl;
  lista1 << "end" << endl;
  lista1.close();
}
//***********************FUNÇÃO PARA PROCURAR USUARIOS JA CADASTRADOS************
int ProcurarUsuario(string usuario_1, string senha_1) {
  string line;
  int proc, cont = 0, cont_2 = 0;

  ifstream lista;
  lista.open("usuario.txt");
  if (lista.is_open()) {
    while (getline(lista, line)) {
      if (usuario_1==line) {
        cont_2 = 1;
        while (getline(lista, line)) {
          proc = line.find(senha_1);
          if (proc!=-1) {
            cout << "chamou" << endl;
            cont = 1;
            return 1;
          }
        }
        if (cont==0) {
          return 2;
        }
      }
    }
    if (cont_2==0) {
      return 3;
    }
  }
  lista.close();
}
//*****************FUNÇÕES CONVERTER_NUMBER E CONVERTER_STRINGS PARA FACILITAR NA BUSCA DE QUESTOES JA CADASTRADAS E QUE SERA CADASTRADAS NA ENUMARAÇÃO**********************
int converter_3(string line1) {
  istringstream oss(line1);
  int n;
  oss >> n;
  return n;
}

string converter_4(int feito) {
  ostringstream oss;
  oss << feito;
  return oss.str();
}
//***********************FUNÇÃO PARA RECOMENDAR QUESTÕES FACEIS************
void RecomendaFacil(string usuario_1) {
  string line, line1;
  int proc, proc_1, feito = 0;
  int cont = 0, pause;
//**************** ALGORITMO PARA REVER QUESTÕES JA FEITAS PELO USUARIO****************
  ifstream lista;
  lista.open("historico_1.txt");
  if (lista.is_open()) {
    while (getline(lista, line)) {
      proc = line.find(usuario_1);
      if (proc!=-1) {
        cont = cont + 1;
        line = " ";
      }
      if (cont>=1) {
        proc_1 = line.find("Respondeu");
        //proc1 = line.find();
        if (proc_1!=-1) {
          break;
        }
        else {
          line1 = line;
          //cont1++;
          cout << line << endl;
        }
      }
    }
   // cout << line1 << endl;
    feito = converter_3(line1);
    feito = feito + 1;
  //  cout << feito << endl;
    line1 = converter_4(feito);
  //  cout << feito << endl;
  }
  lista.close();
//***********************AGORA RECOMENDA QUESTÕES NÃO FEITAS************
  //cont1 = 0;
  cont = 0;
  ifstream lista1;
  lista1.open("exercicio_1.txt");
  if (lista1.is_open()) {
    while (getline(lista1, line)) {
      if (line==line1) {
        cont++;
      }
      if (cont>0) {
        if (line!="end") {
          cout << line << endl;
        }
        else {
          feito++;
          cout << endl;
          cout << endl;
          cout << "Partir para proxima: (press 1, ou 2 para sair!)";
          cin >> pause;
          if (pause==2) {
            break;
          }
        }
      }
    }
  }
  lista1.close();
 // cout << feito << endl;
//*****************MARCA QUESTÕES FEITAS P/ NÃO REPETIR********************
  feito = feito - 1;
  fstream lista2;
  lista2.open("historico_1.txt");
  if (lista2.is_open()) {
    while (getline(lista2, line)) {
      proc = line.find(usuario_1);
      if (proc!=-1) {
        //lista2 << endl;
        lista2 << feito;
        //lista2 << endl;
      }
    }
  }
  lista2.close();
}

int converter_5(string line1) {
  istringstream oss(line1);
  int n;
  oss >> n;
  return n;
}

string converter_6(int feito) {
  ostringstream oss;
  oss << feito;
  return oss.str();
}
//***********************FUNÇÃO PARA RECOMENDAR QUESTÕES DIFICEIS************
void RecomendaDificil(string usuario_1) {
  string line, line1;
  int proc, proc_1, feito = 0;
  int cont = 0, pause;
//**************** ALGORITMO PARA REVER QUESTÕES JA FEITAS PELO USUARIO****************
  ifstream lista;
  lista.open("historico_2.txt");
  if (lista.is_open()) {
    while (getline(lista, line)) {
      proc = line.find(usuario_1);
      if (proc!=-1) {
        cont = cont + 1;
        line = " ";
      }
      if (cont>=1) {
        proc_1 = line.find("Respondeu");
        //proc1 = line.find();
        if (proc_1!=-1) {
          break;
        }
        else {
          line1 = line;
          //cont1++;
          cout << line << endl;
        }
      }
    }
   // cout << line1 << endl;
    feito = converter_5(line1);
    feito = feito + 1;
  //  cout << feito << endl;
    line1 = converter_6(feito);
  //  cout << feito << endl;
  }
  lista.close();
//***********************AGORA RECOMENDA QUESTÕES NÃO FEITAS************
  //cont1 = 0;
  cont = 0;
  ifstream lista1;
  lista1.open("exercicio_2.txt");
  if (lista1.is_open()) {
    while (getline(lista1, line)) {
      if (line==line1) {
        cont++;
      }
      if (cont>0) {
        if (line!="end") {
          cout << line << endl;
        }
        else {
          feito++;
          cout << endl;
          cout << endl;
          cout << "Partir para proxima: (press 1, ou 2 para sair!)";
          cin >> pause;
          if (pause==2) {
            break;
          }
        }
      }
    }
  }
  lista1.close();
 // cout << feito << endl;
//*****************MARCA QUESTÕES FEITAS P/ NÃO REPETIR********************
  feito = feito - 1;
  fstream lista2;
  lista2.open("historico_2.txt");
  if (lista2.is_open()) {
    while (getline(lista2, line)) {
      proc = line.find(usuario_1);
      if (proc!=-1) {
        //lista2 << endl;
        lista2 << feito;
      }
    }
  }
  lista2.close();
}

string converter(int cont) {
  ostringstream oss;
  oss << cont;
  return oss.str();
}

string converter_2(int cont_2) {
  ostringstream oss;
  oss << cont_2;
  return oss.str();
}
