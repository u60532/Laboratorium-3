
/* ****************************************************************************** 
   **********************************Zadanie 1*********************************** 
   ****************************************************************************** */


/* <===+Znacznik do zadania 1


#include <iostream> 
#include <cmath>     
// Definicja stałej M_PI na wypadek

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Klasa `RobotStary` reprezentuje starszy system sterowania robota, używający współrzędnych prostokątnych.
// Wirtualna metoda, która przyjmuje współrzędne prostokątne (x, y)
// i wyświetla komunikat o przemieszczaniu robota.
class RobotStary {
public:
    virtual void idzDo(double x, double y) {

        std::cout << "RobotStary idzie do punktu (" << x << ", " << y << ") w układzie prostokątnym.\n";
    }
};

// Klasa `RobotNowy` reprezentuje nowoczesny system sterowania robota, używający współrzędnych biegunowych.
// Metoda przyjmuje współrzędne biegunowe (kąt w stopniach i odległość)
// i wyświetla komunikat o przemieszczaniu robota.
class RobotNowy {
public:
    void idzDo(double kat, double odleglosc) {

        std::cout << "RobotNowy idzie do punktu (" << kat << "°, " << odleglosc << ") w układzie biegunowym.\n";
    }
};

// Klasa `AdapterRobota` jest adapterem, który umożliwia nowemu systemowi współpracę
// z kodem, który korzysta ze starego systemu współrzędnych.

class AdapterRobota : public RobotStary {
private:
    // Wskaźnik do obiektu klasy `RobotNowy`, umożliwia interakcję z nowym systemem sterowania.
    RobotNowy* robotNowy;
public:
    // Konstruktor klasy `AdapterRobota` inicjalizuje wskaźnik `robotNowy` wskazanym obiektem klasy `RobotNowy`.
    AdapterRobota(RobotNowy* nowyRobot) : robotNowy(nowyRobot) {}
    // Nadpisanie metody `idzDo` z klasy `RobotStary` w celu przekształcenia współrzędnych.
    void idzDo(double x, double y) override {
        // Obliczenie odległości w układzie biegunowym na podstawie współrzędnych prostokątnych.
        double odleglosc = std::sqrt(x * x + y * y);
        // Obliczenie kąta w stopniach na podstawie współrzędnych prostokątnych.
        double kat = std::atan2(y, x) * (180.0 / M_PI);
        // Wywołanie metody `idzDo` obiektu klasy `RobotNowy` z przeliczonymi wartościami.
        robotNowy->idzDo(kat, odleglosc);

    }
};


int main() {
    // Tworzenie obiektu klasy `RobotNowy`.
    RobotNowy nowyRobot;
    // Tworzenie adaptera, który używa obiektu `RobotNowy`.
    AdapterRobota adapter(&nowyRobot);
    // Wywołanie metody `idzDo` adaptera, która konwertuje współrzędne prostokątne (3, 4)
    // na biegunowe i przekazuje je do metody `idzDo` klasy `RobotNowy`.

    adapter.idzDo(3, 4);
    return 0;
}
/**/


/* ******************************************************************************
   **********************************Zadanie 2***********************************
   ****************************************************************************** */

/* <===+Znacznik do zadania 2


#include <iostream>  // Nagłówek umożliwiający obsługę wejścia/wyjścia
#include <memory>    // Nagłówek umożliwiający korzystanie z inteligentnych wskaźników

// Klasa bazowa
class Robot {
public:
    virtual void operacja() {
        // Wirtualna metoda, która wypisuje komunikat o podstawowej funkcji robota
        std::cout << "Robot porusza sie.\n";
    }
    virtual ~Robot() = default; 
};

// Klasa konkretna
class RobotPodstawowy : public Robot {
public:
    void operacja() override {
        // Nadpisanie metody operacja() z klasy bazowej
        std::cout << "RobotPodstawowy porusza sie.\n";
    }
};

// Klasa abstrakcyjna Dekorator
class RobotDekorator : public Robot {
protected:
    std::shared_ptr<Robot> robot; 
public:
    RobotDekorator(std::shared_ptr<Robot> r) : robot(r) {
    }

    virtual void operacja() override {
        robot->operacja();
    }
};

// Dekorator: Kamera
class RobotZKamera : public RobotDekorator {
public:
    RobotZKamera(std::shared_ptr<Robot> r) : RobotDekorator(r) {
    }

    void operacja() override {
        RobotDekorator::operacja();
        std::cout << "Robot ma kamere.\n";
    }
};

// Dekorator: Czujnik temperatury
class RobotZCzujnikiemTemperatury : public RobotDekorator {
public:
    RobotZCzujnikiemTemperatury(std::shared_ptr<Robot> r) : RobotDekorator(r) {
    }

    void operacja() override {
        RobotDekorator::operacja();
        std::cout << "Robot ma czujnik temperatury.\n";
    }
};

// Dekorator: Dźwięk
class RobotZDzwiekiem : public RobotDekorator {
public:
    RobotZDzwiekiem(std::shared_ptr<Robot> r) : RobotDekorator(r) {
    }

    void operacja() override {
        RobotDekorator::operacja();
        std::cout << "Robot ma system dzwiekowy.\n";
    }
};

int main() {
    // Stworzenie podstawowego robota
    auto robotPodstawowy = std::make_shared<RobotPodstawowy>();

    // Dodanie kamery do robota
    auto robotZKamera = std::make_shared<RobotZKamera>(robotPodstawowy);

    // Dodanie czujnika temperatury do robota z kamera
    auto robotZCzujnikiemTemperatury = std::make_shared<RobotZCzujnikiemTemperatury>(robotZKamera);

    // Dodanie systemu dźwiękowego do robota z kamerą i czujnikiem temperatury
    auto robotZDzwiekiem = std::make_shared<RobotZDzwiekiem>(robotZCzujnikiemTemperatury);

    // Test: Wywołujemy metodę operacja() na najbardziej udekorowanym robocie
    robotZDzwiekiem->operacja();

    return 0;
}
/**/