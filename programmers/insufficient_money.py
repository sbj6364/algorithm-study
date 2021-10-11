def solution(price, money, count):
    
    if price < 1 or price > 2500:
        return -1
    if money < 1 or money > 1000000000:
        return -1
    if count < 1 or count > 2500:
        return -1
    
    answer = -1
    total = 0
    
    for i in range(count + 1):
        total = total + price * i
    
    answer = total - money
    if answer < 0:
        answer = 0
    
    return answer

print(solution(10, 300, 3))