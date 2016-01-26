import QtQuick 2.0

Rectangle {
    id: topLeftRect
    width: 46
    height: 55
    radius: 6
    border.color: "#808080"

    Image {
        id: qtImage
        x: 10
        y: 20
        width: 46
        height: 56
        visible: true
        source: "../../tp180.png"
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
    }

    Rectangle {
        id: middleRightRect
        x: -2
        y: -3
        width: 46
        height: 55
        radius: 6
        anchors.right: parent.right
        anchors.rightMargin: 2
        Image {
            id: qtImage1
            x: 10
            y: 20
            width: 46
            height: 56
            visible: true
            source: "../../tp180.png"
        }

        MouseArea {
            id: mouseArea2
            anchors.fill: parent
        }
        border.color: "#808080"
    }

    Rectangle {
        id: topLeftRect2
        x: -5
        y: -2
        width: 46
        height: 55
        radius: 6
        Image {
            id: qtImage2
            x: 10
            y: 20
            width: 46
            height: 56
            visible: true
            source: "../../tp180.png"
        }

        MouseArea {
            id: mouseArea3
            anchors.fill: parent
        }
        border.color: "#808080"
    }
}
