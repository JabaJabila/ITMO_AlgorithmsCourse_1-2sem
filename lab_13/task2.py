def hash_s(s, n):
    h = 0
    for i in range(n):
        h = (h * 2 + ord(s[i]) - 65) % 1000000000000000000000001
    return h

inputf = list(open("search2.in"))

s1 = inputf[0][:-1]
s2 = inputf[1]

ans = []

m = len(s1)
n = len(s2)

if (m > n):
    with open('search2.out', 'w') as file:
        file.write("0\n")

else:
    xm = 2 ** m

    h1 = hash_s(s1, m)
    h2 = hash_s(s2[:m], m)

    for i in range(1, n - m + 2):
        if (s2[i - 1] == s1[0] and h1 == h2):
            cur = i;
            flag = True
            for j in range(1, m):
                if s2[cur] != s1[j]:
                    flag = False
                    break
                cur += 1
            if flag:
                ans.append(i)
        if i != n - m + 1:
            h2 = (h2 * 2 - (ord(s2[i - 1]) - 65) * xm + (ord(s2[i - 1 + m]) - 65)) % 1000000000000000000000001

    with open('search2.out', 'w') as file:
        file.write(str(len(ans)) + "\n")
        for i in ans:
            file.write(str(i) + " ")
