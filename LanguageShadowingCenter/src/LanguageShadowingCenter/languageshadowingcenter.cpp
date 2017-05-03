#include "languageshadowingcenter.h"
#include "lscepisodepreparation.h"
#include "lscepisodepreparationsm.h"
#include <QQuickView>

LanguageShadowingCenter::LanguageShadowingCenter(QWidget *parent) :
    QObject(parent),
    view(new QQuickView)
{


    view->setSource(QUrl::fromLocalFile("LanguageShadowingCenter.qml"));
    view->show();

    /*    m_LSCEpisodePreparation = new LSCEpisodePreparation;

    m_LSCEpisodePreparationSM = new LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationActsProps>>(m_LSCEpisodePreparation));
    m_LSCEpisodePreparation->show();
*/
}

LanguageShadowingCenter::~LanguageShadowingCenter()
{

}

