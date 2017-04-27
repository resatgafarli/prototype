#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QMainWindow>
#include "lscepisodepreparation.h"
namespace Ui {
class LanguageShadowingCenter;
}

class LanguageShadowingCenter : public QMainWindow
{
    Q_OBJECT

public:
    LSCEpisodePreparation _LSCEpisodePreparation;
    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

private:
    Ui::LanguageShadowingCenter *ui;
};

#endif // LANGUAGESHADOWINGCENTER_H
