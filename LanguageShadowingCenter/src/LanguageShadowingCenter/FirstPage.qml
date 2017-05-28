import QtQuick 2.6
import QtQuick.Controls 1.4

Item{
    TabView {
         id: myContent
         anchors.fill: parent
         Tab {
                   title: "Red"
                   Rectangle { color: "red" }
               }
               Tab {
                   title: "Blue"
                   Rectangle { color: "blue" }
               }
               Tab {
                   title: "Green"
                   Rectangle { color: "green" }
               }
     }
}
