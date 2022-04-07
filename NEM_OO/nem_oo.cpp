#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "nem_oo.h"

int sajat::atoi(const char *p, int base) {
  
  int szam = 0;
  int len = strlen(p);
  
  for(int i = 0; i < len; i++) {
    int ertek = 0;

    if(p[i] - '0' >= base) {
      throw "QJBZPV";
    } 

    if(isdigit(p[i]) && p[i] - '0' < base) {
      ertek = p[i] - '0';
    } else {
      throw "QJBZPV";
    }
    
    szam = szam * base + ertek;
  }
  return szam;
}

char *sajat::strcat(const char *p1, const char *p2) {
  int len = strlen(p1) + strlen(p2) + 1;

  char *uj = new char[len];
  
  int i = 0;
  int j = 0;
  while(p1[i] != '\0') {
    uj[j++] = p1[i++];
  }
  i = 0;
  while(p2[i] != '\0') {
    uj[j++] = p2[i++];
  }

  uj[j] = '\0';

  return uj;
}

char *sajat::unique(char *first, char *last) {
  char *iteratorb = first;
  char *iteratorj = first+1;

  while(iteratorj != last) {
    if(*iteratorb == *iteratorj) {
      iteratorj++;
    }
    else {
      iteratorb++;
      *iteratorb = *iteratorj;
      iteratorj++;
    }
  }
  return ++iteratorb;
}