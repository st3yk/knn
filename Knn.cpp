#include "Knn.h"
#include <math.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_map>

Knn::Knn(Data* my_data){
    this->data = my_data;
}

bool sort_pair(const std::pair<std::string, double> &a, const std::pair<std::string, double> &b){
    return a.second < b.second;
}

void Knn::classify(int neighborsNo){
    int score = 0;
    for(size_t i = 0; i < data->test_classes.size(); ++i){
        score += classify_one(data->test_values[i], data->test_classes[i], neighborsNo);
    }
    double result = ((double)score / (double)data->test_classes.size());
    result *= 100;
    std::cout << "Classified using KNN with " << neighborsNo << " neighbors." << std::endl;
    std::cout << "Result: " << result << "%. " << std::endl;
    std::cout << score << "/"  << data->test_classes.size() << std::endl;
}

int Knn::classify_one(std::vector<double> &v, std::string cls, int neighborsNo){
    std::vector<std::pair<std::string, double>> distances;
    for(size_t i = 0; i < data->train_classes.size(); ++i){
        double dist = norm(v, data->train_values[i]);
        std::pair<std::string, double> temp(data->train_classes[i], dist);
        distances.push_back(temp);
    }
    sort(distances.begin(), distances.end(), sort_pair); 

    std::unordered_map<std::string, int> scores;
    for(int i = 0; i < neighborsNo; ++i){
        scores[distances[i].first]++;
    }
    
    int max_score = -1;
    std::string classified_as;
    for(auto s: scores){
        if(s.second > max_score){
            max_score = s.second;
            classified_as = s.first;
        }
    }
    if(!cls.compare(classified_as)){
        return 1;
    }
        return 0;
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

