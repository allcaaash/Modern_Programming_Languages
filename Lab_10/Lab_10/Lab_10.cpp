#include <iostream>
#include <string>
#include "ForwardList.h"

struct Bus {
    int number;
    std::string driver;
    int route;

    friend std::ostream& operator<<(std::ostream& os, const Bus& bus) {
        os << "Bus " << bus.number << " (Driver: " << bus.driver
            << ", Route: " << bus.route << ")";
        return os;
    }

    bool operator!=(const Bus& other) const {
        return number != other.number;
    }

    bool operator==(const Bus& other) const {
        return number == other.number;
    }
};

int main()
{
    ForwardList<Bus> inDepot;
    ForwardList<Bus> onRoute;

    // Начальное формирование данных
    inDepot.push_back({ 101, "Ivanov A.I.", 12 });
    inDepot.push_back({ 202, "Petrov B.V.", 5 });
    inDepot.push_back({ 303, "Sidorov V.G.", 8 });

    std::cout << "In the depot: ";
    inDepot.print();

    Bus* bus = inDepot.findData({ 202, "", 0 });
    if (bus) {
        onRoute.push_back(*bus);
        inDepot.remove(*bus);
        std::cout << "Bus 202 on the route." << std::endl;
    }

    std::cout << "In the depot: ";
    inDepot.print();
    std::cout << "On the route: ";
    onRoute.print();
}