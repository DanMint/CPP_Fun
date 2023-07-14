#include <iostream>
#include <vector>

class Engine {
public:
    Engine() {
        amountOfCylinders = 0;
        horsePower = 0;
        layout = "None";
        turboCharged = false;
        enginePrice = 0;
    }

    void buildYourEngine() {
        std::cout << "How many cylinders would you like:";
        int cyl;
        std::cin >>cyl;
        amountOfCylinders = cyl;
        std::string lay;

        if (cyl == 3) {
            std::cout << "Please choose from the following engine layouts: Inline, V3: ";
            while (true) {
                std::cin >> lay;

                if (lay != "Inline" && lay != "inline" && lay != "V3" && lay != "v3") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;

                std::cout << "Do you want to turbo charge your engine? [y/n} ";

                std::string answer;
                std::cin >> answer;
                if (answer != "y" && answer != "n") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (50 + 200) / 2;
                    enginePrice = (1500 + 7000) / 2;
                }

                else if (answer == "y") {
                    horsePower = (100 + 200) / 2;
                    enginePrice = (2500 + 5500) / 2;
                    turboCharged = true;

                }
                break;
            }
        }

        if (cyl == 4) {
            std::cout << "Please choose from the following engine layouts: Inline, V4, Flat: ";
            while (true) {
                std::cin >> lay;

                if (lay != "Inline" && lay != "inline" && lay != "V4" && lay != "v4" && lay != "Flat" && lay != "flat") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;


                std::cout << "Do you want to turbo charge your engine? [y/n} ";

                std::string answer;
                std::cin >> answer;
                if (answer != "y" && answer != "n") {
                    std::cout << "Please answer y or n" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (80 + 300) / 2;
                    enginePrice = (2000 + 8000) / 2;

                }
                else if (answer == "y") {
                    horsePower = (100 + 450) / 2;
                    enginePrice = (3000 + 10000 ) / 2;
                    turboCharged = true;
                }

                break;
            }
        }

        else if (cyl == 5) {
            std::cout << "Please choose from the following engine layouts: Inline, V5: ";
            while (true) {
                std::cin >> lay;

                if (lay != "Inline" && lay != "inline" && lay != "V5" && lay != "v5") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;


                std::cout << "Do you want to turbo charge your engine? [y/n} ";

                std::string answer;
                std::cin >> answer;

                if (answer != "y" && answer != "n") {
                    std::cout << "Please answer y or n" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (100 + 350) / 2;
                    enginePrice = (2000 + 10000) / 2;
                }

                else if (answer == "y") {
                    horsePower = (150 + 500) / 2;
                    enginePrice = (3000 + 12000) / 2;
                    turboCharged = true;
                }

                break;
            }
        }

        if (cyl == 6) {
            std::cout << "Please choose from the following engine layouts: Inline, V6, Flat : ";
            while (true) {
                std::cin >> lay;

                if (lay != "Inline" && lay != "inline" && lay != "V6" && lay != "v6" && lay != "Flat" && lay != "flat") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;


                std::cout << "Do you want to turbo charge your engine? [y/n} ";

                std::string answer;
                std::cin >> answer;

                if (answer != "y" && answer != "n") {
                    std::cout << "Please answer y or n" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (150 + 450) / 2;
                    enginePrice = (3000 + 12000) / 2;
                }

                    else if (answer == "y") {
                    horsePower = (200 + 550) / 2;
                    turboCharged = true;
                    enginePrice = (4000 + 15000) / 2;
                }

                break;
            }
        }

        if (cyl == 8) {
            std::cout << "Please choose from the following engine layouts: Inline, V8, Flat ";
            while (true) {
                std::cin >> lay;

                if (lay != "Inline" && lay != "inline" && lay != "V8" && lay != "v8" && lay != "Flat" && lay != "flat") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;

                std::cout << "Do you want to turbo charge your engine? [y/n} ";


                std::string answer;
                std::cin >> answer;

                if (answer != "y" && answer != "n") {
                    std::cout << "Please answer y or n" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (250 + 700) / 2;
                    enginePrice = (4000 + 20000) / 2;
                }
                else if (answer == "y") {
                    horsePower = (400 + 1050) / 2;
                    turboCharged = true;
                    enginePrice = (6000 + 23000) / 2;
                }

                break;
            }
        }

        if (cyl == 12) {
            std::cout << "Please choose from the following engine layouts: Inline, V12, Flat " << std::endl;
            while (true) {
                std::cin >> lay;
                if (lay != "Inline" && lay != "inline" && lay != "V12" && lay != "v12" && lay != "Flat" && lay != "flat") {
                    std::cout << "Impossible layout, please try again" << std::endl;
                    continue;
                }
                else
                    layout = lay;

                std::cout << "Do you want to turbo charge your engine? [y/n}: ";

                std::string answer;
                std::cin >> answer;

                if (answer != "y" && answer != "n") {
                    std::cout << "Please answer y or n" << std::endl;
                    continue;
                }
                else if (answer == "n") {
                    horsePower = (500 + 1200) / 2;
                    enginePrice = (10000 + 25000) / 2;
                }

                else if (answer == "y") {
                    horsePower = (700 + 1550) / 2;
                    turboCharged = true;
                    enginePrice = (15000 + 30000) / 2;
                }

                break;
            }
        }

    }

    void getDataEngine() {
        std::cout << "Amount of cylinders: " << amountOfCylinders << std::endl;
        std::cout << "Horse power: " << horsePower << std::endl;
        std::cout << "Engine layout: " << layout << std::endl;
        std::cout << "Turbo charged: " << turboCharged << std::endl;
        std::cout << "Engine total cost: " << enginePrice << std::endl;
    }

    int getEngineCost() const {return enginePrice; }

private:
    int amountOfCylinders;
    int horsePower;
    std::string layout;
    bool turboCharged;
    int enginePrice;

};

class Type {
public:
    Type() : carType(""), carTypeCost(0) {}

    void buildYourType() {
        std::cout << "What car type would you want? ";
        std::string type;

        while (true) {
            std::cin >> type;

            if (type == "convertible" || type =="Convertible" || type =="CONVERTIBLE") {
                carType = "convertible";
                carTypeCost = 5000;
            }
            else if (type == "sedan" || type =="Sedan" || type =="SEDAN") {
                carType = "sedan";
                carTypeCost = 9000;
            }
            else if (type == "jeep" || type =="Jeep" || type =="JEEP") {
                carType = "jeep";
                carTypeCost = 8000;
            }
            else if (type == "sport" || type =="Sport" || type =="SPORT") {
                carType = "sport";
                carTypeCost = 10000;
            }
            else if (type == "luxury" || type =="Luxury" || type =="LUXURY") {
                carType = "luxury";
                carTypeCost = 20000;
            }
            else if (type == "super" || type =="Super" || type =="SUPER") {
                carType = "super";
                carTypeCost = 25000;
            }
            else
                continue;

            break;
        }
    }

    void getDataType() {
        std::cout << "Your car type is: " << carType << std::endl;
        std::cout << "Cost of type: " << carTypeCost << std::endl;
    }

    int getCarTypeCost() const {return carTypeCost;}

private:
    std::string carType;
    int carTypeCost;
};

class Wheels {
public:
    Wheels() : wheelType(""), wheelPrice(0){};

    void buildYourWheel() {
        std::cout << "What type of wheels would you want? ";
        std::string wheelTypeTemp;

        while (true) {
            std::cin >> wheelTypeTemp;

            if (wheelTypeTemp == "Off road" || wheelTypeTemp == "Offroad" || wheelTypeTemp == "OffRoad" || wheelTypeTemp == "OFFROAD" || wheelTypeTemp == "OFF ROAD") {
                wheelType = wheelTypeTemp;
                wheelPrice = 500 * 4;
                break;
            }
            else if (wheelTypeTemp == "Luxury" || wheelTypeTemp == "luxury" || wheelTypeTemp == "LUXURY") {
                wheelType = wheelTypeTemp;
                wheelPrice = 1300 * 4;
                break;
            }
            else if (wheelTypeTemp == "Low Rider" || wheelTypeTemp == "low rider" || wheelTypeTemp == "LOW RIDER" || wheelTypeTemp == "LOWRIDER" || wheelTypeTemp == "lowrider") {
                wheelType = wheelTypeTemp;
                wheelPrice = 1100 * 4;
                break;
            }
            else if (wheelTypeTemp == "Sport" || wheelTypeTemp == "sport" || wheelTypeTemp == "SPORT") {
                wheelType = wheelTypeTemp;
                wheelPrice = 1000 * 4;
                break;
            }
        }
    }

    void getDataWheel() {
        std::cout << "Wheel type: " << wheelType << std::endl;
        std::cout << "Wheel cost: " << wheelPrice << std::endl;
    }

    int getWheelsPrice() const {return wheelPrice;}
private:
    std::string wheelType;
    int wheelPrice;
};

class Car : public Engine, public Type, public Wheels  {
public:
    Car()  {
        std::cout << "Build you car: " << std::endl;
    }
};

int main() {
    Car temp;
    temp.buildYourEngine();
    temp.buildYourType();
    temp.buildYourWheel();

    std::cout << "Total cost: " << temp.getWheelsPrice() + temp.getCarTypeCost() + temp.getEngineCost() << std::endl;


}
