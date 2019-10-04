#include "funcs.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main() {
  string usuario_1;
  string senha_1;
  string verifica = "1", verifica_2 = "1";
  string line;
  int esc = 0, proc;
  int esc_2 = 0;
  int testa = 0;
  int cont = 1, cont_2 = 1, menu = 0;
  usuario *novo = new usuario[10];

  esc = entrada();

//***************** SWITCH PARA OP��ES DO USUARIO**********
  while (menu<6) {
    switch (esc) {
  //*****************CHAMA A FUN��O CADASTRO DE USUARIOS****************
      case 1:
        cout << "Crie um nome de usuario: ";
        cin.ignore();
        getline(cin, novo->nome);
        cout << "Crie uma senha: ";
        getline(cin, novo->senha);
        CadastraUsuario(novo);
      break;
  //********************CHAMA AS FUN��ES DE CADASTRO DE QUEST�ES************
      case 2:
        cout << "NIVEL FACIL (PRESS 1)" << endl;
        cout << "NIVEL DIFICIL (PRESS 2)" << endl;
        cout << endl;
        cout << "Dificuldade do exercicio: ";
        cin >> esc_2;
        cout << endl;
        if (esc_2==1) {
          ofstream lista1;
          lista1.open("exercicio_1.txt", ios::out|ios::app);
          lista1.close();
          ifstream lista;
          lista.open("exercicio_1.txt");
          if (lista.is_open()) {
            while (getline(lista, line)) {
              proc = line.find(verifica);
              if (proc!=-1) {
                cont++;
                verifica = converter(cont);// ENUMERA��O DAS QUEST�ES FACEIS
              // cout << "chamou" << endl;
              }
            }
            cadastraExe_1(cont); // ENVIA A PROX. SEQUENCIA DA QUEST�O
          }
          lista.close();
        }
        else if (esc_2==2) {
          ofstream lista1;
          lista1.open("exercicio_2.txt", ios::out|ios::app);
          lista1.close();
          ifstream lista;
          lista.open("exercicio_2.txt");
          if (lista.is_open()) {
            while (getline(lista, line)) {
              proc = line.find(verifica_2);
              if (proc!=-1) {
                cont_2++;
                verifica_2 = converter_2(cont_2); // ENUMERA��O DAS QUEST�ES DIFICEIS
              // cout << "chamou" << endl;
              }
            }
            cadastraExe_2(cont_2); // ENVIA A PROX. SEQUENCIA DA QUEST�O
          }
          lista.close();
        }
      break;
  //***********************LOGIN DO USUARIO P/ RECOMENDAR QUEST�ES*******
      case 3:
        while (testa!=1) {
          cout << "Informe nome de usuario: ";
          cin >> usuario_1;
          cout << "Informe a senha: ";
          cin >> senha_1;
          testa = ProcurarUsuario(usuario_1, senha_1);
          if (testa==2) {
            cout << "Senha incorreta, tente novamente!" << endl;
          }
          else if (testa==3) {
            cout << "Usuario n�o encontrado, tente novamente!" << endl;
          }
        }
        if (testa==1) {
          cout << "ENTROU" << endl;
          cout << "Qual tipo de exercicio voce deseja praticar: Facil(press 1) ou Dificil(press 2)" << endl;
          cin >> esc;
          if (esc==1) {
            cont = 0;
            ofstream lista1;
            lista1.open("historico_1.txt", ios::out|ios::app);
            lista1.close();
            ifstream lista;
            lista.open("historico_1.txt"); //*******VERIFICA SE ELE JA FEZ QUEST�O ANTES
            if (lista.is_open()) {
              while (getline(lista, line)) {
                proc = line.find(usuario_1);
                if (proc!=-1) {
                  cont = 1;
                  RecomendaFacil(usuario_1);
                }
              }
              if (cont==0) {
                lista.close();
                ofstream lista;
                lista.open("historico_1.txt", ios::out|ios::app); // SALVA OS DADOS PARA N�O REPETIR QUEST�O
                //lista << endl;
                lista << "feitos por: " << usuario_1 << endl;
                lista << "0" << endl;
                lista << "Respondeu";
                lista.close();
                RecomendaFacil(usuario_1);
              }
            }
            lista.close();
          }
          else if (esc==2) {
            cont = 0;
            ofstream lista1;
            lista1.open("historico_2.txt", ios::out|ios::app);
            lista1.close();
            ifstream lista;
            lista.open("historico_2.txt"); // VERIFICA SE ELE JA FEZ QUEST�O ANTES
            if (lista.is_open()) {
              while (getline(lista, line)) {
                proc = line.find(usuario_1);
                if (proc!=-1) {
                  cont = 1;
                  RecomendaDificil(usuario_1);
                }
              }
              if (cont==0) {
                lista.close();
                ofstream lista;
                lista.open("historico_2.txt", ios::out|ios::app); // SALVA OS DADOS P/ N�O REPETIR QUEST�O
                //lista << endl;
                lista << "feitos por: " << usuario_1 << endl;
                lista << "0" << endl;
                lista << "Respondeu";
                lista.close();
                RecomendaDificil(usuario_1);
              }
            }
            lista.close();
          }
        }
      break;
    }
    cout << endl;
    cout << "Mais alguma coisa? (siga as instru��es iniciais)" << endl;
    cout << "Caso queira sair! (press 5)" << endl;
    cin >> esc;
    cout << endl;
    if (esc==5) {
      break;
    }
  }
}
