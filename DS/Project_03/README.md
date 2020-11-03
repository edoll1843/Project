# 섬 그래프를 이용하여 최단 경로 찾기 프로그램

## 1.  Introduction

    이번 프로젝트는 섬 그래프를 이용하여 최단 경로 찾기 프로그램을 구현합니다. 이 프로그램은
    섬을 연결하는 섬에 대한 정보가 저장되어 있는 mapdata텍스트 파일을 통 하여 그래프를 구성합
    니다. 이 그래프를 기반으로 하여 Dijkstra, Bellman-ford 알고리즘을 이용해 섬의 경로와 거리를
    구합니다. 섬 그래프 정보는 방향성과 가중치 모두 가지고 있고 Matrix 형태로 저장 되어있습니다.
    만약 가중치가 음수일 경우 Dijkstra는 에러를 출력하고, Bellman-Ford에서는 음수 사이클이 발생
    한 경우 에러, 음수 사이클이 발생하지 않았을 때 최단 경로와 거리를 구합니다. FLOYD에서는 음
    수 사이클이 발생한 경우 헤러, 음수 사이클이 발생하지 않았을 경우 최단 경로 행렬을 구합니다.
    프로그램 동작은 명령어 파일에서 요청하는 명령에 따라 각각의 기능을 수행하고 그 결과를 로그
    파일에 저장합니다.
    Dijkstra는 start vertex와 end vertex를 입력을 받아 경로와 거리를 구합니다. 경로를 구하는 방법
    으로는 STL set을 사용하고, 결과로 찾은 최단 경로를 다시 순회하여 start vertex부터 end vertex
    순으로 경로를 구합니다.
    Dijkstra with min heap 방법으로는 Dijkstra와 알고리즘은 동일하지만 STL set을 쓰는 대신에 min
    heap을 사용하여 구현을 합니다.
    Bellman-Ford는 start vertex와 end vertex를 입력을 받아 최단 경로와 거리를 구합니다. 거리의 가
    중치 weght가 음수인 경우에도 동작을 하며, 음수 weight에 사이클이 발생한 경우에는 알맞은 에
    러를 출력합니다.
    Floyd는 명령어 인자 없이 모든 쌍에 대하여 최단 경로 행렬을 구합니다. 거리의 가중 치 weght
    가 음수인 경우에도 동작을 하며, 음수 weight에 사이클이 발생한 경우에는 알맞은 에러를 출력
    합니다.

## 2. Algorithm

### 2.1 LOAD

    프로그램에 섬 Mapdata의 정보를 기반으로 하여 그래프를 형성합니다, 위의 그림처럼
    Matrix의 형태로 그래프의 정보를 관리합니다. 만약 LOAD 할 텍스트 파일이 없거나 읽을
    수 없을 경우, 에러코드를 출력하고 오류 코드 101를 출력합니다. 또한 하나의 커맨드 파
    일에서 LOAD가 2번 이상 성공하는 경우는 고려하지 않습니다
    섬을 이어주는 경로의 데이터 정보가 존재하는 텍스트파일의 파일명인 filepath를 불러 와
    ifstream형의 변수로 선언을 해주고 fin.open()함수를 사용하여 파일을 열어줍니다. 만약 파일이 제
    대로 열리지 않았을 경우 에러 코드를 출력해주고 함수를 종료합니다
    벡터에 값을 저장할 때, n x n의 행렬을 가집니다 벡터의 개수는 n개이며, 각각의 벡 터에 존재하
    는 edge의 개수도 n개로 나타낼 수 있습니다. 따라서 맨 처음 for문을 이용하여 n번 만큼 반복을
    하며, 현재의 i를 vertex의 값으로 지정하여 추가해줍니다. 그 후 첫번째 값을 edge로 넣어준 후,
    n-1번 for문을 이용하여 해당 vector에 edge값을 n개 만큼 넣어 줍니다. 반복문이 종료하게 되면
    success를 return해주며 함수를 종료합니다.

### 2.2 PRINT

    섬 정보 데이터를 읽어 섬 정보를 출력하는 명령어입니다. Matrix 형태로 섬 정보를 출력
    합니다. 섬 정보 데이터가 존재하지 않을 경우엔 로그파일에 오류코드 202를 출력합니다.
    함수 실행 시 m_graph의 size 가 비어 있다면, 즉 아무 값도 들어가 있지 않는 상황이라면 알맞
    은 에러코드를 출력하고 함수를 return하여 종료를 합니다.
    graph 클래스 내에서 print 함수로 넘어가줍니다. 벡터 vertex를 m_pVhead 로 지정해준 후, 
    while문을 돌려 벡터 안에 들어있는 값인 edge들을 모두 출력을 해줍니다. While문 안에서 또다
    른 for문을 돌리면서, 들어온 값의 key값과 비교하여 edge숫자 전의 edge들에 값에 대해서는 0을
    출력해 주도록 합니다. 하나의 edge를 출력을 해주었다면, edge = edge -> GetNext()를 이용하여
    다음 edge 로 넘어가도록 해줍니다. vector = vector -> GetNext() 함수를 이용하여 벡터를 이동시
    킵니다. 이렇게 모든 벡터들을 거쳐가면서 출력을 마치면 반복문이 종료가 되고 함수를 종료를
    시켜줍니다.

### 2.3 DIJKSTRA

```C++
else if(DIJKSTRA)
 find start key, end key
 if(inserted vertex is insufficient)
 error : VertexKeyNotExist
 FindShortestPathDijkstraUsingSet(start,end)
 print error 
 ```
    mapdata를 기반으로 하여 시작점과 끝점의 최단경로와 거리를 찾는 알고리즘. STL set을
    이용하여 구현하였습니다. set을 이용하여 최단 Distance를 구분하여 최단거리와 경로를
    찾아내고, 시작점과 끝점의 Distance를 반환하여 출력합니다. 마찬가지로 LOAD 가 된 데
    이터가 없을 경우 에러를 출력하며, 명령어 인자가 부족한 경우에는 VertexKeyNotExist,
    인자로 입력한 Vertex 가 존재하지 않는 경우에는 InvalidVertexKey, 맵 데이터 중 음수의
    Weight 가 존재하는 경우에는 InvalidAlgorithm을 출력하며, 에러없이 정상적인 구동을
    완료하면 에러코드는 0입니다
    함수 실행 시 세 가지의 경우의 수에 따라 예외 처리를 해줍니다. 첫 번째, m_graph의 size 가 비
    어 있다면, 즉 아무 값도 들어가 있지 않는 상황입니다. 두 번째, 입력 받은 시작 vertex 와 마지
    막 vertex 값들이 m_graph 안에 있는지 FindVertex()함수를 확인 해 줌으로써 하나라도 NULL 값
    을 가지고 있는 경우, 해당 vertex가 그래프 존재하지 않는 상황입니다. 세 번째로
    IsNegativeEdge()의 함수가 true를 반환을 한다면, 그래프 안에 음수가 존재하는 상황입니다. 다음
    세 가지의 경우를 예외처리를 해주어 알맞은 result값을 return하여 함수를 종료합니다.
    graph 클래스 내에서 FindPathDijkstrausingset 함수로 넘어갑니다. 그 후 사용할 변수들 중, 거리
    를 저장할 dist 값들을 전부 IN_FINITY, 방문 여부를 확인하는 visited 값들을 전부 unvisited, 마지
    막으로 경로를 저장할 path값들을 전부 -1로 초기화를 해줍니다. while문을 이용하여 반복문을 실
    행시켜 주고, key 값이 end vertex의 key값과 동일할 경우 반복문을 종료하도록 if 문을 이용하여
    반복문을 벗어날 수 있도록 설정을 하였습니다. Vertex를 key 값에 해당하는 vertex, 해당 key 값
    의 visit 값을 visited, edge를 vertex의 head 로 지정을 해줍니다. While 문 조건에 edge를 넣어
    edge 가 next 로 이동하면서 방문을 기록하는 visit 배열안에 순서가 unvisited 로 되어 있을 시,
    이때의 edge를 거쳐서 가는 거리와 key 값에 해당하는 vertex 로 바로 가는 거리를 if 문을 이용
    하여 비교를 한 다음, 더 작은 값을 dist 안에 정보를 update를 해줍니다. 반복문을 벗어나게 된
    다면 stack 안에 있는 맨 첫번째의 second 값을 stack에서 꺼내 다음 key 값으로 지정을 해주고,
    stack의 맨 첫번째 값을 erase 해주어 그 값을 지워주게 됩니다. 그 후에 endvertex의 path를 따
    라가다 보면 경로를 알 수 있으므로, 거꾸로 찾아가는 방식으로 vector에 Vertex값들을 넣어주며,
    마지막으로 endVertex까지 오는 최단거리 값을 추가해주고 함수를 종료합니다

### 2.4 DIJKSTRAMIN

```C++
else if(DIJKSTRAMIN) 
 find start key, end key
 if(inserted vertex is insufficient)
 error : VertexKeyNotExist
 FindShortestPathDijkstraUsingMinHeap(start,end)
 print error 
``` 
    DIJKSTRAMIN의 경우 flowchart 에서도 볼 수 있듯이, DIJKSTRA 와 같은 알고리즘을 사용한다는
    점을 알 수 있습니다. 초반에 세 가지에 대하여 예외 처리를 해주고, vertex 와 edge를 while 문
    을 통하여 바꿔 주면서 최단 거리를 비교하며 정보들을 업데이트를 해주며 최단거리를 구해줍니
    다. Min Heap을 사용한다는 점에서 DIJKSTRA와 다르다는 것을 알 수 있습니다

### 2.5 BELLMANFORD

```C++
Else if(BELLMANFORD)
if(Graph is not exist)
error : GraphNotExist
if(Vertex is not exist(start or end)
error : InvalidVertexKey
if(Graph have – Weight)
error : InvalidAlgorithm
p = Head vertex
count = 0, count2 = 0, dis(arr), dis2(arr)
while(count != graph size-1)
while(count2 != graph size)
if(dis of p != infinity)
 while(visit all of edge of p)
 if( need update distance of edge) 
14
 update dis,dis2
 count2++
 p = next vertex
count2 = 0
count++
p = Head vertex
doing again only use dis
if(dis != dis2)
return empty vector //error
else
push total distance
push path
return vector(include path and total distance) 
```

    함수 실행 시 세 가지의 경우의 수에 따라 예외 처리를 해줍니다. 첫 번째, m_graph의 size 가 비
    어 있다면, 즉 아무 값도 들어가 있지 않는 상황입니다. 두 번째, 입력 받은 시작 vertex 와 마지
    막 vertex 값들이 m_graph 안에 있는지 FindVertex()함수를 확인해 줌으로써 하나라도 NULL 값을
    가지고 있는 경우, 해당 vertex 가 그래프 존재하지 않는 상황입니다. 세 번째, 음수 사이클이 존
    재하는 상황입니다. 다음 세 가지의 경우를 예외처리를 해주어 알맞은 result값을 return 하여 함
    수를 종료합니다.
    graph 클래스 내에서 FindPath 함수로 넘어가줍니다. 그 후 사용할 변수들 중, 거리를 저장할
    dist 값들을 전부 IN_FINITY, 경로를 저장할 path 값들을 전부 -1 로 초기화를 해줍니다. for 문을
    사용하여 m_vSize 만큼 반복을 하도록 설정을 합니다. While 문 조건에 vertex를 넣어 vertex 가
    next 로 이동하면서 vertex 값이 존재하는 경우에 반복문을 실행하도록 합니다. key 값에 해당하
    는 vertex, 해당 key 값의 visit 값을 visited, edge를 vertex의 head 로 지정을 해줍니다. While
    문 조건에 edge를 넣어 edge 가 next 로 이동하면서 방문을 기록하는 visit 배열안에 순서가
    unvisited 로 되어 있을 시, 이때의 edge를 거쳐서 가는 거리와 key 값에 해당하는 vertex 로 바
    로 가는 거리를 if문을 이용하여 비교를 한 다음, 더 작은 값을 dist 안에 정보를 update를 해줍니
    다.
    업데이트를 마친 후, 한번 더 위와 같은 while 문 2 개를 사용, 조건을 vertex, edge를 넣어주어
    한번 더 탐색을 해줍니다. 만약 음수 사이클이 존재를 할 경우 새로운 업데이트가 다시 생기기
    때문입니다. 업데이트를 한번 더 해줄 경우, v 값 맨 앞에 IN_FINITY 값을 넣어주어 음수 사이클
    이 존재함을 확인을 하도록 합니다.
    그 후에 endvertex의 path를 따라가다 보면 경로를 알 수 있으므로, 거꾸로 찾아가는 방식으로
    vector에 Vertex 값들을 넣어주며, 마지막으로 endVertex까지 오는 최단거리 값을 추가해주고 함
    수를 종료합니다.

### 2.6 FLOYD

    함수 실행 시 m_graph의 size 가 비어 있다면, 즉 아무 값도 들어가 있지 않는 상황이라면 알맞
    은 에러코드를 출력하고 함수를 return하여 종료를 시켜줍니다.
    기존에 Manager 가 가지고 있던 graph의 정보를 새로운 벡터 vetor<vector<int>형에 저장을 해
    줍니다. 이는 while 문을 2 개 사용하여 vector를 이동하고 해당하는 벡터에 있는 edge 들을
    while 문을 이용하여 next 로 이동하면서 graph의 정보를 벡터로 그래도 가져오게 됩니다. 
  
  
