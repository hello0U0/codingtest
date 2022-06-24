from collections import defaultdict

def solution(fees, records):
    answer = []
    car_time = defaultdict(str)
    car_pay = defaultdict(int)
    for oper in records:
        time, carnum, inout = oper.split()
        
        if inout == "IN":
            car_time[carnum] = time
            continue
        
        intime = int(car_time[carnum][:2]) * 60 + int(car_time[carnum][3:])
        outtime = int(time[:2]) * 60 + int(time[3:])
        car_pay[carnum] += outtime - intime
        car_time[carnum] = ""
        
    for carnum,car_intime in car_time.items():
        if car_intime:
            intime = int(car_intime[:2]) * 60 + int(car_intime[3:])
            outtime = 23 * 60 + 59
            car_pay[carnum] += outtime - intime
            
    for carnum in sorted(car_pay.keys()):
        pay = fees[1] + (max(car_pay[carnum] - fees[0], 0) +fees[2] - 1) // fees[2] * fees[3]
        answer.append(pay)
        
    return answer