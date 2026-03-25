int maxAqua(string s, int L) {
    int maxA = 0, n = s.length();
    for (int i = 0; i < n; i += L) {
        int currentA = 0;
        for (int j = i; j < i + L && j < n; j++) {
            if (s[j] == 'A') currentA++;
        }
        maxA = max(maxA, currentA);
    }
    return maxA;
}
