#ifndef UNTITLED6_CARGO_H
#define UNTITLED6_CARGO_H


#include <string>
#include <vector>

class Cargo {
private:
    int id;
    float weight;
    std::string type;
    std::vector<int> extra_properties;

public:
    Cargo(int id_, float weight_, std::vector<int> extra_properties_);
    std::string determineType();
    int getId();
    float getWeight();
    std::string getType();
    std::vector<int> getExtraProperties();
};


#endif
