#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// defining recruit class
class Recruit 
{
public:
    Recruit();

    // Copy constructor
    Recruit(const Recruit& other);

    // Destructor
    ~Recruit();

    void read_txt(ifstream &input);
    
    void print_txt(ofstream &output) const;

    string getFirstName() const;
    string getLastName() const;
    string getPosition() const;
    string getCity() const;
    string getState() const;
    string getHighschool() const;
    string getHeight() const;
    int getWeight() const;
    int getStars() const;
    int getGrade() const;
    string getSchool() const;



    void setFirstName(const string& firstname);
    void setLastName(const string& lastname);
    void setPosition(const string& position);
    void setCity(const string& city);
    void setState(const string& state);
    void setHighschool(const string& highschool);
    void setHeight(const string& height);
    void setWeight(int weight);
    void setStars(int stars);
    void setGrade(int grade);
    void setSchool(const string& school);

private:
    string FirstName;
    string LastName;
    string Position;
    string City;
    string State;
    string Highschool;
    string Height;
    int Weight;
    int Stars;
    int Grade;
    string School;
};
