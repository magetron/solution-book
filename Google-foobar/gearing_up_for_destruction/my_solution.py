from fractions import Fraction

sign = -1

def calc_ans(pegs, data_len):
    ans = 0;
    if data_len > 2:
        if data_len % 2 == 0:
            for i in range (1, data_len - 1):
                ans += 2 * pegs[i] * sign ** (i + 1);
            ans += - pegs[0] + pegs[data_len - 1];
            ans_o = Fraction(ans * 2, 3);

        if data_len % 2 == 1:
            for i in range (1, data_len - 1):
                ans += 2 * pegs[i] * sign ** (i + 1);
            ans -= pegs[0] + pegs[data_len - 1];
            ans_o = Fraction(ans * 2, 1);

    elif data_len == 2:
        ans = pegs[1] - pegs[0];
        ans_o = Fraction(ans * 2, 3);

    return ans_o;


def is_valid_ans(pegs, data_len, ans):
    check0 = ans;
    dist = 0;
    for i in range(0, data_len - 2):
        dist = pegs[i + 1] - pegs[i];
        check1 = dist - check0;
        if check0 < 1 or check1 < 1:
            return 0;
        check0 = check1;

    return 1;

def answer(pegs):
    data_len = len(pegs);
    ans = calc_ans(pegs, data_len);
    if is_valid_ans(pegs, data_len, ans):
        return [ans.numerator, ans.denominator];
    else:
        return [-1, -1];

print(answer([4, 17, 50]));
