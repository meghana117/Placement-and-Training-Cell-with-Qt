#ifndef CONTACTS_H
#define CONTACTS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QSignalMapper>
#include "Db_Class.h"
#include "contact_object.h"

class Contacts : public QWidget
{
    Q_OBJECT
public:
    explicit Contacts(QWidget *parent = nullptr);
    ~Contacts();
private:
    QPushButton *add,*cancel;
    QVBoxLayout *vb1,*vb2;
    QHBoxLayout *hb1,*hb2;
    QWidget *new_widget;
    Db_Class db;
    void initialize();
    void initialize_add();

    QWidget *add_widget;
    QPushButton *add1,*cancel1;
    QVBoxLayout *vbox1;
    QHBoxLayout *hbox1,*hbox2,*hbox3,*hbox4,*hbox5,*hbox6,*hbox7;
    QLineEdit *name,*designation,*contact1,*contact2,*email;
    QLabel *name_label,*designation_label,*contact1_label,*contact2_label,*email_label,*error;


signals:

public slots:
    void add_contact();
    void add_contact_to_db();
    void cancel_add();
    void delete_contact(int);
    void update_contact(int);
};

#endif // CONTACTS_H
