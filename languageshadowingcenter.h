#ifndef LANGUAGESHADOWINGCENTER_H
#define LANGUAGESHADOWINGCENTER_H

#include <QMainWindow>

namespace Ui {
class LanguageShadowingCenter;
}

class LanguageShadowingCenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit LanguageShadowingCenter(QWidget *parent = 0);
    ~LanguageShadowingCenter();

private:
    Ui::LanguageShadowingCenter *ui;
};

#endif // LANGUAGESHADOWINGCENTER_H
