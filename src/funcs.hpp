#ifndef _proj_h_
#define _proj_h_
#include <sstream>

using namespace std;

typedef struct _usuario_{
  string nome;
  string senha;
}usuario;

int entrada();
void CadastraUsuario(usuario *novo);
void cadastraExe_1(int cont);
void cadastraExe_2(int cont_2);
int ProcurarUsuario(string usuario_1, string senha_1);
int converter_3(string line1);
string converter_4(int feito);
void RecomendaFacil(string usuario_1);
int converter_5(string line1);
string converter_6(int feito);
void RecomendaDificil(string usuario_1);
string converter(int cont);
string converter_2(int cont_2);

#endif