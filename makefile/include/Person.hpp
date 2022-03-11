#ifndef PERSON_HPP
#define PERSON_HPP

#include <utility>

class Person{
/*
  Atributos
  ----------
  Int id: ID do indivíduo. Parâmetro de desempate entre dois indivíduos de mesma idade.
  
  Int age: Idade do indivíduo. Geralmente é utilizada como critério de ordenação no programa.
  
  Pair<int,int> position: Posição de um indivíduo na matriz, sendo o primeiro int a linha e o segundo a coluna. 

  List<Station*> station_list: Contém referência a todos os objetos dos postos de vacinação em ordem de preferência.

  Métodos
  ----------
  Construtores, setters e getters. Métodos manipuladores de lista.
*/
  public:

    Person(int id, int age, int lin, int col): _id(id), _age(age), _position(lin,col){}; 
    Person(): _id(0), _age(0), _position(0,0){};

    int getId() const { return this->_id;}
    void setId(int new_id){ this->_id = new_id; }
    
    int getAge() const { return this->_age;}
    void setAge(int new_age){ this->_age = new_age; }

    std::pair<int,int> getPosition() const { return this->_position; }
    void setPosition(int line, int col){ this->_position.first = line; this->_position.second = col;}

    bool getIsAllocated() const {return this->_is_allocated;}
    void setIsAllocated(bool status){ this->_is_allocated = status; }

  private:

    int _id;
    
    int _age;

    std::pair<int,int> _position;

    bool _is_allocated = false;
};


#endif