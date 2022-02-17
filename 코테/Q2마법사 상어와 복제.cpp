#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Fish {
    int x;
    int y;
    int d;
};

vector<Fish> map[5][5];
vector<Fish> c_map[5][5];
vector<Fish> d_map[5][5];

int smell[5][5];
int Sx, Sy;
int S;
int M;

int dx_fish[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy_fish[9] = { 0,-1,-1,0,1,1,1,0,-1 };

int dx_shark[5] = { 0,-1,0,1,0 };
int dy_shark[5] = { 0,0,-1,0,1 };

void Input()
{
    cin >> M; cin >> S;
    for (int i = 0; i < M; i++) {
        int x, y, d;
        cin >> x; cin >> y; cin >> d;
        Fish fish;
        fish.x = x; fish.y = y; fish.d = d;
        map[x][y].push_back(fish);
    }
    cin >> Sx; cin >> Sy;
}

void First()
{
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            c_map[i][j].clear();
            c_map[i][j] = map[i][j];

            d_map[i][j].clear();
        }
    }
}

int Chang_dir(int d)
{
    d -= 1;
    if (d == 0) d = 8;
    return d;
}

void Move(Fish fish)
{
    int x = fish.x;
    int y = fish.y;
    int d = fish.d;

    bool flag = true;
    while (flag) {
        int nx = x + dx_fish[d];
        int ny = y + dy_fish[d];
        if (nx < 1 || ny < 1 || nx >= 5 || ny >= 5) {
            d = Chang_dir(d);
            if (d == fish.d) { flag = false; }
            continue;
        }
        if (nx == Sx && ny == Sy) {
            d = Chang_dir(d);
            if (d == fish.d) { flag = false; }
            continue;
        }
        if (smell[nx][ny] != 0) {
            d = Chang_dir(d);
            if (d == fish.d) { flag = false; }
            continue;
        }
        Fish n_fish;
        n_fish.x = nx;
        n_fish.y = ny;
        n_fish.d = d;
        d_map[nx][ny].push_back(n_fish);
        break;
    }
    if (!flag) {
        d_map[fish.x][fish.y].push_back(fish);
    }
}

void Second()
{
    for (int i = 1; i <= 4; i++) {  //mistake 
        for (int j = 1; j <= 4; j++) {
            if (map[i][j].empty())continue;
            for (int k = 0; k < map[i][j].size(); k++) {
                Move(map[i][j][k]);
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            map[i][j].clear();
            map[i][j] = d_map[i][j];
        }
    }
}

int arr[4];
int sum_max;
vector<int> candidate;

void DFS(int cnt)
{
    if (cnt == 3) {
        int sum = 0;

        int a1, b1, a2, b2;

        int nSx = Sx + dx_shark[arr[1]];
        int nSy = Sy + dy_shark[arr[1]];
        if (nSx < 1 || nSy < 1 || nSx >= 5 || nSy >= 5)return;
        sum += map[nSx][nSy].size();
        a1 = nSx; b1 = nSy;

        nSx = nSx + dx_shark[arr[2]];
        nSy = nSy + dy_shark[arr[2]];
        if (nSx < 1 || nSy < 1 || nSx >= 5 || nSy >= 5)return;
        sum += map[nSx][nSy].size();
        a2 = nSx; b2 = nSy;

        nSx = nSx + dx_shark[arr[3]];
        nSy = nSy + dy_shark[arr[3]];
        if (nSx < 1 || nSy < 1 || nSx >= 5 || nSy >= 5)return;
        if ((nSx == a1 && nSy == b1) || (nSx == a2 && nSy == b2)) {
            sum += 0;
        }
        else sum += map[nSx][nSy].size();

        if (sum_max > sum)return;
        else if (sum_max == sum) {
            int temp = arr[1] * 100 + arr[2] * 10 + arr[3];
            candidate.push_back(temp);
            return;
        }
        else if (sum_max < sum) {
            int temp = arr[1] * 100 + arr[2] * 10 + arr[3];
            candidate.clear();
            candidate.push_back(temp);
            sum_max = sum;
            return;
        }
    }
    for (int i = 1; i <= 4; i++) {
        arr[cnt + 1] = i;
        DFS(cnt + 1);
    }
}

void Smell_Check()
{
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (smell[i][j] == 0)continue;
            smell[i][j]--;
        }
    }
}

void Third()
{
    candidate.clear();
    sum_max = 0;
    DFS(0);
    sort(candidate.begin(), candidate.end());
    /*
    for(int i=0;i<candidate.size();i++){
        cout<<"cand"<<i+1<<" "<<candidate[i]<<endl;
    }*/
    //cout<<"max"<<" "<<sum_max<<endl;
    string max_dir = to_string(candidate[0]);
    arr[1] = max_dir.at(0) - '0';
    arr[2] = max_dir.at(1) - '0';
    arr[3] = max_dir.at(2) - '0';

    //cout<<"shark dir: ";
    /*
    for(int i=1;i<=3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    */

    Smell_Check();

    Sx = Sx + dx_shark[arr[1]];
    Sy = Sy + dy_shark[arr[1]];
    if (map[Sx][Sy].size() > 0) {
        smell[Sx][Sy] = 2;
    }
    map[Sx][Sy].clear();

    Sx = Sx + dx_shark[arr[2]];
    Sy = Sy + dy_shark[arr[2]];
    if (map[Sx][Sy].size() > 0) {
        smell[Sx][Sy] = 2;
    }
    map[Sx][Sy].clear();

    Sx = Sx + dx_shark[arr[3]];
    Sy = Sy + dy_shark[arr[3]];
    if (map[Sx][Sy].size() > 0) {
        smell[Sx][Sy] = 2;
    }
    map[Sx][Sy].clear();
}

void Fourth()
{
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (c_map[i][j].size() == 0)continue;
            for (int k = 0; k < c_map[i][j].size(); k++) {
                map[i][j].push_back(c_map[i][j][k]);
            }
        }
    }
}

void Solution()
{
    while (S--) {
        // cout<<"start shark"<<Sx<<" "<<Sy<<" "<<endl;
        First();
        Second();
        /*
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                cout<<map[i][j].size()<<" ";
            }
            cout<<endl;
        }
        */
        Third();
        Fourth();
        //cout<<"end shark"<<Sx<<" "<<Sy<<" "<<endl;

    }

    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (map[i][j].size() == 0)continue;
            ans += map[i][j].size();
        }
    }
    cout << ans;
}

void Solve()
{
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
