int solution(int number, int limit, int power) {
    int answer = 0;

    int* nDivisor = new int[number + 1]{0};
    for (int i = 1; i <= number; i++) {
        for (int j = i; j <= number; j += i) nDivisor[j]++;
    }
    for (int i = 1; i <= number; i++) {
        answer += nDivisor[i] > limit ? power : nDivisor[i];
    }
    delete[] nDivisor;

    return answer;
}