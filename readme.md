# Map 생성
* X 축의 크기와 Y 축의 크기 그리고 지뢰의 수를 입력한다. X, Y축은 최소 3부터 좌표 지정을 위해 사용하는 alphabet 크기인 26까지 입력할 수 있으며, 지뢰는 최소 1개부터 최대 전체 타일 수보다 하나 작은 크기까지 입력할 수 있다. 범위를 넘어서는 값이 입력되면 다시 입력하라고 동일 메시지가 반복된다. 3가지 값을 모두 지정하면 Map 이 생성되며 console 창에 Map 이 표시된다.

 [![video](https://img.youtube.com/vi/Ru3OZ_lyioQ/0.jpg)](https://www.youtube.com/watch?v=Ru3OZ_lyioQ)


# 게임 진행
* 행과 열에 목표 좌표를 입력하여 게임을 진행한다. 행과 열은 각각 Y축과 X축에 해당하는 알파벳을 입력하면 된다. Map 생성 시와 마찬가지로 범위를 넘어서는 값이 입력되면 다시 입력하라고 동일 메시지가 반복된다.
* 선택한 타일의 최근접 타일(위, 아래, 좌, 우, 대각선에 위치)에 지뢰가 없으면 선택한 타일에 0이 표시되며, 주변 타일까지 순회하면서 동일한 작업을 진행하며, 선택한 타일의 최근접 타일에 지뢰가 있으면 최근접 타일 중 몇 개의 타일에 지뢰가 존재하는지 숫자로 선택한 타일에 나타나고 계산이 그 타일에서 종료된다.
 
 [![video](https://img.youtube.com/vi/S1WDWclmaYE/0.jpg)](https://www.youtube.com/watch?v=S1WDWclmaYE)

# 승리
* 위의 방식을 반복하여 지뢰를 제외한 모든 타일을 열면 승리 메시지와 함께 게임이 종료된다.

 [![video](https://img.youtube.com/vi/S1WDWclmaYE/0.jpg)](https://www.youtube.com/watch?v=S1WDWclmaYE)

# 패배
* 선택한 타일이 지뢰인 경우 지뢰를 뜻하는 m 이 선택한 타일에 나타나고 패배 메시지와 함께 게임이 종료된다.

 [![video](https://img.youtube.com/vi/59WF2fXTbDQ/0.jpg)](https://www.youtube.com/watch?v=59WF2fXTbDQ)
