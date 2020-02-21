from fractions import Fraction
from fractions import gcd

def sort_list(abs_state, n):
    new_lis = abs_state + [i for i in range(0, n) if i not in set(abs_state)]
    return new_lis;

def absorbing_state(m, n):
    state = [];
    for i in range (0, n):
        tmp = 0;
        for j in range (0, n):
            tmp += m[i][j];
        if tmp == 0:
            state.append(i);
    return state;

def fundamental_matrix(non_abs_count, q):
    f = [[0 for i in range(0, non_abs_count)] for j in range(0, non_abs_count)];
    for i in range(0, non_abs_count):
        for j in range(0, non_abs_count):
            if i == j:
                f[i][j] = 1;
            f[i][j] -= q[i][j];
    return f;

def transpose_matrix(m):
    return map(list, zip(*m));

def matrix_minor(m, i, j):
    return [k[:j] + k[j + 1:] for k in (m[:i] + m[i + 1:])];

def matrix_determinant(m):
    if len(m) ==2:
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    else:
        d = 0;
        for i in range(0, len(m)):
            d += ( (-1) ** i) * m[0][i] * matrix_determinant(matrix_minor(m, 0, i));
        return d;

def matrix_inverse(m):
    #print(m);
    d = matrix_determinant(m);
    #print('d=',d);

    if len(m) == 2:
        return [[m[1][1] / d, -1 * m[0][1] / d],
                [-1 * m[1][0] / d, m[0][0] / d]];
    else :
        c = [];
        for i in range(len(m)):
            c_r = [];
            for j in range(len(m)):
                mi = matrix_minor(m, i, j);
                c_r.append(((-1) ** (i + j)) * matrix_determinant(mi));
            c.append(c_r);
        c = transpose_matrix(c);
        for i in range(len(m)):
            for j in range(len(m)):
                c[i][j] = c[i][j] / d;
        return c;

def standard_form(m, n, abs_s):
    mm = [[0 for i in range (0, n)] for j in range (0, n)];
    for i in abs_s:
        mm[i][i] = 1;
    for i in range (0, n):
        s = 0;
        for j in range (0, n):
            s += m[i][j];
        for j in range (0, n):
            if s > 0 :
                mm[i][j] = Fraction(m[i][j], s);
            if s == 0 :
                if j != i :
                    mm[i][j] = Fraction(0, 1);
                else:
                    mm[i][j] = Fraction(1, 1);
    #for i in mark_matrix:
    #    print(i);
    tmp = [[0 for i in range (0, n)] for j in range (0, n)];
    for i in range (0, n):
        for j in range (0, n):
            tmp_l = sort_list(abs_s, n);
            tmp[i][j] = mm[tmp_l[i]][tmp_l[j]];
    mm = tmp;
    return mm;

def matrix_product(m, n):
    return [[sum(a * b for a, b in zip(m_row, n_col)) for n_col in zip(*n)] for m_row in m];

def lcm(a, b):
    return a * b // gcd(a, b);

def answer(m):
    #for i in m:
    #    print(i);
    n = len(m); #n states
    #print(n);
    abs_s = absorbing_state(m,n);
    abs_count = len(abs_s);
    markov_matrix = standard_form(m, n, abs_s);
    if abs_count == n:
        return [1, 1];
    #for i in mark_matrix:
    #    print(i);
    non_abs_count = n - abs_count;
    r = [];
    q = [];
    for i in markov_matrix[abs_count:n]:
        r.append(i[0:abs_count]);
        q.append(i[abs_count:n]);
    #for i in r:
    #   print(i);
    #for i in q:
    #    print(i);
    f = matrix_inverse(fundamental_matrix(non_abs_count, q));
    #for i in f:
    #    print(i);
    #print("end f");
    ans = matrix_product(f, r);
    ans = ans[0];
    #print(ans);
    d = reduce(lcm, [i.denominator for i in ans]);
    #print(d);
    for i in range (0, len(ans)):
        ans[i] *= d;
        ans[i] = ans[i].numerator;
    #print(ans);
    ans.append(d);
    return ans;


#m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]];
#m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
#m = [
#        [0, 0, 12, 0, 15, 0, 0, 0, 1, 8],
#        [0, 0, 60, 0, 0, 7, 13, 0, 0, 0],
#        [0, 15, 0, 8, 7, 0, 0, 1, 9, 0],
#        [23, 0, 0, 0, 0, 1, 0, 0, 0, 0],
#        [37, 35, 0, 0, 0, 0, 3, 21, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#    ]
#m = [
#        [0, 7, 0, 17, 0, 1, 0, 5, 0, 2],
#        [0, 0, 29, 0, 28, 0, 3, 0, 16, 0],
#        [0, 3, 0, 0, 0, 1, 0, 0, 0, 0],
#        [48, 0, 3, 0, 0, 0, 17, 0, 0, 0],
#        [0, 6, 0, 0, 0, 1, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#    ]
#print(answer(m));
