#include "languageshadowingcenter.h"
#include "lscepisodepreparation.h"
#include "lscepisodepreparationsm.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <QFile>
#include <QQmlError>
#include <QDebug>

LanguageShadowingCenter::LanguageShadowingCenter(QWidget *parent) :
    QObject(parent),
    engine(new QQmlEngine),
    component (new QQmlComponent(engine))
{
    QFile file("../../../src/LanguageShadowingCenter/LanguageShadowingCenter.qml");
    if(file.exists()){
        component->loadUrl(QUrl::fromLocalFile("../../../src/LanguageShadowingCenter/LanguageShadowingCenter.qml"));
        component->create();
        for (auto e: component->errors()){
               qDebug()<<e.description()<<endl;
        }

    }

    /*    m_LSCEpisodePreparation = new LSCEpisodePreparation;

    m_LSCEpisodePreparationSM = new LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationActsProps>>(m_LSCEpisodePreparation));
    m_LSCEpisodePreparation->show();
*/
}

LanguageShadowingCenter::~LanguageShadowingCenter()
{

}

