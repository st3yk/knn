#include <iostream>
#include "Knn.h"

int main(){
    Data* my_data = new Data("iris");
    my_data->train_test_split(0.8);
    Knn classifier = Knn(my_data);
    classifier.classify(3);
    delete my_data;
    return 0;
}
