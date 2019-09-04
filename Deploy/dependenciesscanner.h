/*
 * Copyright (C) 2018-2019 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */

#ifndef WINDEPENDENCIESSCANNER_H
#define WINDEPENDENCIESSCANNER_H

#include <QMultiMap>
#include <QStringList>
#include "deploy_global.h"
#include "pe.h"
#include "elf.h"
#include "libinfo.h"


enum class PrivateScaner: unsigned char {
   UNKNOWN,
   PE,
   ELF
};

class DEPLOYSHARED_EXPORT DependenciesScanner {


private:

    DeployCore::QtModule _qtModules = DeployCore::NONE;

    QStringList _env;
    QMultiHash<QString, QString> _EnvLibs;
    QHash<QString, LibInfo> _scanedLibs;

    PE _peScaner;
    ELF _elfScaner;

    PrivateScaner getScaner(const QString& lib) const;

    QMultiMap<LibPriority, LibInfo> getLibsFromEnvirement(const QString& libName) const;
    bool fillLibInfo(LibInfo& info ,const QString& file) const;

    void recursiveDep(LibInfo& lib, QSet<LibInfo> &res);

public:
    explicit DependenciesScanner();

    void setEnvironment(const QStringList &env);

    QSet<LibInfo> scan(const QString& path);

    ~DependenciesScanner();

    friend class deploytest;
    void clearScaned();
    DeployCore::QtModule getQtModules() const;
};

#endif // WINDEPENDENCIESSCANNER_H
