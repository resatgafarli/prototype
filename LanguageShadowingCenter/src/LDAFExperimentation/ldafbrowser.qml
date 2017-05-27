import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4



ApplicationWindow {
    id: ldafbrowser_ui
    visible: true
    objectName: "ldafbrowser_appwindow"
    visibility: "FullScreen"
    title: "LDAFBrowser"

    Action {
        id: closeWindow
        text: "Close Window"
    }

    toolBar: ToolBar {
           RowLayout {
               anchors.fill: parent
               ToolButton { action: closeWindow}
           }
       }


/*
    Action {
        id: secondPageAction
        text: "&Go to Second Page"
        shortcut: StandardKey.Copy
        //iconName: ""
        enabled: true
        onTriggered: {
            //var nextPath = "SecondPage"
            //ldafbrowser.openPage(nextPath)
        }
    }

    toolBar: ToolBar {
           RowLayout {
               anchors.fill: parent
               ToolButton { action: secondPageAction}
           }
       }
       menuBar: MenuBar {
           Menu {
               title: "&File"
               MenuItem { action: secondPageAction }
           }
       }
*/
}
