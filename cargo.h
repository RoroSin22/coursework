#ifndef UNTITLED6_CARGO_H
#define UNTITLED6_CARGO_H


#include <string>
#include <vector>

class Cargo {
private:
    unsigned int id;
    std::string name;
    float weight;
    std::string type;
    std::vector<unsigned int> extra_properties;

public:
    Cargo(unsigned int id_, std::string name_, float weight_, std::vector<unsigned int> extra_properties_);
    std::string determineType();
    unsigned int getId();
    std::string getName();
    float getWeight();
    std::string getType();
    std::vector<unsigned int> getExtraProperties();
};

int typeToInt(std::string type);


#endif
