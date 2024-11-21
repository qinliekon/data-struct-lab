#include <iostream>
#include "SqQueue.h"
#include "LiQueue.h"
using namespace std;


class Hospitalsq {
private:
    SqQueue<string> queue;
public:
    void PatientArrives(string patientName) {
        queue.enQueue(patientName);
    }

    void NurseCallsNextPatient() {
        string patientName;
        if (queue.deQueue(patientName)) {
            cout << "���� " << patientName << " �������Ҿ��" << endl;
        } else {
            cout << "û�л��ߵȴ����" << endl;
        }
    }

    void DoctorEndsShift() {
            cout << "ҽ���°࣬�������»������վ��" << endl;
    }
};

class HospitalLi {
private:
    LinkQueue<string> queue;
public:
    void PatientArrives(string patientName) {
        queue.enQueue(patientName);
    }
    void NurseCallsNextPatient() {
        string patientName;
        if (queue.deQueue(patientName)) {
            cout << "���� " << patientName << " �������Ҿ��" << endl;
        } else {
            cout << "û�л��ߵȴ����" << endl;
        }
    }
    void DoctorEndsShift() {
        if (!queue.QueueEmpty()) {
            cout << "ҽ���°࣬�������»������վ��" << endl;
        }
    }
};

int main() {
    int c;
    cout << "��ѡ�����ݽṹ����1.ѭ������ 2.��ʽ���У�" <<std::endl;
    cin >> c;
    while (true) {
        if (c == 1) {    Hospitalsq hospital;
            hospital.PatientArrives("����A");
            hospital.PatientArrives("����B");
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.DoctorEndsShift();
            return 0;
        } else if (c == 2) {    HospitalLi hospital;
            hospital.PatientArrives("����A");
            hospital.PatientArrives("����B");
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.DoctorEndsShift();
            return 0;
        } else {
            cout << "���������������������" << std::endl;
            continue;
        }
        break;
    }

}