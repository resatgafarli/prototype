import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window
    visible: true

    menuBar: MenuBar {
        Menu {
            title: "Menu_1"
            MenuItem
            {
                text : "Menu_11"
            }
        }

        Menu {
            title: "Menu_2"
            MenuItem
            {
                text : "Menu_21"
            }
        }

    }

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                            text: "TB_1"
                        }

            ToolButton {
                            text: "TB_2"
                        }
        }
    }
    TabView {
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
