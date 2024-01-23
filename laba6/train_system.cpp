#include "train_system.h"
#include <fstream>

// Метод добавления поезда в систему
void TrainSystem::addTrain(int number, const string& destination, const string& time) {
    // Создание нового поезда и добавление его в вектор поездов
    Train newTrain = { number, destination, time };
    trains.push_back(newTrain);
}

// Метод вывода информации о всех поездах
void TrainSystem::displayAllTrains() const {
    // Перебор всех поездов в системе и вывод информации о каждом
    for (const auto& train : trains) {
        cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
            << "\tВремя отправления: " << train.departureTime << endl;
    }
}

// Метод вывода информации о поезде по его номеру
void TrainSystem::displayTrainByNumber(int number) const {
    // Поиск поезда по номеру и вывод информации (если найден)
    for (const auto& train : trains) {
        if (train.trainNumber == number) {
            cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                << "\tВремя отправления: " << train.departureTime << endl;
            return;
        }
    }
    // Вывод сообщения, если поезд не найден
    cout << "Поезд с номером " << number << " не найден." << endl;
}

// Метод вывода информации о поездах до указанной станции
void TrainSystem::displayTrainsBeforeStation(const string& station) const {
    // Перебор поездов и вывод информации о тех, которые идут до указанной станции
    for (const auto& train : trains) {
        if (train.destinationStation < station) {
            cout << "Номер поезда: " << train.trainNumber << "\tСтанция назначения: " << train.destinationStation
                << "\tВремя отправления: " << train.departureTime << endl;
        }
    }
}

// Метод загрузки поездов из файла
void TrainSystem::loadTrainsFromFile(const string& filename) {
    // Открытие файла
    ifstream file(filename);
    if (file.is_open()) {
        int number;
        string destination, time;
        // Чтение данных из файла и добавление поездов в систему
        while (file >> number >> destination >> time) {
            addTrain(number, destination, time);
        }
        // Вывод сообщения об успешной загрузке
        cout << "Данные успешно загружены из файла.\n";
    }
    else {
        // Вывод сообщения об ошибке при открытии файла
        cout << "Ошибка при открытии файла.\n";
    }
}
