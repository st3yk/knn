#include "Data.h"

class Knn{
    private:
        double norm(std::vector<double> &v1, std::vector<double> &v2);
        int classify_one(std::vector<double> &v, std::string class, int neighborsNo);
        Data* data;
    public:
        Knn(Data* data);
        void classify(int neigborsNo);
        ~Knn();
};
    
