#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QMainWindow>
#include <QPointer>

class LSCEpisodePreparation;
class LSCEpisodePreparationSM;


namespace Ui {
class LanguageShadowingCenter;
}


class LanguageShadowingCenter : public QMainWindow
{
    Q_OBJECT

public:
    QPointer<LSCEpisodePreparation> m_LSCEpisodePreparation;
    QPointer<LSCEpisodePreparationSM> m_LSCEpisodePreparationSM;
    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

private:
    Ui::LanguageShadowingCenter *ui;
};

#endif // LANGUAGESHADOWINGCENTER_H
