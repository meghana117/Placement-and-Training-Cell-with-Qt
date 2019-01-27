#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "add_papers.h"
#include "Add_Student_UI.h"
#include "Search_Student.h"
#include "Training.h"
#include "Placement.h"
#include "company.h"
#include "Placed.h"
#include "Contacts.h"
class Training;
class Welcome : public QWidget
{
    Q_OBJECT
public:
    explicit Welcome(QWidget *parent = nullptr);
     ~Welcome();

private:
    QPushButton *student,*papers,*training,*placement,*companies,*sort,*search,*placed,*contact,*update;
    QLabel *welcome;
    QPushButton *Logout;
    QVBoxLayout *vb1,*vb2,*vb3,*vb4,*vb5;
    QHBoxLayout *hb1,*hb2,*hb3,*hb4,*hb5;
    Add_Student_UI add_student;
    Search_Student search_stud;
    Training train;
    Placement place;
    Company company;
    Placed placed_ui;
    Add_Papers paper;
    Contacts contct;

signals:

public slots:
    void add_stud();
    void search_student();
    void training_details();
    void placement_details();
    void companies_visited();
    void placed_info();
    void placement_papers();
    void contact_details();
};

#endif // WELCOME_H
