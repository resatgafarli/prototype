import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import LanguageShadowingCenter.ExampleQmlType 1.0



ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480

    ExampleQmlType{
        id: exampleQmlType
    }

    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        //iconName: "edit-copy"
        enabled: true
        onTriggered: exampleQmlType.copy()
    }

    Action {
        id: cutAction
        text: "Cu&t"
        shortcut: StandardKey.Cut
        //iconName: "edit-cut"
        enabled: true
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        //iconName: "edit-paste"
        enabled: true
        onTriggered: {
                        messageDialog.text = exampleQmlType.paste()
                        messageDialog.visible = true
                      }
        }

    Action {
        id: quitAction
        text: "&Quit"
        shortcut: StandardKey.Quit
        //iconName: "edit-paste"
        enabled: true
        onTriggered: activeFocusItem.quit()
    }

    toolBar: ToolBar {
           RowLayout {
               anchors.fill: parent
               ToolButton { action: quitAction}
               ToolButton { action: cutAction}
               ToolButton { action: copyAction}
               ToolButton { action: pasteAction}

           }
       }
       menuBar: MenuBar {
           Menu {
               title: "&File"
               MenuItem { action: quitAction }
           }
           Menu {
               title: "&Edit"
               MenuItem { action: cutAction }
               MenuItem { action: copyAction }
               MenuItem { action: pasteAction }
           }
           Menu {
               title: "&Help"
               MenuItem {
                   text: "About..."
                   onTriggered: messageDialog.visible = true
               }
           }
       }

       MessageDialog {
           id: messageDialog
           title: "May I have your attention please"
           text: "It's so cool that you are using Qt Quick."

    }
}
