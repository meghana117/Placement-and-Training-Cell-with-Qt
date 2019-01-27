#include "Contacts.h"

Contacts::Contacts(QWidget *parent) : QWidget(parent)
{

    add=new QPushButton("Add");
    cancel=new QPushButton("Cancel");

    vb1=new QVBoxLayout();
    vb2=new QVBoxLayout();
    hb1=new QHBoxLayout();
    hb2=new QHBoxLayout();
    new_widget=new QWidget();
    vb1->addWidget(new_widget);
    vb1->addWidget(add);
    vb1->addWidget(cancel);

    this->setUpdatesEnabled(true);

    initialize();
    initialize_add();

    this->setLayout(vb1);

    connect(add,SIGNAL(clicked(bool)),this,SLOT(add_contact()));
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(close()));

}
void Contacts::initialize()
{
    int count=db.getContactCount();
    if(count>0)
    {
        if (vb1 != 0)
        {
            QLayoutItem *item;
            while ((item = vb1->takeAt(0)) != 0)
            {
                if(auto wid=item->widget())
                    wid->deleteLater();
                else
                    delete item;
//                qDebug()<<vb1->count();
            }
            delete vb1;
        }
        QVBoxLayout *vb1=new QVBoxLayout();
        QWidget *new_widget=new QWidget();
        QPushButton *ad=new QPushButton("Add");
        QPushButton *cance=new QPushButton("Cancel");
        Contact_Object contacts[count];
        db.getContactDetail(contacts);
        QVBoxLayout *vbx1=new QVBoxLayout();
        QHBoxLayout *hbx1[count];
        QHBoxLayout *hbx2[count];
        QHBoxLayout *hbx3[count];
        QHBoxLayout *hbx4[count];
        QLabel *name[count];
        QLabel *designation[count];
        QLabel *contact_label[count];
        QLabel *contact[count];
        QLabel *email_label[count];
        QLabel *email[count];


        connect(ad,SIGNAL(clicked(bool)),this,SLOT(add_contact()));
        connect(cance,SIGNAL(clicked(bool)),this,SLOT(close()));

        QSignalMapper *update_mapper=new QSignalMapper(this);
        connect(update_mapper,SIGNAL(mapped(int)),this,SLOT(update_contact(int)));

        QSignalMapper *delete_mapper=new QSignalMapper(this);
        connect(delete_mapper,SIGNAL(mapped(int)),this,SLOT(delete_contact(int)));
        QPushButton *update_buttons[count];
        QPushButton *delete_buttons[count];
        for(int i=0;i<count;i++)
        {
            hbx1[i]=new QHBoxLayout();
            hbx2[i]=new QHBoxLayout();
            hbx3[i]=new QHBoxLayout();
            hbx4[i]=new QHBoxLayout();
            name[i]=new QLabel();
            designation[i]=new QLabel();
            contact_label[i]=new QLabel();
            contact[i]=new QLabel();
            email[i]=new QLabel();
            email_label[i]=new QLabel();
            name[i]->setText(contacts[i].name);
            designation[i]->setText(contacts[i].designation);
            contact_label[i]->setText("Contact:");
            contact[i]->setText(contacts[i].contact1+contacts[i].contact2);
            email_label[i]->setText("Email:");
            email[i]->setText(contacts[i].email);
            hbx1[i]->addWidget(name[i]);
            hbx2[i]->addWidget(designation[i]);
            hbx3[i]->addWidget(contact_label[i]);
            hbx3[i]->addWidget(contact[i]);
            hbx4[i]->addWidget(email_label[i]);
            hbx4[i]->addWidget(email[i]);
            vbx1->addLayout(hbx1[i]);
            vbx1->addLayout(hbx2[i]);
            vbx1->addLayout(hbx3[i]);
            vbx1->addLayout(hbx4[i]);
            delete_buttons[i]=new QPushButton("Delete contact");
            connect(delete_buttons[i],SIGNAL(clicked()),delete_mapper,SLOT(map()));
            delete_mapper->setMapping(delete_buttons[i],contacts[i].id);
            update_buttons[i]=new QPushButton("Update contact");
            connect(update_buttons[i],SIGNAL(clicked()),update_mapper,SLOT(map()));
            update_mapper->setMapping(update_buttons[i],contacts[i].id);
            vbx1->addWidget(update_buttons[i]);
            vbx1->addWidget(delete_buttons[i]);
        }

        new_widget->setLayout(vbx1);
        vb1->addWidget(new_widget);
        vb1->addWidget(ad);
        vb1->addWidget(cance);
        this->setLayout(vb1);
//        this->update();
    }

}
void Contacts::initialize_add()
{
    add1=new QPushButton("Add");
    cancel1=new QPushButton("Cancel");
    vbox1=new QVBoxLayout();
    hbox1=new QHBoxLayout();
    hbox2=new QHBoxLayout();
    hbox3=new QHBoxLayout();
    hbox4=new QHBoxLayout();
    hbox5=new QHBoxLayout();
    hbox6=new QHBoxLayout();
    hbox7=new QHBoxLayout();

    name_label=new QLabel("Name");
    designation_label=new QLabel("Designation");
    contact1_label=new QLabel("Contact No.");
    contact2_label=new QLabel("Alternate Contact");
    email_label=new QLabel("Email");
    name=new QLineEdit();
    designation=new QLineEdit();
    contact1=new QLineEdit();
    contact2=new QLineEdit();
    email=new QLineEdit();
    error=new QLabel();

    hbox1->addWidget(name_label);
    hbox1->addWidget(name);
    hbox2->addWidget(designation_label);
    hbox2->addWidget(designation);
    hbox3->addWidget(contact1_label);
    hbox3->addWidget(contact1);
    hbox7->addWidget(contact2_label);
    hbox7->addWidget(contact2);
    hbox4->addWidget(email_label);
    hbox4->addWidget(email);
    hbox6->addWidget(error);
    hbox5->addWidget(add1);
    hbox5->addWidget(cancel1);

    vbox1->addLayout(hbox1);
    vbox1->addLayout(hbox2);
    vbox1->addLayout(hbox3);
    vbox1->addLayout(hbox7);
    vbox1->addLayout(hbox4);
    vbox1->addLayout(hbox6);
    vbox1->addLayout(hbox5);

    add_widget=new QWidget();
    add_widget->setLayout(vbox1);

    connect(add1,SIGNAL(clicked(bool)),this,SLOT(add_contact_to_db()));
    connect(cancel1,SIGNAL(clicked(bool)),this,SLOT(cancel_add()));
}
void Contacts::add_contact()
{

    this->setEnabled(false);
    add_widget->show();
}
void Contacts::add_contact_to_db()
{
    Contact_Object contact;
    QMessageBox msg;
    contact.name=name->text();
    contact.email=email->text();
    contact.contact1=contact1->text();
    contact.contact2=contact2->text();
    contact.designation=designation->text();

    if(contact.name==NULL || contact.email==NULL || contact.contact1==NULL || contact.designation==NULL)
    {
        error->setText("Please enter value for required fields");
    }

    else {
        if(db.add_contact_to_db(contact))
        {
            msg.setText("Contact details inserted to db");
            this->initialize();
            msg.exec();
        }
        else {
            msg.setText("Couldn't insert data into databse!");
            msg.exec();
        }
    }
}
void Contacts::cancel_add()
{
    this->setEnabled(true);
    add_widget->close();
}
void Contacts::delete_contact(int id)
{
    QMessageBox msg;
    if(db.delete_contact(id))
    {
        msg.setText("Deleted Contact!");
        msg.exec();
        this->initialize();
    }
    else {
        msg.setText("Couldn't delete Contact");
        msg.exec();
    }
}
void Contacts::update_contact(int id)
{

}
Contacts::~Contacts()
{
}
