#k진수에서 소수판별할 수만 구하기
def make_n_list(n,k):
    s=''         #k진수소수
    while n!=0:
        s += str(n%k)
        n = n//k
    s = s[::-1]
    n_list=[int(i) for i in s.split('0') if i != '']
    return n_list

#소수 체크
def check_prime(n):
    if n == 1:
        return 0
    root_MAX = int(n**(1/2))+1
    for i in range(2,root_MAX):
        if(n % i == 0):
            return 0
    return 1

def solution(n, k):
    answer = -1
    #k진수에서 체크할 숫자들만 리스트로 저장
    n_list = make_n_list(n,k)
    #소수이면 1 아니면 0으로 저장
    n_prime_list = [check_prime(i) for i in n_list]
    #소수 개수 구하기
    answer = sum(n_prime_list)
    return answer