#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QPointer>

class LSCEpisodePreparation;
class LSCEpisodePreparationSM;
class QQuickView;



class LanguageShadowingCenter : public QObject
{
    Q_OBJECT
private:
    QPointer<QQuickView> view;
    QPointer<LSCEpisodePreparation> m_LSCEpisodePreparation;
    QPointer<LSCEpisodePreparationSM> m_LSCEpisodePreparationSM;

public:
    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

};

#endif // LANGUAGESHADOWINGCENTER_H
