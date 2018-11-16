#ax_l_length = 2000;

def find_div(l, l_c):
    for i in range (0, len(l) - 1):
        for j in range (i + 1, len(l)):
            if l[j] % l[i] == 0:
                l_c[j] += 1;
    return;

def find_div_div(l, l_c):
    ans = 0;
    for i in range(1, len(l) - 1):
        for j in range (i + 1, len(l)):
            if l[j] % l[i] == 0:
                ans += l_c[i];
    return ans;

def answer(l):
    l_c = [0 for i in range (0, len(l))];
    find_div(l, l_c);
    #print(l_c);
    return find_div_div(l, l_c);

#print(answer([1, 1, 1]));
#print(answer([1, 2, 3, 4, 5, 6]));
