def solution(scores):
    answer = ''

    n = len(scores)
    for i in range(n):
        tmp = []
        n = len(scores)

        for j in range(n):
            tmp.append(scores[j][i])

        total = sum(tmp)

        if (tmp[i] == max(tmp) or tmp[i] == min(tmp)) and tmp.count(tmp[i]) < 2:
            total -= tmp[i]
            n -= 1

        result = total/n
        
        if result < 50:
            answer += 'F'
        elif result < 70:
            answer += 'D'
        elif result < 80:
            answer += 'C'
        elif result < 90:
            answer += 'B'
        else:
            answer += 'A'
    print(answer)
    return answer

# [[100,90,98,88,65],[50,45,99,85,77],[47,88,95,80,67],[61,57,100,80,65],[24,90,94,75,65]]
# [[50,90],[50,87]]
# [[70,49,90],[68,50,38],[73,31,100]]

solution([[100,90,98,88,65],[50,45,99,85,77],[47,88,95,80,67],[61,57,100,80,65],[24,90,94,75,65]])
