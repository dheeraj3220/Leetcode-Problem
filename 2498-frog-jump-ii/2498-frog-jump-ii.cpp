class Solution {
public:
   int maxJump(vector<int>& st) {
    int res = st[1] - st[0];
    for (int i = 1; i < st.size() - 1; ++i)
        res = max(res, st[i + 1] - st[i - 1]);
    return res;
}
};