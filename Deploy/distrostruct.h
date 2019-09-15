
//#
//# Copyright (C) 2018-2019 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef DISTROSTRUCT_H
#define DISTROSTRUCT_H

#include <QString>
#include <deploy_global.h>

/**
 * @brief The DistroStruct class
 */
class DEPLOYSHARED_EXPORT DistroStruct
{
private:
    QString libOutDir;
    QString binOutDir;
    QString qmlOutDir;
    QString trOutDir;
    QString resOutDir;
    QString pluginsOutDir;

    QString toFullPath(QString path) const;
    QString stripPath(QString path) const;
    QString getRelativePath(QString path) const;

    void setBinOutDir(const QString &value);
    void setLibOutDir(const QString &value);
    void setQmlOutDir(const QString &value);
    void setTrOutDir(const QString &value);
    void setResOutDir(const QString &value);
    void setPluginsOutDir(const QString &value);


public:
    DistroStruct();
    QString getLibOutDir(const QString& basePath = "/") const;
    QString getBinOutDir(const QString& basePath = "/") const;
    QString getQmlOutDir(const QString& basePath = "/") const;
    QString getTrOutDir(const QString& basePath = "/") const;
    QString getResOutDir(const QString& basePath = "/") const;
    QString getPluginsOutDir(const QString& basePath = "/") const;
    QString getRootDir(const QString& basePath = "/") const;

    void init();

    friend class deploytest;
};

#endif // DISTROSTRUCT_H
