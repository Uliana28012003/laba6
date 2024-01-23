#ifndef TRAIN_SYSTEM_H
#define TRAIN_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���������, �������������� ���������� � ������
struct Train {
    int trainNumber;
    string destinationStation;
    string departureTime;
};

// �����, �������������� ������� ���������� ��������
class TrainSystem {
private:
    // ������ ��� �������� �������
    vector<Train> trains;

public:
    // ������ ��� ���������� ��������
    void addTrain(int number, const string& destination, const string& time);
    void displayAllTrains() const;
    void displayTrainByNumber(int number) const;
    void displayTrainsBeforeStation(const string& station) const;
    void loadTrainsFromFile(const string& filename);

    // ����� ��� ��������� ���� ������� � �������
    const vector<Train>& getTrains() const {
        return trains;
    }
};

#endif
