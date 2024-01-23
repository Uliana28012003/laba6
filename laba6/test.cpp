#include "train_system.h"
#include "test.h"
#include <cassert>

// ������������ ������ addTrain � ������ TrainSystem
void testAddTrain() {
    // �������� ������� TrainSystem
    TrainSystem trainSystem;

    // ���������� ������ ������ � �������� ������� �������
    trainSystem.addTrain(1, "StationA", "10:00");
    assert(trainSystem.getTrains().size() == 1);

    // ���������� ��� ���� ������� � �������� ������� �������
    trainSystem.addTrain(2, "StationB", "12:30");
    trainSystem.addTrain(3, "StationC", "14:45");
    assert(trainSystem.getTrains().size() == 3);
}

// ������ ���� ������
bool runTests() {
    // ������ ����� ���������� ������
    testAddTrain();

    return true;
}
