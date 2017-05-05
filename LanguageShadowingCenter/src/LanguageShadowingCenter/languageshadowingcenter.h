#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QPointer>

class LSCEpisodePreparation;
class LSCEpisodePreparationSM;
class QQuickView;
class QQmlEngine;
class QQmlComponent;


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
