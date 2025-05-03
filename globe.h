#ifndef GLOBE_H
#define GLOBE_H
#include <QWidget>
#include <functional>
#include "QStyle"
#include <QRegularExpression>
#include <QDebug>
#include <memory.h>
#include <mutex>
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

extern std::function<void(QWidget*)> repolish;

enum ReqId{
    ID_GET_VARIFY_CODE = 1001, //获取验证码
    ID_REG_USER = 1002, //注册用户

};

enum Modules{
    REGISTERMOD = 0,

};

enum ErrorCodes{
    SUCCESS = 0,
    ERR_JSON = 1, //json解析失败
    ERR_NETWORK = 2, //网络错误

}

#endif // GLOBE_H
