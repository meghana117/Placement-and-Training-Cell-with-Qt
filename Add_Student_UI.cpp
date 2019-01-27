#include "Add_Student_UI.h"


Add_Student_UI::Add_Student_UI(QWidget *parent) : QWidget(parent)
{

    m_calButton = new QPushButton("Select");
    m_calButton->setFlat(true);

    this->setGeometry(700,300,600,600);

    add=new QPushButton("Add");
    add->setAutoDefault(true);
    cancel=new QPushButton("Cancel");
    cancel->setAutoDefault(true);
    name=new QLabel("Name");
    usn=new QLabel("USN");
    dob=new QLabel("DOB");
    email=new QLabel("Email");
    dept=new QLabel("Department");
    contact=new QLabel("Contact no.");
    cgpa=new QLabel("CGPA");
    backlog=new QLabel("No. of backlogs");
    error=new QLabel();
    ten=new QLabel("10th Percentage");
    twelve=new QLabel("12th Percentage");

    name_edit=new QLineEdit();
    QRegExp valid_name("[a-zA-Z ]+");
    QRegExpValidator *validate_name=new QRegExpValidator(valid_name,this);
    name_edit->setValidator(validate_name);

    QRegExp expusn("^[1]{1}[Dd]{1}[Aa]{1}[0-9]{2}[A-Za-z]{2}[0-9]{3}$/i");
    QRegExpValidator *validate_usn=new QRegExpValidator(expusn,this);
    usn_edit=new QLineEdit();
    usn_edit->setValidator(validate_usn);


    m_cal = new QCalendarWidget;
    m_cal->setMaximumDate(QDate::currentDate());
    m_cal->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QRegExp rx("^[a-zA-Z0-9_/./-]+@[a-zA-Z0-9_/./-]+/.[a-zA-Z]{2,5}$");
    QRegExpValidator *validate_email=new QRegExpValidator(rx,this);
    email_edit=new QLineEdit();
    email_edit->setValidator(validate_email);

    dept_edit=new QComboBox();
    QStringList list={"Computer Science and Engineering","Electronics and Communications Engineering","Mechanical Engineering","Civil Engineering","Electrical Engineering","Medical Electronics Engineering","Information Science and Engineering","Telecommunication and Engineering"};
    dept_edit->addItems(list);

    QRegExp expcontact("[1-9]{1}[0-9]{9}");
    QRegExpValidator *validate_contact=new QRegExpValidator(expcontact,this);
    contact_edit=new QLineEdit();
    contact_edit->setValidator(validate_contact);

    cgpa_edit=new QDoubleSpinBox();
    cgpa_edit->setMaximum(10.0);

    ten_edit=new QDoubleSpinBox();
    ten_edit->setMaximum(100.0);

    twelve_edit=new QDoubleSpinBox();
    twelve_edit->setMaximum(100.0);

    backlog_edit=new QSpinBox();
    backlog_edit->setMaximum(10);

    add=new QPushButton("Add");
    cancel=new QPushButton("Cancel");

    vb1=new QVBoxLayout();
    vb2=new QVBoxLayout();
    vb3=new QVBoxLayout();
    hb1=new QHBoxLayout();
    hb2=new QHBoxLayout();
    hb3=new QHBoxLayout();
    hb4=new QHBoxLayout();
    hb5=new QHBoxLayout();
    hb6=new QHBoxLayout();
    hb7=new QHBoxLayout();
    hb8=new QHBoxLayout();
    hb9=new QHBoxLayout();
    hb10=new QHBoxLayout();
    hb11=new QHBoxLayout();
    hb12=new QHBoxLayout();

    vb2->addWidget(name);
    vb3->addWidget(name_edit);

    vb2->addWidget(dob);
    vb3->addWidget(m_calButton);

    vb2->addWidget(email);
    vb3->addWidget(email_edit);

    vb2->addWidget(contact);
    vb3->addWidget(contact_edit);

    vb2->addWidget(dept);
    vb3->addWidget(dept_edit);

    vb2->addWidget(usn);
    vb3->addWidget(usn_edit);

    vb2->addWidget(cgpa);
    vb3->addWidget(cgpa_edit);

    vb2->addWidget(backlog);
    vb3->addWidget(backlog_edit);

    hb1->addWidget(error);


    hb10->addWidget(add);
    hb10->addWidget(cancel);

    vb2->addWidget(ten);
    vb3->addWidget(ten_edit);

    vb2->addWidget(twelve);
    vb3->addWidget(twelve_edit);

    hb2->addLayout(vb2);
    hb2->addLayout(vb3);
    hb2->addLayout(hb1);
//    vb1->addLayout(hb2);
//    vb1->addLayout(hb3);
//    vb1->addLayout(hb4);
//    vb1->addLayout(hb5);
//    vb1->addLayout(hb6);
//    vb1->addLayout(hb7);
//    vb1->addLayout(hb8);
//    vb1->addLayout(hb11);
//    vb1->addLayout(hb12);
//    vb1->addLayout(hb9);
    vb1->addLayout(hb2);
    vb1->addLayout(hb10);

    this->setLayout(vb1);

    connect(m_calButton,SIGNAL(clicked()),m_cal,SLOT(show()),Qt::UniqueConnection);
    connect(m_cal,SIGNAL(clicked(QDate)),this,SLOT(onDateSelected(QDate)),Qt::UniqueConnection);
    connect(add,SIGNAL(clicked(bool)),this,SLOT(add_stud()));
    connect(cancel,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(usn_edit,SIGNAL(textEdited(QString)),this,SLOT(toUpper(QString)));

}

void Add_Student_UI::add_stud()
{
    QDate today;
    Student student;
    today=today.currentDate();
    student.name=name_edit->text();
    student.usn=usn_edit->text();
    student.backlogs=backlog_edit->value();
    student.cgpa=cgpa_edit->value();
    student.contact=contact_edit->text();
    student.dept=dept_edit->currentText();
    student.email=email_edit->text();
    student.password=m_date.toString("dd/MM/yyyy");
    student.dob=m_date.toString("dd/MM/yyyy");
    student.ten=ten_edit->value();
    student.twelve=twelve_edit->value();

    if(student.name.isEmpty()||student.usn.isEmpty()||student.usn.length()<10 || student.contact==NULL || student.email.isEmpty()|| student.usn.isEmpty()|| student.dept.isEmpty() || student.ten<=0 || student.twelve<=0)
    {
        QMessageBox msgBox;
        msgBox.setText("Please enter valid data for all the fields");
        msgBox.exec();
    }
    else
    {

        if(db.add_student(student))
        {
            QMessageBox msgBox;
            msgBox.setText("Student added Successfully!");
            msgBox.exec();
            name_edit->clear();
            usn_edit->clear();
//            dept_edit->clear();
            contact_edit->clear();
            email_edit->clear();
            cgpa_edit->clear();
            backlog_edit->clear();
            ten_edit->clear();
            twelve_edit->clear();
            error->setText(" ");
        }
        else
        {
            error->setText("Duplicate USN");
        }
    }
}

void Add_Student_UI::toUpper(QString txt)
{
    usn_edit->setText(txt.toUpper());
}
void Add_Student_UI::onDateSelected(QDate date)
{
    m_cal->close();
    m_date = date;
    m_calButton->setText(date.toString("dd/MM/yyyy"));
}

Add_Student_UI::~Add_Student_UI()
{
}
