import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2




ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    objectName: "applicationWindow"

    signal exampleQmlToCppSignal(var data)

    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        //iconName: "edit-copy"
        enabled: true
        onTriggered: exampleObject.copy()
    }

    Action {
        id: openNexAction
        text: "&OpenNext"
	//shortcut: StandardKey.Copy
        //iconName: "edit-copy"
        enabled: true
        onTriggered: {
			var nextPath = "LanguageShadowingCenter1"
			ldafbrowser.openPage(nextPath)
			}
    }


    Action {
        id: cutAction
        text: "Cu&t"
        shortcut: StandardKey.Cut
        //iconName: "edit-cut"
        enabled: true
        //onTriggered: languageShadowingCenter.cut()
    }

    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        //iconName: "edit-paste"
        enabled: true
        onTriggered: {
                        messageDialog.text = languageShadowingCenter.paste()
                        messageDialog.visible = true

                        var data = {
                                'key1': ["val11","val12","val12"],
                                'key2': ["val21","val22","val23"],
                                'key3': ["val31","val32","val33"]
                        }
                        exampleQmlToCppSignal(data)
                      }
        }

    Action {
        id: quitAction
        text: "&Quit"
        shortcut: StandardKey.Quit
        //iconName: "edit-paste"
        enabled: true
        //onTriggered: languageShadowingCenter.quit()
    }

    toolBar: ToolBar {
           RowLayout {
               anchors.fill: parent
               ToolButton { action: openNexAction}
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
               MenuItem { action: openNexAction }
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
