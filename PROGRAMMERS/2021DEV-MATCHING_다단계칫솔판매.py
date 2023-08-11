def calMoney(referral, money, pidx, answer):
    refer_money = money // 10
    answer[pidx] += money - refer_money
    
    if pidx != "-" and refer_money >= 10:
        calMoney(referral, refer_money, referral[pidx], answer)
    else:
        answer[referral[pidx]] += refer_money
    return
    
def solution(enroll, referral, seller, amount):
    # 민호 추가
    enroll = ["-"] + enroll
    referral = ["-"] + referral
    totalp = len(enroll)
    
    # 이름 - 숫자 딕셔너리
    name2num = {}
    for i in range(totalp):
        name2num[enroll[i]] = i
    
    # 추천인 숫자로
    referral = [name2num[i] for i in referral]

    #값 계산
    answer = [0] * totalp
    for i in range(len(seller)):
        pidx = name2num[seller[i]]
        money = amount[i] * 100
        calMoney(referral, money, pidx, answer)
    return answer[1:]
