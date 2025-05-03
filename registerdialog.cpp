#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "globe.h"
RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->error_label->setProperty("state","normal");
    repolish(ui->error_label);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_get_code_button_clicked()
{
    auto email = ui->email_edit->text();
    static QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");   // \w表示匹配字母和数字，+表示至少一个
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码
    }else{
        showTip(tr("邮箱地址不正确"),ui->error_label->property("state").toString());
    }
}

void RegisterDialog::showTip(QString str,QString state)
{
    if(state == QString("normal")){
        ui->error_label->setProperty("state","err");
    }else{
        ui->error_label->setProperty("state","normal");
    }
    ui->error_label->setText(str);
    repolish(ui->error_label);
}

