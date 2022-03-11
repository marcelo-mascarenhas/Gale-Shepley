#ifndef AUXFUNC_HPP
#define AUXFUNC_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <cmath>
#include <algorithm>

#include "Person.hpp"
#include "Station.hpp"

class Auxiliar{
/*Classe contém funções auxiliares que auxiliam na execução do programa

  Métodos
  --------
  void readInput :  Lê o arquivo de entrada, criando os objetos, preenchendo os atributos, e
                    alocando as estações e as pessoas nos seus respectivos vetores.
  
void allocPersonsInPost:  Função aloca cada pessoa no respectivo posto que será vacinado.
  
  void orderStationList: Ordena os postos em ordem de preferência de cada indivíduo.
*/    
  public:
    void readInput(std::vector<Person*> *people, std::vector<Station*> *vacination_posts);
    void allocPersonsInPosts(std::vector<Person*> &people, std::vector<Station*> &vacination_posts);
    void orderStationList(Person* p, std::vector<Station*> &station_list);

};

#endif
