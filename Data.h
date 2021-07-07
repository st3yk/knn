#include <string>
#include <vector>

class Data {
private:
    std::string dataset;
    std::string path;
    std::vector<std::string> col_names;
    std::vector<std::string> classes;
    std::vector<std::vector<double>> values;
     
    std::vector<std::string> train_classes;
    std::vector<std::string> test_classes;
    std::vector<std::vector<double>> train_values;
    std::vector<std::vector<double>> test_values;
    
    void load();
    void load_iris();
    friend class Knn;
public:
    Data(std::string dataset);
    void print();
    void train_test_split(double train_size);
    ~Data();
     
};
