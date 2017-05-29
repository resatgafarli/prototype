import QtQuick 2.6
import QtQuick.Controls 1.4

Item{
    Button {
         id: mybutton
         text: "Go to third page"
        onClicked: ldafbrowser.openPage("../../src/LanguageShadowingCenter/ThirdPage.qml","browserContentLoader")

     }
}
