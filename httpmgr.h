#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"

//CRTP技术，单例构造http manager
class HttpMgr:public QObject,public Singleton<HttpMgr>,public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
    ~HttpMgr();  //CRTP的派生类需要设为public，基类需要对成员变量析构，其中智能指针需要调用模板T的析构，模板T是派生类自己，因此基类的析构需要调用派生类的析构。
private:
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;
    void PostHttpReq(QUrl url, QJsonObject json,ReqId req_id, Modules mod);
signals:
    void sig_http_finish(RedId id,QString res, ErrorCodes err, Modules mod);
};

#endif // HTTPMGR_H
