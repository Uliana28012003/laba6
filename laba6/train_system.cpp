#include "train_system.h"
#include <fstream>

// ����� ���������� ������ � �������
void TrainSystem::addTrain(int number, const string& destination, const string& time) {
    // �������� ������ ������ � ���������� ��� � ������ �������
    Train newTrain = { number, destination, time };
    trains.push_back(newTrain);
}

// ����� ������ ���������� � ���� �������
void TrainSystem::displayAllTrains() const {
    // ������� ���� ������� � ������� � ����� ���������� � ������
    for (const auto& train : trains) {
        cout << "����� ������: " << train.trainNumber << "\t������� ����������: " << train.destinationStation
            << "\t����� �����������: " << train.departureTime << endl;
    }
}

// ����� ������ ���������� � ������ �� ��� ������
void TrainSystem::displayTrainByNumber(int number) const {
    // ����� ������ �� ������ � ����� ���������� (���� ������)
    for (const auto& train : trains) {
        if (train.trainNumber == number) {
            cout << "����� ������: " << train.trainNumber << "\t������� ����������: " << train.destinationStation
                << "\t����� �����������: " << train.departureTime << endl;
            return;
        }
    }
    // ����� ���������, ���� ����� �� ������
    cout << "����� � ������� " << number << " �� ������." << endl;
}

// ����� ������ ���������� � ������� �� ��������� �������
void TrainSystem::displayTrainsBeforeStation(const string& station) const {
    // ������� ������� � ����� ���������� � ���, ������� ���� �� ��������� �������
    for (const auto& train : trains) {
        if (train.destinationStation < station) {
            cout << "����� ������: " << train.trainNumber << "\t������� ����������: " << train.destinationStation
                << "\t����� �����������: " << train.departureTime << endl;
        }
    }
}

// ����� �������� ������� �� �����
void TrainSystem::loadTrainsFromFile(const string& filename) {
    // �������� �����
    ifstream file(filename);
    if (file.is_open()) {
        int number;
        string destination, time;
        // ������ ������ �� ����� � ���������� ������� � �������
        while (file >> number >> destination >> time) {
            addTrain(number, destination, time);
        }
        // ����� ��������� �� �������� ��������
        cout << "������ ������� ��������� �� �����.\n";
    }
    else {
        // ����� ��������� �� ������ ��� �������� �����
        cout << "������ ��� �������� �����.\n";
    }
}
