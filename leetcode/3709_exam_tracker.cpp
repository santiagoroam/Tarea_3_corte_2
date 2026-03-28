#include <iostream>
#include <vector>
using namespace std;

class ExamTracker {
private:
    vector<int> times;
    vector<long long> prefix;

public:
    ExamTracker() {
    }

    void record(int time, int score) {
        times.push_back(time);

        if (prefix.size() == 0) {
            prefix.push_back(score);
        } else {
            prefix.push_back(prefix.back() + score);
        }
    }

    int buscarInicio(int startTime) {
        for (int i = 0; i < times.size(); i++) {
            if (times[i] >= startTime) {
                return i;
            }
        }
        return -1;
    }

    int buscarFin(int endTime) {
        for (int i = times.size() - 1; i >= 0; i--) {
            if (times[i] <= endTime) {
                return i;
            }
        }
        return -1;
    }

    long long totalScore(int startTime, int endTime) {
        int inicio = buscarInicio(startTime);
        int fin = buscarFin(endTime);

        if (inicio == -1 || fin == -1 || inicio > fin) {
            return 0;
        }

        if (inicio == 0) {
            return prefix[fin];
        } else {
            return prefix[fin] - prefix[inicio - 1];
        }
    }
};

int main() {
    ExamTracker exam;

    exam.record(1, 98);
    cout << exam.totalScore(1, 1) << endl;

    exam.record(5, 99);
    cout << exam.totalScore(1, 3) << endl;
    cout << exam.totalScore(1, 5) << endl;
    cout << exam.totalScore(3, 4) << endl;
    cout << exam.totalScore(2, 5) << endl;

    return 0;
}