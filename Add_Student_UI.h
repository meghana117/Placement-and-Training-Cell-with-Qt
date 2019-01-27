#ifndef ADD_STUDENT_UI_H
#define ADD_STUDENT_UI_H

#include <QWidget>
#include<QCalendarWidget>
#include<QRegExp>
#include<QValidator>
#include<QComboBox>
#include<QLineEdit>
#include<QLabel>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDateEdit>
#include<QPushButton>
#include<QDoubleSpinBox>
#include<QSpinBox>
#include<QMessageBox>
#include <QDebug>
#include "Db_Class.h"
#include "Student.h"



class Add_Student_UI : public QWidget
{
    Q_OBJECT
public:
    explicit Add_Student_UI(QWidget *parent = nullptr);
    ~Add_Student_UI();



private:
    QLabel *name,*usn,*dob,*email,*dept,*contact,*backlog,*cgpa,*error,*ten,*twelve;
    QDoubleSpinBox *cgpa_edit,*ten_edit,*twelve_edit;
    QComboBox *dept_edit;
    QCalendarWidget *m_cal;
        QDate m_date;
    QDateEdit *DOB;
    QSpinBox *backlog_edit;
    QPushButton *add,*cancel,*m_calButton;
    QLineEdit *name_edit,*usn_edit,*pass_edit,*email_edit,*contact_edit;
    QVBoxLayout *vb1,*vb2,*vb3;
    QHBoxLayout *hb1,*hb2,*hb3,*hb4,*hb5,*hb6,*hb7,*hb8,*hb9,*hb10,*hb11,*hb12;
    Db_Class db;




signals:

public slots:
    void onDateSelected(QDate);
        void add_stud();
        void toUpper(QString);
};

#endif // ADD_STUDENT_UI_H
