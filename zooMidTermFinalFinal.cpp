#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include <regex>
using namespace std;


// create an Animal class that all other species can derive from, include all attributes you wish to parse from file as well as any additional attributes.
class Animal {
public:
    string name;
    int age;
    string birthdate;
    string color;
    string gender;
    int weight;
    string origin;
    string arrivalDate;
    string uniqueID;
    string species;
    string birthSeason;
    string sound;


    static int animalCount;
  

    // construct for Animal 
    Animal(const string& _name, int _age, const string& _birthdate, const string& _color, const string& _gender,
        int _weight, const string& _origin, const string& _arrivalDate, const string& _species)
        : name(_name), age(_age), birthdate(_birthdate), color(_color), gender(_gender), weight(_weight),
        origin(_origin), arrivalDate(_arrivalDate), species(_species), uniqueID("") {
        animalCount++;
    }


   
    // create setter & getter for Unique ID
    string getUniqueID() const {
        return uniqueID;
    }

    void setUniqueID(const string& id) {
        uniqueID = id;
    }

};
// declare 0 for animal count
int Animal::animalCount = 0;


// Create the different species classes and make them derive from Animal
class Hyena : public Animal {

    // create variable hyena count to keep track of hyenas as they are created
public:
    static int hyenaCount;

public:
   // create a vector holding different hyena sounds to be assigned to a created hyena object
    vector<string> sounds;

public:
    // hyena construct has to be same as set in Animal construct
    Hyena(const string& _name, int _age, const string& _birthdate, const string& _color, const string& _gender,
        int _weight, const string& _origin, const string& _arrivalDate)
        : Animal(_name, _age, _birthdate, _color, _gender, _weight, _origin, _arrivalDate, "Hyena") {


        // this will assign a unique id while incrementing for every hyena object created 
        ostringstream idStream;
        idStream << "Hy";
        if (hyenaCount + 1 < 10) { // Change this line
            idStream << "0";
        }
        idStream << hyenaCount + 1; // Increment the count here
        uniqueID = idStream.str();
        hyenaCount++;
    }

    // function to calculate hyena birthdate based off of 'current date - age' + 'birth month and day default to month and day of start of season
    static string calculateHyenaBirthdate(string description, string birthSeason) {

        // Parse the age from the description
        smatch match;  // part of the regex library to store an expression match

        // formatted to find the digits so it doesnt parse 'years old'
        if (regex_search(description, match, regex(R"(\b(\d+)\s*year\s*old)"))) {
            int age = stoi(match[1]);

            // Get the current year and month
            chrono::system_clock::time_point today = chrono::system_clock::now();
            time_t now_c = chrono::system_clock::to_time_t(today);
            tm now_tm;
            localtime_s(&now_tm, &now_c);

            int birthYear = now_tm.tm_year + 1900 - age;

            int birthMonth, birthDay;

            if (birthSeason == "spring") {
                birthMonth = 3;
                birthDay = 21;
            }
            else if (birthSeason == "summer") {
                birthMonth = 6;
                birthDay = 21;
            }
            else if (birthSeason == "fall") {
                birthMonth = 9;
                birthDay = 21;
            }
            else if (birthSeason == "winter") {
                birthMonth = 12;
                birthDay = 21;
            }
            else {
                // Handle unknown or invalid season (default to January 1st)
                birthMonth = 1;
                birthDay = 1;
            }

            // Create a string to represent the birthdate
            ostringstream oss;  // used to build strings by writing data to it. 
            oss << birthMonth << "/" << birthDay << "/" << birthYear;

            return oss.str();
        }
        else {
            return "Invalid age information in the description";
        }
    }

    // create a function to display hyena objects
    void displayHyenaLL() const {
        // Display Hyena-specific information
        cout << "Unique ID: " << getUniqueID() << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Color: " << color << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << "lbs" << endl;
        cout << "Origin: " << origin << endl;

        cout << endl;
    }
};
// initiate hyenacount as 0
int Hyena::hyenaCount = 0;


// REPEAT ALL STEPS FOR EACH OF THE OTHER SPECIES: LIONS, BEARS, TIGERS

class Tiger : public Animal {
public:
    static int tigerCount;

public:

    Tiger(const string& _name, int _age, const string& _birthdate, const string& _color, const string& _gender,
        int _weight, const string& _origin, const string& _arrivalDate)
        : Animal(_name, _age, _birthdate, _color, _gender, _weight, _origin, _arrivalDate, "Tiger") {
        ostringstream idStream;
        idStream << "Ti";
        if (tigerCount + 1 < 10) { // Change this line
            idStream << "0";
        }
        idStream << tigerCount + 1; // Increment the count here
        uniqueID = idStream.str();
        tigerCount++;
    }
    void displayTigerLL() const {
        // Display Hyena-specific information
        cout << "Unique ID: " << getUniqueID() << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Color: " << color << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << "lbs" << endl;
        cout << "Origin: " << origin << endl;
        
        cout << endl;
    }

    static string calculateTigerBirthdate(string description, string birthSeason) {
        // Parse the age from the description
        smatch match;
        if (regex_search(description, match, regex(R"(\b(\d+)\s*year\s*old)"))) {
            int age = stoi(match[1]);

            // Get the current year and month
            chrono::system_clock::time_point today = chrono::system_clock::now();
            time_t now_c = chrono::system_clock::to_time_t(today);
            tm now_tm;
            localtime_s(&now_tm, &now_c);

            int birthYear = now_tm.tm_year + 1900 - age;

            int birthMonth, birthDay;

            if (birthSeason == "spring") {
                birthMonth = 3;
                birthDay = 21;
            }
            else if (birthSeason == "summer") {
                birthMonth = 6;
                birthDay = 21;
            }
            else if (birthSeason == "fall") {
                birthMonth = 9;
                birthDay = 21;
            }
            else if (birthSeason == "winter") {
                birthMonth = 12;
                birthDay = 21;
            }
            // Create a string to represent the birthdate
            ostringstream oss;
            oss << birthMonth << "/" << birthDay << "/" << birthYear;

            return oss.str();
        }
        else {
            return "Invalid age information in the description";
        }
    }

};

int Tiger::tigerCount = 0;

class Lion : public Animal {
public:
    static int lionCount;

public:
    Lion(const string& _name, int _age, const string& _birthdate, const string& _color, const string& _gender,
        int _weight, const string& _origin, const string& _arrivalDate)
        : Animal(_name, _age, _birthdate, _color, _gender, _weight, _origin, _arrivalDate, "Lion") {
        ostringstream idStream;
        idStream << "Li";
        if (lionCount + 1 < 10) { // Change this line
            idStream << "0";
        }
        idStream << lionCount + 1; // Increment the count here
        uniqueID = idStream.str();
        lionCount++;
    }
    void displayLionLL() const {
        // Display Hyena-specific information
        cout << "Unique ID: " << getUniqueID() << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Color: " << color << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << "lbs" << endl;
        cout << "Origin: " << origin << endl;
       
        cout << endl;
    }

    static string calculateLionBirthdate(string description, string birthSeason) {
        // Parse the age from the description
        smatch match;
        if (regex_search(description, match, regex(R"(\b(\d+)\s*year\s*old)"))) {
            int age = stoi(match[1]);

            // Get the current year and month
            chrono::system_clock::time_point today = chrono::system_clock::now();
            time_t now_c = chrono::system_clock::to_time_t(today);
            tm now_tm;
            localtime_s(&now_tm, &now_c);

            int birthYear = now_tm.tm_year + 1900 - age;

            int birthMonth, birthDay;

            if (birthSeason == "spring") {
                birthMonth = 3;
                birthDay = 21;
            }
            else if (birthSeason == "summer") {
                birthMonth = 6;
                birthDay = 21;
            }
            else if (birthSeason == "fall") {
                birthMonth = 9;
                birthDay = 21;
            }
            else if (birthSeason == "winter") {
                birthMonth = 12;
                birthDay = 21;
            }
            // Create a string to represent the birthdate
            ostringstream oss;
            oss << birthMonth << "/" << birthDay << "/" << birthYear;

            return oss.str();
        }
        else {
            return "Invalid age information in the description";
        }
    }
};

int Lion::lionCount = 0;

class Bear : public Animal {
public:
    static int bearCount;

public:
    Bear(const string& _name, int _age, const string& _birthdate, const string& _color, const string& _gender,
        int _weight, const string& _origin, const string& _arrivalDate)
        : Animal(_name, _age, _birthdate, _color, _gender, _weight, _origin, _arrivalDate, "Bear") {
        ostringstream idStream;
        idStream << "Br";
        if (bearCount + 1 < 10) { // Change this line
            idStream << "0";
        }
        idStream << bearCount + 1; // Increment the count here
        uniqueID = idStream.str();
        bearCount++;
    }
    void displayBearLL() const {
        // Display Hyena-specific information
        cout << "Unique ID: " << getUniqueID() << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Color: " << color << endl;
        cout << "Gender: " << gender << endl;
        cout << "Weight: " << weight << "lbs" << endl;
        cout << "Origin: " << origin << endl;
       
        cout << endl;
    }

    static string calculateBearBirthdate(string description, string birthSeason) {
        // Parse the age from the description
        smatch match;
        if (regex_search(description, match, regex(R"(\b(\d+)\s*year\s*old)"))) {
            int age = stoi(match[1]);

            // Get the current year and month
            chrono::system_clock::time_point today = chrono::system_clock::now();
            time_t now_c = chrono::system_clock::to_time_t(today);
            tm now_tm;
            localtime_s(&now_tm, &now_c);

            int birthYear = now_tm.tm_year + 1900 - age;

            int birthMonth, birthDay;

            if (birthSeason == "spring") {
                birthMonth = 3;
                birthDay = 21;
            }
            else if (birthSeason == "summer") {
                birthMonth = 6;
                birthDay = 21;
            }
            else if (birthSeason == "fall") {
                birthMonth = 9;
                birthDay = 21;
            }
            else if (birthSeason == "winter") {
                birthMonth = 12;
                birthDay = 21;
            }
            // Create a string to represent the birthdate
            ostringstream oss;
            oss << birthMonth << "/" << birthDay << "/" << birthYear;

            return oss.str();
        }
        else {
            return "Invalid age information in the description";
        }
    }
};

int Bear::bearCount = 0;


// Create a vector that will store the names read in from the animal names file

vector<string> readNamesForSpecies(ifstream& inputFile, const string& species) {
    vector<string> names;
    string line;
    bool readingTargetSpecies = false;  // ensures it is reading names from the file

    // create a while loop to read the names in the file
    while (getline(inputFile, line)) {
        if (line.find(species + " Names:") != string::npos) { // checks if each line contains "(species) Name:"
            readingTargetSpecies = true;
        }
        else if (readingTargetSpecies && !line.empty()) { // processes the line if it contains valid info
            line.erase(0, line.find_first_not_of(" "));
            line.erase(line.find_last_not_of(" ") + 1);
            names.push_back(line);
        }
        else if (readingTargetSpecies && line.empty()) { // if condition isnt met (if done reading in all names) then stop reading in names
            break;
        }
    }
    return names;
}


// create a function that assigns a random name to an animal object corresponding to its species name list
string getRandomNameForSpecies(vector<string>& names) {
    if (!names.empty()) {
        vector<string> shuffledNames = names;
        random_shuffle(shuffledNames.begin(), shuffledNames.end());
        string selectedName = shuffledNames[0];
        names.erase(names.begin()); // Remove the selected name from the list
        return selectedName;
    }
    return "Unknown";
}

// function to correctly extract gender from the lines of descriptions
std::string extractGender(const std::string& description) {
    size_t agePosition = description.find(" years old"); // parses the gender which comes after 'years old'
    if (agePosition != std::string::npos) {
        std::string remaining = description.substr(agePosition + 11); // Skip " years old"
        std::istringstream iss(remaining);
        std::string gender;
        iss >> gender;
        return gender;
    }
    return "Gender not specified";
}

// create animal node 
struct AnimalNode {
    Animal* animal;
    AnimalNode* next;

    AnimalNode(Animal* _animal) : animal(_animal), next(nullptr) {}
};

// create function to append information from vectors into a linked list
class AnimalLinkedList {
public:
    AnimalNode* head;
    AnimalNode* tail;
    vector<Hyena> hyenas;
    vector<Lion> lions;
    vector<Bear> bears;
    vector<Tiger> tigers;

    
    AnimalLinkedList() : head(nullptr), tail(nullptr) {}

    // Add an animal to the end of the linked list
    void append(Animal* animal) {
        AnimalNode* newNode = new AnimalNode(animal);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

// format for writing information onto file
void saveHabitatToFile(std::ofstream& file, const std::string& habitat, const std::vector<Animal>& animals) {
    file << habitat << " Habitat:\n\n";

    for (const Animal& animal : animals) {
        file << animal.getUniqueID() << "; " << animal.name << "; " << animal.age << " years old; birth date " << animal.birthdate
            << "; " << animal.color << " color; " << animal.gender << "; " << animal.weight << " lbs; from " << animal.origin << "\n";
    }

    file << "\n";
}


    int main() {

        // read in animal names file
        ifstream inputFile("C:\\Users\\Johnny\\JavaFiles\\animalNames.txt");
        if (!inputFile.is_open()) {
            cerr << "Failed to open the name file." << endl;
            return 1;
        }

     
        string line;
        //declare variable for 'current species'
        string currentSpecies;
        
        // create vectors to store each of the species names 
        vector<string> hyenaNames, lionNames, bearNames, tigerNames;


        //optional menu to select what species names to look up
        string specifiedSpecies;
        cout << "Enter the animal species to look up names (Hyena, Lion, Bear, Tiger): ";
        cin >> specifiedSpecies;

        // while loop to iterate through names and store in the corresponding species vectors
        while (getline(inputFile, line)) {

            //if statements to determine what species names are being read
            if (line.find("Hyena Names:") != string::npos) {
                currentSpecies = "Hyena";
            }
            else if (line.find("Lion Names:") != string::npos) {
                currentSpecies = "Lion";
            }
            else if (line.find("Bear Names:") != string::npos) {
                currentSpecies = "Bear";
            }
            else if (line.find("Tiger Names:") != string::npos) {
                currentSpecies = "Tiger";
            }
            else if (!currentSpecies.empty()) {
                istringstream lineStream(line);
                string name;

                // while reading through a species names store them into vector
                while (getline(lineStream, name, ',')) {
                    name.erase(0, name.find_first_not_of(" "));
                    name.erase(name.find_last_not_of(" ") + 1);
                    if (currentSpecies == "Hyena") {
                        hyenaNames.push_back(name);
                    }
                    else if (currentSpecies == "Lion") {
                        lionNames.push_back(name);
                    }
                    else if (currentSpecies == "Bear") {
                        bearNames.push_back(name);
                    }
                    else if (currentSpecies == "Tiger") {
                        tigerNames.push_back(name);
                    }
                }
            }
        }

        // if statements to display specified species names
        if (specifiedSpecies == "Hyena") {
            for (const string& name : hyenaNames) {
                cout << "Species: " << specifiedSpecies << ", Name: " << name << endl;
            }
        }
        else if (specifiedSpecies == "Lion") {
            for (const string& name : lionNames) {
                cout << "Species: " << specifiedSpecies << ", Name: " << name << endl;
            }
        }
        else if (specifiedSpecies == "Bear") {
            for (const string& name : bearNames) {
                cout << "Species: " << specifiedSpecies << ", Name: " << name << endl;
            }
        }
        else if (specifiedSpecies == "Tiger") {
            for (const string& name : tigerNames) {
                cout << "Species: " << specifiedSpecies << ", Name: " << name << endl;
            }
        }
        else {
            cout << "Invalid species. Please choose from Hyena, Lion, Bear, or Tiger." << endl;
        }

        string description;
        string birthSeason;
        string birthdate;
        
        // read in the arriving animals file
        ifstream inputFile2("C:\\Users\\Johnny\\JavaFiles\\arrivingAnimals2.txt");
        if (!inputFile2.is_open()) {
            cerr << "Failed to open the name file." << endl;
            return 1;
        }

        string line2;

        vector<Hyena> hyenas;  // Vector to store Hyena objects
        vector<Lion> lions;  // Vector to store Lion objects
        vector<Bear> bears; // Vector to store Bear objects
        vector<Tiger> tigers; // Vector to store Tiger objects

        // while loop to find "hyena" in the lines of descriptions and if found store the lines containing "hyena
        while (getline(inputFile2, line2)) {
            if (line2.find("hyena") != string::npos) {
                smatch match;

                int age = 0; // Declare age variable and initialize it to 0
                string birthSeason;

                // parse age setting the correct format to correctly extract
                if (regex_search(line2, match, regex(R"(\b(\d+)\s*year\s*old\b)"))) {
                    age = stoi(match[1]);
                    cout << "\nAge: " << age << " years" << endl;
                }
                // parse gender
                std::string gender;
                if (regex_search(line2, match, regex(R"((female|male))"))) {
                    gender = match[1];
                        cout << "Gender: " << gender << endl;
                }
                else {
                    cout << "Gender not specified" << endl;
                }
                // parse birth season
                if (regex_search(line2, match, regex(R"(born in\s+(\w+))"))) {
                    birthSeason = match[1];
                    cout << "Birth Season: " << birthSeason << endl;
                }

                // parse color
                string color;
                if (regex_search(line2, match, regex(R"((\w+)\s+color)"))) {
                    color = match[1];
                    cout << "Color: " << color << endl;
                }

                //parse weight 
                int weight = 0;
                if (regex_search(line2, match, regex(R"(\b(\d+)\s*pounds\b)"))) {
                    weight = stoi(match[1]);
                    cout << "Weight: " << weight << " pounds" << endl;
                }
                // parse origin
                string origin;
                if (regex_search(line2, match, regex(R"(from\s+(.+)$)"))) {
                    origin = match[1];
                    cout << "Origin: " << origin << endl;
                }

                // Create a new Hyena object for each line read in containing 'hyena'
                string name = getRandomNameForSpecies(hyenaNames); // assign random name from corresponding name vector
                string description = to_string(age) + " year old female hyena"; 
                string birthdate = Hyena::calculateHyenaBirthdate(description, birthSeason);// call hyena birthday calculation
                Hyena hyena(name, age, birthdate, color, gender, weight, origin, ""); // set the format for how info is to be stored

                // Store the Hyena object in the vector
                hyenas.push_back(hyena);

                
            }

            // REPEAT ALL STEPS FOR READING IN AND CREATING ANIMAL OBJECTS FOR THE OTHER THREE SPECIES: LION, BEAR, TIGER

            else if (line2.find("lion") != string::npos) {
                smatch match;

                int age = 0; // Declare age variable and initialize it to 0
                string birthSeason;

                if (regex_search(line2, match, regex(R"(\b(\d+)\s*year\s*old\b)"))) {
                    age = stoi(match[1]);
                    cout << "\nAge: " << age << " years" << endl;
                }

                if (regex_search(line2, match, regex(R"(born in\s+(\w+))"))) {
                    birthSeason = match[1];
                    cout << "Birth Season: " << birthSeason << endl;
                }
                std::string gender;
                if (regex_search(line2, match, regex(R"((female|male))"))) {
                    gender = match[1];
                        cout << "Gender: " << gender << endl;
                }
                else {
                    cout << "Gender not specified" << endl;
                }

                string color;
                if (regex_search(line2, match, regex(R"((\w+)\s+color)"))) {
                    color = match[1];
                    cout << "Color: " << color << endl;
                }

                int weight = 0;
                if (regex_search(line2, match, regex(R"(\b(\d+)\s*pounds\b)"))) {
                    weight = stoi(match[1]);
                    cout << "Weight: " << weight << " pounds" << endl;
                }

                string origin;
                if (regex_search(line2, match, regex(R"(from\s+(.+)$)"))) {
                    origin = match[1];
                    cout << "Origin: " << origin << endl;
                }

                // Create a new Lion object
                string name = getRandomNameForSpecies(lionNames);
                string description = to_string(age) + " year old female lion";
                string birthdate = Lion::calculateLionBirthdate(description, birthSeason);
                Lion lion(name, age, birthdate, color, gender, weight, origin,"");

                // Store the Lion object in the vector
                lions.push_back(lion);

                


            }
            else if (line2.find("bear") != string::npos) {
                smatch match;

                int age = 0; // Declare age variable and initialize it to 0
                string birthSeason;

                if (regex_search(line2, match, regex(R"(\b(\d+)\s*year\s*old\b)"))) {
                    age = stoi(match[1]);
                    cout << "\nAge: " << age << " years" << endl;
                }

                if (regex_search(line2, match, regex(R"(born in\s+(\w+))"))) {
                    birthSeason = match[1];
                    cout << "Birth Season: " << birthSeason << endl;
                }
                std::string gender;
                if (regex_search(line2, match, regex(R"((female|male))"))) {
                    gender = match[1];
                        cout << "Gender: " << gender << endl;
                }
                else {
                    cout << "Gender not specified" << endl;
                }

                string color;
                if (regex_search(line2, match, regex(R"((\w+)\s+color)"))) {
                    color = match[1];
                    cout << "Color: " << color << endl;
                }

                int weight = 0;
                if (regex_search(line2, match, regex(R"(\b(\d+)\s*pounds\b)"))) {
                    weight = stoi(match[1]);
                    cout << "Weight: " << weight << " pounds" << endl;
                }

                string origin;
                if (regex_search(line2, match, regex(R"(from\s+(.+)$)"))) {
                    origin = match[1];
                    cout << "Origin: " << origin << endl;
                }

                // Create a new Bear object
                string name = getRandomNameForSpecies(bearNames);
                string description = to_string(age) + " year old female bear";
                string birthdate = Bear::calculateBearBirthdate(description, birthSeason);
                Bear bear(name, age, birthdate, color, gender, weight, origin, "Arrival Date");

                // Store the Bear object in the vector
                bears.push_back(bear);

                
            }
            else if (line2.find("tiger") != string::npos) {
                smatch match;

                int age = 0; // Declare age variable and initialize it to 0
                string birthSeason;

                if (regex_search(line2, match, regex(R"(\b(\d+)\s*year\s*old\b)"))) {
                    age = stoi(match[1]);
                    cout << "\nAge: " << age << " years" << endl;
                }

                if (regex_search(line2, match, regex(R"(born in\s+(\w+))"))) {
                    birthSeason = match[1];
                    cout << "Birth Season: " << birthSeason << endl;
                }

                string color;
                if (regex_search(line2, match, regex(R"(\b(\w+\s+and\s+\w+\s+stripes|\w+\s+stripes|\w+\s+and\s+\w+)\s+color)"))) {
                    color = match[1];
                    cout << "Color: " << color << " color" << endl;
                }
                std::string gender;
                if (regex_search(line2, match, regex(R"(female|male)", regex::icase))) {
                    gender = match[0]; // Use match[0] to get the full match
                    cout << "Gender: " << gender << endl;
                }
                else {
                    cout << "Gender not specified" << endl;
                }

                int weight = 0;
                if (regex_search(line2, match, regex(R"(\b(\d+)\s*pounds\b)"))) {
                    weight = stoi(match[1]);
                    cout << "Weight: " << weight << " pounds" << endl;
                }

                string origin;
                if (regex_search(line2, match, regex(R"(from\s+(.+)$)"))) {
                    origin = match[1];
                    cout << "Origin: " << origin << endl;
                }

                vector<string> usedTigerNames;

                string name;
                do {
                    name = getRandomNameForSpecies(tigerNames);
                } while (find(usedTigerNames.begin(), usedTigerNames.end(), name) != usedTigerNames.end());
                usedTigerNames.push_back(name);
                // Create a new Tiger object
               // string name = getRandomNameForSpecies(tigerNames);
                string description = to_string(age) + " year old female tiger";
                string birthdate = Tiger::calculateTigerBirthdate(description, birthSeason);
                Tiger tiger(name, age, birthdate, color, gender, weight, origin, "");

                // Store the Tiger object in the vector
                tigers.push_back(tiger);

               
            }
        }



        inputFile2.close();

        
        
        // declare variables for each species count & total animal count
        int numberOfHyenas = Hyena::hyenaCount;
        int numberOfTigers = Tiger::tigerCount;
        int numberOfBears = Bear::bearCount;
        int numberOfLions = Lion::lionCount;
        int numberOfAnimals = Animal::animalCount;

        // display species & animal count
        cout << "\n\nNumber of hyenas: " << numberOfHyenas << endl;
        cout << "Number of Tigers: " << numberOfTigers << endl;
        cout << "Number of Bears: " << numberOfBears << endl;
        cout << "Number of Lions: " << numberOfLions << endl;
        cout << "Total Number of Animals: " << numberOfAnimals << endl << endl;



        // Create an instance of AnimalLinkedList
        AnimalLinkedList animalList;

        // Append Hyenas to the linked list
        for (const Hyena& hyena : hyenas) {
            animalList.hyenas.push_back(hyena);
        }

        // Append Lions to the linked list
        for (const Lion& lion : lions) {
            animalList.lions.push_back(lion);
        }

        // Append Bears to the linked list
        for (const Bear& bear : bears) {
            animalList.bears.push_back(bear);
        }

        // Append Tigers to the linked list
        for (const Tiger& tiger : tigers) {
            animalList.tigers.push_back(tiger);
        }
        

        // display each species linked list after appending animal object from vectors
        cout << "Hyena Habitat:" << endl << endl;
        for (const Hyena& hyena : hyenas) {
            hyena.displayHyenaLL();
        }

        cout << "Lion Habitat:" << endl << endl;
        for (const Lion& lion : lions) {
            lion.displayLionLL();
        }

        cout << "Bear Habitat:" << endl << endl;
        for (const Bear& bear : bears) {
            bear.displayBearLL();
        }

        cout << "Tiger Habitat:" << endl << endl;
        for (const Tiger& tiger : tigers) {
            tiger.displayTigerLL();
        }

        

     
        // Create an output file for the entire zoo population
        std::ofstream zooPopulationFile("Zoo_Population.txt");

        // Check if the file was opened successfully
        if (!zooPopulationFile.is_open()) {
            std::cerr << "Failed to open Zoo_Population.txt." << std::endl;
            return 1;
        }

        // Group animals by habitat
        std::map<std::string, std::vector<Animal>> habitats;

        for (const Animal& hyena : hyenas) {
            habitats["Hyena"].push_back(hyena);
        }

        for (const Animal& lion : lions) {
            habitats["Lion"].push_back(lion);
        }

        for (const Animal& bear : bears) {
            habitats["Bear"].push_back(bear);
        }

        for (const Animal& tiger : tigers) {
            habitats["Tiger"].push_back(tiger);
        }

        // Save animals by habitat to the zooPopulationFile
        for (const auto& habitat : habitats) {
            saveHabitatToFile(zooPopulationFile, habitat.first, habitat.second);
        }

        // Close the zooPopulationFile
        zooPopulationFile.close();

        // ...



        return 0;
    }
