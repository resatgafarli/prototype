import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480

    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        iconName: "edit-copy"
        enabled: true
        onTriggered: activeFocusItem.copy()
    }

    Action {
        id: cutAction
        text: "Cu&t"
        shortcut: StandardKey.Cut
        iconName: "edit-cut"
        enabled: true
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        iconName: "edit-paste"
        enabled: true
        onTriggered: activeFocusItem.paste()
    }

    toolBar: ToolBar {
           RowLayout {
               anchors.fill: parent
               anchors.margins: spacing
               Label {
                   text: UI.label
               }
               Item { Layout.fillWidth: true }
               CheckBox {
                   id: enabler
                   text: "Enabled"
                   checked: true
               }
           }
       }

       menuBar: MenuBar {
           Menu {
               title: "&File"
               MenuItem {
                   text: "E&xit"
                   shortcut: StandardKey.Quit
                   onTriggered: Qt.quit()
               }
           }
           Menu {
               title: "&Edit"
               visible: tabView.currentIndex == 2
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
