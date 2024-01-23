#include "train_system.h"
#include "test.h"
#include <cassert>

// Тестирование метода addTrain в классе TrainSystem
void testAddTrain() {
    // Создание объекта TrainSystem
    TrainSystem trainSystem;

    // Добавление одного поезда и проверка размера вектора
    trainSystem.addTrain(1, "StationA", "10:00");
    assert(trainSystem.getTrains().size() == 1);

    // Добавление еще двух поездов и проверка размера вектора
    trainSystem.addTrain(2, "StationB", "12:30");
    trainSystem.addTrain(3, "StationC", "14:45");
    assert(trainSystem.getTrains().size() == 3);
}

// Запуск всех тестов
bool runTests() {
    // Запуск теста добавления поезда
    testAddTrain();

    return true;
}
