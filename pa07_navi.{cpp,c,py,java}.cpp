//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <string>
//#include <queue>
//#include <algorithm>
//using namespace std;
//int start_x = 0;
//int start_y = 0;
//int end_x = 0;
//int end_y = 0;//임시저장 값
//int m = 0;//지도의 크기
//int n = 0;//지도의 크기
//int move_go[4][2] = {{-1,0},
//                     {1,0},
//                     {0,-1},
//                     {0,1}};
//struct Node{
//    int x,y;
//    int g,h,f;
//    int state;
//    Node*parent;
//    bool operator<(const Node& other) const {
//        return this->f > other.f;
//    }
//};
//vector<Node*>closed_node;
//
//int euclidean_distance(Node* a, Node* b)
//{
//    return (pow(abs(a->x-b->x)*3,2)+pow(abs(a->y-b->y)*3,2))*3;
//}
//int menhatan_distance(Node*a,Node*b)
//{
//    return abs(a->x-b->x)+abs(a->y-b->y);
//}
//bool cmp(Node* a,Node * b)
//{
//    if(a->f<b->f)
//    {
//        return a->f<b->f;
//    }
//    else if(a->f==b->f)
//    {
//        if(a->g<b->g)
//        {
//            return a->g<b->g;
//        }
//        else if(a->g == b->g)
//        {
//            return a->h<b->h;
//        }
//    }
//
//}
//int A_Star(Node **nodes)
//{
//    int result = 0;
//    Node * explore_node;
//    Node * Start_node = &nodes[start_x][start_y];
//    Node * end_node = &nodes[end_x][end_y];
//    Start_node->g = 0;
//    Start_node->h = euclidean_distance(Start_node,end_node);
//    Start_node->f = Start_node->g+Start_node->h;
//    priority_queue<Node*>open_node;
//    open_node.push(Start_node);
//    while(!open_node.empty())
//    {
//
//        Node * current_node = open_node.top();
//        //open_node.erase(remove(open_node.begin(),open_node.end(),current_node),open_node.end());
//        open_node.pop();
//        if(current_node->x == end_node->x&&current_node->y == end_node->y)
//        {
//            while(current_node->parent != nullptr)
//            {
//                current_node = current_node->parent;
//                result+=3;
//            }
//            return result;
//        }
//        current_node->state = -1;
//        for(int i =0;i<4;i++)
//        {
//            int explore_x = current_node->x+move_go[i][0];
//            int explore_y = current_node->y+move_go[i][1];
//            if(explore_x<m&&explore_x>=0&&explore_y<m&&explore_y>=0)
//            {
//                explore_node = &nodes[explore_x][explore_y];
//
//                if(explore_node->state==1) { //만약 접근이 가능한 노드라면 실행한다.
//                    explore_node->g = menhatan_distance(Start_node,explore_node);
//                    explore_node->h = euclidean_distance(end_node, explore_node);
//                    explore_node->f = explore_node->g + explore_node->h;
//                    explore_node->parent = current_node;
//                    open_node.push(explore_node);
////                        if(explore_x==end_x&&explore_y==end_y)
////                        {
////                            return explore_node->f;
////                            while(current_node->parent != nullptr)
////                            {
////                                current_node = current_node->parent;
////                                result += 3;
////                            }
////                            result += 3;
////                            open_node.clear();
////                            break;
////                        }
//                }
//                else{}
//            }
//        }
//    }
//    return result;
//}
//int main(void)
//{
//    int zero_num;//0인 셀의 개수
//    int ob_num;//장애물의 수
//    int ob_x1,ob_y1,ob_x2,ob_y2;
//    string str;
//    cin>>m>>n;
//    int result= 0;
//    Node **nodes = new Node *[m];
//    for(int i =0;i<m;i++)
//    {
//        nodes[i] = new Node[n];
//    }
//    for(int i =0;i<m;i++)
//    {
//        for(int j = 0;j<n;j++)
//        {
//            nodes[i][j].y = j;
//            nodes[i][j].x = i;
//            nodes[i][j].state = 1;
//        }
//    }
//    cin>>zero_num;
//    for(int i = 0;i<zero_num;i++)
//    {
//        cin>>start_x>>start_y>>end_x;
//        nodes[start_y][end_x].state = start_x;
//        Node * node1 = &nodes[start_y][end_x];
//        closed_node.push_back(node1);
//    }
//    cin>>str>>start_x>>start_y;
//    nodes[start_x][start_y].state = 1;//시작점 좌표
//    cin>>str>>end_x>>end_y;
//    nodes[end_x][end_y].state = 1;//도착점 좌표
//    cin>>str>>ob_num;
//    for(int i =0;i<ob_num;i++) {
//        cin >> ob_x1 >> ob_y1 >> ob_x2 >> ob_y2;
//        int sx = min(ob_x1,ob_x2);
//        int sy= min(ob_y1,ob_y2);
//        int bx = max(ob_x1,ob_x2);
//        int by = max(ob_y1,ob_y2);
//        for (int j = sx; j <= bx; j++) {
//            for (int k = sy; k <= by; k++) {
//                nodes[j][k].state = -1;
//                Node * node1 = &nodes[j][k];
//                closed_node.push_back(node1);
//            }
//        }
//    }
//
//    result = A_Star(nodes);
//    cout<<result;
//
//
//}
//
