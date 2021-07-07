#include <iostream>
#include <fstream>
#include "Data.h"

Data::Data(std::string dataset){
    this->dataset = dataset;
    this->path = "datasets/" + dataset + ".csv";
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
    std::cout<<"Loading iris...\n";
    std::fstream fin;
    fin.open(path, std::ios::in);
}

Data::~Data(){

}
