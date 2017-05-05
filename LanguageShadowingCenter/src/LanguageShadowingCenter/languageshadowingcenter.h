#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QPointer>
#include <QDebug>
class LSCEpisodePreparation;
class LSCEpisodePreparationSM;
class QQuickView;
class QQmlEngine;
class QQmlComponent;

class ExampleQmlType : public QObject{
    Q_OBJECT
public:
    ExampleQmlType(){}
    Q_INVOKABLE void copy(){
        qDebug()<<"Copy is called..."<<endl;
    }

    Q_INVOKABLE QString paste(){
        return "Paste function return...";
    }
};

class LanguageShadowingCenter : public QObject
{
    Q_OBJECT
private:
    QPointer<QQmlEngine> engine;
    QPointer<QQmlComponent> component;
    QPointer<LSCEpisodePreparation> m_LSCEpisodePreparation;
    QPointer<LSCEpisodePreparationSM> m_LSCEpisodePreparationSM;

public:
    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

};

#endif // LANGUAGESHADOWINGCENTER_H
