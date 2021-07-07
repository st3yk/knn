#include <string>
#include <vector>

class Data {
private:
    std::string dataset;
    std::string path;
    std::vector<std::string> col_names;
    std::vector<std::string> classes;
    std::vector<std::vector<double>> values;
    
    void load();
    void load_iris();

public:
    Data(std::string dataset);
    void print();
    ~Data();
     
};
