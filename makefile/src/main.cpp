#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <chrono>

#include "Auxiliar.hpp"


int main(int argc, char* argv[]){

  std::vector<Person*> people; 
  
  std::vector<Station*> vacination_stations;

  // std::fstream my_file; my_file.open(argv[1]);
  
  // if(my_file.is_open() == false){
  //   std::cout << "O arquivo de entrada não abriu. Favor tentar novamente. " << std::endl;
  //   return 0;
  // }

  Auxiliar o1;
  
  o1.readInput( &people, &vacination_stations);
  std::cout << "Saiu";
  
  // my_file.close();

  //Ordenação estável, preserva as posições relativas dos ID's e ordena por idade.

  std::stable_sort(people.begin(), people.end(),
  [] (const Person *a, const Person *b) { return a->getAge() > b->getAge(); });
  
  
  o1.allocPersonsInPosts(people, vacination_stations);

  for(unsigned int i = 0; i < vacination_stations.size(); i++){
    if(vacination_stations[i]->isListEmpty() == false){
      std::cout << vacination_stations[i]->getId() << std::endl;
      vacination_stations[i]->printPersons();
    }
    //Deletando no processo.
    delete(vacination_stations[i]);
  }
  for(Person* item : people){
    delete(item);
  }




}