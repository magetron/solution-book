import math;

area_max = 1000000;
area_min = 1;

def answer(area):
    #init
    ans_list = [];
    #recursive
    do_work(area, ans_list);
    #modify list for output
    ans_list.reverse();
    return ans_list;


def do_work(area, ans_list):
    if area >= area_min and area <= area_max:
        tmp = int(math.sqrt(area));
        tmp *= tmp;

        if tmp == 0:
            return;
        else:
            area -= tmp;
            do_work(area, ans_list);
            ans_list.append(tmp);
        return;

print(answer(999999));
