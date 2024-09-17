#include "recruit.h"
#include <iostream>
#include <fstream>

using namespace std;

// beginning constructor
Recruit::Recruit() : Weight(0), Stars(0), Grade(0) 
{
}


// copy  constructor
Recruit::Recruit(const Recruit& other) 
{
    FirstName = other.FirstName;
    LastName = other.LastName;
    Position = other.Position;
    City = other.City;
    State = other.State;
    Highschool = other.Highschool;
    Height = other.Height;
    School = other.School;
    Weight = other.Weight;
    Stars = other.Stars;
    Grade = other.Grade;
}

// destructor
Recruit::~Recruit() 
{
}



void Recruit::read_txt(ifstream &inputFile) 
{
    
    // clears previous data, didn't know i needed this until 2 hours after debugging...
    FirstName.clear();
    LastName.clear();
    Position.clear();
    City.clear();
    State.clear();
    Highschool.clear();
    Height.clear();
    School.clear();
    Weight = 0;
    Stars = 0;
    Grade = 0;

    // reads the recruit's information in order
    getline(inputFile, FirstName);
    getline(inputFile, LastName);
    getline(inputFile, Position);
    getline(inputFile, City);
    getline(inputFile, State);
    getline(inputFile, Highschool);
    getline(inputFile, Height);
    inputFile >> Weight;
    inputFile.ignore(); 
    string starString;
    getline(inputFile, starString);
    Stars = starString.length();  
    inputFile >> Grade;
    inputFile.ignore();  
    getline(inputFile, School); 
}



// getters
string Recruit::getFirstName() const 
{ 
    return FirstName; 
}
string Recruit::getLastName() const 
{ 
    return LastName; 
}
string Recruit::getPosition() const 
{ 
    return Position; 
}
string Recruit::getCity() const 
{ 
    return City; 
}
string Recruit::getState() const 
{ 
    return State; 
}
string Recruit::getHighschool() const 
{ 
    return Highschool; 
}
string Recruit::getHeight() const 
{ 
    return Height; 
}
int Recruit::getWeight() const 
{ 
    return Weight; 
}
int Recruit::getStars() const 
{ 
    return Stars; 
}
int Recruit::getGrade() const 
{ 
    return Grade; 
}
string Recruit::getSchool() const 
{ 
    return School; 
}

// setters with some error checking
void Recruit::setFirstName(const string& firstname)
{
    FirstName = firstname;
}

void Recruit::setLastName(const string& lastname)
{
    LastName = lastname;
}

void Recruit::setPosition(const string& position)
{
    Position = position;
}

void Recruit::setCity(const string& city)
{
    City = city;
}

void Recruit::setState(const string& state)
{
    State = state;
}

void Recruit::setHighschool(const string& highschool)
{
    Highschool = highschool;
}

void Recruit::setHeight(const string& height)
{
    Height = height;
}

void Recruit::setWeight(int weight)
{
    if (weight >= 100 && weight <= 360)
        Weight = weight;
    else
        cout << "Invalid weight, Please enter a weight between 100-360 lbs.\n";
}

void Recruit::setStars(int stars)
{
    if (stars >= 0 && stars <= 5)
        Stars = stars;
    else
        cout << "Invalid stars, Please enter a value between 0-5.\n";
}

void Recruit::setGrade(int grade)
{
    if (grade >= 7 && grade <= 12) 
        Grade = grade;
    else
        cout << "Invalid grade! Please enter a grade between 7-12.\n";
}

void Recruit::setSchool(const string& school)
{
    School = school;
}

// print recruit in the same format as the input file
void Recruit::print_txt(ofstream& output) const 
{
    output << FirstName << endl;
    output << LastName << endl;
    output << Position << endl;
    output << City << endl;
    output << State << endl;
    output << Highschool << endl;
    output << Height << endl;
    output << Weight << endl;
    for (int i = 0; i < Stars; ++i) 
    {
        output << "*";
    }
    output << endl;
    output << Grade << endl;
    output << School << endl;
}
