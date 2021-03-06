# 과제

# Assignment 1-1

    1번 문제는 도형에 관한 별 찍기($) 프로그램이다. 사용자로부터 입력을 받고(입력은 3의 거듭제
    곱으로 1부터 7까지 입력이 가능하다.) 프로그램의 문자는 ‘$’ 사용하여 출력한다.
    형태는 3의 1승의 정사각형 모양으로 중간은 구멍이 있는 형태이다. 1 부터 입력 받은 숫자 까지
    반복하여 출력하는 형태인데 그 크기가 커질수록 이전에 승수의 모양을 합쳐서 만든 모습이다.
    중간은 예외없이 항상 구멍이 뚫려 있다

# Assignment 1-2

    2번 문제는 에라토스테네스의 체를 이용하여 모든 소수를 찾는 프로그램을 구현하는 것이다. 사
    용자로부터 인풋을 받아 2부터 인풋 사이에 있는 모든 소수를 찾는다. 1은 소수가 아니므로 제외
    한다. 이 문제는 5단계의 스텝이 존재한다.
      1. N 이하의 모든 소수를 찾으려면 2에서 N사이의 모든 정수를 먼저 만든다.
      2. 가장 작은 소수 즉 p=2부터 시작한다.
      3. N보다 작은 p의 모든 배수를 표시한다.
      4. P의 배수 계산이 끝났으면 그 다음 소수의 배수를 계산한다.
      5. P<=루트n까지 반복한다.


# Assignment 1-3

    3번 문제는 사용자로부터 bit stream을 input으로 받는다.
    그 후 다음과 같은 함수를 거치게 된다.

      S0=사용자로부터 받은 bit stream
      Sn = f(g(Sn-1))+1 → n is odd
         = f(g(Sn-1))+0 → n is even
 
    식을 설명하자면 bit를 먼저 1011→1101와 같이 MSB와 LSB기준으로 자리를 바꿔주는 것이 G함
    수이다. g함수를 거치고 1011 → 0100과 같이 0은 1로 1은 0으로 값을 반전시켜주는 것이 f함수이
    다. 그 후 만약 n이 홀수 일 경우 1을 맨 처음 bit에 넣어 bit수를 늘려주고 짝수일 경우 0을 넣
    어준다. 마지막으로 단계가 끝나는 시점의 bit를 10진수로 표현한다. 여기서 만약 overflow가 일어
    나게 되면 제일 큰 숫자를 출력한다.


# Assignment 1-4

    4번 문제는 input으로 받은 문자열을 소문자 혹은 대문자를 대문자 혹은 소문자로 변환하고 앞뒤
    의 위치를 바꿔주는 프로그램이다.
    여기서 C과 C++의 표준 라이브러리 함수를 사용하지 않고 즉 문자열 유형의 함수를 사용하지
    않고 프로그램을 진행한다.

# Assignment 1-5

    5번의 문제는 사용자로부터 행렬을 입력 받고 그 크기에 해당하는 Matrix판을 만들어 random한
    숫자들로 채운다. 이 숫자들은 중복이 되지 않고 값이 0부터 Matrix의 크기 보다 1작은 수만큼
    값이 채워져야 한다. 입력 받은 행은 1보다 같거나 커야 하고 열은 100보다 같거나 작아야 한다.
    그리고 행과 열을 바꿔서 출력한다. 

# Assignment 1-6

    6번 문제는 C++언어를 이용하여 tic-tac-toe게임을 구현하는 것이다. 이 게임은 두 사람이서 번갈
    아 가며 3x3 표에 O와 X를 표시하여 가로, 세로, 대각선으로 동일한 모양이 나오게 되면 해당하
    는 player는 승리를 하는 프로그램이다. 만약 판이 꽉 찼는 경우에도 승자가 나오지 않게 되면
    Draw를 출력해준다.


# Assignment 1-7

    2차원 데카르트 좌표에 3개의 점(P1,P2,P3)를 사용자로부터 입력 받아 P1→P2→P3으로 가는 방향
    을 시계, 반시계, 직선으로 나눠 출력하는 프로그램이다. P1,P2,P3를 연결하는 선은 겹치지 않는다
    만약 두 벡터 u = (m1,m2,m3) v =(n1,n2,n3)이 있다고 했을 때 u X v = (m2n3-m3n2,m3n1-
    m1n3,m1n2-m2n1)이다. 이렇게 두 벡터의 외적을 구하고 m3과 n3이 0인 것을 고려하여 다음 식
    을 얻을 수 있다. u X v = (0,0, m1n2-m2n1) 이로서 m1n2 – m2n1의 부호에 따라서 점 P1,P2,P3의
    방향을 구할 수 있다. 오른손 법칙에 의하여
    D = m1n2 -m2n1가 D>0 반시계 방향, D = 0 직선, D<0 시계 방향을 구하였다.

# Assignment 1-8

    8번 문제는 시저 암호를 이용하여 주어진 txt를 해독하는 프로그램이다.
    일반 텍스트의 각 문자가 특정 숫자만큼 shift되는 암호 유형이다. 예를 들어 A를 3만큼 shift한다
    면 A, B, C, D 즉 A에서부터 오른쪽에 3번째에 있는 알파벳인 D가 출력이 된다. 엘리스는 텍스트
    에 16진수로 저장된 시저 암호를 사용하여 Bob에게 암호를 보냈지만 아스키 문자로 변환하여 시
    저 암호를 통해 일반 텍스트를 찾아야한다. 하지만 엘리스는 shift되는 수를 알려주지 않았기 때
    문에 0부터 127까지 모두 shift하면서 엘리스의 평문을 얻는 프로그램이다.

# Assignment 1-9

    9번 문제는 전화 요금제에서 월별 전화 요금을 계산하는 프로그램이다. 표에 표시된 것처럼 월
    기본 요금, 기본 제공 문자, 기본제공 음성통화, 추가 요금이 다른 4가지 유형의 요금제가 있을
    경우 사용자로부터 요금제 유형, 사용한 문자 량, 통화한 음성통화 시간을 입력 받아 기본요금과
    지불해야하는 추가 요금의 총을 구하는 프로그램이다.

# Assignment 1-10

    10번은 Hit & blow 라는 게임을 구현하는 것이다. 게임이 시작되면 프로그램은 겹치지 않고 0에
    서 9사이의 4개의 난수를 설정한다. 이때 이 숫자는 표시되지 않는다. 그 후 매 턴마다 숫자를 추
    측하고 입력할 때마다 힌트가 표시된다. 난수와 입력한 숫자가 같은 위치에 같은 숫자가 있다면
    Hit을 표시하고 같은 숫자지만 다른 위치에 있다면 blow를 표시한다. 기회는 10번이며 그 안에
    정확한 숫자를 입력하면 Win을 출력한다.

# Assignment 2-1

    2-1은 주어진 파일(source.txt)를 사용하여 각 줄을 input으로 넣어 사용자로 하여금 각 줄을 print
    하는 프로그램을 작성하는 것이다. 이때 프로그램에 입력할 때 정확도와 속도를 표시해야 한다.

    속도: 모든 문자/경과 시간

    프로그램에 문자를 입력하면 시간 측정이 시작되고 ENTER를 입력하면 종료된다. 종료됨과 동시
    에 새로운 시간 측정이 시작된다. 결과는 result.txt에 저장한다.

    정확도: 올바른 문자/원문 길이

    화면은 문자를 입력하고 초기화 되며 그 후 이전 입력 확인 결과를 인쇄한다. 처음에는 정확도가
    0이고 속도도 0이다. 역시 결과는 result.txt에 저장한다.

    입력 받을 text와 입력할 text를 연다. 한 문장을 읽으면 바로 사용자로 입력을 받는데 사용자가
    입력을 시작할 때 측정하는 방법을 찾다가 키보드로부터 입력이 있으면 반응하는 함수를 찾았다.
    이부분이 제일 고민이 였던 부분이다. 그리고 time을 cin함수 위 아래로 시작과 끝을 정해 시간을
    측정하였다. 그리고 system함수로 화면 초기화를 하였다. 문장은 공백까지 포함하기 위하여
    cin.getline을 이용하였고 문장의 char 수를 count 해주는 함수를 따로 빼고 원문과 비교하는 함수
    도 따로 밖으로 빼서 사용하였다.

# Assignment 2-2

    2-2문제는 포인터 변수를 사용하여 다른 변수의 주소를 나타내고 주어진 양식 대로 출력하는 프
    로그램이다. 조건은 1부터 6까지 값을 가진 2x3배열이있다. 변수는 a,b,c,d,e,f,g,h,i,j가 존재한다.
    1) a,b,c,d,h,i,j를 순서대로 값을 출력한다.
    2) 포인터를 사용하여 1~6값을 가리키는 변수의 주소를 인쇄한다.
    3) 포인터 e, f, g의 값을 순서대로 출력한다.
    1번 조건인 a,b,c,d,h,I,j를 출력 한 결과 값이다. A는 1을 가리키고 있고 i와 h는 1을 가리키고 있
    는 a를 가리키고 있다. C는 2, d는 3, b는 4를 가리키고 있으며 j는 c를 가리키고 있는 것을 알 수
    있다.
    2번 조건은 각 숫자들에 대한 주소 값들을 출력하는 조건이다.
    3번은 e,f,g 즉 값이 하나가 아닌 3개 6개를 출력하는 것을 확인 하였다.

# Assignment 2-3

    2-3번 문제는 사용자로부터 x와 y의 값을 입력 받아 2차원 배열을 생성하고 시계방향으로 소용돌
    이 모양으로 숫자가 증가되는 꼴의 배열을 출력한다.

# Assignment 2-4

    2-4문제는 strstr함수의 기능을 구현하는 것이다. strstr함수는 strSearch로 표시된 문자열이 포인터
    변수 str로 표시된 문자열에 포함이 됐는지 찾는 것이다. 그러나 이번의 문제는 예를 들어, str은
    oh sad day! 이고 strSearch는 sad, strChange는 happy라고 가정했을 때 str은 Oh happy day! 되는
    것이다. 즉 str은 원문이고 strSearch는 찾는 문자, strChange는 교체할 문자라고 정의할 수 있다.
    각각의 크기는 100이고 string에 관련된 함수는 일체 쓰지 않는 조건으로 프로그램을 작성한다.
    또한 찾는 문자가 없는 NULL일 경우도 고려해준다.

    원본 문자열을 입력 받는다. 변경 전 문자열은 sad가 되고 변경 후 문자열은 Happy가 된다. 그리
    고 sad자리에 변경된 문자열인 Happy가 자리하고 있는 것을 확인하였다.

    변경 전 문자열이 aaa로 원본 문자열에 존재하지 않는 경우 즉 NULL경우도 고려해준 모습이다.


# Assignment 2-5

    2-5번 문제는 환자 정보의 클래스를 구현하는 프로그램이다. 환자의 개인 정보를 저장하는
    PatientInfo class를 구현한다. class에는 환자의 이름, 주소, 등록번호, 전화번호를 저장하는 private
    변수가 있다. 화면에 4명의 데이터를 입력 받고 모든 변수 값을 출력하는 프로그램을 만든다.

    환자의 정보를 담을 class를 선언해준다. Private 부분에 변수들을 선언하고 public엔 함수들을 선
    언하였다. get과 set의 함수들이다. Class의 생성자 부분을 초기화 해주고 main에서 4명의 환자를
    만들고 값을 입력 받는다. 입력을 받는 것과 동시에 set함수로 값들을 넣어준다. 4명 환자들의 정
    보를 모두 넣어 줬으면 get함수로 출력을 해준다.


# Assignment 2-6

    369 게임 프로그램 class로 작성하는 프로그램이다. 규칙은 다음과 같다.
    1. Class 이름은 ThreeSixNine이다.
    2. Value는 1부터 300까지 들어 갈 수있다.
    3. 3, 6, 9가 들어가면 !를 출력하고 아닌 경우에는 숫자를 출력한다.
    4. 10개마다 라인 교체를 한다

    main함수는 주어진 상태이고 class 이름은 ThreeSixNine으로 하였다. 수행할 print369의 함수는 1
    부터 사용자의 입력까지 이중의 for문을 돌면서 369의 여부를 판단해준다. 숫자를 char로 바꿔주
    면서 3,6,9와 같을 때 카운트가 올라가고 올라간 카운트만큼 “!!”를 출력하게 된다. 문제의 예시처
    럼 10단위로 줄을 바꾸어 주었다.

# Assignment 2-7

    두개의 클래스 Pharmacist, Buyer를 작성하고 마스크를 구입하는 프로그램을 만든다.
    사용자와 대화 형식으로 프로그램이 진행이 되고 메뉴는 다음과 같다.
    
      0. 프로그램 종료
      1. 마스크 재고 물어보기
      2. 마스크 가격 물어보기
      3. 마스크 구매하기
      4. 내 마스크 개수 확인하기
      5. 내 지갑 확인하기
      
    사용자로부터 0을 입력 받으면 그대로 프로그램은 종료된다. 1,2,4,5번을 입력 받으면 클래스로부
    터 각각의 값을 가져와 인쇄해준다. 3번을 입력 받으면 다시 한번 구매할 마스크의 수량을 묻고
    입력을 받는다. 만약 사용자의 돈이나 마스크의 재고가 부족하다면 에러 매세지를 출력한다. 혹은
    마스크의 재고가 부족하고 돈이 부족 할 시 그에 맞는 에러 매세지를 출력한다.

    1을 입력하여 마스크 개수를 확인하고 2를 입력하여 마스크의 가격, 4를 입력하여 나의 마스크
    개수를 확인하고 5를 눌러 나의 잔액을 확인한다. 3을 입력하여 마스크 구매하고 구매할 수량을
    입력한다. 1을 눌러 마스크의 재고가 바뀐 것을 확인하고 4를 입력하여 나의 마스크 개수가 2개
    된 것을 확인한다. 마지막으로 나의 잔액이 바뀐 것을 확인하고 0을 눌러 프로그램을 종료한다.

    계속 하여 나올 메뉴판은 따로 함수로 빼서 사용했다. 구매자와 판매자의 class를 만들고 반복문
    을 돌면서 프로그램이 진행된다. 조건문으로 사용자의 입력이 0일 때 프로그램 종료, 1,2,4,5일 때
    class로부터 값을 가져와 출력을 해주었다. 만약 사용자가 3을 입력하여 마스크를 구매 할 시 구
    매할 마스크의 수량을 다시 입력 받아 에러매세지 출력 여부를 판단해주고 에러가 아닐 시 구매
    할 마스크 만큼 재고와 지갑의 돈을 업데이트 해주었다.


# Assignment 2-8

    Class와 상속을 사용하여 입력된 문자열로 환율을 계산하는 프로그램을 작성한다. 환율은 다음과
    같다.
      KRW:USD = 1200: 1
      KRW:JPY = 1100:100
      KRW:EUR = 1300:1
      KRW:CNY = 170:1
    사용자로부터 받는 input의 양식은
    [가격] 환전받을 나라 to 환전 후 나라가 된다.
    클래스는 총 6개가 존재하고 Exchange 클래스는 슈퍼 클래스가 되고 다른 클래스들은 하위 클래
    스들이다. 교환된 값은 소수점 첫째 자리에서 반올림한다.

    각 나라마다 class를 만들고 슈퍼 클래스인 exchange class도 만들었다.
    반복문을 돌면서 사용자의 대답이 Y이거나 y일 때 진행했다. 사용자로부터 환전할 돈과 나라들의
    이름을 잘라 값들을 비교해주었다. 환전 전의 나라를 비교하여 일치하는 클래스의 함수로 들어가
    환전 후의 나라와 환율을 계산하여 환전 후의 돈을 출력하는 식으로 진행하였다. 만약 n이 입력
    으로 들어가면 프로그램을 종료한다. cin으로 값을 입력 받을 때 cin을 비워줘야 다음 환율을 계산
    하는데 cin이 비워지지 않아서 애를 먹었다. 결국 cin.ignore()함수를 사용하여 문제를 해결 하였다.

# Assignment 3-1

        Linked list를 이용하여 카페 메뉴를 관리하는 프로그램을 구현한다. 프로그램은 카페 메
        뉴 정보를 저장하고 카테고리 별로 메뉴를 저장하는 ‘input.txt’에서 읽으며 카테고리가 저장된다.
        카테고리 노드, 메뉴 및 가격이 메뉴 노드에 저장된다. 이 프로그램은 LOAD, PRINT, INSERT,
        SEARCH, DELETE의 기능을 수행한다. 삽입은 가격을 기준으로 오름 차순으로 정렬이 된다. 만약
        같다면 알파벳 순서대로 삽입한다.
        이때 대문자와 소문자는 구별하지 않고 입력 값의 변수가 부족하면 저장되지 않고 에러 메시지를
        출력한다. 노드 자체의 속성을 변경하는 것이 아닌 노드 자체를 변경해야 한다.

        사용자가 입력할 수 있는 번호판을 먼저 만든다. 1번이 입력되면 텍스트 파일을 읽어와 탭을 기준
        으로 잘라 하나의 노드에 정보를 저장한다. 입력이 되지 않은 정보가 있는지 확인하고 있다면 에
        러를 출력하고 없다면 삽입을 진행한다. 2를 선택하면 모든 노드를 출력하게 한다. 3을 입력하면
        수동으로 메뉴를 추가할 수 있다. 4를 입력하면 검색하는 기능으로 카테고리를 찾아 카테고리에
        맞는 데이터들을 출력해준다. 5를 입력하면 찾고 싶은 메뉴를 찾게 해준다. 6은 삭제를 해주는 함
        수로 입력을 받고 그에 맞는 정보를 삭제 후 다시 연결해준다. 7을 입력하면 프로그램을 종료한다.
        1번은 single linked list로 처음 head로 이뤄진다. 옆에는 각 카테고리마다 연결 리스트가 존재하
        며 각 리스트의 첫번째는 연결이 되어있다. 이번 프로젝트에서 비교적 쉬운 편에 속하였다

# Assignment 3-2

        Circular Doubly Linked list를 사용하여 강의 목록 관리 프로그램을 작성 및 관리한다. 관리되는 강
        의의 특성은 강의의 이름, 교수 및 학년이며 이 프로그램의 관리 기능은 다음과 같다.
            ✓ Insert lecture at beginning
            ✓ Insert lecture at last
            ✓ Insert lecture at position
            ✓ Delete lecture
            ✓ Update lecture
            ✓ Search lecture
            ✓ Search professor
            ✓ Search grade
            ✓ Sort by grade in ascending order
            ✓ Display lecture list
            ✓ Reverse lecture list
        강의 관리 프로그램은 클라스를 기반으로 구현한다. 또한 같은 등급의 강의가 있으면 이름 별로
        정렬하고 중복 강의는 없다고 한다. 종료 기능 할때까지 메뉴는 반복적으로 인쇄되며 노드의 속
        성 값이 아닌 노드 자체를 변경해야한다. 함수 3 즉 포지션 별로 삽입을 수행할 땐 다시 입력하
        도록 예외 처리를 한다.

        Circular Doubly Linked list를 사용하여 전체적인 프로그램을 구현하였다. 1번을 입력 받으면 맨 처
        음에 입력을 한다. 즉 head가 되게 구현해준다. 2번을 입력하면 맨 마지막에 입력하는 것으로 tail
        이 되게 해준다. 3번을 입력하면 원하는 포지션에 넣을 수 있는데 만약 전체 포지션의 범위를 벗
        어나면 에러를 출력해준다. 만약 tail의 다음인 tail+1에 추가할 수 있도록 해주었다. 4를 입력하면
        리스트를 돌며 원하는 강의를 지우고 5를 입력하면 강의를 업데이트한다. 6을 입력하면 강의를 검
        색하고 7은 강의 중 교수님이 맡은 강의는 전부 출력해준다. 8은 검색할 학년이 있는 강의를 전부
        출력해주고 10번은 전체 강의를 출력해준다. 9번은 오름차순으로 정렬하는 것인데 만약 학년이
        같다면 강의의 이름의 크기를 비교하여 오름차순으로 정렬해준다. 11번은 역으로 노드를 바꾸는
        것인데 속성을 바꾸는 것이 아니고 노드 자체를 움직였다. 맨 마지막 노드와 그 앞의 노드의 연
        결을 끊고 끊은 노드를 기준으로 맨 뒤에 삽입하게 하고 다시 연결해 주었다.


# Assignment 3-3

        먼저 크기와 숫자를 입력하고 숫자 순서대로 BST를 구현한다. 큐를 사용하여 BST의 inorder,
        postorder, preorder를 출력한다. 큐에는 push, pop, front 및 isEmpty 함수가 포함되어야 하며 큐는
        라이브러리가 아닌 구현해야한다. 겹치는 숫자는 없다고 가정하며 모든 숫자를 양의 정수로만 입
        력한다.

        사용자로부터 입력할 숫자의 개수와 숫자를 입력 받은 후 출력의 방식을 선택하여 각각 맞는 출
        력을 해주었다. 큐를 직접 구현해야 하는 것이 번거로웠다.
        BST를 구현하는 과제로 데이터구조때 배웠던 것을 생각하여 구현하였다. 또한 큐와 각 순회를 출
        력하는 것 또한 이전에 배운 것을 토대로 구현하였다.


# Assignment 3-5

        2048게임은 4*4의 판을 기준으로 진행되며 16개의 블록으로 구성된 보드에서 실행된다. 한 블록
        에서는 숫자 값과 좌표 값이 있다.
        2048게임은 MyBlock 클래스와 Myboard 클래스를 사용하여 구현되며 Mybolck의 첫 번째 멤버
        변수는 각 블록의 숫자값을 나타내는 변수이고 두번 째 및 세번쨰 멤버 변수는 x,y 좌표 값을 저
        장하는 변수다. Myblock 클래스는 4개의 Myblock 포인터가 있고 각 블록의 위 아래 왼쪽 및 오
        른쪽이 블록에 대한 포인터이다. Head는 0,0으로 사용자의 입력에 따라 작동하는 up, down, left,
        right의 네 가지 멤버 함수가 있다. 프로그램이 실행되면 보드가 생성이 되고 각 블록의 좌표값이
        초기화 된다. 각 블록의 숫자는 각 객체의 멤버 변수에서 임의로 생성 및 초기화된다.
        게임의 룰은 각 턴이 시작되기 전에 임의의 위치에서 빈 블록에 숫자 2를 생성한다. 동작을 사용
        자로부터 입력받고 입력에 따라 함수가 실행된다. 각 기능에서 모든 블록은 입력 방향의 끝에 있
        는 블록으로 이동된다. 만약 동일한 값을 가진 두 블록이 만나면 수는 합쳐진다. 빈 블록이 없고
        더 이상 블록을 추가할 수 없는 경우 게임은 진다. 2048을 만들면 win을 출력하고 프로그램을 종
        료한다.

# 프로젝트

# 2048 MFC

## Introduction 

    2048 게임은 16개의 사각 블록으로 구성된 4x4 보드에서 하는 퍼즐 게임이다. 이
    게임의 목표는 2의 블록을 움직여 2048을 만드는 것이다. 게임을 하는 동안
    블록을 움직일 수 없을 때 게임은 끝난다.
    이 프로젝트의 목표는 두가지로 MFC를 이용한 디스플레이 4x4 보드는 16개의
    블록을 가진 모델 다이어그램을 사용하는 것이 하나이고 키보드와 마우스 입력에
    따라 4x4 보드를 조작하여 2048 게임인 프로그램을 작성하는 것이 나머지
    하나이다. 세부 메뉴 선택에 따라 프로그램은 보드위에 숫자나 숫자, 색상을
    표현할 수 있어야 하며 키보드와 마우스 입력을 기록하는 로그 파일을 생성할 수
    있어야 한다. 프로그램을 시작할 때 보드의 임의의 위치에 2번 블록이 생성되고
    게임이 시작된다. 플레이어는 마우스나 키보드를 사용하여 보드를 회전하거나
    블록을 이동할 수 있으며 프로그램은 플레이어가 수행한 마우스나 키보드 작동
    기록을 로그 파일로 저장할 수 있다. 플레이어의 선택에 따라 프로그램은 번호나
    색상을 보드에 표시할 수 있다. 키보드 입력에 의한 보드의 움직임은 위, 아래,
    좌, 우 4가지 방향에 따라 보드의 블록을 이동시켜 게임을 실행할 수 있다.
    키보드 input에 따르면 게임에 사용되는 블록은 해당 방향의 가장자리에 위치한
    빈 블록으로 이동한다. 블록의 이동이 완료되면 빈 블록 중 하나에서 숫자 2가
    생성된다.
    보드는 16개의 블록으로 구성되어 있으며 각 블록에는 1개의 번호가 있다. 한
    블록은 위, 아래, 왼쪽, 오른쪽으로 표시할 수 있는 4개의 포인터가 있다. 4x4
    보드로 구성된 16개 블록의 다이어그램의 Block_Header는 왼쪽 상부 블록을
    가리킨다. 각 블록은 4개의 포인터를 사용하여 각 블록을 기준으로 위, 아래,
    왼쪽, 오른쪽으로 위치한 블록을 가리킨다. 포인터가 NULL값을 가진 포인터를
    가리키는 위치에 블록이 없는 경우 혹은 블록에 값이 없으면 블록 값이 0으로
    설정된다.


