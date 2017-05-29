import QtQuick 2.6
import QtQuick.Controls 1.4

Item{
    Button {
         id: mybutton
         text: "Go to first page"
        onClicked: ldafbrowser.openPage("../../src/LanguageShadowingCenter/FirstPage.qml","browserContentLoader")
     }
}
