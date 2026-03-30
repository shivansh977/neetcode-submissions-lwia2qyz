class CountSquares {
private:
    map<pair<int,int>, int> cnt;
public:
    CountSquares() {}

    void add(vector<int> point) {
        cnt[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int ans = 0;
        for (auto const& pai : cnt) {
            auto p = pai.first;
            if (p.first == point[0] || p.second == point[1]) continue;

            int dx = abs(p.first - point[0]);
            int dy = abs(p.second - point[1]);
            if (dx != dy) continue;

            ans += pai.second
                * cnt[{p.first, point[1]}]
                * cnt[{point[0], p.second}];
        }
        return ans;
    }
};
