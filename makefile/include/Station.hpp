#ifndef STATION_HPP
#define STATION_HPP

#include <utility>
#include <list>
#include <iostream>

#include "Person.hpp"

class Station{
/*
  Atributos
  ----------
  int id: Número identificador do posto.
  
  unsigned int capacity: Parâmetro que identifica o número máximo de posições que a lista de pessoas terá.
  
  Pair<int,int> position: Armazena a posição do posto na matriz. O primeiro int representa a linha,
                          e o segundo int representa a coluna.
  
  List<Person> person_list: Lista que armazena ponteiros responsáveis por referenciar os objetos das pessoas
                            que serão atreladas/vacinadas posto.
  Métodos
  ----------
  Construtores, setters e getters.

  bool isListFull: Checa se a lista está cheia, i.e, o número de pessoas alocadas é igual à capacidade.
  void printPersons: Imprime os id's das pessoas em uma linha.
*/

  public:

    Station(): _id(0), _capacity(0), _position(0,0){};
    Station(int id, int capacity, int lin, int col): _id(id), _capacity(capacity), _position(lin,col){};

    void setId(int id){ this->_id = id;}
    int getId() const { return this->_id;}

    void setCapacity(int capacity){ this->_capacity = capacity;}
    int getCapacity() const { return this->_capacity;}

    std::pair<int,int> getPosition() const { return this->_position;}
    void setPosition(int li, int co){ this->_position.first = li; this->_position.second = co;}

    void allocPerson(Person* reference){if(this->isListFull() == false){ _person_list.push_back(reference);}}
    void removePerson(Person* reference){ this->_person_list.remove(reference);}
    void clearPersonList(){ this->_person_list.clear();}
    void printPersons() const { for(Person* i : _person_list){ std::cout << i->getId() << " ";} std::cout << std::endl;}
    
    bool isListEmpty() const { return (this->_person_list.empty()); }
    bool isListFull() const { return (this->_person_list.size() >= this->_capacity); }

  private:
    
    int _id;

    unsigned int _capacity;

    std::pair<int,int> _position;

    std::list<Person*> _person_list;

};



#endif