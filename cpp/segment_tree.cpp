class SegmentTree {
public:
    SegmentTree(int n) : m_size(n), m_arr(4 * n, 0) {}

    void modify(int x, int v) {
        modify(1, 0, m_size - 1, x, v);
    }

    int query(int x, int y) {
        return query(1, 0, m_size - 1, x, y);
    }

private:
    void modify(int i, int l, int r, int x, int v) {
        if (l == r) {
            m_arr[i] += v;
            return;
        }

        int m = (l + r) / 2;
        if (x <= m)
            modify(2 * i, l, m, x, v);
        else
            modify(2 * i + 1, m + 1, r, x, v);

        // parent node is updated with the sum of the children
        m_arr[i] = m_arr[2 * i] + m_arr[2 * i + 1];
    };


    int query(int i, int l, int r, int x, int y) {
        if (l == x && r == y)
            return m_arr[i];

        int m = (l + r) / 2;

        if (m >= y)
            return query(2 * i, l, m, x, y);
        else if (m < x)
            return query(2 * i + 1, m + 1, r, x, y);
        else
            return query(2 * i, l, m, x, m) + query(2 * i + 1, m + 1, r, m + 1, y);
    };

    size_t m_size;
    std::vector<int> m_arr;
};
