#include "Auxiliar.hpp"


void Auxiliar::readInput(std::vector<Person*> *people, std::vector<Station*> *vacination_posts){

  std::string lines_aux;

  unsigned int id = 0, number_of_objects, count = 0;
  
  int cap_age, lin, col;
  
  /*Executa 2 vezes, pois existem dois blocos - de pessoas e postos.*/

  while(count < 2){
    std::getline(std::cin, lines_aux);

    std::stringstream sstream(lines_aux); 
    
    sstream >> number_of_objects;

    while(id < number_of_objects){
      std::getline(std::cin,lines_aux);
      std::stringstream attributes(lines_aux);

      attributes >> cap_age >> lin >> col;
      
      //Os postos são lidos na primeira iteração, por isso a disposição abaixo.

      if(count == 0){
        Station* p1 = new Station(id, cap_age, lin, col);
        vacination_posts->push_back(p1);
      }

      else if(count == 1){
        Person* p1 = new Person(id, cap_age, lin, col);
        people->push_back(p1);
      }
      id++;
    }
  
    count++;
    id = 0;
  }

}
void Auxiliar::orderStationList(Person* p, std::vector<Station*> &station_list){

  std::stable_sort(station_list.begin(), station_list.end(), [p]
    (Station* r, Station* l){
      float distance1, distance2, pl1, pl2;
      
      pl1 = r->getPosition().first - p->getPosition().first;
      
      pl2 = r->getPosition().second- p->getPosition().second;
      
      distance1 = sqrt(pow(pl1,2) + pow(pl2,2));

      pl1 = l->getPosition().first - p->getPosition().first;

      pl2 = p->getPosition().second - l->getPosition().second;
      
      distance2 = sqrt(pow(pl1,2) + pow(pl2,2));
      
      return distance1 < distance2;
      });

}

void Auxiliar::allocPersonsInPosts(std::vector<Person*> &people, std::vector<Station*> &vacination_post){
  
  std::vector<Station*> aux_list;

  for(int i = 0; i < people.size(); i++){
    
    for(int j = 0; j < vacination_post.size(); j++){
      aux_list.push_back(vacination_post[j]);
    }

    this->orderStationList(people[i], aux_list);
    
    for(Station* item : aux_list){
      if(item->isListFull() == true){
        continue;
      }else{
        item->allocPerson(people[i]);
        people[i]->setIsAllocated(true);
        break;
      }

    }
    //Se alguma pessoa passou por todos os postos sem ser alocada, significa que todos estão cheios
    //e o resto das pessoas não serão alocadas.

    if(people[i]->getIsAllocated() == false){
      break;
    }

    aux_list.clear();


  };


}