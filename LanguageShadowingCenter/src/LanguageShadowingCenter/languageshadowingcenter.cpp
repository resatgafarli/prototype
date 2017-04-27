#include "languageshadowingcenter.h"
#include "ui_languageshadowingcenter.h"


LanguageShadowingCenter::LanguageShadowingCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LanguageShadowingCenter)
{
    ui->setupUi(this);
    _LSCEpisodePreparation.show();
}

LanguageShadowingCenter::~LanguageShadowingCenter()
{
    delete ui;
}

