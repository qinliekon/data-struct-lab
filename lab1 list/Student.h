#include <cstring>
#include <iostream>

class Student
{
public:
    std::string num;
    std::string name;
    double score;
public:
    Student() : num(""), name(""), score(0.0) {}

    Student(const std::string& num, const std::string& name, double score)
            : num(num), name(name), score(score) {}
    ~Student(){}

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "ѧ��: " << s.num << ", ����: " << s.name << ", ����: " << s.score;
        return os;
    }
};
