#include "languageshadowingcenter.h"
#include "ui_languageshadowingcenter.h"
#include "lscepisodepreparation.h"
#include "lscepisodepreparationsm.h"


LanguageShadowingCenter::LanguageShadowingCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LanguageShadowingCenter)
{
    ui->setupUi(this);
    m_LSCEpisodePreparation = new LSCEpisodePreparation;

    m_LSCEpisodePreparationSM = new LSCEpisodePreparationSM(static_cast<QPointer<LSCEpisodePreparationActsProps>>(m_LSCEpisodePreparation));
    m_LSCEpisodePreparation->show();
}

LanguageShadowingCenter::~LanguageShadowingCenter()
{
    delete ui;
}

