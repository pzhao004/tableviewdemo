#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGui/qsurfaceformat.h>
#include <QtQml/qqml.h>
#include "sortfilterproxymodel.h"
#include "qtquickcontrolsapplication.h"

int main(int argc, char *argv[])
{
    //高清分辨路屏幕的支持 从5.6.0 版本开始支持
#if(QT_VERSION>=QT_VERSION_CHECK(5,6,0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); //一定要加在QApplication创建 之前
#endif

        //关于QLatin1String可以参考https://blog.csdn.net/qq_33266987/article/details/72843578
        //QCoreApplication::arguments()返回一个命令行参数列表
        //qDebug() << QCoreApplication::arguments().last();


    if(QCoreApplication::arguments().contains(QLatin1String("--coreprofile"))){
        qDebug() << "..........................................1";
        QSurfaceFormat fmt;
        fmt.setVersion(4,4);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(fmt);
    }
    qDebug() << "..........................................2";
    qmlRegisterType<SortFilterProxyModel>("org.qtproject.example",1,0,"SortFilterProxyModel");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
