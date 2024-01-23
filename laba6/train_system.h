#ifndef TRAIN_SYSTEM_H
#define TRAIN_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура, представляющая информацию о поезде
struct Train {
    int trainNumber;
    string destinationStation;
    string departureTime;
};

// Класс, представляющий систему управления поездами
class TrainSystem {
private:
    // Вектор для хранения поездов
    vector<Train> trains;

public:
    // Методы для управления поездами
    void addTrain(int number, const string& destination, const string& time);
    void displayAllTrains() const;
    void displayTrainByNumber(int number) const;
    void displayTrainsBeforeStation(const string& station) const;
    void loadTrainsFromFile(const string& filename);

    // Метод для получения всех поездов в системе
    const vector<Train>& getTrains() const {
        return trains;
    }
};

#endif
