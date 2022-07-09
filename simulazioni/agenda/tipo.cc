#include "tipo.h"

#include <iostream>
#include <cstring>

bool compare(tipo_inf x, tipo_inf y) {
  if((strcmp(x.data, y.data) == 0) && (strcmp(x.ora_i, y.ora_i) == 0)){
    return true;
  }

  return false;
}

void copy(tipo_inf &dst, tipo_inf src) {
  dst = src;
}

void print(tipo_inf x) {
  using namespace std;
  cout
    << x.data[4] << x.data[5] << "-" << x.data[2] << x.data[3] << "-" << x.data[0] << x.data[1] << "  "  // gg-mm-aa
    << x.ora_i[0] << x.ora_i[1] << ":" << x.ora_i[2] << x.ora_i[3] << " "  // hh:mm inizio
    << x.ora_f[0] << x.ora_f[1] << ":" << x.ora_f[2] << x.ora_f[3] << " "  // hh:mm fine
     << " " << x.descr<<endl;
}