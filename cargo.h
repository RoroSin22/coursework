#ifndef UNTITLED6_CARGO_H
#define UNTITLED6_CARGO_H


#include <string>
#include <vector>

class Cargo {
private:
    unsigned int id;
    std::string name;
    std::vector<unsigned int> extra_properties;

public:
    Cargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties);
    unsigned int getId();
    std::string getName();
    std::vector<unsigned int> getExtraProperties();
};

class SmallCargo: public Cargo{
private:
    float weight;
    std::string type;
public:
    SmallCargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties, float weight, std::string type);
    float getWeight();
    std::string getType();
    std::string determineType();
};

class LargeCargo: public Cargo{
private:
    int size[2];
public:
    LargeCargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties, int size1, int size2);
    int* getSize();
};

int typeToInt(std::string type);


#endif
