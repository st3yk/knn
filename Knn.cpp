#include "Knn.h"
#include <math.h>
#include <iostream>
#include <utility>

Knn::Knn(Data* my_data){
    this->data = my_data;
}

void Knn::classify(int neighborsNo){
    for(size_t i = 0; i < data->test_classes.size(); ++i){
        classify_one
    }
}

int Knn::classify_one(std::vector<double> &v, std::string class, int neighborsNo){
    std::vector<std::pair<std::string, double>> distances;
    for(size_t i = 0; i < data->train_classes.size(); ++i){
        double dist = norm(v, data->train_values[i]);
        std::pair<std::string, double> temp(data->train_classes[i], dist);
        distances.push_back(temp);
    }
}

double Knn::norm(std::vector<double> &v1, std::vector<double> &v2){
    double sum = 0;
    for(size_t i = 0; i < v1.size(); ++i){  
        sum += (v2[i] - v1[i]) *  (v2[i] - v1[i]); 
    }
    return sqrt(sum);
}

Knn::~Knn(){

}
