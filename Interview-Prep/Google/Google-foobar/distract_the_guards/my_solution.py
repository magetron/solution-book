from fractions import gcd;

def is_forever(x, y):
    n = (x + y) / gcd(x, y);
    return not (n & (n - 1)) == 0 and n > 0;

def matched_lists(l, v):
    return [i for i in range(0, len(l)) if l[i] == v ]

def delete_value(l, i, j):
    if i in l:
        del l[l.index(i)];
    if j in l:
        del l[l.index(j)];
    return l;

def answer(banana_list):
    ans = 0;
    banana_list = sorted(banana_list);
    f_list = [[banana_list[i] for i in range(0, len(banana_list)) if is_forever(banana_list[i], banana_list[j])] for j in range(0, len(banana_list))];
    min_list = min(f_list, key = lambda i: len(i) or 101);

    while len(min_list) and len(filter(lambda x: len(x), f_list)) > 1:
        c_item = banana_list[f_list.index(min_list)];
        f_item = min_list[0];
        for i in matched_lists(banana_list, f_item):
            if len(f_list[i]):
                    del f_list[i][:];
                    break;
        del min_list[:];

        f_list = map(lambda x:  delete_value(x, c_item, f_item), f_list);
        ans += 2;
        min_list = min(f_list, key = lambda i: len(i) or 101);

    return len(banana_list) - ans;

#print(answer([1,1]));
#print answer([1, 7, 3, 21, 13, 19])
#print answer([1])
#print answer([1, 2, 1, 7, 3, 21, 13, 19])
