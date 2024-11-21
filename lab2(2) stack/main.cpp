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
            cout << "患者 " << patientName << " 进入诊室就诊。" << endl;
        } else {
            cout << "没有患者等待就诊。" << endl;
        }
    }

    void DoctorEndsShift() {
            cout << "医生下班，提醒余下患者明日就诊。" << endl;
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
            cout << "患者 " << patientName << " 进入诊室就诊。" << endl;
        } else {
            cout << "没有患者等待就诊。" << endl;
        }
    }
    void DoctorEndsShift() {
        if (!queue.QueueEmpty()) {
            cout << "医生下班，提醒余下患者明日就诊。" << endl;
        }
    }
};

int main() {
    int c;
    cout << "请选择数据结构：（1.循环队列 2.链式队列）" <<std::endl;
    cin >> c;
    while (true) {
        if (c == 1) {    Hospitalsq hospital;
            hospital.PatientArrives("患者A");
            hospital.PatientArrives("患者B");
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.DoctorEndsShift();
            return 0;
        } else if (c == 2) {    HospitalLi hospital;
            hospital.PatientArrives("患者A");
            hospital.PatientArrives("患者B");
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.NurseCallsNextPatient();
            _sleep(1000);
            hospital.DoctorEndsShift();
            return 0;
        } else {
            cout << "错误的索引，请重新输入" << std::endl;
            continue;
        }
        break;
    }

}