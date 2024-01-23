#include "train_system.h"
#include "test.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }

private:
    steady_clock::time_point start;
};

int main() {
    {
        LogDuration input;
        setlocale(LC_ALL, "Russian");
        if (runTests()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cout << "����-����� �� ��������!" << endl;
        }

        // ������� ������ TrainSystem
        TrainSystem trainSystem;
        int choice;

        do {
            cout << "\n����:" << endl;
            cout << "1. �������� �����\n";
            cout << "2. ������� ���������� � ���� �������\n";
            cout << "3. ������� ���������� � ������ �� ������\n";
            cout << "4. ������� ���������� � ������� �� ��������� �������\n";
            cout << "5. ��������� ������ �� �����\n";
            cout << "0. �����\n";
            cout << "������� ��� �����: ";

            // ��������� ����� ������������
            cin >> choice;

            // ������������ ����� ������������
            switch (choice) {
            case 1: {
                // ���������� ������ ������
                int number;
                string destination, time;
                cout << "������� ����� ������: ";
                cin >> number;
                cout << "������� ������� ����������: ";
                cin >> destination;
                cout << "������� ����� �����������: ";
                cin >> time;
                trainSystem.addTrain(number, destination, time);
                break;
            }
            case 2:
                // ����� ���������� � ���� �������
                cout << "\n���������� � ���� �������:" << endl;
                trainSystem.displayAllTrains();
                break;
            case 3: {
                // ����� ���������� � ������ �� ������
                int number;
                cout << "������� ����� ������: ";
                cin >> number;
                cout << "\n���������� � ������ �� ������:" << endl;
                trainSystem.displayTrainByNumber(number);
                break;
            }
            case 4: {
                // ����� ���������� � ������� �� ��������� �������
                string station;
                cout << "������� ������� ����������: ";
                cin >> station;
                cout << "\n���������� � ������� �� ��������� �������:" << endl;
                trainSystem.displayTrainsBeforeStation(station);
                break;
            }
            case 5: {
                // �������� ������� �� �����
                string filename;
                cout << "������� ��� ����� � ������� � �������: ";
                cin >> filename;
                trainSystem.loadTrainsFromFile(filename);
                break;
            }
            case 0:
                // ����� �� ���������
                cout << "����� �� ���������.\n";
                break;
            default:
                // ������������ ����� ������������
                cout << "�������� �����. ���������� �����.\n";
            }

        } while (choice != 0);

        return 0;
    }
}
