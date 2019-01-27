#include "Welcome.h"

Welcome::Welcome(QWidget *parent) : QWidget(parent)
{

    this->setGeometry(700,300,500,500);
    student=new QPushButton("Add Students");
    update=new QPushButton("Update Student Info");
    papers=new QPushButton("Placement Papers");
    training=new QPushButton("Training Schedule");
    placement=new QPushButton("Placement schedule");
    companies=new QPushButton("Companies visited");
    sort=new QPushButton("Sort/Select Students");
    search=new QPushButton("Search Student");
    placed=new QPushButton("Placed Students");
    contact=new QPushButton("Contact");
    Logout=new QPushButton("Logout");

    vb1=new QVBoxLayout();
    hb1=new QHBoxLayout();
    hb1->addWidget(student);
    hb1->addWidget(update);
    hb1->addWidget(search);
    vb1->addLayout(hb1);



    vb2=new QVBoxLayout();
    hb2=new QHBoxLayout();
    hb2->addWidget(papers);
    hb2->addWidget(training);
    hb2->addWidget(placement);
    vb2->addLayout(hb2);

    vb3=new QVBoxLayout();
    hb3=new QHBoxLayout();
    hb3->addWidget(companies);
    hb3->addWidget(sort);
    hb3->addWidget(placed);
    vb3->addLayout(hb3);

    vb4=new QVBoxLayout();
    hb4=new QHBoxLayout();
    hb4->addWidget(contact);
    hb4->addWidget(Logout);
    vb4->addLayout(hb4);

    vb5=new QVBoxLayout();
    vb5->addLayout(vb1);
    vb5->addLayout(vb2);
    vb5->addLayout(vb3);
    vb5->addLayout(vb4);

    this->setLayout(vb5);

    connect(student,SIGNAL(clicked(bool)),this,SLOT(add_stud()));
    this->setStyleSheet("QPushButton:hovered{color:white;}");
    connect(search,SIGNAL(clicked(bool)),this,SLOT(search_student()));
    connect(training,SIGNAL(clicked(bool)),this,SLOT(training_details()));
    connect(placement,SIGNAL(clicked(bool)),this,SLOT(placement_details()));
    connect(companies,SIGNAL(clicked(bool)),this,SLOT(companies_visited()));
    connect(placed,SIGNAL(clicked(bool)),this,SLOT(placed_info()));
    connect(papers,SIGNAL(clicked(bool)),this,SLOT(placement_papers()));
    connect(contact,SIGNAL(clicked(bool)),this,SLOT(contact_details()));

}

void Welcome::add_stud()
{
    this->setEnabled(false);
//    this->close();
    add_student.show();
    this->setEnabled(true);
}

void Welcome::search_student()
{
    search_stud.show();
}
void Welcome::training_details()
{
    train.show();
}
void Welcome::placement_details()
{
    place.show();
}
void Welcome::companies_visited()
{
    company.show();
}
void Welcome::placed_info()
{

    placed_ui.show();
}

void Welcome::placement_papers()
{
    paper.show();
}
void Welcome::contact_details()
{
    contct.show();
}
Welcome::~Welcome()
{

}
