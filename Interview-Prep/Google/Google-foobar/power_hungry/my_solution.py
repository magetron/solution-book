def answer(xs):
    pos = [];
    neg = [];
    ans = 1;
    data_len = len(xs);

    for i in range(0, data_len):
        if xs[i] > 0:
            pos.append(xs[i]);
        elif xs[i] < 0:
            neg.append(xs[i]);

    #print(pos);
    #print(neg);

    pos_len = len(pos);
    neg_len = len(neg);
    
    if pos_len == 0 and neg_len == 1 and data_len > 1:
        return str(0);

    elif pos_len == 0 and neg_len ==1 and data_len == 1:
        return str(neg[0]);

    elif pos_len == 0 and neg_len == 0:
        return str(0);

    else:
        
        if neg_len % 2 == 1:
            neg.remove(max(neg));
            neg_len -= 1;

        for i in range(0, pos_len):
            ans *= pos[i];

        for i in range(0, neg_len):
            ans *= neg[i];

    return str(ans);

print(answer([0, 0, -50000]));


