import QtQuick 2.6

ApplicationWindow {
    id: window
    visible: true

    menuBar: MenuBar {
        /*Menu { MenuItem {...} }
        Menu { MenuItem {...} }
        */
    }

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            //ToolButton {...}

        }
    }

    TabView {
        id: myContent
        /*anchors.fill: parent*/

    }
}
