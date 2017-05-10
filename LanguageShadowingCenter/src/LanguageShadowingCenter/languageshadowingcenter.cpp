#include "languageshadowingcenter.h"
#include "lscepisodepreparation.h"
#include "lscepisodepreparationsm.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QFile>
#include <QQmlError>
#include <QDebug>
#include <QQmlContext>
#include <QJsonArray>



LanguageShadowingCenter::LanguageShadowingCenter(QWidget *parent) :
    QObject(parent),
    m_exampleObject(new ExampleObject),
    m_engine(new QQmlEngine),
    m_component (new QQmlComponent(m_engine))

{

    m_engine->rootContext()->setContextProperty("languageShadowingCenter",this);
    m_engine->rootContext()->setContextProperty("exampleObject",m_exampleObject);


    QFile file("../../../src/LanguageShadowingCenter/LanguageShadowingCenter.qml");
    if(file.exists()){
        m_component->loadUrl(QUrl::fromLocalFile("../../../src/LanguageShadowingCenter/LanguageShadowingCenter.qml"));
        QPointer<QObject> rootObject = m_component->create();
        for (auto e: m_component->errors()){
               qDebug()<<e.description()<<endl;
        }
        if (!rootObject.isNull()){
            connect(rootObject,SIGNAL(exampleQmlToCppSignal(QVariant)),this, SLOT(exampleQmlToCppSlot(QVariant)));
        }

    }

    /*    m_LSCEpisodePreparation = new LSCEpisodePreparation;

    m_LSCEpisodePreparationSM = new LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationActsProps>>(m_LSCEpisodePreparation));
    m_LSCEpisodePreparation->show();
*/
}

void LanguageShadowingCenter::exampleQmlToCppSlot(QVariant listOfdata){

    auto keyValueMap = listOfdata.toMap();
    QListIterator<QString>  keyListIt = keyValueMap.keys();
    keyListIt.toFront();
    while(keyListIt.hasNext()){
        auto key = keyListIt.next();
        qDebug()<<key<<":";
        QVariantList varList = keyValueMap.values(key);

        QListIterator<QVariant> vals = varList.at(0).toList();//At 0 is imortant. It holds as list of list.!!!!!

        vals.toFront();

        while (vals.hasNext()){
            auto val = vals.next();
            qDebug()<<val.toString()<<",";
        }
        qDebug()<<endl;
    }
    qDebug()<<"Sender name"<< QObject::sender()->objectName()<<endl;
}


LanguageShadowingCenter::~LanguageShadowingCenter()
{

}

