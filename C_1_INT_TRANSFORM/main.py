def transform(N, P):
    n_str = str(N)
    p_digit = int(n_str[len(n_str) - P])
    result = ''
    for i, c in enumerate(n_str):
        if i < len(n_str) - P:
            result += str((int(c) + p_digit) % 10)
        elif i > len(n_str) - P:
            result += str(abs(int(c) - p_digit))
        else:
            result += c
    return int(result)


with open("input.txt", "r", encoding="utf-8") as f:
    lines = f.readlines()
    for line in lines:
        n, p = line.split()
        result = transform(int(n), int(p))
        print(result)
