#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/img_res/XchatIcon.jpg"));
    login_dialog = new LoginDialog(this);
    setCentralWidget(login_dialog);


    connect(login_dialog,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);

    reg_dialog = new RegisterDialog(this);

    login_dialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    reg_dialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(reg_dialog);
    //login_dialog->hide();
    //reg_dialog->show();
}
