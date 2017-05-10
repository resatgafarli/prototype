#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QPointer>
#include <QDebug>
#include <QDebug>


class LSCEpisodePreparation;
class LSCEpisodePreparationSM;
class QQuickView;
class QQmlEngine;
class QQmlComponent;

class ExampleObject : public QObject{
    Q_OBJECT
public:
    ExampleObject(){}
    Q_INVOKABLE void copy(){
        qDebug()<<"Copy is called from example object..."<<endl;
    }
};


class LanguageShadowingCenter : public QObject
{
    Q_OBJECT
private:
    QPointer<ExampleObject> m_exampleObject;
    QPointer<QQmlEngine> m_engine;
    QPointer<QQmlComponent> m_component;
    QPointer<LSCEpisodePreparation> m_LSCEpisodePreparation;
    QPointer<LSCEpisodePreparationSM> m_LSCEpisodePreparationSM;

public:

    Q_INVOKABLE QString paste(){
        return "Paste invoked from LanguageShadowingCenter ...";
    }

    Q_SLOT void exampleQmlToCppSlot(QVariant);

    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

};

#endif // LANGUAGESHADOWINGCENTER_H
