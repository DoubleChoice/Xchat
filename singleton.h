#ifndef SINGLETON_H
#define SINGLETON_H

#include "globe.h"

template <typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T>& t) = delete;
    Singleton& operator= (const Singleton<T>& t) = delete;
    static std::shared_ptr<T> _instance = nullptr;
public:
    static std::shared_ptr<T>& getInstance(){
        static std::shared_ptr<T> _instance;
        return _instance;
    }

    ~Singleton(){
        qDebug()<<"sigleton destruct"<<std::endl;
    }
}

#endif // SINGLETON_H
