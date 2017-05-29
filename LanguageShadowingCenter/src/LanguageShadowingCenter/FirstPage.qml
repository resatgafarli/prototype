import QtQuick 2.6
import QtQuick.Controls 1.4

Item{
    Button {
         id: mybutton
         text: "Go to second page"
        onClicked: ldafbrowser.openPage("../../src/LanguageShadowingCenter/SecondPage.qml","browserContentLoader")

     }
}
