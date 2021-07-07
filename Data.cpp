#include <iostream>
#include <sstream>
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
    std::ifstream file(this->path, std::ifstream::in);
    std::string line, val;
    
    //Extracting column names 
    if(file.good()){
        std::getline(file, line);
        std::stringstream ss(line);
        
        while(std::getline(ss, val, ',')){
            col_names.push_back(val);
        }
    } 

    //Reading values and classes
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::vector<double> temp;
        for(size_t i = 0; i < col_names.size(); i++){
            std::getline(ss, val, ',');
            if(5 > i && i > 0){
                temp.push_back(std::stod(val));
            }else if(i == 5){
                classes.push_back(val);    
            }
        }
        values.push_back(temp);
    }
    
    //Deleting index from columns names since we don't use it
    col_names.erase(col_names.begin());
}

void Data::print(){
    for(auto name: col_names) std::cout << name << "  ";
    std::cout << std::endl;
    for(size_t i = 0; i < classes.size(); ++i){
        for(auto val: values[i]) std::cout << val << "  ";
        std::cout << "> " << classes[i] << std::endl;
    }
}

void Data::train_test_split(double train_size){
    int split_point = train_size * classes.size();
    int r = 500;
    int ind1, ind2;
    while(r--){
        ind1 = rand() % classes.size();
        ind2 = rand() % classes.size();
        swap(classes[ind1], classes[ind2]);
        swap(values[ind1], values[ind2]);
    }
    copy(classes.begin(), classes.begin() + split_point, std::back_inserter(train_classes));
    copy(classes.begin() + split_point, classes.end(), std::back_inserter(test_classes));
    copy(values.begin(), values.begin() + split_point, std::back_inserter(train_values));
    copy(values.begin() + split_point, values.end(), std::back_inserter(test_values));
}

Data::~Data(){

}
