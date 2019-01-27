#ifndef SEARCH_STUDENT_H
#define SEARCH_STUDENT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QComboBox>
#include <QCloseEvent>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QRegExpValidator>
#include<QMessageBox>
#include <QValidator>
#include <QGridLayout>
#include "Db_Class.h"
#include "Student.h"

class Search_Student : public QWidget
{
    Q_OBJECT
public:
    explicit Search_Student(QWidget *parent = nullptr);
    ~Search_Student();

private:

    void initialize_search();
    void initialize_update();
    QWidget *search_widget,*update_widget;
    QLabel *USN,*error;
    QLineEdit *usn_edit;
    QVBoxLayout *vbox1,*vbox2;
    QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4;
    QPushButton *search,*cancel;

    QLabel *sname,*susn,*sdob,*semail,*sdept,*scontact,*sbacklog,*scgpa,*serror,*sten,*stwelve,*soffer;
    QLabel *ssname,*ssusn,*ssdob,*ssemail,*ssdept,*sscontact,*ssbacklog,*sscgpa,*sserror,*ssten,*sstwelve,*ssoffer;
    QVBoxLayout *vbx1,*vbx2;
    QHBoxLayout *hbx1,*hbx2,*hbx3,*hbx4,*hbx5,*hbx6,*hbx7,*hbx8,*hbx9,*hbx10,*hbx11,*hbx12,*hb13;
    QPushButton *update,*del;
    QGridLayout *grid;



    QLabel *name,*usn,*dob,*email,*dept,*contact,*backlog,*cgpa,*error1,*ten,*twelve;
    QDoubleSpinBox *cgpa_edit,*ten_edit,*twelve_edit;
    QComboBox *dept_edit;
    QCalendarWidget *m_cal;
    QDate m_date;
    QDateEdit *DOB;
    QSpinBox *backlog_edit;
    QPushButton *update1,*m_calButton;
    QLineEdit *name_edit,*usnedit,*pass_edit,*email_edit,*contact_edit;
    QVBoxLayout *vb1,*vb2;
    QHBoxLayout *hb1,*hb2,*hb3,*hb4,*hb5,*hb6,*hb7,*hb8,*hb9,*hb10,*hb11,*hb12;
    QPushButton *cancel2;
    int flag=0,flag1=0;


    Db_Class db;
    Student student;
    QMessageBox msgBox;

    void closeEvent(QCloseEvent *);

signals:

public slots:

    void search_action();
    void update_action();
    void update_stud();
    void onDateSelected(QDate date);
    void close_update();
    void delete_stud();
    void toUpper(QString);

};

#endif // SEARCH_STUDENT_H
