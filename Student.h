#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student();
    QString usn,password,name,email,dept,contact,dob;
    float ten,twelve,cgpa;
    int offer,backlogs;

    ~Student();
};

#endif // STUDENT_H
