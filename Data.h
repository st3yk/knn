#include <string>
#include <vector>

class Data {
private:
    std::string dataset;
    std::string path;
    std::vector<std::vector<double>> values;
    std::vector<std::string> classes;
    
    void load();
    void load_iris();
public:
    Data(std::string dataset);
    ~Data();
     
};
