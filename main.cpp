#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
// #include <QTextCodec>

int main(int argc, char *argv[])
{
    // 在创建 QApplication 之前设置 High-DPI 缩放舍入策略
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication a(argc, argv);
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "XFCatLanEncrypter_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    // 设置透明度：0.0（全透明） ~ 1.0（不透明）
    w.setWindowOpacity(0.99);
    // w.setWindowFlags(w.windowFlags() | Qt::FramelessWindowHint); // 无边框
    w.show();
    return a.exec();
}
