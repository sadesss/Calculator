#include "mainwindow.h"
#include <QRegularExpression>
#include "./ui_mainwindow.h"
#include "calculate.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox::information(this,"Welcome", "Hi! Welcome to the Calculator. You can count the functions you need and even find an Easter egg. Here you can work with the exponent! ~ this is a minus");
    connect(ui->pbn_0, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_1, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_2, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_3, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_4, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_5, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_6, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_7, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_8, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_9, &QPushButton::clicked, this, &MainWindow::on_num_clicked);
    connect(ui->pbn_plus, &QPushButton::clicked, this, &MainWindow::on_sub_clicked);
    connect(ui->pbn_minus, &QPushButton::clicked, this, &MainWindow::on_sub_clicked);
    connect(ui->pbn_division, &QPushButton::clicked, this, &MainWindow::on_sub_clicked);
    connect(ui->pbn_multiplication, &QPushButton::clicked, this, &MainWindow::on_sub_clicked);
    connect(ui->btn_sin, &QPushButton::clicked, this, &MainWindow::on_trig_clicked);
    connect(ui->btn_cos, &QPushButton::clicked, this, &MainWindow::on_trig_clicked);
    connect(ui->btn_tg, &QPushButton::clicked, this, &MainWindow::on_trig_clicked);
    connect(ui->btn_ctg, &QPushButton::clicked, this, &MainWindow::on_trig_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_trig_clicked()
{
    QPushButton *btn = (QPushButton *) sender();
    QString num=ui->lbl_output->text();
    if ((!num.contains('+')) && !num.contains('~') && !num.contains('*') && !num.contains('/')){
        struct Data data_1;
        data_1.num1 = num.toDouble();
        data_1.operation=(btn->text()).toLatin1()[0];
        double res1 = calc(data_1);
        if (res1 == ERROR) {
            ui->lbl_output->setText(QString::number(data_1.num1, 'g', 15));
            QMessageBox::information(this,"Error", "Put correct math function");
        }else{
            ui->lbl_output->setText(QString::number(res1, 'g', 15));
        }
    } else if (!num.contains('e')){
        ui->lbl_output->setText(num);
        QMessageBox::information(this,"Error", "Put only one number.");
    }
    ui->pbn_del->setEnabled(true);
}

void MainWindow::on_num_clicked()
{
    if (ui->lbl_output->text().size() < 25){
        QPushButton *btn = (QPushButton *) sender();
        QString str = ui->lbl_output->text();
        if ((ui->lbl_output->text()!='0')){
            ui->lbl_output->setText(ui->lbl_output->text()+btn->text());
            set_operations_true(true);
            ui->pbn_root->setEnabled(true);
            ui->pbn_comma->setEnabled(true);
            ui->pbn_del->setEnabled(true);
        }else{
            ui->lbl_output->setText(btn->text());
        }
    }
}

void MainWindow::set_numbers_true(bool status){
        ui->pbn_0->setEnabled(status);
        ui->pbn_1->setEnabled(status);
        ui->pbn_2->setEnabled(status);
        ui->pbn_3->setEnabled(status);
        ui->pbn_4->setEnabled(status);
        ui->pbn_5->setEnabled(status);
        ui->pbn_6->setEnabled(status);
        ui->pbn_7->setEnabled(status);
        ui->pbn_8->setEnabled(status);
        ui->pbn_9->setEnabled(status);
}

void MainWindow::set_operations_true(bool status){
    ui->pbn_plus->setEnabled(status);
    ui->pbn_multiplication->setEnabled(status);
    ui->pbn_division->setEnabled(status);
    ui->pbn_minus->setEnabled(status);
    ui->pbn_comma->setEnabled(status);
    set_trig_true(status);
}

void MainWindow::set_trig_true(bool status){
    ui->btn_sin->setEnabled(status);
    ui->btn_cos->setEnabled(status);
    ui->btn_tg->setEnabled(status);
    ui->btn_ctg->setEnabled(status);
}

void MainWindow::on_pbn_reset_clicked()
{
    this->ui->lbl_output->clear();
    set_numbers_true(true);
    set_operations_true(false);
    ui->pbn_root->setEnabled(false);
    ui->pbn_del->setEnabled(false);
    ui->pbn_comma->setEnabled(false);
}


void MainWindow::on_pbn_del_clicked(){
    QString str = ui->lbl_output->text();
    if (!str.contains('e')){
        str.chop(1);
        ui->lbl_output->setText(str);
        if (str.isEmpty() || str=="-0"){
                ui->lbl_output->setText(" ");
                set_operations_true(false);
        }
        str = ui->lbl_output->text();
    }
     if (str.contains('e')){
            if (str.count('+')<=1 || str.count('-')<=2 || str.contains('~') || str.contains('*')||str.contains('/')){
                 set_operations_true(true);
                 ui->pbn_del->setEnabled(true);
                 str.chop(1);
                 e_in_text();
                 ui->lbl_output->setText(str);
            }
        }
    if (!ui->lbl_output->text().contains('.')){
        ui->pbn_comma->setEnabled(true);
    }
    ui->pbn_res->setEnabled(true);
}

void MainWindow::on_sub_clicked(){
    QPushButton *btn = (QPushButton *) sender();
    QString num=ui->lbl_output-> text();
    int check=FLAG;
    if ((!num.contains('+')) && (!num.contains('~')) && !num.contains('*') && !num.contains('/')){
        if (num!='-'){
            if (num[num.length()-1]!='.'){
                ui->lbl_output->setText(ui->lbl_output->text()+btn->text());
                check++;
            }
        }
    }
    num=ui->lbl_output-> text();
    if ((num.contains('e')) ){
        set_numbers_true(true);
        if ((num.count('+')==1 ||num.count('-')==1) && !num.contains('~') && !num.contains('*')&& !num.contains('/') && check==FLAG){
            ui->lbl_output->setText(ui->lbl_output->text()+btn->text());
            set_numbers_true(true);
        }
    }
    ui->pbn_res->setEnabled(true);
    ui->pbn_del->setEnabled(true);
}

void MainWindow::e_in_text()
{
    if (ui->lbl_output->text().contains('e')) {
        set_numbers_true(false);
        set_operations_true(true);
        ui->pbn_del->setEnabled(false);
        ui->pbn_comma->setEnabled(false);
        ui->pbn_res->setEnabled(false);
    }
}

void MainWindow::on_pbn_res_clicked(){
    QString num=ui->lbl_output->text();
    QList<QString> res = num.split(QRegularExpression("[+|~|*|/]"));
    struct Data data_1;
    double res1;
    if (res.count() == 2) {
        data_1.num1 = res[0].toDouble();
        data_1.num2 = res[1].toDouble();
        data_1.operation = num.at(res[0].length()).toLatin1();

    } else if (num.contains('e')){
        data_1.num1 = (res[0]+num.at(res[0].length()).toLatin1()+res[1]).toDouble();
        data_1.num2 = res[2].toDouble();
        data_1.operation = num.at(res[0].length()+1+res[1].length()).toLatin1();
    }
    res1 = calc(data_1);
    ui->lbl_output->setText(QString::number(res1, 'g', 15));
    if (res1 == ERROR) {
        ui->lbl_output->setText(QString::number(data_1.num1, 'g', 15));
        QMessageBox::information(this,"Error", "Put correct math function");
    }
    e_in_text();
}



void MainWindow::on_pbn_comma_clicked()
{
    set_numbers_true(true);
    QPushButton *btn = (QPushButton *) sender();
    QString num=ui->lbl_output->text();
    int len=num.length();
    if (num.count('.')<1){
     if (num[len-1]!='+' && num[len-1]!='~'&& num[len-1]!='-' && num[len-1]!='*'&& num[len-1]!='/'&& num[len-1]!='.' ){
        ui->lbl_output->setText(ui->lbl_output->text()+btn->text());
     }
    }
    if (num.count('.')==1){
        if (num[len-1]!='+' && num[len-1]!='~'&& num[len-1]!='-' && num[len-1]!='*'&& num[len-1]!='/'&& num[len-1]!='.' ){
           if (num.count('+')>=1 || num.count('/')>=1 || num.count('*')>=1 || num.count('~')>=1){
               ui->lbl_output->setText(ui->lbl_output->text()+btn->text());
           }
        }
    }
    ui->pbn_comma->setEnabled(false);
}


void MainWindow::on_pbn_root_clicked()
{
    QString num=ui->lbl_output->text();
    if (!num.contains('+') && !num.contains('~')&& !num.contains('*') && !num.contains('/')){
        struct Data data_1;
        data_1.num1 = num.toDouble();
        data_1.num2 = ERRORS;
        double res1 = calc(data_1);
        if (res1 == ERROR) {
            ui->lbl_output->setText(QString::number(data_1.num1, 'g', 15));
            QMessageBox::information(this,"Error", "Put number more than 0");
        }else{
            ui->lbl_output->setText(QString::number(res1, 'g', 15));
        }
    } else if (!num.contains('e')){
        ui->lbl_output->setText(num);
        QMessageBox::information(this,"Error", "Put only one number.");
    }
    if (num=='-'){
            ui->lbl_output->setText(num);
            pixel_art();
    }
}


void MainWindow::on_pbn_change_clicked()
{
    QString num=ui->lbl_output->text();
    if ((!num.contains('+')) && !num.contains('~') && !num.contains('*') && !num.contains('/')){
        struct Data data_1;
        data_1.num1 = num.toDouble();
        data_1.num2=  ERROR;
        double res1 = calc(data_1);
        ui->lbl_output->setText(QString::number(res1, 'g', 15));
    } else if (!num.contains('e')){
        ui->lbl_output->setText(num);
        QMessageBox::information(this,"Error", "Put only one number. Else if you want to make the second number negative, count and then press '+/-'. Remember that minus by minus gives a plus.");
    }
    ui->pbn_del->setEnabled(true);
}

void MainWindow::pixel_art(){
    QMessageBox::information(this,"Do you need coffee?      ", ">>>>>>>>....c(--)....c(__).... :3 <<<<<<<");
}
