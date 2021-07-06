#include <iostream>
#include "Data.h"

Data::Data(std::string dataset){
    this->dataset = dataset;
    this->load();
}

void Data::load(){
    if(this->dataset == "iris"){
        this->load_iris();
    }else{
        std::cout<<"Not such dataset avaiable!";
    }
}

void Data::load_iris(){
    std::cout<<"Loading iris\n";
}

Data::~Data(){

}
