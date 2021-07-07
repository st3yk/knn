#include <iostream>
#include "Data.h"

int main(){
    Data my_data = Data("iris");
    my_data.train_test_split(0.8);
    return 0;
}
