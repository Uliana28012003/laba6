/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Train {
    int trainNumber;
    std::string destinationStation;
    std::string departureTime;
};

class TrainSystem {
private:
    std::vector<Train> trains;

public:
    void addTrain(int number, const std::string& destination, const std::string& time) {
        Train newTrain = { number, destination, time };
        trains.push_back(newTrain);
    }

    void displayAllTrains() const {
        for (const auto& train : trains) {
            std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                << "\tВремя отправления: " << train.departureTime << std::endl;
        }
    }

    void displayTrainByNumber(int number) const {
        for (const auto& train : trains) {
            if (train.trainNumber == number) {
                std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                    << "\tВремя отправления: " << train.departureTime << std::endl;
                return;
            }
        }
        std::cout << "Поезд с номером " << number << " не найден." << std::endl;
    }

    void displayTrainsBeforeStation(const std::string& station) const {
        for (const auto& train : trains) {
            if (train.destinationStation < station) {
                std::cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                    << "\tВремя отправления: " << train.departureTime << std::endl;
            }
        }
    }

    void loadTrainsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            int number;
            std::string destination, time;
            while (file >> number >> destination >> time) {
                addTrain(number, destination, time);
            }
            std::cout << "Данные успешно загружены из файла.\n";
        }
        else {
            std::cout << "Ошибка при открытии файла.\n";
        }
    }
};

int main() {
    TrainSystem trainSystem;
    int choice;

    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Добавить поезд\n";
        std::cout << "2. Вывести информацию о всех поездах\n";
        std::cout << "3. Вывести информацию о поезде по номеру\n";
        std::cout << "4. Вывести информацию о поездах до указанной станции\n";
        std::cout << "5. Загрузить поезда из файла\n";
        std::cout << "0. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int number;
            std::string destination, time;
            std::cout << "Введите номер поезда: ";
            std::cin >> number;
            std::cout << "Введите станцию назначения: ";
            std::cin >> destination;
            std::cout << "Введите время отправления: ";
            std::cin >> time;
            trainSystem.addTrain(number, destination, time);
            break;
        }
        case 2:
            std::cout << "\nИнформация о всех поездах:" << std::endl;
            trainSystem.displayAllTrains();
            break;
        case 3: {
            int number;
            std::cout << "Введите номер поезда: ";
            std::cin >> number;
            std::cout << "\nИнформация о поезде по номеру:" << std::endl;
            trainSystem.displayTrainByNumber(number);
            break;
        }
        case 4: {
            std::string station;
            std::cout << "Введите станцию назначения: ";
            std::cin >> station;
            std::cout << "\nИнформация о поездах до указанной станции:" << std::endl;
            trainSystem.displayTrainsBeforeStation(station);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Введите имя файла с данными о поездах: ";
            std::cin >> filename;
            trainSystem.loadTrainsFromFile(filename);
            break;
        }
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}*/
